#include<stdio.h>

struct student{
	char reg_no[20];
	char name[50];
	int age;
}s[5];

int main(){
	FILE *fp;
	fp = fopen("q_one.txt", "w");
	int i;
	
	if(fp==NULL){
		printf("File is not oppened..\n");
	}
	
	for(i=0; i<5; i++){
		printf("\nStudent %d\n", i+1);
		printf("Enter the registration number = ");
		scanf("%s", s[i].reg_no);
		printf("Enter your name = ");
		scanf("%s", s[i].name);
		printf("Enter age = ");
		scanf("%d", &s[i].age);
	}
	
	fprintf(fp, "\nStudent details\n");
	fprintf(fp, "StRe_no\t\tSt_Name\t\tSt_age\n");
	for(i=0; i<5; i++){
		fprintf(fp, "%s\t\t%s\t\t%d\n", s[i].reg_no, s[i].name, s[i].age);
	}
	fclose(fp);
	
	return 0;
}
