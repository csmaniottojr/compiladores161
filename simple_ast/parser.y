%{
#include "ast.h"
#include <iostream>
#include "structures.h"
#include <string>
	
	AST::Block *programRoot; /* the root node of our program AST:: */
	Structures::SymbolTable* simbolTable = new Structures::SymbolTable(); /*The simble table of the program*/
	extern int yylex();
	extern void yyerror(const char *s, ...);




%}

%code requires {
#include "structures.h"
	
}

/* yylval == %union
 * union informs the different ways we can store data
 */
%union {
	char* identifier;
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
%type <node> expr line var
%type <block> lines program
//%type <int> exprVar


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
| T_DEF var T_NL {$$ = $2;} /*Variable definitions*/
;

expr
: T_INT { $$ = new AST::Integer($1); }
| T_ID {$$= simbolTable->getIdentifierValue($1);}
| expr T_PLUS expr { $$ = new AST::BinOp($1,AST::plus,$3); }
| expr T_MULT expr { $$ = new AST::BinOp($1,AST::mult,$3);}
| expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
;
var /*list of declared vars.*/
: T_ID { $$ = simbolTable->insertVariable($1,NULL);}
| var T_VIRGULA T_ID {$$= simbolTable->insertVariable($3,$1);} /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;




%%


