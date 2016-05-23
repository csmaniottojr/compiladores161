/*
 * Copyright 2016 <Luis Decker> <luisgustavo.decker@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include "structures.h"
#include "ast.h"


//Constructors=====================================================================================
//SymbolTable====================================
Structures::SymbolTable::SymbolTable() {
	pai = nullptr;
}

//Symbol=========================================
Structures::Symbol::Symbol() {
	this->initialized = false;
	this->type = Structures::Types::tInteger;
	this->kind = Structures::Kinds::kVariable;
}



/*
 idMap is a <string,Symbol> Map !
 Where string is the id. name (the "var name")
 and id is the identifier infos (A Structures::Symbol obj)
 */
//SymbolTable======================================================================================
//===============================================
//definir variavel
AST::Node *Structures::SymbolTable::insertId ( std::string idName, AST::Node *nextVar, Structures::Types tipo, bool isArray ) {
		
	if ( ! containsIdentifier( idName ) )  {
		if( !isArray ) {
			Structures::Symbol newSymbol( Kinds::kVariable,tipo,false, false );
			std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
			this->symbolMap.insert ( newElement );

			return new AST::Variable( idName,nextVar,AST::Variable::ini,( AST::Types )tipo );
		} else {
			Structures::Symbol newSymbol( Kinds::kVariable,tipo,false, true );
			std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
			this->symbolMap.insert ( newElement );
			return new AST::Array( idName,nextVar,AST::Array::ini,( AST::Types )tipo,1 );
		}
	} else {
		if( symbolMap.at( idName ).isArray ) {
			yyerror( "Erro semantico: arranjo %s sofrendo redefinicao.\n",idName.c_str() );
		} else {
			yyerror( "Erro semantico: variavel %s sofrendo redefinicao.\n",idName.c_str() );
		}
		symbolMap.at( idName ).foiRedefinida=true;
		if( !isArray ) {
			return new AST::Variable( idName,nextVar,AST::Variable::ini,AST::Types::undefined );
		} else {
			return new AST::Array( idName,nextVar,AST::Array::ini,AST::Types::undefined,1 );
		}
	}
}



//===============================================
//Mudar recursivamente o tipo de uma lista de variaveis primitivas
void Structures::SymbolTable::updateTypes( AST::Node *nodo, Structures::Types tipo ) {
	AST::Variable *thisvar = dynamic_cast<AST::Variable *>( nodo );
	if( !symbolMap.at( thisvar->id ).foiRedefinida ) {
		thisvar->type = ( AST::Types ) tipo;
		symbolMap.at( thisvar->id ).updateType( tipo );
	}
	if( thisvar->next != nullptr ) {
		updateTypes( thisvar->next,tipo );
	}
}

//===============================================
//Mudar recursivamente o tipo de uma lista de variaveis compostas
void Structures::SymbolTable::updateTypes( AST::Node *nodo, Structures::Types tipo, std::string idType ) {
	AST::Variable *thisvar = dynamic_cast<AST::Variable *>( nodo );
	if( !symbolMap.at( thisvar->id ).foiRedefinida ) {
		symbolMap.at( thisvar->id ).idType = idType;
		thisvar->type = ( AST::Types ) tipo;
		thisvar->idType = idType;
		symbolMap.at( thisvar->id ).updateType( tipo );
	}
	if( thisvar->next != nullptr ) {
		updateTypes( thisvar->next,tipo );
	}
}
//===============================================
//Mudar recursivamente o tipo de uma lista de arranjos primitivas
void Structures::SymbolTable::updateTypesAndSize( AST::Node *nodo, Structures::Types tipo, int size ) {
	AST::Array *thisvar = dynamic_cast<AST::Array *>( nodo );
	int newSize = size;
	if( size <= 0 ) {
		yyerror( "Erro semantico: arranjo %s com tamanho menor do que um.\n",thisvar->id.c_str() );
		newSize = 1;
	}
	if( !symbolMap.at( thisvar->id ).foiRedefinida ) {
		thisvar->type = ( AST::Types ) tipo;
		thisvar->size = newSize;
		symbolMap.at( thisvar->id ).updateType( tipo );
	}
	if( thisvar->next != nullptr ) {
		updateTypesAndSize( thisvar->next,tipo,size );
	}
}
//===============================================
//Mudar recursivamente o tipo de uma lista de arranjos compostos
void Structures::SymbolTable::updateTypesAndSize( AST::Node *nodo, Structures::Types tipo, int size,std::string idType ) {
	AST::Array *thisvar = dynamic_cast<AST::Array *>( nodo );
	int newSize = size;
	if( size <= 0 ) {
		yyerror( "Erro semantico: arranjo %s com tamanho menor do que um.\n",thisvar->id.c_str() );
		newSize = 1;
	}
	if( !symbolMap.at( thisvar->id ).foiRedefinida ) {
		symbolMap.at( thisvar->id ).idType = idType;
		thisvar->type = ( AST::Types ) tipo;
		thisvar->size = newSize;
		thisvar->idType = idType;
		symbolMap.at( thisvar->id ).updateType( tipo );
	}
	if( thisvar->next != nullptr ) {
		updateTypesAndSize( thisvar->next,tipo,size,idType );
	}
}

//===============================================
// Obter tipo da variavel
Structures::Types Structures::SymbolTable::getidentifierType( std::string id ) {
	if ( symbolMap.find( id ) != symbolMap.end() ) {
		return symbolMap.at( id ).type;
	} else {
		return Structures::Types::undefined;
	}
}

//===============================================
bool Structures::SymbolTable::containsIdentifier( std::string idName ) {

	return symbolMap.find(idName) != symbolMap.end();
	
}
//===============================================
//Ler variavel
AST::Node *Structures::SymbolTable::getIdentifier( std::string id ) {
	Types symbolType;
	if( !containsIdentifier( id ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
			return new AST::Variable( id,NULL,AST::Variable::read,AST::Types::undefined );
		}else{
			
			return pai->getIdentifier(id);

		}			
	}
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			if(  it->second.type == Structures::Types::compound ) {
				yyerror( "Erro semantico: tipo %s com uso como variavel.\n",id.c_str() );
				return new AST::Variable( id,NULL,AST::Variable::read,AST::Types::undefined );
			}
			if( !it->second.initialized ) {
				yyerror( "Erro semantico: variavel %s nao inicializada.\n",id.c_str() );
			}
			symbolType = it->second.type;
			//std::cout<<"[usou " << id <<" "<< AST::TypesString[(int)symbolType]<< "]";
		}
	}
	return new AST::Variable( id, NULL, AST::Variable::read , ( AST::Types )symbolType );
}

//===============================================
//Ler variavel no indice
AST::Node *Structures::SymbolTable::getIdentifier( std::string id,AST::Node *indice ) {
	Types symbolType;
	if( !containsIdentifier( id ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
			return new AST::ArrayItem( id,NULL,AST::ArrayItem::read,AST::Types::undefined,indice );

		}else{
			
			return pai->getIdentifier(id,indice);

		}	

	}
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";

			if(  it->second.type == Structures::Types::compound ) {
				yyerror( "Erro semantico: tipo %s com uso como variavel.\n",id.c_str() );
				return new AST::ArrayItem( id,NULL,AST::ArrayItem::read,AST::Types::undefined,indice );
			}

			if( !it->second.initialized ) {
				yyerror( "Erro semantico: variavel %s  nao inicializada.\n",id.c_str() );
			}
			symbolType = it->second.type;
			//std::cout<<"[usou " << id <<" "<< AST::TypesString[(int)symbolType]<< "]";
		}
	}
	return new AST::ArrayItem( id, NULL, AST::ArrayItem::read , ( AST::Types )symbolType,indice );
}
//===============================================
//Ler variável de composto

AST::Node *Structures::SymbolTable::getIdentifier( std::string idVar, std::string idComponent ) {
	Types symbolType;
		if( !containsIdentifier( idVar ) ) {

			if(pai == nullptr){
				
				yyerror( "Erro semantico: variavel %s sem declaracao.\n",idVar.c_str() );
				return new AST::Variable( idVar,NULL,AST::Variable::read,AST::Types::undefined );
			}else{
				
				return pai->getIdentifier(idVar,idComponent);

			}			
		}


		if(symbolMap.at(idVar).type != Structures::Types::compound){
			if( symbolMap.at( idVar ).isArray ) {
				yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			}else{
				yyerror( "Erro semantico: variavel %s com uso como tipo.\n",idVar.c_str() );
				}
				return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
			}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::Variable *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){
			
			if(!this->compoundScopeMap[idType]->symbolMap[idComponent].initialized){
				yyerror( "Erro semantico: componente %s nao inicializada.\n",idComponent.c_str() );
			}
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type );
			varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
			
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined );
			varType = Structures::Types::undefined;
		}

		AST::Variable *var = new AST::Variable( idVar,NULL,AST::Variable::read,( AST::Types )varType);
		var->idType = idType;


		var->component = compVar;
		return var;

}

//===============================================
//Ler variável de composto no indice

AST::Node *Structures::SymbolTable::getIdentifier( std::string idVar, std::string idComponent, AST::Node *indice ) {
	Types symbolType;
		if( !containsIdentifier( idVar ) ) {

			if(pai == nullptr){
				
				yyerror( "Erro semantico: variavel %s sem declaracao.\n",idVar.c_str() );
				return new AST::Variable( idVar,NULL,AST::Variable::read,AST::Types::undefined );
			}else{
				
				return pai->getIdentifier(idVar,idComponent);

			}			
		}


		if(symbolMap.at(idVar).type != Structures::Types::compound){
			if( symbolMap.at( idVar ).isArray ) {
				yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			}else{
				yyerror( "Erro semantico: variavel %s com uso como tipo.\n",idVar.c_str() );
				}
				return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
			}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::ArrayItem *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){
			
			
			

			if(!this->compoundScopeMap[idType]->symbolMap[idComponent].isArray){
				yyerror("Erro semantico: componente %s do tipo %s sendo tratado como arranjo é variável primitiva.\n", idComponent.c_str(),idType.c_str());
				compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,AST::Types::undefined,indice);
				varType = varType = Structures::Types::undefined;
			
			}else{
				
				compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type,indice );
				varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
			}


			
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,AST::Types::undefined,indice );
			varType = Structures::Types::undefined;
		}

		AST::Variable *var = new AST::Variable( idVar,NULL,AST::Variable::read,( AST::Types )varType);
		var->idType = idType;


		var->component = compVar;
		return var;

}

//===============================================
//Ler variável no indice de componente

AST::Node *Structures::SymbolTable::getIdentifier( std::string idVar,  AST::Node *indice, std::string idComponent ) {
	Types symbolType;
		if( !containsIdentifier( idVar ) ) {

			if(pai == nullptr){
				
				yyerror( "Erro semantico: variavel %s sem declaracao.\n",idVar.c_str() );
				return new AST::Variable( idVar,NULL,AST::Variable::read,AST::Types::undefined );
			}else{
				
				return pai->getIdentifier(idVar,idComponent);

			}			
		}


		if(symbolMap.at(idVar).type != Structures::Types::compound){
			if( symbolMap.at( idVar ).isArray ) {
				yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			}else{
				yyerror( "Erro semantico: variavel %s com uso como tipo.\n",idVar.c_str() );
				}
				return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
			}

		if(!symbolMap.at( idVar ).isArray ) {
			yyerror( "Erro semantico: variavel %s com uso como arranjo.\n",idVar.c_str() );
		}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::Variable *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){
			

			if(this->compoundScopeMap[idType]->symbolMap[idComponent].isArray){
				yyerror("Erro semantico: componente %s do tipo %s sendo tratado como variável primitiva é arranjo.\n", idComponent.c_str(),idType.c_str());
				compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined);
				varType = varType = Structures::Types::undefined;
			
			}else{
				
				compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type );
				varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
			}


			
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined );
			varType = Structures::Types::undefined;
		}

		AST::ArrayItem *var = new AST::ArrayItem( idVar,NULL,AST::ArrayItem::read,( AST::Types )varType,indice);
		var->idType = idType;


		var->component = compVar;
		return var;

}

//===============================================
//Atribuir  variavel
AST::Node *Structures::SymbolTable::assignVariable( std::string id ) {
		
	if( !containsIdentifier( id ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
			return new AST::Variable( id,NULL,AST::Variable::atrib,AST::Types::undefined );
		}else{
			
			return pai->assignVariable(id);
		}	

	} else {
		if( symbolMap.at( id ).isArray ) {
			yyerror( "Erro semantico: arranjo %s com uso como variavel.\n",id.c_str() );
			return new AST::Variable( id,NULL,AST::Variable::atrib,AST::Types::undefined );
		}
		this->symbolMap[id].initialized=true;
		//std::cout << "[atribuindo " << id << " " << AST::TypesString[(int)this->symbolMap.at(id).type]<< "]";
		return new AST::Variable( id,NULL,AST::Variable::atrib,( AST::Types )this->symbolMap[id].type );
	}
}
//===============================================
//Atribuir variavel no indice
AST::Node *Structures::SymbolTable::assignVariable( std::string id , AST::Node *indice ) {
	if( !containsIdentifier( id ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: arranjo %s sem declaracao.\n",id.c_str() );
			return new AST::ArrayItem( id,NULL,AST::ArrayItem::atrib,AST::Types::undefined, indice );
		}else{
			
			return pai->assignVariable(id,indice);

		}	
		
	}
	if( !symbolMap.at( id ).isArray ) {
		yyerror( "Erro semantico: variavel %s com uso como arranjo.\n",id.c_str() );
		return new AST::ArrayItem( id,NULL,AST::ArrayItem::atrib,AST::Types::undefined,indice );
	}
	this->symbolMap[id].initialized=true;
	//std::cout << "[atribuindo " << id << " " << AST::TypesString[(int)this->symbolMap.at(id).type]<< "]";
	return new AST::ArrayItem( id,NULL,AST::ArrayItem::atrib,( AST::Types )this->symbolMap[id].type, indice );
}

//===============================================
//atribuir componente de tipo composto
AST::Node *Structures::SymbolTable::assignVariable( std::string idVar, std::string idComponent ){
	if( !containsIdentifier( idVar ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: variavel %s sem declaracao.\n",idVar.c_str() );
			return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
		}else{
			
			return pai->assignVariable(idVar);
		}	

	} else {

		if(symbolMap.at( idVar ).type != Structures::Types::compound){
			if( symbolMap.at( idVar ).isArray ) {
				yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			}else{
				yyerror( "Erro semantico: variavel %s com uso como tipo.\n",idVar.c_str() );
			}
			return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
		}

		if( symbolMap.at( idVar ).isArray ) {
			yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
		}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::Variable *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){
			this->compoundScopeMap[idType]->symbolMap[idComponent].initialized=true;
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type );
			varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined );
			varType = Structures::Types::undefined;
		}

		AST::Variable *var = new AST::Variable( idVar,NULL,AST::Variable::atrib,( AST::Types )varType);
		var->idType = idType;


		var->component = compVar;
		return var;
	}
}

//===============================================
//atribuir componente de tipo composto no indice
AST::Node *Structures::SymbolTable::assignVariable( std::string idVar, std::string idComponent,AST::Node *indice  ){
	if( !containsIdentifier( idVar ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: variavel %s sem declaracao.\n",idVar.c_str() );
			return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
		}else{
			
			return pai->assignVariable(idVar);
		}	

	} else {

		if(symbolMap.at( idVar ).type != Structures::Types::compound){
			if( symbolMap.at( idVar ).isArray ) {
				yyerror( "Erro semantico: arranjo %s com uso como tipo.\n",idVar.c_str() );
			}else{
				yyerror( "Erro semantico: variavel %s com uso como tipo.\n",idVar.c_str() );
			}
			return new AST::Variable( idVar,NULL,AST::Variable::atrib,AST::Types::undefined );
		}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::ArrayItem *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){

			if(!this->compoundScopeMap[idType]->symbolMap[idComponent].isArray){
				yyerror("Erro semantico: componente %s do tipo %s sendo tratado como arranjo é variável primitiva.\n", idComponent.c_str(),idType.c_str());
				compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,AST::Types::undefined,indice);
				varType = varType = Structures::Types::undefined;
			
			}else{
				this->compoundScopeMap[idType]->symbolMap[idComponent].initialized=true;
				compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type,indice );
				varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
			}
			
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::ArrayItem( idComponent,NULL,AST::ArrayItem::read,AST::Types::undefined ,indice);
			varType = Structures::Types::undefined;
		}

		AST::Variable *var = new AST::Variable( idVar,NULL,AST::Variable::atrib,( AST::Types )varType);
		var->idType = idType;


		var->component = compVar;
		return var;
	}
}




//===============================================
//atribuir indice de tipo composto na variavel
AST::Node *Structures::SymbolTable::assignVariable( std::string idVar, AST::Node *indice, std::string idComponent  ){
	if( !containsIdentifier( idVar ) ) {

		if(pai == nullptr){
			
			yyerror( "Erro semantico: arranjo %s sem declaracao.\n",idVar.c_str() );
			return new AST::ArrayItem( idVar,NULL,AST::ArrayItem::atrib,AST::Types::undefined,indice);
		}else{
			
			return pai->assignVariable(idVar);
		}	

	} else {

		if(symbolMap.at( idVar ).type != Structures::Types::compound){
			if(! symbolMap.at( idVar ).isArray ) {
				
				yyerror( "Erro semantico: variavel %s com uso como arranjo.\n",idVar.c_str() );
			}
			return new AST::ArrayItem( idVar,NULL,AST::ArrayItem::atrib,AST::Types::undefined,indice );
		}

		std::string idType = symbolMap.at( idVar ).idType;

		Structures::Types varType;

		AST::Variable *compVar;

		if(compoundScopeMap[idType]->symbolMap.find(idComponent) != compoundScopeMap[idType]->symbolMap.end()){

			if(this->compoundScopeMap[idType]->symbolMap[idComponent].isArray){
				yyerror("Erro semantico: componente %s do tipo %s sendo tratado como arranjo é variável primitiva.\n", idComponent.c_str(),idType.c_str());
				compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined);
				varType = varType = Structures::Types::undefined;
			
			}else{
				this->compoundScopeMap[idType]->symbolMap[idComponent].initialized=true;
				compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,( AST::Types )this->compoundScopeMap[idType]->symbolMap[idComponent].type );
				varType = this->compoundScopeMap[idType]->symbolMap[idComponent].type;
			}
			
		}else{
			yyerror("Erro semantico: tipo %s nao contem componente %s.\n", idType.c_str(),idComponent.c_str());
			compVar =  new AST::Variable( idComponent,NULL,AST::Variable::read,AST::Types::undefined);
			varType = Structures::Types::undefined;
		}

		AST::ArrayItem *var = new AST::ArrayItem( idVar,NULL,AST::ArrayItem::atrib,( AST::Types )varType,indice);
		var->idType = idType;


		var->component = compVar;
		return var;
	}
}


//===============================================
//Insere um tipo composto
AST::Node *Structures::SymbolTable::insertCompound( std::string idName, Structures::SymbolTable *compoundScope, AST::Node* declarations ) {
	
	if ( ! containsIdentifier( idName ) )  {
		
			Structures::Symbol newSymbol( Kinds::kVariable,Structures::Types::compound,false, false );
			std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
			this->symbolMap.insert ( newElement );

			std::pair<std::string,Structures::SymbolTable*> newCompost ( idName,compoundScope );
			this->compoundScopeMap.insert ( newCompost );


			return new AST::Compound(idName,dynamic_cast<AST::Block *>( declarations ));
		
	} else {
		
		yyerror( "Erro semantico: tipo %s sofrendo redefinicao.\n",idName.c_str() );
		
		symbolMap.at( idName ).foiRedefinida=true;
		return new AST::Compound(idName,dynamic_cast<AST::Block *>( declarations ));
		
	}

}
//===============================================
//Modifica o escopo (tabela) pai
void Structures::SymbolTable::updatePai( Structures::SymbolTable *newPai ) {
	this->pai = newPai;
}


