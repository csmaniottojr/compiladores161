#include "ast.h"

using namespace AST;

/* ================Print Methods================*/
//Integerw
void Integer::printTree() {
	std::cout << value;
	return;
}
//Binary Operation
void BinOp::printTree() {
	left->printTree();
	switch( op ) {
		case plus: std::cout << " + "; break;
		case mult: std::cout << " * "; break;
	}
	right->printTree();
	return;
}
//Block
void Block::printTree() {
	for ( Node *line: lines ) {
		line->printTree();
		std::cout << std::endl;
	}
}

//Variable
void Variable::printTree() {
	if( next != nullptr ) {
		next->printTree();
	}
	std::cout << this->id;F
	return;
}


/* ================Compute methods================*/
//Integer
int Integer::computeTree() {
	return value;
}
//Binary Operation
int BinOp::computeTree() {
	int value, lvalue, rvalue;
	lvalue = left->computeTree();
	rvalue = right->computeTree();
	switch( op ) {
		case plus: value = lvalue + rvalue; break;
		case mult: value = lvalue * rvalue; break;
	}
	return value;
}
//Block
int Block::computeTree() {
	int value;
	for ( Node *line: lines ) {
		value = line->computeTree();
		std::cout << "Computed " << value << std::endl;
	}
	return 0;
}
//Variable
int Variable::computeTree() {
	return simbolTable.symbolMap[this->id].value;
}

