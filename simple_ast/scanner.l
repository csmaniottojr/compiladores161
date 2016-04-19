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
"*"		{return T_MULT;}
","		{return T_VIRGULA;}
"def"		{return T_DEF;}
"=" 		{return T_ATRIB;}
"int"		{return T_TINT;}
"double"	{return T_TDOUBLE;}
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

