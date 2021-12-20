



typedef struct {
	char *word;
	int freq;
	} WordFreq;

int menu(	int argc ,  char * argv[], char * menu[] );

void printExtruturaWordFres(WordFreq words[], int size);

int createWordFreq(WordFreq * wordsToPointer[] , char *arrayPointer[], int numWord );

void qsortCrescente(WordFreq *wordsToPointer[], int sizeWordsToPointer);

void qsortWword( char * key, WordFreq * wordsToPointer[]);

void qsortMenosNumber(int num, WordFreq * wordsToPointer[], int sizeWordsToPointer );

void qsortMaisNumber(int num, WordFreq * wordsToPointer[], int sizeWordsToPointer );
