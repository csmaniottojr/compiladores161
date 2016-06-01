#include <iostream>
#include "ast.h"
#include <stdio.h>

extern AST::Block *programRoot; //set on Bison file
extern int yyparse();
extern FILE *yyin;
extern int yydebug;

int main( int argc, char **argv ) {
	//yydebug = 1;
	FILE *arquivo = std::fopen( "input_example","r" );
	if( arquivo == nullptr ) {
		std::perror( "Erro ao abrir arquivo!" );
		return 0;
	} else {
		//std::cout <<"Arquivo ok!"<<std::endl;
	}
	yyin = arquivo;
	yyparse();                  //parses whole data
//	programRoot->computeTree(); //computes the ASTs
	if( programRoot == nullptr ) {
		std::cout << "É NULO!";
	};
	programRoot->printTree();   //prints the ASTs
	return 0;
}
