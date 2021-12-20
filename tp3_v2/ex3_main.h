
# define MAX_LEN 1000
# define MAX_WORD_SIZE 100

#include "1.2_Normalize"
#include "ex3.c"
#include "1.1_SplitFrase"


typedef struct {
	char *word;
	int freq;
	} WordFreq;

int menu(	int argc ,  char * argv[], char * menu[] );

int printExtruturaWordFres(WordFreq words[],int size);

int lineSplitNext(int sizeArray, char line[],char * array[]);

char *normalize( char * word);
