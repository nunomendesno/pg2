
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int lineSplitNext(int sizeArray, char line[],char ** words){
   
    //char line[] = "Geeks for Geeks dsfsdf  sdfsdf sdfsdf sdfdsf";
    
    //char **words;
    
   /* words = malloc(sizeof(char));
    if(words==NULL){
		printf("Probls to alocate mem in word");
		exit(1);
		}
		*/

	int getWord=0;
	int getFristWord=1;
	int i=0;
	int sizeBuffer=0;
	//sizeArray=0;
	
	char * bufferWord;
	bufferWord= malloc(sizeof(char));
    if(bufferWord==NULL){
		printf("Probls to alocate mem in bufferWord");
		exit(1);
		}
	
	
		
	do{
		
		bufferWord = realloc(bufferWord ,(sizeBuffer+1)*sizeof(char));
			if(bufferWord==NULL){
				printf("Problems to alocate realloc mem in bufferWord");
				exit(1);
			}
		
		if(line[i]!=' '&&line[i]!='\n'){
			getWord=1;
			
			
			
			 
			bufferWord[sizeBuffer]=line[i];
			//bufferWord[sizeBuffer+1]='\0';
			sizeBuffer++;
			
			
			if(getFristWord)
				getFristWord=0;
		}
	
	
		if((line[i]==' '||line[i]=='\n') && getWord ){
			
			
			//printf("buffer----------------%s\n",bufferWord);
			//printf("sizeArray----------------- %d\n",sizeArray);
			//printf("sizeBuffer----------------- %d\n",sizeBuffer);
			
			words = realloc( words,(sizeArray+1)*sizeof(words));
			if(words==NULL){
				printf("Problems to alocate realloc mem in word[]");
				exit(1);
			}
			
			
			words[sizeArray] =  malloc((sizeBuffer+1)*sizeof(char));
			if(words[sizeArray] ==NULL){
				printf("Problems to alocate realloc mem in word[][]");
				exit(1);
			}
			
			bufferWord = realloc( bufferWord,(sizeBuffer+1)*sizeof(char));
				if(bufferWord==NULL){
					printf("Problems to alocate realloc mem in bufferWord");
					exit(1);
				}
				
			strcat(bufferWord,"\n");
						//printf("buffer----------------%s\n",bufferWord);
			
			strcpy(words[sizeArray],bufferWord);
			//words[sizeArray]=bufferWord;
			
			//memcpy(words[sizeArray], bufferWord, strlen(bufferWord)+1);
					printf("words[sizeArray]----------------%s\n",words[sizeArray]);
			sizeArray++;
			//printf("Estou aqui\n");
			
			//strcpy(bufferWord,"\0");
			free(bufferWord);										//renicio o buffer
			
			bufferWord= malloc(sizeof(char));
			if(bufferWord==NULL){
				printf("Probls to alocate mem in bufferWord");
				exit(1);
			}
			
			sizeBuffer=0;
			getWord=0;
			getFristWord=1;

		}
		
		i++;
		
		}while(line[i]!='\0' );
		
	//printa split frases	
	//for(int j=0; j< sizeArray;j++){
		
		//	printf("%s\n",words[j]);
	//	}
		/*
	free(words);
	for(int j=0; j< sizeArray;j++){
		
			free(words[j]);
		}*/
		

return sizeArray;
		
}
