#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binario(int num){ 
	int aux; 
	if(num==0) 
	return; 
	aux=num%2; 
	num=num/2; 
	binario(num); 
	printf("%d",aux);
} 

void Seguidor(int a){
	printf("Voy en el paso %i \n", a+1);
}

int i=0,j=0,m=0,o=0,s=0,a=1;
int dim=0;
int flag=1;
unsigned int cuad1[1000], cuad2[1000], cuad3[1000], cuad4[1000];
char alfabeto[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		unsigned int mem_in [100] 		= {0};
		unsigned int mem_in_dim[100] 	= {0};
		unsigned int mem_out [100] 		= {0};
		unsigned int mem_out_dim[100]	= {0};
		unsigned int mem_sig[100] 		= {0};
		unsigned int mem_sig_dim[100]	= {0};
		unsigned int mem_temp [100]		= {0};

int main(void)
{
	printf("\n	Simulador de Circuitos Digitales\n");
	printf("		Kuac v2.0.1\n\nRecuerda que para el uso de este software se debio\n  compilar previamente el código del circuito\n");
	printf("	haciendo uso de Kuac_Compiler.exe\n\n");
	/*for(i=0;i<27;i++)
	printf("%c",alfabeto[i]);*/
	
	while(flag){
	
		int cont_last=0;
		while(cont_last<=100)
		{
			mem_in [cont_last] 		= 0;
			mem_in_dim[cont_last] 	= 0;
			mem_out [cont_last] 	= 0;
			mem_out_dim[cont_last]	= 0;
			mem_sig[cont_last] 		= 0;
			mem_sig_dim[cont_last]	= 0;
			mem_temp [cont_last]	= 0;
			cont_last=cont_last+1;
		}
		
		i=0,j=0,m=0,o=0,s=0,a=1;
		/* Open File to Read Quadruples */
		FILE *f;	
		f =fopen("file.txt","r");

		while(!feof(f))
		{
			fscanf(f, "%i %i %i %i \n", &cuad1[i], &cuad2[i], &cuad3[i], &cuad4[i]);
			i++;
		}
		
		fclose(f);
		/* Close File to Read Quadruples */
		
		while(j<i){
			switch(cuad1[j]){
				case 0://=	
					if(cuad2[j]<1000){ // Asignación de Constantes
						if(cuad4[j]>=1000 && cuad4[j]<2000)
							mem_in[cuad4[j]-1000] = cuad2[j];// Se asigna Const en In
						else if(cuad4[j]>=2000 && cuad4[j]<3000)
							mem_out[cuad4[j]-2000] = cuad2[j];//Se asigna Const en Out
						else if(cuad4[j]>=3000 && cuad4[j]<4000)
							mem_sig[cuad4[j]-3000] = cuad2[j];//Se asigna Const en Signal
						else if(cuad4[j]>=6000 && cuad4[j]<7000)
							mem_in[cuad4[j]-6000] = cuad2[j];//Se asigna Const en Temp
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){//Asignación de Ins
						if(cuad4[j]>=2000 && cuad4[j]<3000)
							mem_out[cuad4[j]-2000] = mem_in[cuad2[j]-1000];//Se asigna In en Out
						else if(cuad4[j]>=3000 && cuad4[j]<4000)
							mem_sig[cuad4[j]-3000] = mem_in[cuad2[j]-1000];//Se asigna In en Signal
						else if(cuad4[j]>=6000 && cuad4[j]<7000)
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000];//Se asigna In en Temp
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){//Asignación de Signals
						if(cuad4[j]>=2000 && cuad4[j]<3000)
							mem_out[cuad4[j]-2000] = mem_sig[cuad2[j]-3000];//Se asigna Signal en Out
						else if(cuad4[j]>=3000 && cuad4[j]<4000)
							mem_temp[cuad4[j]-3000] = mem_sig[cuad2[j]-3000];//Se asigna Signal en Signal
						else if(cuad4[j]>=6000 && cuad4[j]<7000)
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000];//Se asigna Signal en Temp
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){//Asignación de Temporales
						if(cuad4[j]>=2000 && cuad4[j]<3000)
							mem_out[cuad4[j]-2000] = mem_temp[cuad2[j]-6000];//Se asigna Temp en Out
						else if(cuad4[j]>=3000 && cuad4[j]<4000)
							mem_sig[cuad4[j]-3000] = mem_temp[cuad2[j]-6000];//Se asigna Temp en Signal
						else if(cuad4[j]>=6000 && cuad4[j]<7000)
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000];//Se asigna Temp en Temp
					}
					break;
				case 1://==
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							if(cuad2[j] == cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(cuad2[j] == mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(cuad2[j] == mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(cuad2[j] == mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constantes
							if(mem_in[cuad2[j]-1000] == cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_in[cuad2[j]-1000] == mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_in[cuad2[j]-1000] == mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_in[cuad2[j]-1000] == mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							if(mem_sig[cuad2[j]-3000] == cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_sig[cuad2[j]-3000] == mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_sig[cuad2[j]-3000] == mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_sig[cuad2[j]-3000] == mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							if(mem_temp[cuad2[j]-6000] == cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_temp[cuad2[j]-6000] == mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_temp[cuad2[j]-6000] == mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_temp[cuad2[j]-6000] == mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					break;
				case 2://SHL 
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] << cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] << mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] << mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] << mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] << cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] << mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] << mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] << mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] << cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] << mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] << mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] << mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] << cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] << mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] << mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] << mem_temp[cuad3[j]-6000];
					}
					break;
				case 3://SHR
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] >> cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] >> mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] >> mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] >> mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] >> cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] >> mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] >> mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] >> mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] >> cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] >> mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] >> mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] >> mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] >> cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] >> mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] >> mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] >> mem_temp[cuad3[j]-6000];
					}
					break;
				case 4:// !=
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							if(cuad2[j] != cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(cuad2[j] != mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(cuad2[j] != mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(cuad2[j] != mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constantes
							if(mem_in[cuad2[j]-1000] != cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
	
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_in[cuad2[j]-1000] != mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_in[cuad2[j]-1000] != mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_in[cuad2[j]-1000] != mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							if(mem_sig[cuad2[j]-3000] != cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_sig[cuad2[j]-3000] != mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_sig[cuad2[j]-3000] != mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_sig[cuad2[j]-3000] != mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							if(mem_temp[cuad2[j]-6000] != cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_temp[cuad2[j]-6000] != mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_temp[cuad2[j]-6000] != mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_temp[cuad2[j]-6000] != mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					break;
				case 5://<
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							if(cuad2[j] < cuad3[j])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(cuad2[j] < mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(cuad2[j] < mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(cuad2[j] < mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constantes
							if(mem_in[cuad2[j]-1000] < cuad3[j])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_in[cuad2[j]-1000] < mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_in[cuad2[j]-1000] < mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_in[cuad2[j]-1000] < mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							if(mem_sig[cuad2[j]-3000]< cuad3[j])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_sig[cuad2[j]-3000] < mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_sig[cuad2[j]-3000] < mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_sig[cuad2[j]-3000] < mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							if(mem_temp[cuad2[j]-6000] < cuad3[j])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_temp[cuad2[j]-6000] < mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_temp[cuad2[j]-6000] < mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_temp[cuad2[j]-6000] < mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 0;
							else
								mem_temp[cuad4[j]-6000] = 1;
					}
					break;
				case 6://>
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							if(cuad2[j] > cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(cuad2[j] > mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(cuad2[j] > mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(cuad2[j] > mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constantes
							if(mem_in[cuad2[j]-1000] > cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_in[cuad2[j]-1000] > mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_in[cuad2[j]-1000] > mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_in[cuad2[j]-1000] > mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							if(mem_sig[cuad2[j]-3000] > cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_sig[cuad2[j]-3000] > mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_sig[cuad2[j]-3000] > mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_sig[cuad2[j]-3000] > mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							if(mem_temp[cuad2[j]-6000] > cuad3[j])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							if(mem_temp[cuad2[j]-6000] > mem_in[cuad3[j]-1000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							if(mem_temp[cuad2[j]-6000] > mem_sig[cuad3[j]-3000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							if(mem_temp[cuad2[j]-6000] > mem_temp[cuad3[j]-6000])
								mem_temp[cuad4[j]-6000] = 1;
							else
								mem_temp[cuad4[j]-6000] = 0;
					}
					break;
				case 7://&
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] & cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] & mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] & mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] & mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] & cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] & mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] & mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] & mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] & cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] & mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] & mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] & mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] & cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] & mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] & mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] & mem_temp[cuad3[j]-6000];
					}
					break;
				case 8://|
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] | cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] | mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] | mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] | mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] | cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] | mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] | mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] | mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] | cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] | mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] | mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] | mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] | cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] | mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] | mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] | mem_temp[cuad3[j]-6000];
					}
					break;
				case 9:// !
					if(cuad2[j]<1000) // Constantes
						mem_temp[cuad4[j]-6000] = !cuad2[j];
						
					else if(cuad2[j]>=1000 && cuad2[j]<2000) // Ins
						mem_temp[cuad4[j]-6000] = !mem_in[cuad2[j]-1000]; 
							
					else if(cuad2[j]>=3000 && cuad2[j]<4000) // Signals
						mem_temp[cuad4[j]-6000] = !mem_sig[cuad2[j]-3000];
						
					else if(cuad2[j]>=6000 && cuad2[j]<7000) // Temporales
						mem_temp[cuad4[j]-6000] = !mem_temp[cuad2[j]-6000];
					break;
				case 10://^
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] ^ cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] ^ mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] ^ mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] ^ mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] ^ cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] ^ mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] ^ mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] ^ mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] ^ cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] ^ mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] ^ mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] ^ mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] ^ cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] ^ mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] ^ mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] ^ mem_temp[cuad3[j]-6000];
					}
					break;
				case 11://+
					if(cuad2[j]<1000){ // Constantes
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad2[j] + cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad2[j] + mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad2[j] + mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] + mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=1000 && cuad2[j]<2000){ // Ins
						if(cuad3[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] + cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] + mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] + mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad2[j]-1000] + mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){ // Signals
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] + cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] + mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] + mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad2[j]-3000] + mem_temp[cuad3[j]-6000];
					}
					else if(cuad2[j]>=6000 && cuad2[j]<7000){ // Temporales
						if(cuad3[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] + cuad3[j];
						else if(cuad3[j]>=1000 && cuad3[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] + mem_in[cuad3[j]-1000];
						else if(cuad3[j]>=3000 && cuad3[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] + mem_sig[cuad3[j]-3000];
						else if(cuad3[j]>=6000 && cuad3[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad2[j]-6000] + mem_temp[cuad3[j]-6000];
					}
					break;
				case 12://-
					if(cuad3[j]<1000){ // Constantes
						if(cuad2[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = cuad3[j] - cuad2[j];
						else if(cuad2[j]>=1000 && cuad2[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = cuad3[j] - mem_in[cuad2[j]-1000];
						else if(cuad2[j]>=3000 && cuad2[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = cuad3[j] - mem_sig[cuad2[j]-3000];
						else if(cuad2[j]>=6000 && cuad2[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = cuad3[j] - mem_temp[cuad2[j]-6000];
					}
					else if(cuad3[j]>=1000 && cuad3[j]<2000){ // Ins
						if(cuad2[j]<1000) // Con Constante
							mem_temp[cuad4[j]-6000] = mem_in[cuad3[j]-1000] - cuad2[j];
						else if(cuad2[j]>=1000 && cuad2[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_in[cuad3[j]-1000] - mem_in[cuad2[j]-1000];
						else if(cuad2[j]>=3000 && cuad2[j]<4000) // Con Signals
							mem_temp[cuad4[j]-6000] = mem_in[cuad3[j]-1000] - mem_sig[cuad2[j]-3000];
						else if(cuad2[j]>=6000 && cuad2[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_in[cuad3[j]-1000] - mem_temp[cuad2[j]-6000];
					}
					else if(cuad3[j]>=3000 && cuad3[j]<4000){ // Signals
						if(cuad2[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_sig[cuad3[j]-3000] - cuad2[j];
						else if(cuad2[j]>=1000 && cuad2[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_sig[cuad3[j]-3000] - mem_in[cuad2[j]-1000];
						else if(cuad2[j]>=3000 && cuad2[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_sig[cuad3[j]-3000] - mem_sig[cuad2[j]-3000];
						else if(cuad2[j]>=6000 && cuad2[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_sig[cuad3[j]-3000] - mem_temp[cuad2[j]-6000];
					}
					else if(cuad3[j]>=6000 && cuad3[j]<7000){ // Temporales
						if(cuad2[j]<1000) // Con Constantes
							mem_temp[cuad4[j]-6000] = mem_temp[cuad3[j]-6000] - cuad2[j];
						else if(cuad2[j]>=1000 && cuad2[j]<2000) // Con Ins
							mem_temp[cuad4[j]-6000] = mem_temp[cuad3[j]-6000] - mem_in[cuad2[j]-1000];
						else if(cuad2[j]>=3000 && cuad2[j]<4000) // Con Signal
							mem_temp[cuad4[j]-6000] = mem_temp[cuad3[j]-6000] - mem_sig[cuad2[j]-3000];
						else if(cuad2[j]>=6000 && cuad2[j]<7000) // Con Temporales
							mem_temp[cuad4[j]-6000] = mem_temp[cuad3[j]-6000] - mem_temp[cuad2[j]-6000];
					}
					break;
				case 13://go to
					j = cuad4[j]-1;
					break;
				case 14://go to false
					if(mem_temp[cuad2[j]-6000]==1)
						j = cuad4[j]-1;
					break;
				case 15://go to true
					if(mem_temp[cuad2[j]-6000]==0)
						j = cuad4[j]-1;
					break;
				case 16://Asignación variables
					if(cuad2[j]>=1000 && cuad2[j]<2000){//Inputs
						mem_in_dim[m] = cuad4[m];
						dim = pow(2,mem_in_dim[m])-1;
						do{/*Verify Inputs*/
							printf("Input %c (En Decimal)\n", alfabeto[j]);
							scanf("%d", &mem_in[cuad2[j]-1000]);
							if(pow(2,mem_in_dim[m])-1 < mem_in[cuad2[j]-1000]){
								printf("Argumento Invalido, Favor de Introducir un Numero Valido\n");
								printf("Dimension Máxima de la variable %d\n\n\n",dim);
							}
						}while(dim < mem_in[cuad2[j]-1000]);
						m++;
					}
					else if(cuad2[j]>=2000 && cuad2[j]<3000){//Outputs
						mem_out[o] = 0;
						mem_out_dim[o] = cuad4[j];
						o++;
					}
					else if(cuad2[j]>=3000 && cuad2[j]<4000){//Signals
						mem_sig[s] = 0;
						mem_sig_dim[s] = cuad4[j];
						s++;
					}
					break;
				default:
					printf("ERROR \n");
					break;
			}
			j++;
			a++;	
		}
		j=0;
		while(j<o){ /*Print Outputs*/
		printf("\n");
			if(mem_out[j]==0)
				printf("Output %i:\n0\n",j);
			else{
				printf("Output %i:\n",j);
				binario(mem_out[j]);
			}
			j++;
		}
		printf("\n\n");
	}
	return 0;
}