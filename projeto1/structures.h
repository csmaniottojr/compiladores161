
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
	enum Types {tInteger, tDouble};



	class Symbol {
	public:

		Kinds kind;//Kind of symbol (var, func,...)
		Types type;//Type of symbol (Int, Double,...)
		DataContainer value;//Space to store a value while interpretating
		bool initialized;//Defines if th symbol was initialized or not
		Symbol( Kinds kind, Types type, DataContainer value, bool initialized ):
			kind( kind ), type( type ),value( value ),initialized( initialized ) {};
		Symbol();

	};

	class SymbolTable {
	public:
		std::map<std::string , Symbol> symbolMap;
		SymbolTable();

		AST::Node *insertVariable( std::__cxx11::string idName, AST::Node *nextVar );
		AST::Node *assignVariable( std::string id );
		bool containsIdentifier( std::string id );
		AST::Node *getIdentifierValue( std::string id );
	};



}
