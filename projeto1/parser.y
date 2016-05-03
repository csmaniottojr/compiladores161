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
	double ddouble;
	AST::Node *node;
	AST::Block *block;
	AST::Operation *operation;
	bool boolean;

}

/* token defines our terminal symbols (tokens).
 */
%token <identifier> T_ID
%token <integer> T_INT
%token <ddouble> T_DOUBLE
%token T_PLUS T_MULT T_NL T_ATRIB T_MINUS T_DIV T_IGUAL T_DIFERENTE T_MAIOR T_MENOR
%token T_MAIOR_IGUAL T_MENOR_IGUAL T_NOT T_PAREN_L T_PAREN_R T_AND T_OR 
%token T_TRUE T_FALSE
%token T_TINT T_TDOUBLE T_TBOOL
%token T_VIRGULA T_DEF


/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line var
%type <block> lines program
%type <operation> op
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
|type T_DEF var T_NL {$$ = $3;} /*Variable definitions*/
| T_ID T_ATRIB expr {  	AST::Node* node = simbolTable->assignVariable($1);
			$$ = new AST::BinOp(node,AST::oassign,$3); }
;

expr
: T_INT { $$ = new AST::Integer($1); }
| T_DOUBLE {$$ = new AST::Double($1);}
| T_ID {$$ = simbolTable->getIdentifierValue($1);}
| expr op expr { $$ = new AST::BinOp($1,$2,$3); }
| expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
;
var /*list of declared vars.*/
: T_ID { $$ = simbolTable->insertVariable($1,NULL);}
| var T_VIRGULA T_ID {$$= simbolTable->insertVariable($3,$1);} /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;

type
:T_TDOUBLE
|T_TINT
|T_TBOOL

op
: T_PLUS {$$ = AST::oplus;}
| T_MULT {$$ = AST::omult;}
| T_MINUS {$$ = AST::ominus;}
| T_DIV {$$ = AST::odiv;}
| T_IGUAL {$$ = AST::oequal;}
| T_DIFERENTE {$$ = AST::odifferent;}
| T_MAIOR {$$ = AST::ogreater;}
| T_MENOR {$$ = AST::oless;}
| T_MAIOR_IGUAL {$$ = AST::ogreatereq;}
| T_MENOR_IGUAL {$$ = AST::olesseq;}
| T_AND {$$ = AST::oor;}
| T_OR {$$ = AST::oand;}
;



%%


