
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
	enum Types {tInteger= 0, tDouble, tBool, undefined, compound};



	class Symbol {
	public:

		Kinds kind;//Kind of symbol (var, func,...)
		Types type;//Type of symbol (Int, Double,...)
		bool initialized;//Defines if th symbol was initialized or not
		bool isArray; //flag to indicate if symbol is array or not
		bool foiRedefinida = false;
		std::string idType = "";
		Symbol( Kinds kind, Types type, bool initialized, bool isArray ):
			kind( kind ), type( type ),initialized( initialized ), isArray( isArray ) {};
		Symbol();
		void updateType  ( Types newType ) {this->type=newType;};

	};

	// class Compound {
	// public:

	// 	Types type;
	// 	std::vector<Symbol> components;

	// 	Compound(std::vector<Symbol> components): components(components) {type = Types::tCompound;};
	// 	Compound();
	// };

	class SymbolTable {
	public:

		SymbolTable();

		SymbolTable *pai = nullptr;

		void updatePai( SymbolTable *newPai );

		std::map<std::string , Symbol> symbolMap;
		std::map<std::string, SymbolTable*> compoundScopeMap;


		AST::Node *insertId( std::string idName, AST::Node *nextVar, Structures::Types tipo,bool isArray );
		AST::Node *insertCompound( std::string idName, Structures::SymbolTable *compostScope, AST::Node* declarations );

		AST::Node *assignVariable( std::string id );
		AST::Node *assignVariable( std::string id, AST::Node *indice );
		AST::Node *assignVariable( std::string idVar, std::string idComponent );
		AST::Node *assignVariable( std::string idVar, std::string idComponent, AST::Node *indice );
		AST::Node *assignVariable( std::string idVar, AST::Node *indice, std::string idComponent );

		bool containsIdentifier( std::string id );

		AST::Node *getIdentifier( std::string id );
		AST::Node *getIdentifier( std::string id ,AST::Node *indice );
		AST::Node *getIdentifier( std::string idVar, std::string idComponent );
		AST::Node *getIdentifier( std::string idVar, std::string idComponent,AST::Node *indice );
		AST::Node *getIdentifier( std::string idVar, AST::Node *indice, std::string idComponent );
		Types getidentifierType( std::string id );

		void updateTypes( AST::Node *, Structures::Types tipo );
		void updateTypes( AST::Node *nodo, Structures::Types tipo, std::string idType );
		void updateTypesAndSize( AST::Node *nodo, Structures::Types tipo, int size );
		void updateTypesAndSize( AST::Node *nodo, Structures::Types tipo, int size, std::string idType );
		//void updateTypesAndSize( AST::Node *nodo, Structures::Types tipo,std::string idType, int size );


	};



}
