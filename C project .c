/*  Record file of retaurant containing records of customers*/
#include<stdio.h>
#include<string.h>

#define TRUE 1

typedef struct {
	int month;
	int day;
	int year;
}date;

typedef struct{
	char name[80];
	char address[80];
	int account_no;
	float currentbalance;
	char orderedfood[80];
	float price;
	float newbalance;
	date payment;
}record;

record readscreen(record customer);
void writefile(record customer);

FILE *fpt;

int main()
{
	int flag = TRUE;
	record customer;
	
	fpt=fopen("billing.txt", "w");
	
	printf("\t \t WELCOME TO OUR RESTAURANT");
	printf("\n\n\t\t OUR BILLING SYSTEM");
	
	printf("\n\n \t \t Kindly enter today's date (yyyy/mm/dd): ");
	scanf("%d/%d/%d", &customer.payment.year, &customer.payment.month, &customer.payment.day);
	
	customer.newbalance=0;
	customer.price=0;
	
	while (flag) {
		printf("\n\nName(Enter \'OK\' when finished): ");
		scanf(" %[^\n]", customer.name);
		fprintf(fpt, "\n%s\n", customer.name);
		
		if(strcmp(customer.name, "OK")==0)
			break;
		
		customer=readscreen(customer);
		writefile(customer);
	}
	fclose(fpt);
}

record readscreen(record customer)
{
	printf("Address: ");
	scanf(" %[^\n]", customer.address);
	printf("Account Number: ");
	scanf("%d",&customer.account_no);
	printf("Current Balance: ");
	scanf("%f", &customer.currentbalance);
	printf("Ordered Food: ");
	scanf("%s", customer.orderedfood);
	printf("Enter Price of Ordered Food: ");
	scanf("%f", &customer.price);
	customer.newbalance=customer.currentbalance-customer.price;
	printf("New Balance:%f ", customer.newbalance);
}

void writefile(record customer)
{
	fprintf(fpt, "%s\n", customer.name);
	fprintf(fpt, "%d\n", customer.account_no);
	fprintf(fpt, "%.2f\n", customer.currentbalance);
	fprintf(fpt, "%s\n", customer.orderedfood);
	fprintf(fpt, "%.2f\n", customer.price);
	fprintf(fpt, "%.2f\n", customer.newbalance);
	fprintf(fpt, "%d/%d/%d\n", customer.payment.year, customer.payment.month, customer.payment.day);
	
	return;
	
}
	

