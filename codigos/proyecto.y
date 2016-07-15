%{
	void yyerror (char *s);
	#include <stdio.h>
	#include <stdlib.h>

	int pilaOperandos [100];
	int pilaOperadores [100];
	int pilaFondoFalso [100];
	int pilaSaltos [100];
	int operadores=0,operandos=0,fondo_falso=0, saltos=0;
	
	int temp=6000;
	int mem_in=1000;
	int mem_out=2000;
	int mem_signal=3000;
	int mem_const=4000;
	
	int cuad1[1000], cuad2[1000], cuad3[1000], cuad4[1000];
	int cuad_cont=0;
	int cont;
	int cont_tranza;
	int flag=1;
		
	//-----------cubos semanticos----------------------------------------------------------//
	
	int semantica2 [5][15]=	{{-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12},
							{100,100,100,100,100,100,100,100,100,100,100,-1,100,101,100},
							{100,101,-1,100,101,101,100,100,100,101,101,-1,101,101,101},
							{101,100,101,100,101,101,100,100,100,101,101,-1,101,101,101},
							{101,101,101,100,101,101,100,100,100,101,101,-1,101,101,101}};
							
	int semantica1 [10][15]={{-1,-1,0,1,2,33,4,5,6,7,8,9,10,11,12},
							{200,200,-1,200,200,200,200,200,200,200,200,200,200,200,200},
							{200,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{200,202,-1,202,202,202,202,202,202,202,202,202,202,202,202},
							{201,200,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{201,201,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{201,202,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{202,200,202,202,202,202,202,202,202,202,202,202,202,202,202},
							{202,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{202,202,202,202,202,202,202,202,202,202,202,202,202,202,202}};
	
	//----------Fin de cubos semanticos----------------------------------------------------//
	
	//-------------------Tabla de variables------------------------------------------------//
	
	char Table_var[100][3];
	int Table_var_mem[100];
	int contab=0;
	
	//----------------Fin de tabla de variables--------------------------------------------//

%}

%union {int integer; char id; char tipos;}
%start PROGRAM

%token entity
%token is
%token to
%token end
%token architecture
%token of
%token begin
%token IF
%token THEN
%token ELSE
%token CASE
%token WHEN
%token BREAK
%token OTHER
%token SHL
%token SHR

%token <integer> CTE_INT
%token <id> ID
%token <tipos> in out signal bit vector

%type <integer> VARS VAR1 VAR2 VAR EXPRESION EXPRESION1 EXP LOGIC LOGIC1 TERMINO TERMINO1 FACTOR FACTOR1 VAR_CTE
%type <id> BLOQUE INOUT TIPO ESTATUTO1 ESTATUTO2 ESTATUTO ASIGNACION CONDIF CONDCASE CONDCASE1

%%

PROGRAM		:VARS BLOQUE									{;}
			;
			
VARS		:entity ID is '(' VAR1 ')' end ID ';'			{if($2!=$8)
																printf("error semantico\n");
															for(cont=0; cont<contab; cont++)
																{
																	cuad1[cuad_cont]=16;
																	cuad2[cuad_cont]=Table_var_mem[cont];
																	cuad3[cuad_cont]=-1;
																	cuad4[cuad_cont]=Table_var[cont][2];
																	cuad_cont++;
																}
															}
			;

VAR1		:VAR VAR2										{;}
			;

VAR2		:												{;}
			|VAR1											{;}
			;
			
VAR			:ID ':' 										{Table_var[contab][0]=$1;} 
			INOUT TIPO ';'									{;}
			;
			
INOUT		:in												{Table_var[contab][1]='i';Table_var_mem[contab]=mem_in++;}
			|out											{Table_var[contab][1]='o';Table_var_mem[contab]=mem_out++;}
			|signal											{Table_var[contab][1]='s';Table_var_mem[contab]=mem_signal++;}
			;
			
TIPO		:vector '(' CTE_INT ')'							{Table_var[contab][2]=$3; contab=contab+1;}
			|bit											{Table_var[contab][2]=1; contab=contab+1;}
			;
			
BLOQUE		:architecture of ID is begin ESTATUTO1 end ID ';'	{if($3!=$8)
																	printf("error semantico\n");
																FILE *f = fopen("file.txt", "w");
																  int n=cuad_cont;
																  int i;
																  for(i=0; i<n; i++)
																	fprintf(f, "%d %d %d %d\n", cuad1[i], cuad2[i], cuad3[i], cuad4[i]);	
																  fclose(f);}
			;
			
ESTATUTO1	:ESTATUTO ESTATUTO2								{;}
			;
			
ESTATUTO2	:												{;}
			|ESTATUTO1										{;}
			;
		
ESTATUTO	:ASIGNACION										{;}
			|CONDIF											{;}
			|CONDCASE										{;}
			;

ASIGNACION	:ID 											{for(cont=0; cont<=contab; cont++)
																if(Table_var[cont][0]==$1)
																	if(Table_var_mem[cont]<2000)
																	{
																		printf("error semantico\n asignacion a valor de entrada\n");
																	}
																	else
																	{
																		operandos++;
																		pilaOperandos[operandos]=Table_var_mem[cont];
																	}
															}
			'=' 											{operadores++;pilaOperadores[operadores]=0;}
			EXP
															{cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=-1;
															cuad4[cuad_cont]=pilaOperandos[operandos];operandos--;
															//operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															}
			';'
			;
			
CONDIF		:IF '(' {fondo_falso++; pilaFondoFalso[fondo_falso]=pilaOperadores[operadores];} EXPRESION ')' {fondo_falso--;} THEN {operadores++;pilaOperadores[operadores]=15;
																																  cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																																  cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																																  cuad3[cuad_cont]=-1;
																																  cuad4[cuad_cont]=-1;
																																  cuad_cont++;
																																  saltos++;pilaSaltos[saltos]=cuad_cont-1;}
			ESTATUTO1 CONDIF1 {;}
			;
			
CONDIF1		:end IF {cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;}
			';' {;}
			|ELSE {operadores++;pilaOperadores[operadores]=13;
				   cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
				   cuad2[cuad_cont]=-1;
				   cuad3[cuad_cont]=-1;
				   cuad4[cuad_cont]=-1;
				   cuad_cont++;
				   cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;
				   saltos++;pilaSaltos[saltos]=cuad_cont-1;}
			ESTATUTO1 end IF {cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;}
			';' {;}
			;
			
CONDCASE	:CASE ID 							{saltos++;pilaSaltos[saltos]=-5;
												for(cont=0; cont<=contab; cont++)
													if(Table_var[cont][0]==$2)
														if(Table_var_mem[cont]>1999&&Table_var_mem[cont]<3000)
														{
															printf("error semantico\n mal uso de variable de salida\n");
														}
														else
														{
															operandos++;
															pilaOperandos[operandos]=Table_var_mem[cont];
														}
												}
			is CONDCASE1 end CASE 				{operandos--;
												cont_tranza=cuad_cont;
												while(cont_tranza>1)
												{	
													if(cuad1[cont_tranza]==13&&cuad4[cont_tranza]==-1)
													{
														cuad4[cont_tranza]=cuad_cont;
													}
													cont_tranza--;
												}
												//cuad4[pilaSaltos[saltos]]=cuad_cont;
												//saltos--;
												}
			';'									{;}
			;
			
CONDCASE1	:WHEN OPCASE ':' 					{while(pilaSaltos[saltos]!=-5)
												{	
													if(cuad1[pilaSaltos[saltos]]==14)
													{
														cuad4[pilaSaltos[saltos]]=cuad_cont+1;
													}
													saltos--;
												}
												cuad1[cuad_cont]=13;
												cuad2[cuad_cont]=-1;
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												}
			ESTATUTO1 BREAK ';' 				{if(flag==1)
													{
														cuad4[pilaSaltos[saltos]]=cuad_cont+1;
														saltos--;
														cuad1[cuad_cont]=13;
														cuad2[cuad_cont]=-1;
														cuad3[cuad_cont]=-1;
														cuad4[cuad_cont]=-1;
														cuad_cont++;
														saltos++;pilaSaltos[saltos]=cuad_cont-1;
													}
													flag=1;
												}
			CONDCASE1							{;}
			|									{;}
			;
			
OPCASE		:CTE_INT							{cuad1[cuad_cont]=1;
												cuad2[cuad_cont]=pilaOperandos[operandos];
												cuad3[cuad_cont]=$1;
												cuad4[cuad_cont]=temp++;
												cuad_cont++;
												cuad1[cuad_cont]=14;
												cuad2[cuad_cont]=cuad4[cuad_cont-1];
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												//operandos--;
												operandos++;pilaOperandos[operandos]=cuad2[cuad_cont-2];
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												}
			|OTHER								{cuad1[cuad_cont]=1;
												cuad2[cuad_cont]=pilaOperandos[operandos];
												cuad3[cuad_cont]=pilaOperandos[operandos];
												cuad4[cuad_cont]=temp++;
												cuad_cont++;
												cuad1[cuad_cont]=14;
												cuad2[cuad_cont]=cuad4[cuad_cont-1];
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												//operandos--;
												operandos++;pilaOperandos[operandos]=cuad2[cuad_cont-2];
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												flag=0;}
			;
			
EXPRESION	:EXP EXPRESION1									{;}
			;

EXPRESION1	:												{;}
			|'=='  											{operadores++;pilaOperadores[operadores]=1;} 
			EXP												{cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															}
			|'!=' 											{operadores++; pilaOperadores[operadores]=4;}
			EXP												{cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															}
			|'<'											{operadores++; pilaOperadores[operadores]=5;}
			EXP												{cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															}
			|'>'											{operadores++; pilaOperadores[operadores]=6;}
			EXP												{cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															}
			;
			
EXP			:LOGIC LOGIC1									{;}
			|'!'											{operadores++; pilaOperadores[operadores]=9;}
			EXP												{if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=-1;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			;
			
LOGIC1		:												{;}
			|'&'											{operadores++; pilaOperadores[operadores]=7;}
			EXP												{if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			|'|'											{operadores++; pilaOperadores[operadores]=8;}
			EXP												{if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			|'^'											{operadores++; pilaOperadores[operadores]=10;}
			EXP												{if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			;
			
LOGIC		:TERMINO TERMINO1								{;}
			;
			
TERMINO1	:												{;}
			|'+'											{operadores++; pilaOperadores[operadores]=11;}
			LOGIC											{if(pilaOperadores[operadores]==11|pilaOperadores[operadores]==12)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			|'-'											{operadores++; pilaOperadores[operadores]=12;}
			LOGIC											{if(pilaOperadores[operadores]==11|pilaOperadores[operadores]==12)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			;
			
TERMINO		:FACTOR FACTOR1									{;}
			;
			
FACTOR1		:												{;}
			|SHL											{operadores++; pilaOperadores[operadores]=2;}
			TERMINO											{if(pilaOperadores[operadores]==3|pilaOperadores[operadores]==2)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			|SHR											{operadores++; pilaOperadores[operadores]=3;}
			TERMINO											{if(pilaOperadores[operadores]==3|pilaOperadores[operadores]==2)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																}}
			;
			
FACTOR		:'(' {fondo_falso++; pilaFondoFalso[fondo_falso]=pilaOperadores[operadores];} EXP ')'{fondo_falso--;}
			|VAR_CTE										{;}
			;
			
VAR_CTE		:ID												{for(cont=0; cont<=contab; cont++)
																if(Table_var[cont][0]==$1)
																	if(Table_var_mem[cont]>1999&&Table_var_mem[cont]<3000)
																	{
																		printf("error semantico\n mal uso de variable de salida\n");
																	}
																	else
																	{
																		operandos++;
																		pilaOperandos[operandos]=Table_var_mem[cont];
																	}
															}
			|CTE_INT										{operandos++; pilaOperandos[operandos]=$1;}
			;

%%

int main(void)
{
	return yyparse();
}

void yyerror (char *s) {printf("%s\n", s);}