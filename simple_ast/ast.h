#pragma once

#include <iostream>
#include <vector>
#include "structures.h"

extern void yyerror(const char*s, ...);//The error funtion in Bison 
namespace Structures {class SymbolTable;};

extern Structures::SymbolTable* simbolTable;//Simbol Table, in Bison file

namespace AST {

//Binary operations
	enum Operation { plus, mult, assign };
        
	class Node;

	typedef std::vector<Node *> NodeList; //List of nodes

	class Node {
	public:
		virtual ~Node() {}
		virtual void printTree() {}
		virtual int computeTree() {return 0;}
	};

	class Integer : public Node {
	public:
		int value; //Value of the integer.
		Integer(int value) : value(value) {  }//Default Constructor
		void printTree();//Just prints the value :)
		int computeTree();//Just pops the value :)
	};

	class BinOp : public Node {
	public:
		Operation op;//The operation to be executed
		Node *left;//the left operand
		Node *right;//The right operand
		BinOp(Node *left, Operation op, Node *right) : left(left), right(right), op(op) { }//Default Contructor
		void printTree();//Print the tree (right->tree << [operation] << left.tree)
		int computeTree();//Returns (left.computeTree [operation] right.computeTree)
	};

	class Block : public Node {
	public:
		NodeList lines;//The nodes of this block
		Block() { }//Empty Constructor
		void printTree();//Print the tree to  every node in "lines".
		int computeTree();//Computes the tree to  every node in "lines".
	};
        
        class Variable : public Node{
        public:
          std::string id;//The var "name"
          AST::Node* next;//Next Variable, to multiple variable declarations
          Variable(std::string id,  Node* next) :id(id), next(next){} //Default Constructor
          void printTree();//Print the node infos
          int computeTree();//Compute the node infos
         
        };

}

