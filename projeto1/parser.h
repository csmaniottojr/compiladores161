/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "parser.y" /* yacc.c:1909  */

#include "structures.h"
	

#line 49 "parser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ID = 258,
    T_INT = 259,
    T_DOUBLE = 260,
    T_TRUE = 261,
    T_FALSE = 262,
    T_PLUS = 263,
    T_MULT = 264,
    T_NL = 265,
    T_ATRIB = 266,
    T_MINUS = 267,
    T_DIV = 268,
    T_IGUAL = 269,
    T_DIFERENTE = 270,
    T_MAIOR = 271,
    T_MENOR = 272,
    T_MAIOR_IGUAL = 273,
    T_MENOR_IGUAL = 274,
    T_NOT = 275,
    T_PAREN_L = 276,
    T_PAREN_R = 277,
    T_AND = 278,
    T_OR = 279,
    T_COLCH_L = 280,
    T_COLCH_R = 281,
    T_TINT = 282,
    T_TDOUBLE = 283,
    T_TBOOL = 284,
    T_WHILE = 285,
    T_END = 286,
    T_DO = 287,
    T_IF = 288,
    T_THEN = 289,
    T_ELSE = 290,
    T_DEF = 291,
    T_TYPE = 292,
    T_VIRGULA = 293,
    T_DECL = 294,
    T_FUNC = 295,
    T_RETURN = 296,
    T_FUNCDECL = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "parser.y" /* yacc.c:1909  */

	char* identifier;
	int integer;
	double ddouble;
	AST::Node *node;
	AST::Block *block;
	AST::Operation operation;
	bool boolean;
	Structures::Types type;


#line 116 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
