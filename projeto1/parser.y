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
	AST::Operation operation;
	bool boolean;
	Structures::Types type;

}

/* token defines our terminal symbols (tokens).
 */
%token <identifier> T_ID
%token <integer> T_INT
%token <ddouble> T_DOUBLE
%token <boolean> T_TRUE T_FALSE
%token T_PLUS T_MULT T_NL T_ATRIB T_MINUS T_DIV T_IGUAL T_DIFERENTE T_MAIOR T_MENOR
%token T_MAIOR_IGUAL T_MENOR_IGUAL T_NOT T_PAREN_L T_PAREN_R T_AND T_OR T_COLCH_L T_COLCH_R
%token T_TINT T_TDOUBLE T_TBOOL T_WHILE T_END T_DO T_IF T_THEN T_ELSE T_DEF T_TYPE
%token T_VIRGULA T_DECL T_FUNC T_RETURN T_FUNCDECL


/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line var unOp value varAr cmd decl
%type <block> lines program componentDecl
%type <operation> op
%type <type> type
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
|cmd {$$ = $1;}
|T_DEF T_TYPE T_DECL T_ID componentDecl T_END T_DEF { $$ = new AST::Block(); simbolTable->insertCompound($4,$5);}
;

cmd
:decl {$$=$1;}
|T_ID T_ATRIB expr T_NL {AST::Node* node = simbolTable->assignVariable($1);
			$$ = new AST::BinOp(node,AST::oassign,$3); }

|T_ID T_COLCH_L value T_COLCH_R T_ATRIB expr T_NL {AST::Node* node = simbolTable->assignVariable($1,$3);
			$$ = new AST::BinOp(node,AST::oassign,$6); }

|T_WHILE expr T_DO lines T_END T_WHILE {$$ = new AST::Loop($2,$4);}
|T_IF expr T_THEN lines T_END T_IF {$$ = new AST::Conditional($2, $4,NULL);}
|T_IF expr T_THEN lines T_ELSE lines T_END T_IF {$$ = new AST::Conditional($2, $4, $6);}
;

componentDecl
: decl { $$ = new AST::Block(); $$->lines.push_back($1); }
| componentDecl decl { if($2 != NULL) $1->lines.push_back($2); }
;


decl
:type T_DECL var T_NL {$$ = $3;simbolTable->updateTypes($3, $1);} /*Variable definitions*/
|type T_COLCH_L T_INT T_COLCH_R T_DECL varAr T_NL {simbolTable->updateTypesAndSize($6, $1, $3); $$ = $6; }/*Array definitions*/
;

expr 
: value {$$ = $1;}
| T_PAREN_L expr T_PAREN_R {$2->hasParentheses = true; $$ = $2; }
| expr op expr { $$ = new AST::BinOp($1,$2,$3);}
| expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
;

 varAr/*list of declared vars.*/
: T_ID { $$ = simbolTable->insertId($1,NULL,Structures::Types::tInteger,true); }
| varAr T_VIRGULA T_ID {$$= simbolTable->insertId($3,$1,Structures::Types::tInteger,true); } /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;

var /*list of declared vars.*/
: T_ID { $$ = simbolTable->insertId($1,NULL,Structures::Types::tInteger,false); }
| var T_VIRGULA T_ID {$$= simbolTable->insertId($3,$1,Structures::Types::tInteger,false); } /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;



value
: T_INT { $$ = new AST::Integer($1); }
| T_DOUBLE {$$ = new AST::Double($1);}
| T_TRUE {$$ = new AST::Boolean(true);}
| T_FALSE {$$ = new AST::Boolean(false);}
| unOp {$$ = $1;}
| T_ID {$$ = simbolTable->getIdentifier($1);}
| T_ID T_COLCH_L value T_COLCH_R {$$ = simbolTable->getIdentifier($1,$3);}
;

unOp
: T_MINUS expr {$$ = new AST::UnaryOp(AST::ominus,$2);}
| T_NOT expr {$$ = new AST::UnaryOp(AST::onot,$2);}
;


type
:T_TDOUBLE 	{$$=Structures::Types::tDouble;}
|T_TINT		{$$=Structures::Types::tInteger;}
|T_TBOOL	{$$=Structures::Types::tBool;}
;

//	enum Types {tInteger, tDouble, tBool};
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


