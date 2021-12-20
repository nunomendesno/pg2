
#include <string.h>
#include <stdio.h>


 int lineSplitNext(int sizeArray, char line[],char * array[]){

  	 
	
	int getWord=0;
	int getFristWord=1;
	int i=0;
	int sizeBuffer=0;
			
	char buffer[100];
		
	while(line[i]!='\0' ){
		buffer[sizeBuffer++]=line[i];
		
		if(line[i]!=' '){
			sizeBuffer=0;
			getWord=1;
			if(getFristWord)
				strcpy(array[++sizeArray],buffer);
			getFristWord=0;
		}
				
		if(line[i]==' ' && getWord ){
			line='\0';
			return sizeArray;
		}
		
		i++;
		}

	
   
return -1;
}



int main () {
	
	
	
	
	char  *words[1000];
	
	if(words==NULL){
		printf("Erro na allocacao de memoria *word. \n");
		return 0;}
	
	
	
	//if(wordsSplit==NULL){printf("Erro na allocacao de memoria1. \n");}
	
    FILE* arquivo = fopen("frases.txt", "r");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }
	
	
	
    char  linha[1240];
    
   // linha= malloc( sizeof(*linha));
    
    int sizeArray=0;

	
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
			//printf(" 1+ size_i*sizeof(char *)");
    	/* note como não precisamos especificar uma nova linha, o fgets já a inclui na string linha quando a encontra */
      sizeArray=lineSplitNext(sizeArray,linha,  words);
        
        //printf("%s\n", linha);
      //   printf("%p\n", linha);
        //i++;
    }

    fclose(arquivo);
    
    
    
    for (int i=0; i<sizeArray;i++)
    printf("Word[%d]=%s\n", i, words[i]);
	
	
	
	
		
 
   
   return(0);

}
