
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

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include "ast.h"
#include "datacontainer.h"


namespace AST {class Node;}
namespace Structures {

	enum Kinds {kVariable};
	enum Types {tInteger= 0, tDouble, tBool};



	class Symbol {
	public:

		Kinds kind;//Kind of symbol (var, func,...)
		Types type;//Type of symbol (Int, Double,...)
		DataContainer value;//Space to store a value while interpretating
		bool initialized;//Defines if th symbol was initialized or not
		bool isArray; //flag to indicate if symbol is array or not
		bool foiRedefinida;
		Symbol( Kinds kind, Types type, DataContainer value, bool initialized, bool isArray, bool foiRedefinida ):
			kind( kind ), type( type ),value( value ),initialized( initialized ), isArray(isArray), foiRedefinida(foiRedefinida){};
		Symbol();
		void updateValue( DataContainer value ) {this->value = value;};
		void updateType  ( Types newType ) {this->type=newType;};

	};

	class SymbolTable {
	public:
		std::map<std::string , Symbol> symbolMap;
		SymbolTable();

		AST::Node *insertVariable( std::string idName, AST::Node *nextVar, Structures::Types tipo);
		AST::Node *insertVariable( std::string idName, AST::Node *nextVar, Structures::Types tipo, AST::Node * tamanho);
		AST::Node *assignVariable( std::string id );
		AST::Node *assignVariable( std::string id, AST::Node * indice );
		bool containsIdentifier( std::string id );
		AST::Node *getIdentifier( std::string id );
		AST::Node *getIdentifier( std::string id ,AST::Node * indice);
		// DataContainer getIdentifierValue( std::string id );
		// void updateIdentifierValue( std::string id, DataContainer value );
		void updateTypes( AST::Node *, Structures::Types tipo );
		bool jaAtribuiu = false;
		Types getidentifierType( std::string id );
	};



}
