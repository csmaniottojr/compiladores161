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
#define N_TYPES 3

extern void yyerror( const char *s, ... ); //The error funtion in Bison file
namespace Structures {class SymbolTable;};

extern Structures::SymbolTable *simbolTable;//Simbol Table, in Bison file

namespace AST {

//Binary operations
	enum Operation { oplus, omult, oassign, oand, oor, ominus, odiv, oequal, ogreater, oless, ogreatereq, olesseq, odifferent,onot };
	enum Types { tInt,tReal, tBool,tCompound,undefined};
	static std::string TypesString [4]= {"inteiro", "real","booleano","indefinido"};
	static std::string tipoOperacoes[4] = {"inteira", "real", "booleana","Indefinida"};
	class Node;

	typedef std::vector<Node *> NodeList; //List of nodes

	class Node {
	public:
		virtual ~Node() {}
		virtual void printTree() {}

		Types type;
		Types coercionTo;
		bool hasParentheses = false;
	};

	class Integer : public Node {
	public:
		int value; //Value of the integer.
		Integer( int value ) : value( value ) {type = tInt;  } //Default Constructor
		void printTree();//Just prints the value :)

	};
	class Double : public Node {
	public:
		double value;
		Double( double value ) : value( value ) {type = tReal;}
		void printTree();

	};

	class Boolean : public Node {
	public:
		bool value;
		Boolean( bool value ) : value( value ) {type = tBool;}
		void printTree();

	};

	class BinOp : public Node {
	public:
		Operation op;//The operation to be executed
		Node *left;//the left operand
		Node *right;//The right operand

		BinOp( Node *left, Operation op, Node *right ) : left( left ), right( right ), op( op ) { verifyOperands();} //Default Contructor
		void printTree();//Print the tree (right->tree << [operation] << left.tree)
		bool isArithmetic();
		bool isBinary();
		bool isComparation();
		bool isAttribution();
		void verifyOperands();
		std::string printOp();
	};

	class UnaryOp : public Node {
	public:
		Operation op;//The operation to be executed
		Node *operand;//the left operand
		

		UnaryOp( Operation op, Node *operand ) : op( op ), operand( operand ) {this->type = operand->type;} //Default Contructor
		void printTree();//Print the tree (right->tree << [operation] << left.tree)
		std::string printOp();
	};

	class Block : public Node {
	public:
		NodeList lines;//The nodes of this block
		Block() { }//Empty Constructor
		void printTree();//Print the tree to  every node in "lines".

	};

	class Variable : public Node {
	public:
		enum use {atrib,ini,read};
		std::string id;//The var "name"
		AST::Node *next;//Next Variable, to multiple variable declarations
		use useType;

		Variable( std::string id,  Node *next, use useType,Types type ) :id( id ), next( next ),useType( useType )  {this->type = type;} //Default Constructor
		void printTree();//Print the node infos


	};

	class Array : public Node {
	public:
		enum use {ini};
		std::string id;//The var "name"
		AST::Node *next;//Next Variable, to multiple variable declarations
		use useType;
		int size;

		Array( std::string id,  Node *next, use useType,Types type, int size ) :id( id ), next( next ),useType( useType ),size( size )  {this->type = type;} //Default Constructor
		void printTree();//Print the node infos

	};

	class ArrayItem : public Node {
	public:
		enum use {atrib,read};
		std::string id;//The var "name"
		AST::Node *next;//Next Variable, to multiple variable declarations
		use useType;
		AST::Node *index;
		void verifyIndex();

		ArrayItem( std::string id,  Node *next, use useType,Types type, AST::Node *index ) :id( id ), next( next ),useType( useType ),index( index )  {this->type = type; verifyIndex();} //Default Constructor
		void printTree();//Print the node infos
	};

	class Loop: public Node{
	public:
		AST::Node * expr;
		AST::Block *stmts;

		Loop(AST::Node * expr, AST::Block *stmts) : expr(expr), stmts(stmts){verifyExpression();}
		void verifyExpression();
		void printTree();
	};

	class Conditional: public Node{

	public:
		AST::Node * expr;
		AST::Block * ifblock;
		AST::Block * elseblock;

		Conditional(AST::Node * expr, AST::Block *ifblock, AST::Block * elseblock) : expr(expr), ifblock(ifblock), elseblock(elseblock) {verifyExpression();}
		void verifyExpression();
		void printTree();
	};

	class Compound : public Node{

	public:
		std::string id;
		AST::Block *components;
		Compound(std::string id, AST::Block *components): id(id), components(components){}
		void printTree();
	};

}

