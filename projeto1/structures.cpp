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
AST::Node *Structures::SymbolTable::insertVariable ( std::__cxx11::string idName, AST::Node *nextVar ) {
	if ( this->symbolMap.find( idName ) == this->symbolMap.end() ) {
		int initialValue = 0;
		Structures::Symbol newSymbol( Kinds::kVariable,Types::tInteger,DataContainer( initialValue ),false );
		std::pair<std::string,Structures::Symbol> newElement ( idName,newSymbol );
		this->symbolMap.insert ( newElement );
		//Aqui tinha um return ????
	} else {
		yyerror( "Variable redefinition! [%s]",idName.c_str() );
	}
	
	return new AST::Variable( idName,nextVar );
}
//===============================================
bool Structures::SymbolTable::containsIdentifier( std::string idName ) {
	return ( !( this->symbolMap.find( idName ) == this->symbolMap.end() ) );
}
//===============================================
AST::Node *Structures::SymbolTable::getIdentifierValue( std::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Variable \"%s\" used but not defined!",id.c_str() );
	}
	if( !symbolMap[id].initialized ) {
		yyerror( "Variable \"%s\" defined but not initilized!",id.c_str() );
	}
	return new AST::Variable( id, NULL );
}
//===============================================
AST::Node *Structures::SymbolTable::assignVariable( std::__cxx11::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Variable \"%s\" used but not defined!",id.c_str() );
	}
	this->symbolMap[id].initialized=true;
	return new AST::Variable( id,NULL );
}

