#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include "ex3.h"
#include "1.2_Normalize.h"
#include "1.1_SplitFrase.h"





int main(int argc, char *argv[] )
{
	char menu1[3];
	strcpy(menu1,"a");
	
	char menu2[3];
	
	strcpy(menu2,"ao");
	
	//char * menu[];
	//menu=malloc(sizeof(menu)*3);
	//if(menu==NULL){ 
	//	printf("Erro alloc mem menu");
	//	exit(1)
	//}
	
	//if( menu(argc ,  argv[],  menu){
		//printf("ERRO Menu desconhecido");
		//retun 0;
	//	}
	
	
	FILE *input_file;									//cria instancia de output
	
	//input_file = fopen (argv[1], "r");								//acede ao ficheiro
	//input_file = fopen (menu[1], "r");								//acede ao ficheiro
	input_file = fopen ("frases.txt", "r");								//acede ao ficheiro

	if(input_file == NULL) {											// verifica leitura  de ficheiro
		printf("Erro ao abrir o ficheiro de entrada.\n");
			exit(1);
		}
				
	//char* limitador="%s";
	//int numWord=0;
	
	
	char **savePointerWord;
	
	savePointerWord = malloc( sizeof(char));
	//*savePointerWord = malloc( sizeof(char));
	if(savePointerWord== NULL) {											// verifica leitura  de ficheiro
		printf("Erro ao abrir o ficheiro de entrada.\n");
			exit(1);
		}
		
		
	char  linha[1000];
        
    int sizeArray=0;
		
	while(fgets(linha, sizeof(linha), input_file) != NULL) {
      sizeArray=lineSplitNext( sizeArray,linha,  savePointerWord);		//separa palavras linha a linha e guarda tamanho de array
	printf("size array %d.\n",sizeArray);
printf("%s\n",savePointerWord[sizeArray]);
    }
    
    fclose(input_file);
		
		
	/*	while(fscanf(input_file, limitador, &savePointerWord[numWord]) != EOF) {		//%[^\n] 	////vai buscar palavras do ficheiro e guarda no array
		   // printf("%s\n",savePointerWord[numWord]);
			numWord++;
		}
		*/
	

	/*char* arrayPointer[numWord];									//vai guardar endereços daspalavras normalizadas	
		
	 for (int k=0; k<numWord;k++)									//Normaliza palavras
		arrayPointer[k]=normalize(savePointerWord[k]);
		*/
	/*for(int j=0; j< sizeArray-1;j++){
		
		printf("%s\n",savePointerWord[j]);
		}*/
	
	printf("antes normalizacao\n");
	for (int k=0; k<sizeArray;k++)	{								//Normaliza palavras
		normalize(savePointerWord[k]);}
		
		printf("estou aqui\n");
				
		
	WordFreq **  wordsToPointer;											// cria array de estruturas
	
	 wordsToPointer= malloc(sizeof(WordFreq));
	if( wordsToPointer== NULL) {											// verifica leitura  de ficheiro
		printf("Erro ao abrir o ficheiro de entrada.\n");
			exit(1);
		}
	
	
	int sizeWordFreq=0;
	
	sizeWordFreq= createWordFreq(  wordsToPointer , savePointerWord, sizeArray );
	
	
			
		//printExtruturaWordFres(words,newExiste );
		//cria array de pointers
		
		/*************************************************************************************************************************/
		//WordFreq * wordsToPointer[sizeWordFreq];
		
		
		//for (int k=0; k< sizeWordFreq ;k++){
			//wordsToPointer[k]=&words[k];
			//printf("wordsToPointer[k] %p\n",wordsToPointer[k]);
			//}
	
	
		if (!strcmp(menu1,"a")){
			
			qsortCrescente( wordsToPointer ,  sizeWordFreq);
				
		}
		
		if (!strcmp(menu1,"w")){
			
			 qsortWword( menu2,  wordsToPointer);
		}	   
			
		if (!strcmp(menu1,"+")){
			
			int num=atoi(menu2);
			qsortMenosNumber(num,  wordsToPointer, sizeWordFreq );
		}
		
		if (!strcmp(menu1,"-")){
			int num=atoi(menu2);
			
			qsortMaisNumber( num,  wordsToPointer, sizeWordFreq );
			
			
		}
	  
		if (!strcmp(menu1,"q"))
		printf(" o programa ira terminar");
		
	
	return 0;
	

}
