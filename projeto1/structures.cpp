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
}

//Symbol=========================================
Structures::Symbol::Symbol() {
	this->initialized = false;
	this->type = Structures::Types::tInteger;
	this->kind = Structures::Kinds::kVariable;
	this->value = DataContainer( 0 ); //Creates a int* with 0 in its elements
}



/*
 idMap is a <string,Symbol> Map !
 Where string is the id. name (the "var name")
 and id is the identifier infos (A Structures::Symbol obj)
 */
//SymbolTable======================================================================================
//===============================================
//definir variavel
AST::Node *Structures::SymbolTable::insertVariable ( std::string idName, AST::Node *nextVar, Structures::Types tipo ) {
	if ( ! containsIdentifier( idName ) )  {
		Structures::Symbol newSymbol( Kinds::kVariable,tipo,DataContainer( 0 ),false, false,false );
		std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
		this->symbolMap.insert ( newElement );
		return new AST::Variable( idName,nextVar,AST::Variable::ini,( AST::Types )tipo );
	} else {
		if( symbolMap.at( idName ).isArray ) {
			yyerror( "Erro semantico: arranjo %s sofrendo redefinicao.\n",idName.c_str() );
		} else {
			yyerror( "Erro semantico: variavel %s sofrendo redefinicao.\n",idName.c_str() );
		}
		symbolMap.at( idName ).foiRedefinida=true;
		return new AST::Variable( idName,nextVar,AST::Variable::ini,AST::Types::undefined );
	}
}

//definir arranjo
AST::Node *Structures::SymbolTable::insertVariable ( std::string idName, AST::Node *nextVar, Structures::Types tipo, int tamanho ) {
	if( tamanho <= 0 ) {
		yyerror( "Erro semantico: arranjo %s com tamanho menor do que um.\n",idName.c_str() );
		tamanho = 1;
	}
	if ( ! containsIdentifier( idName ) )  {
		Structures::Symbol newSymbol( Kinds::kVariable,tipo,DataContainer( 0 ),false, true,false );
		std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
		this->symbolMap.insert ( newElement );
		return new AST::Array( idName,nextVar,AST::Array::ini,( AST::Types )tipo,tamanho );
	} else {
		if( symbolMap.at( idName ).isArray ) {
			yyerror( "Erro semantico: arranjo %s sofrendo redefinicao.\n",idName.c_str() );
		} else {
			yyerror( "Erro semantico: variavel %s sofrendo redefinicao.\n",idName.c_str() );
		}
		symbolMap.at( idName ).foiRedefinida=true;
		return new AST::Array( idName,nextVar,AST::Array::ini,AST::Types::undefined,tamanho );
	}
}

//===============================================
//Mudar recursivamente o tipo de uma lista de variaveis
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
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		//std::cout << "procurando "<<idName<<" comparando "<< it->first<<"\n";
		if( it->first == idName ) {
			return true;
		}
	}
	return false;
}
//===============================================
//Ler variavel
AST::Node *Structures::SymbolTable::getIdentifier( std::string id ) {
	Types symbolType;
	if( !containsIdentifier( id ) ) {
		yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
		return new AST::Variable( id,NULL,AST::Variable::read,AST::Types::undefined );
	}
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			if( !it->second.initialized ) {
				yyerror( "Erro semantico: variavel %s nao inicializada.\n",id.c_str() );
			}
			symbolType = it->second.type;
			//std::cout<<"[usou " << id <<" "<< AST::TypesString[(int)symbolType]<< "]";
		}
	}
	return new AST::Variable( id, NULL, AST::Variable::read , ( AST::Types )symbolType );
}


AST::Node *Structures::SymbolTable::getIdentifier( std::string id,AST::Node *indice ) {
	Types symbolType;
	if( !containsIdentifier( id ) ) {
		yyerror( "[read]Variable \"%s\" used but not defined!\n",id.c_str() );
	}
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			if( !it->second.initialized ) {
				yyerror( "[read]Variable \"%s\" defined but not initilized!\n",id.c_str() );
			}
			symbolType = it->second.type;
			//std::cout<<"[usou " << id <<" "<< AST::TypesString[(int)symbolType]<< "]";
		}
	}
	return new AST::ArrayItem( id, NULL, AST::ArrayItem::read , ( AST::Types )symbolType,indice );
}

//===============================================
//Atribuir  variavel
AST::Node *Structures::SymbolTable::assignVariable( std::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
		return new AST::Variable( id,NULL,AST::Variable::atrib,AST::Types::undefined );
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

AST::Node *Structures::SymbolTable::assignVariable( std::string id , AST::Node *indice ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Erro semantico: variavel %s sem declaracao.\n",id.c_str() );
		return new AST::ArrayItem( id,NULL,AST::ArrayItem::atrib,AST::Types::undefined, indice );
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
//ler valor de variavel
// DataContainer Structures::SymbolTable::getIdentifierValue( std::string id ) {
// 	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
// 		if( it->first == id ) {
// 			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
// 			return it->second.value;
// 		}
// 	}
// 	return DataContainer( 666 );
// }
//===============================================
//Atualizar valor de variavel
// void Structures::SymbolTable::updateIdentifierValue( std::string id, DataContainer value ) {
// 	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
// 		if( it->first == id ) {
// 			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
// 			it->second.updateValue( value );
// 			jaAtribuiu = true;
// 		}
// 	}
// }
