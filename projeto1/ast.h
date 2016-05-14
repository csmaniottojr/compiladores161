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
#include <string>
#include "structures.h"
#include "datacontainer.h"
#define N_TYPES 3

extern void yyerror( const char *s, ... ); //The error funtion in Bison file
namespace Structures {class SymbolTable;};

extern Structures::SymbolTable *simbolTable;//Simbol Table, in Bison file

namespace AST {

//Binary operations
	enum Operation { oplus, omult, oassign, oand, oor, ominus, odiv, oequal, ogreater, oless, ogreatereq, olesseq, odifferent };
	enum Types { tInt,tReal, tBool,undefined};
	static std::string TypesString [4]= {"Inteiro", "Real","Booleano","Indefinido"};
	static std::string tipoOperacoes[4] = {"inteira", "real", "booleana","Indefinida"};
	class Node;

	typedef std::vector<Node *> NodeList; //List of nodes

	class Node {
	public:
		virtual ~Node() {}
		virtual void printTree() {}
		virtual DataContainer computeTree() {return DataContainer( 0 );}
		Types type;
	};

	class Integer : public Node {
	public:
		int value; //Value of the integer.
		Integer( int value ) : value( value ) {type = tInt;  } //Default Constructor
		void printTree();//Just prints the value :)
		DataContainer computeTree();//Just pops the value :)
	};
	class Double : public Node {
	public:
		double value;
		Double( double value ) : value( value ) {type = tReal;}
		void printTree();
		DataContainer computeTree();
	};

	class Boolean : public Node {
	public:
		bool value;
		Boolean( bool value ) : value( value ) {type = tBool;}
		void printTree();
		DataContainer computeTree();
	};



	class BinOp : public Node {
	public:
		Operation op;//The operation to be executed
		Node *left;//the left operand
		Node *right;//The right operand
		
		BinOp( Node *left, Operation op, Node *right ) : left( left ), right( right ), op( op ) { this->type = undefined;} //Default Contructor
		void printTree();//Print the tree (right->tree << [operation] << left.tree)
		DataContainer computeTree();//Returns (left.computeTree [operation] right.computeTree)
		void computeType();
	};

	class Block : public Node {
	public:
		NodeList lines;//The nodes of this block
		Block() { }//Empty Constructor
		void printTree();//Print the tree to  every node in "lines".
		DataContainer computeTree();//Computes the tree to  every node in "lines".
	};

	class Variable : public Node {
	public:
		enum use {atrib,ini,read};
		std::string id;//The var "name"
		AST::Node *next;//Next Variable, to multiple variable declarations
		use useType;
		
		Variable( std::string id,  Node *next, use useType,Types type ) :id( id ), next( next ),useType( useType )  {this->type = type;} //Default Constructor
		void printTree();//Print the node infos
		DataContainer computeTree();//Compute the node infos

	};

}

