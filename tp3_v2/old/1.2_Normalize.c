

char *normalize( char * word){
	
	int j=0;
	int fristWord=0;
	int lastWord=0;
	
	for(int i = 0 ; word[i]!='\0' && fristWord==0 ;i++ ){ 				// processa inicio de palavra
		
		
		
		if((word[i]>=0x30 && word[i]<=0x39) || (word[i]>=0x41 && word[i]<=0x54) || (word[i]>=0x61 && word[i]<=0x7a) )
			fristWord=1;
			
		int x=0;
		if(fristWord){
			for(x=0; word[j+x]!='\0'; x++)		//reorganiza word
				word[x]=word[j+x];
			word[x]='\0';
		  
		  }
		  
		j++;
						
	}
				

	
	for(int i = 0 ; word[i]!='\0';i++ ){ 				// deteta ultima palavra
		
		if((word[i]>=0x30 && word[i]<=0x39) || (word[i]>=0x41 && word[i]<=0x54) || (word[i]>=0x61 && word[i]<=0x7a) )
			lastWord=i;
	}
	 
	word[lastWord+1]='\0';
		  
	for(int i = 0 ; word[i]!='\0';i++ ){ 				// converte p minusculas
		
		if( (word[i]>=0x41 && word[i]<=0x54) )
			word[i]+=0x20;
	}	
	
	
return word;
	}

