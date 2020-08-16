#include<stdio.h>
#include<stdlib.h>

struct family{
	int id_number;
	int ann_income;
	int numOfMembers;
	int s;
}f[5];

int sumOfIncome = 0;
int totlMmbrs = 0;
int k=0;

void averageIncome(int income){
	sumOfIncome = sumOfIncome + income; 
}

void totalOfMembers(int mem){
	totlMmbrs = totlMmbrs + mem;
	f[k].s = totlMmbrs;
	k++;
}

int main(){
	FILE *fp;
	fp = fopen("readme.txt", "r");
	int i, medianIncome;
	
	for(i=0; i<5; i++){
		fscanf(fp, "%d %d %d", &f[i].id_number, &f[i].ann_income, &f[i].numOfMembers);	
		averageIncome(f[i].ann_income);
		totalOfMembers(f[i].numOfMembers);
	}
	
	printf("IDNumber\tAnnualIncome($)\tNoOfMembers\n\n");
	for(i=0; i<5; i++){
		printf("%d\t\t%d\t\t%d\n", f[i].id_number, f[i].ann_income, f[i].numOfMembers);
	}
	
	int avrgeIncm = sumOfIncome/5;
	
	printf("\nAverage household income ($) - %d\n", avrgeIncm);
	
	printf("\nTotal number of members in the town - %d\n", totlMmbrs);
	
	int medianPoint = totlMmbrs/2;
	
	for(i=0; i<5; i++){
		if(medianPoint- f[i].s<0){
			medianIncome = f[i].ann_income;
			break;
		}
	} 
	
	printf("\nMedian Annual Income($) - %d", medianIncome);
	
	return 0;
}
