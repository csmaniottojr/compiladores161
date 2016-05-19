%{
#include <string>
#include "ast.h"
#include "parser.h"
#include <cstdarg>

	extern int yylineno;
	void yyerror(const char *s, ...);
%}

%option noyywrap nodefault yylineno

digs [0-9]+

digsd [0-9]*

%%

[\n \t]		; //ignores spaces

{digs}		{yylval.integer = std::atoi(yytext); return T_INT;}
{digsd}\.{digs}	{yylval.ddouble = std::atof(yytext); return T_DOUBLE;}		
"+"		{return T_PLUS;}
"-"		{return T_MINUS;}
"*"		{return T_MULT;}
"/"		{return T_DIV;}
","		{return T_VIRGULA;}
"="		{return T_IGUAL;}
"~="		{return T_DIFERENTE;}
">"		{return T_MAIOR;}
"<"		{return T_MENOR;}
">="		{return T_MAIOR_IGUAL;}
"<="		{return T_MENOR_IGUAL;}
":=" 		{return T_ATRIB;}
"~"		{return T_NOT;}
":"		{return T_DEF;}
"("		{return T_PAREN_L;}
")"		{return T_PAREN_R;}
"["		{return T_COLCH_L;}
"]"		{return T_COLCH_R;}
"while" {return T_WHILE;}
"end"	{return T_END;}
"do"	{return T_DO;}
"int"		{return T_TINT;}
"real"		{return T_TDOUBLE;}
"bool"		{return T_TBOOL;}
"AND"		{return T_AND;}
"OR"		{return T_OR;}
"TRUE"		{return T_TRUE;}
"FALSE"		{return T_FALSE;}
";"		{return T_NL;}
[a-z][a-z0-1]*  {yylval.identifier = strdup(yytext); return T_ID;} /*Copy the string, so are diferent pointers!*/
.		{yyerror("Unknown token! %c\n", *yytext);} /*complains about every unknown character like a bitch*/

%%

void yyerror(const char *s, ...) {
	va_list ap;
	va_start(ap, s);
	std::fprintf(stderr, "Line %d: error: ", yylineno);
	std::vfprintf(stderr, s, ap);
}

