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
AST::Node *Structures::SymbolTable::insertVariable ( std::string idName, AST::Node *nextVar, Structures::Types tipo  ) {
	if ( ! containsIdentifier( idName ) )  {
		Structures::Symbol newSymbol( Kinds::kVariable,tipo,DataContainer( 0 ),false );
		std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
		this->symbolMap.insert ( newElement );
		//Aqui tinha um return ????
	} else {
		yyerror( "[Def]Variable redefinition! [%s]\n",idName.c_str() );
	}
	return new AST::Variable( idName,nextVar,AST::Variable::ini );
}
//===============================================
void Structures::SymbolTable::updateTypes( AST::Node *nodo, Structures::Types tipo ) {
	AST::Variable *thisvar = dynamic_cast<AST::Variable *>( nodo );
	symbolMap.at( thisvar->id ).updateType( tipo );
	if( thisvar->next != nullptr ) {
		updateTypes( thisvar->next,tipo );
	}
}
//===============================================
Structures::Types Structures::SymbolTable::getidentifierType( std::__cxx11::string id ) {
	return symbolMap.at( id ).type;
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
	if( !containsIdentifier( id ) ) {
		yyerror( "[read]Variable \"%s\" used but not defined!\n",id.c_str() );
	}
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			if( !it->second.initialized ) {
				yyerror( "[read]Variable \"%s\" defined but not initilized!\n",id.c_str() );
			}
		}
	}
	return new AST::Variable( id, NULL, AST::Variable::read );
}
//===============================================
//Atribuir  variavel
AST::Node *Structures::SymbolTable::assignVariable( std::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "[assign]Variable \"%s\" used but not defined!\n",id.c_str() );
	}
	this->symbolMap[id].initialized=true;
	return new AST::Variable( id,NULL,AST::Variable::atrib );
}
//===============================================
//ler valor de variavel
DataContainer Structures::SymbolTable::getIdentifierValue( std::__cxx11::string id ) {
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			return it->second.value;
		}
	}
	return DataContainer( 666 );
}
//===============================================
//Atualizar valor de variavel
void Structures::SymbolTable::updateIdentifierValue( std::__cxx11::string id, DataContainer value ) {
	for ( std::map<std::string,Structures::Symbol>::iterator it = simbolTable->symbolMap.begin(); it!= simbolTable->symbolMap.end(); it++ ) {
		if( it->first == id ) {
			//		std::cout <<"{ST achou  " << id << "="<<it->second.value<<"}";
			it->second.updateValue( value );
			jaAtribuiu = true;
		}
	}
}
