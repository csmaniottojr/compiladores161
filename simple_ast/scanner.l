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
\n		{return T_NL;}
","		{return T_VIRGULA;}
"def"		{return T_DEF;}
[a-zA-Z_][a-zA-Z0-9_] * { yylval.identifier = new Structures::Identifier(yytext); return T_ID;}
.		{yyerror("Unknown token! %c\n", *yytext);} /*complains about every unknown character like a bitch*/

%%

void yyerror(const char *s, ...) {
	va_list ap;
	va_start(ap, s);
	std::fprintf(stderr, "Line %d: error: ", yylineno);
	std::vfprintf(stderr, s, ap);
}

