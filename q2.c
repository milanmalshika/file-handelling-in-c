#include<stdio.h>
#include<stdlib.h>

struct employee{
	char empName[20];
	int empNo;
	float basicSal;
	int ot;
	float salary;
	float otamnt;
}e[4];
int k=0;

float netSalary(float sal, int ot){
	float otamount = 0;
	float ntslry = 0;
	otamount = (float)ot * 15.00;
	e[k].otamnt = otamount;
	ntslry = sal + sal*0.35 + otamount;
	k++;
	return ntslry;
}

int main(){
	FILE *fp;
	fp = fopen("q_two.txt", "r");
	int i;
	float sum=0;
	
	for(i=0; i<4; i++){
		fscanf(fp, "%s %d %f %d", e[i].empName, &e[i].empNo, &e[i].basicSal, &e[i].ot);
		e[i].salary = netSalary(e[i].basicSal, e[i].ot);	
	}
	
	for(i=0; i<4; i++){
		sum = sum + e[i].salary;
	}
	
	printf("Emp_Id\tBasic_Salary\tOT_Amount\tNet_Salary\n");
	for(i=0; i<4; i++){
		printf("%d\t%.2f\t%.2f\t\t%.2f\n", e[i].empNo, e[i].basicSal, e[i].otamnt, e[i].salary );
	}

	printf("\nTotal amount of money this company should have to pay the employee salaries = %.2f\n", sum);
	
	fclose(fp);	
	
	return 0;
}
