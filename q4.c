#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

int main(){
	FILE *fp;
	fp = fopen("myword.txt", "a");
	
	if(fp==NULL){
		printf("File is not oppened..\n");
	}
	
	int n, i, aCount=0, eCount=0, iCount=0, oCount=0, uCount=0, count=0;
	char word[MAXSIZE];
	printf("Enter the word = ");
	gets(word);
	
	n = strlen(word);
	
	for(i=0; i<n; i++){
		if(word[i]>='A' && word[i]<='Z'){
			word[i] = word[i] + 32;
		}
	}

	
//	for(i=0; i<n; i++){
//		printf("%c", word[i]);	
//	}
	for(i=0; i<n; i++){
		if(word[i]=='a'){
			aCount = aCount + 1;
		}
		else if(word[i]=='e'){
			eCount = eCount + 1;
		}
		else if(word[i]=='i'){
			iCount = iCount + 1;
		}
		else if(word[i]=='o'){
			oCount = oCount + 1;
		}
		else if(word[i]=='u'){
			uCount = uCount + 1;
		}
		else{
			count = count + 1;	
		} 
	}
	
	//fprintf(fp, "Word\ta\te\ti\to\tu\tother\t\ttotal\n");
	fprintf(fp, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", word, aCount, eCount, iCount, oCount, uCount, count, n);
	
	return 0;
}
