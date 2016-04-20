#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include "ast.h"


namespace AST{class Node;}
namespace Structures {

        enum Kinds {variable};
        enum Types {integer, doub};
	class Symbol {
	public:
		
                Kinds kind;//Kind of symbol (var, func,...)
                Types type;//Type of symbol (Int, Double,...)
                void* value;//Space to store a value while interpretating
                bool initialized;//Defines if th symbol was initialized or not
		Symbol(Kinds kind, Types type, void* value, bool initialized):
		kind(kind), type(type),value(value),initialized(initialized){};
                Symbol();
         
        };

	class SymbolTable {
	public:
		std::map<std::string , Symbol> symbolMap;
		SymbolTable();

                AST::Node* insertVariable(std::__cxx11::string idName, AST::Node *nextVar);
                AST::Node* assignVariable(std::string id);
                bool containsIdentifier(std::string id);
		AST::Node* getIdentifierValue(std::string id);
	};


}
