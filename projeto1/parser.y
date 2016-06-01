%{
#include "ast.h"
#include <iostream>
#include "structures.h"
#include <string>
	
	AST::Block *programRoot; /* the root node of our program AST:: */
	Structures::SymbolTable* simbolTable = new Structures::SymbolTable(); /*The simble table of the program*/
	std::string* ultimoId = nullptr;
	Structures::FuncParams* ultimoParam = nullptr;
	
	extern int yylex();
	extern void yyerror(const char *s, ...);




%}

%code requires {
#include "structures.h"
	
}
%define parse.trace

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
	Structures::SymbolTable* scope;
	Structures::FuncParams* funcParams;

}

/* token defines our terminal symbols (tokens).
 */
%token <identifier> T_ID
%token <integer> T_INT
%token <ddouble> T_DOUBLE
%token <boolean> T_TRUE T_FALSE
%token T_PLUS T_MULT T_NL T_ATRIB T_MINUS T_DIV T_IGUAL T_DIFERENTE T_MAIOR T_MENOR
%token T_MAIOR_IGUAL T_MENOR_IGUAL T_NOT T_PAREN_L T_PAREN_R T_AND T_OR T_COLCH_L T_COLCH_R T_POINT
%token T_TINT T_TDOUBLE T_TBOOL T_WHILE T_END T_DO T_IF T_THEN T_ELSE T_DEF T_TYPE
%token T_VIRGULA T_DECL T_FUNC T_RETURN T_FUNCDECL


/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line var unOp value varAr cmd decl conds declFunc defFunc
%type <block> lines program componentDecl funclines
%type <operation> op
%type <type> type
%type <scope> killcscope
%type <funcParams> paramList
%type <identifier> idFunc
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
: line 		{ $$ = new AST::Block(); $$->lines.push_back($1); }
| lines line 	{ if($2 != NULL) $1->lines.push_back($2); }
;

line
: T_NL 									{ $$ = NULL; } /*nothing here to be used */
|cmd 									{$$ = $1;}
|T_DEF T_TYPE T_DECL T_ID newscope componentDecl T_END killcscope T_DEF { $$ = simbolTable->insertCompound($4,$8,$6);}
|T_FUNCDECL T_FUNC declFunc						{$$ = $3; /*std::cout << "[byson]Declaracao de funcao" <<std::endl;*/}
|T_DEF T_FUNC defFunc T_END killscope T_DEF				{$$ = $3; std::cout << "[byson]Definicao de funcao" <<std::endl;}
;
/*Funcoes*/
/*Declaracao*/
declFunc
:type T_DECL T_ID T_PAREN_L paramList T_PAREN_R T_NL {$$ = simbolTable->insertFunction( $3, $5, $1 );}
;

/*Definicao*/
defFunc
:type T_DECL idFunc T_PAREN_L paramList T_PAREN_R funclines fnewScope T_RETURN expr {$$ = simbolTable->pai->assignFunction($3,$7,$5);}
;
//AST::Node *Structures::SymbolTable::assignFunction( std::string id, AST::Block *corpo, Structures::FuncParams *params )
idFunc
:T_ID	{$$ = $1; ultimoId = new std::string($1);}
;

fnewScope
:{
	Structures::SymbolTable* newScope = new Structures::SymbolTable;
	newScope->updatePai(simbolTable);
//	AST::Variable * astParams = Structures::FuncParams::convertParams(ultimoParam);
	while (ultimoParam != nullptr){
		newScope->insertId( ultimoParam->nome,nullptr, ultimoParam->tipo,false);
		newScope->assignVariable(ultimoParam->nome);
		ultimoParam = ultimoParam->proximo;
	}
	simbolTable = newScope;
}
;
//AST::Node *insertId( std::string idName, AST::Node *nextVar, Structures::Types tipo,bool isArray );
//AST::Node *assignVariable( std::string id );
/*corpo de funcao*/

funclines
:cmd		{$$ = new AST::Block; $$->lines.push_back($1);}
|funclines cmd	{if($2 != NULL) $1->lines.push_back($2);}
;

/*Lista de parametros para uma declaracao/definicao de funcao*/
paramList
:					{$$ = nullptr; ultimoParam = $$;}
|type T_DECL T_ID			{$$ = new Structures::FuncParams($1,$3); ultimoParam = $$;}
|paramList T_VIRGULA type T_DECL T_ID	{$$ = new Structures::FuncParams($3,$5,$1); ultimoParam = $$;}

;

cmd
:decl 								{$$=$1;}
|conds								{$$ = $1;}
|T_ID T_ATRIB expr T_NL 					{AST::Node* node = simbolTable->assignVariable($1);
								$$ = new AST::BinOp(node,AST::oassign,$3); }
 // nome[10] -> outronome := 10+4;
|T_ID T_COLCH_L value T_COLCH_R T_POINT T_ID T_ATRIB expr T_NL {
	
	//===============POR ALGUM MOTIVO N ESTÁ FUNCIONANDO ESSA REGRA

	std::cout << "entrou na regra bugada" << std::endl;
	//$$= new AST::Node();
	AST::Node* node = simbolTable->assignVariable($1,$3,$6);
	$$ = new AST::BinOp(node,AST::oassign,$8);
}

|T_ID T_COLCH_L value T_COLCH_R T_ATRIB expr T_NL 		{AST::Node* node = simbolTable->assignVariable($1,$3);
								$$ = new AST::BinOp(node,AST::oassign,$6); }
	
|T_ID T_POINT T_ID T_ATRIB expr T_NL 				{AST::Node* node = simbolTable->assignVariable($1,$3);
								$$ = new AST::BinOp(node,AST::oassign,$5);}

|T_ID T_POINT T_ID T_COLCH_L value T_COLCH_R T_ATRIB expr T_NL {AST::Node* node = simbolTable->assignVariable($1,$3,$5);
								$$ = new AST::BinOp(node,AST::oassign,$8);}


;
conds
:T_WHILE expr T_DO newscope lines T_END killscope T_WHILE {$$ = new AST::Loop($2,$5);}
|T_IF expr T_THEN newscope lines T_END killscope T_IF {$$ = new AST::Conditional($2, $5,NULL);}
|T_IF expr T_THEN newscope lines T_ELSE enewscope lines T_END killscope T_IF {$$ = new AST::Conditional($2, $5, $8);}
;

newscope: {Structures::SymbolTable* newScope = new Structures::SymbolTable;

	   newScope->updatePai(simbolTable);

	   simbolTable = newScope;	  
	}
;
enewscope: {Structures::SymbolTable* escopoPai = simbolTable->pai;

	    Structures::SymbolTable* newScope = new Structures::SymbolTable;
	    newScope->updatePai(escopoPai);
	    simbolTable = newScope;    

	    }
;
killscope:{Structures::SymbolTable* escopoPai = simbolTable->pai;
	   simbolTable = escopoPai;}
;
killcscope:{
	Structures::SymbolTable* escopoPai = simbolTable->pai;
	$$ = simbolTable;
	simbolTable = escopoPai;

}
;


componentDecl
: decl			{ $$ = new AST::Block(); $$->lines.push_back($1); }
| componentDecl decl	{ if($2 != NULL) $1->lines.push_back($2); }
;


decl
:type T_DECL var T_NL					{$$ = $3;simbolTable->updateTypes($3, $1);} /*Variable definitions*/
|type T_COLCH_L T_INT T_COLCH_R T_DECL varAr T_NL	{simbolTable->updateTypesAndSize($6, $1, $3); $$ = $6; }/*Array definitions*/
|T_ID T_DECL var T_NL					{$$ = $3;simbolTable->updateTypes($3, Structures::Types::compound,$1);}
|T_ID T_COLCH_L T_INT T_COLCH_R T_DECL varAr T_NL	{$$ = $6;simbolTable->updateTypesAndSize($6, Structures::Types::compound,$3,$1);}
;



expr 
: value				{$$ = $1;}
| T_PAREN_L expr T_PAREN_R	{$2->hasParentheses = true; $$ = $2; }
| expr op expr			{ $$ = new AST::BinOp($1,$2,$3);}
| expr error			{ yyerrok; $$ = $1; } /*just a point for error recovery*/
;

 varAr/*list of declared vars.*/
: T_ID			{ $$ = simbolTable->insertId($1,NULL,Structures::Types::tInteger,true); }
| varAr T_VIRGULA T_ID 	{$$= simbolTable->insertId($3,$1,Structures::Types::tInteger,true); } /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;

var /*list of declared vars.*/
: T_ID 			{ $$ = simbolTable->insertId($1,NULL,Structures::Types::tInteger,false); }
| var T_VIRGULA T_ID 	{$$= simbolTable->insertId($3,$1,Structures::Types::tInteger,false); } /*Inserts $3 in the ST, and marks $1 as it's NEXT*/
;



value
: T_INT 					{ $$ = new AST::Integer($1); }
| T_DOUBLE 					{$$ = new AST::Double($1);}
| T_TRUE					{$$ = new AST::Boolean(true);}
| T_FALSE 					{$$ = new AST::Boolean(false);}
| unOp						{$$ = $1;}
| T_ID						{$$ = simbolTable->getIdentifier($1);}
| T_ID T_COLCH_L value T_COLCH_R 		{$$ = simbolTable->getIdentifier($1,$3);}
| T_ID T_POINT T_ID 				{$$ = simbolTable->getIdentifier($1,$3);}
| T_ID T_POINT T_ID T_COLCH_L value T_COLCH_R	{$$ = simbolTable->getIdentifier($1,$3,$5);}
| T_ID T_COLCH_L value T_COLCH_R T_POINT T_ID	{$$ = simbolTable->getIdentifier($1,$3,$6);}
;

unOp
: T_MINUS expr	{$$ = new AST::UnaryOp(AST::ominus,$2);}
| T_NOT expr	{$$ = new AST::UnaryOp(AST::onot,$2);}
;


type
:T_TDOUBLE 	{$$=Structures::Types::tDouble;}
|T_TINT		{$$=Structures::Types::tInteger;}
|T_TBOOL	{$$=Structures::Types::tBool;}
;

//	enum Types {tInteger, tDouble, tBool};
op
: T_PLUS	{$$ = AST::oplus;}
| T_MULT	{$$ = AST::omult;}
| T_MINUS	{$$ = AST::ominus;}
| T_DIV		{$$ = AST::odiv;}
| T_IGUAL	{$$ = AST::oequal;}
| T_DIFERENTE	{$$ = AST::odifferent;}
| T_MAIOR 	{$$ = AST::ogreater;}
| T_MENOR 	{$$ = AST::oless;}
| T_MAIOR_IGUAL {$$ = AST::ogreatereq;}
| T_MENOR_IGUAL {$$ = AST::olesseq;}
| T_AND 	{$$ = AST::oor;}
| T_OR 		{$$ = AST::oand;}
;

%%


