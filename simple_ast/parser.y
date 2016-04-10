%{
#include "ast.h"
#include <iostream>
#include "structures.h"
#include <string>
using Structures::Identifier;
AST::Block *programRoot; /* the root node of our program AST:: */
Structures::IdList* simbolTable = new Structures::IdList(); /*The simble table of the program*/
extern int yylex();
extern void yyerror(const char *s, ...);



	
%}

%code requires {
#include "structures.h"
using Structures::Identifier;
}

/* yylval == %union
 * union informs the different ways we can store data
 */
%union {
	Identifier* identifier;	
	int integer;
	AST::Node *node;
	AST::Block *block;
	
}

/* token defines our terminal symbols (tokens).
 */
%token <identifier> T_ID
%token <integer> T_INT
%token T_PLUS T_MULT T_NL
%token T_VIRGULA T_DEF


/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line
%type <block> lines program
%type <int> exprVar


/* Operator precedence for mathematical operators
 * The latest it is listed, the highest the precedence
 */
%left T_PLUS
%left T_MULT
%nonassoc error

/* Starting rule
 */
%start program

%%

program 
	:lines { programRoot = $1; }
;


lines
	: line { $$ = new AST::Block(); $$->lines.push_back($1); }
	| lines line { if($2 != NULL) $1->lines.push_back($2); }
;

line
	: T_NL { $$ = NULL; } /*nothing here to be used */
	| expr T_NL /*$$ = $1 when nothing is said*/
	| var T_NL 
;

expr
	: T_INT { $$ = new AST::Integer($1); }
	| expr T_PLUS expr { $$ = new AST::BinOp($1,AST::plus,$3); }
	| expr T_MULT expr { $$ = new AST::BinOp($1,AST::mult,$3);}
	| exprVar { AST::Integer* varExpr = new AST::Integer($1); $$ = varExpr;}
	| exprVar T_PLUS expr { $$ = new::AST::BinOp(new AST::Integer($1),AST::plus,$3); }
	| expr T_PLUS exprVar {$$ = new::AST::BinOp($1,AST::plus,new AST::Integer($3));}
	| exprVar T_MULT expr { $$ = new AST::BinOp(new AST::Integer($1),AST::mult,$3);}
	| expr T_MULT exprVar { $$ = new AST::BinOp($1,AST::mult,new AST::Integer($3));}
	| expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
	;
var
	: T_DEF T_ID { simbolTable->insertIdentifier ( $2->idName ,0 ); std::cout << "Achou o id "<< $2->idName << std::endl;} 
	| var T_VIRGULA T_ID { simbolTable->insertIdentifier ( $3->idName, 0 );std::cout << "Achou o id "<< $3->idName << std::endl; }
	;

exprVar
	:T_ID {
		if(simbolTable->containsIdentifier(*$1)){
			$$ = simbolTable->getIdentifierValue(*$1);
		}else{
		//Erro sintático! Operador não definido!
			yyerrok;//Não  sei bem o que isso faz 
		}
	}
	|exprVar T_PLUS exprVar {$$ = $1 + $3;}
	|exprVar T_MULT exprVar {$$ = $1 * $3;}
	;
	
	
%%


