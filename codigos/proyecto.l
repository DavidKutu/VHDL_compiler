%{
	#include "proyecto.tab.h"
%}

%%

"entity"				return entity;
"is"					return is;
"in"					return in;
"out"					return out;
"signal"				return signal;
"bit"					return bit;
"vector"				return vector;
"to"					return to;
"end"					return end;
"architecture"			return architecture;
"of"					return of;
"begin"					return begin;
"if"					return IF;
"then"					return THEN;
"else"					return ELSE;
"case"					return CASE;
"when"					return WHEN;
"break"					return BREAK;
"other"					return OTHER;
"("						return yytext[0];
")"						return yytext[0];
":"						return yytext[0];
";"						return yytext[0];
"=="					return yytext[0];
"SHL"					return SHL;
"SHR"					return SHR;
"!="					return yytext[0];
"="						return yytext[0];
"<"						return yytext[0];
">"						return yytext[0];
"&"						return yytext[0];
"|"						return yytext[0];
"!"						return yytext[0];
"^"						return yytext[0];
"+"						return yytext[0];
"-"						return yytext[0];
[a-zA-Z][_a-zA-Z0-9]*	{yylval.id = yytext[0]; return ID;}
[0-9]+					{yylval.integer = atoi(yytext); return CTE_INT;}
[ \t\n]					;
.						{ECHO; yyerror("ERROR\n");}

%%

int yywrap(void)
{
	//[0-1]+					{yylval.integer = atoi(yytext); return BYTE;}
	return 1;
}