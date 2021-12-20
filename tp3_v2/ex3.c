#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include "ex3.h"






int booleanComp(const int *ptr1, const int *ptr2){
  return *ptr1 < *ptr2;
}

int comparator(const void **p0, const void **p1){ 
	return strcmp((( WordFreq*) *p0) -> word , (( WordFreq*) *p1) -> word);
} 

int comparatorBsearch(const void *p0, const void **p1) { 
	//printf("value  p %s       e wordfreq%s\n",(char*)p0 ,(( WordFreq*) *p1) -> word );
	return strcmp(p0 , (( WordFreq*) *p1) -> word );
} 

int comparatorCresc(const void **p0, const void **p1) { 
	return (((( WordFreq*) *p0) -> freq )- ((( WordFreq*) *p1) -> freq));
} 

int comparatorDec(const void **p0, const void **p1){ 
	return (((( WordFreq*) *p1) -> freq )- ((( WordFreq*) *p0) -> freq));
} 


int menu(int argc, char *argv[], char **menu){
	
	printf("\nvalor de argc%d\n",argc);

	if(argc>=1){
		printf("comando nome ficheiro-%s \n\n",argv[1]);
		strcpy(menu[0], argv[1]);
	}
		else{
			strcpy(menu[0], "null");
			}
			
	if(argc>=2){
		printf("comando de menu1%s \n\n",argv[2]);
			strcpy(menu[1], argv[2]);
	}
		else{
			strcpy(menu[1], "null");
			}
			
	if(argc>=3){
	printf("comando de menu2%s \n\n",argv[3]);
		strcpy(menu[2], argv[3]);
	}
		else{
			strcpy(menu[2], "null");
			}
			
	if(!strcmp( menu[1],"a")||!strcmp(menu[1],"w")||!strcmp(menu[1],"+")||!strcmp(menu[1],"-"))
	return 1;
		else {return -1;}
			
}




int createWordFreq(WordFreq * wordsToPointer[] , char *arrayPointer[], int numWord )	{	
	WordFreq  words[numWord];											// cria array de estruturas
	int existe=0;
	int newExiste=0;													//tamanho da estrura de freq
		
	for (int k=0; k<numWord ;k++){
		for (int j=0; j<newExiste ;j++){									//verifica se existe na tabela de freq
			if(!strcmp( arrayPointer[k], words[j].word )){
				words[j].freq+=1;
				existe=1;
			}
		}
		
		if(existe==0)	{											//se nao existir nome ma tabela de freq adiciona nova entrada
			strcpy(words[newExiste].word ,arrayPointer[k]);
			newExiste++;
			words[newExiste].freq=1;
		}
	existe=0;
	}
		
	//printExtruturaWordFres(words,newExiste );
	//cria array de pointers
	//////////////////////////////////////////////////////////////WordFreq * wordsToPointer[newExiste];
	for (int k=0; k<newExiste ;k++){
		wordsToPointer[k]=&words[k];
		//printf("wordsToPointer[k] %p\n",wordsToPointer[k]);
		}
return newExiste;
}

void qsortCrescente(WordFreq *wordsToPointer[], int sizeWordsToPointer){
//qsort(wordsToPointer, sizeof(wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparator);
	qsort(wordsToPointer, sizeof(*wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparator);
	
	for(int i=0; i<sizeWordsToPointer ; i++)// Afixação de elementos do array após a ordenação ...
		
		printf("freq< %d     name<%s\n",wordsToPointer[i]-> freq,wordsToPointer[i]-> word);
		
		
		}
		
void qsortWword( char * key, WordFreq * wordsToPointer[]){
			
	qsort(wordsToPointer, sizeof(*wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparator);  //necessario ordenar array primeiro
			
	char **item;
	//item=(char**) bsearch(key,wordsToPointer, sizeof(wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparatorBsearch);
	item=(char**) bsearch(key,wordsToPointer, sizeof(*wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparatorBsearch);
	//void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
	

	if( item != NULL ) 
		  printf("Found item: %s    com freq= %d\n",(( WordFreq*) *item)->word, (( WordFreq*) *item)->freq);
		else {
		  printf("w word insucesso \n");
	   }
}	   
			
void qsortMenosNumber(int num, WordFreq * wordsToPointer[], int sizeWordsToPointer ){
			
	
	qsort(wordsToPointer, sizeof(*wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparatorDec);  //necessario ordenar array primeiro
	
	for(int i=0; i<sizeWordsToPointer ; i++)// Afixação de elementos do array após a ordenação ...
		if(wordsToPointer[i]-> freq <= num)
		printf("freq< %d     name<%s\n",wordsToPointer[i]-> freq,wordsToPointer[i]-> word);
	
	
}
		
void qsortMaisNumber(int num, WordFreq * wordsToPointer[], int sizeWordsToPointer ){
			
	//qsort(wordsToPointer, sizeof(wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparatorCresc);  //necessario ordenar array primeiro		
	qsort(wordsToPointer, sizeof(*wordsToPointer)/sizeof(wordsToPointer[0]),  sizeof(wordsToPointer[0]), (int(*)(const void*,const void*))comparatorCresc);  //necessario ordenar array primeiro
	
	for(int i=0; i<sizeWordsToPointer ; i++)// Afixação de elementos do array após a ordenação ...
		if(wordsToPointer[i]-> freq <= num)
		printf("freq< %d     name<%s\n",wordsToPointer[i]-> freq,wordsToPointer[i]-> word);
	
	
}
	  

	
	
void printExtruturaWordFres(WordFreq words[],int size){
	for (int j=0; j<size ;j++){	
		printf("name %25s       freq %10d \n",words[j].word, words[j].freq);
		}
	}
	
	
	
