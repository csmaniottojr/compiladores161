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

%%

[ \t]		; //ignores spaces

{digs}		{yylval.integer = std::atoi(yytext); return T_INT;}
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
";"		{return T_PTOVIRGULA;}
"("		{return T_PAREN_L;}
")"		{return T_PAREN_R;}
"def"		{return T_DEF;}
"int"		{return T_TINT;}
"real"		{return T_TDOUBLE;}
"bool"		{return T_TBOOL;}
"AND"		{return T_AND;}
"OR"		{return T_OR;}
"TRUE"		{return T_TRUE;}
"FALSE"		{return T_FALSE;}
\n		{return T_NL;}
[a-z][a-z0-1]* { yylval.identifier = strdup(yytext); return T_ID;} /*Copy the string, so are diferent pointers!*/
.		{yyerror("Unknown token! %c\n", *yytext);} /*complains about every unknown character like a bitch*/

%%

void yyerror(const char *s, ...) {
	va_list ap;
	va_start(ap, s);
	std::fprintf(stderr, "Line %d: error: ", yylineno);
	std::vfprintf(stderr, s, ap);
}

