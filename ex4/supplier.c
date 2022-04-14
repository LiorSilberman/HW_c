
#include "supplier.h"

extern supplier supplierList[K];
extern int counterSupp;

void initSupplier(int i);

/*create supplier list*/
void createSupplierList () 
{
	int  i;
	counterSupp = 0;
	for (i = 0; i < K; i++)
	{
		initSupplier(i);
	}
}

/* initialize supplier list*/
void initSupplier (int i) {
	supplierList[i].au_dealer_number[0] = '\0';
	supplierList[i].suplier_name[0] = '\0';
	supplierList[i].suplier_phone_number[0] = '\0';
	supplierList[i].num_of_transactions[0] = '\0';
	supplierList[i].sumOf_num_of_transactions[0] = '\0';
}

/* get input from user and add new supplier*/
int addNewSupplier ()
{
	get_user_input_num(supplierList[counterSupp].au_dealer_number, "Enter authorized dealer number: ", SIZE_TEN);
	printf("out - %s\n" ,supplierList[counterSupp].au_dealer_number );
	get_user_input_string(supplierList[counterSupp].suplier_name,"Enter suplier name: " ,SIZE_FIVE);

	get_user_input_num(supplierList[counterSupp].suplier_phone_number, "Enter phone number: ", SIZE_TEN);

    get_user_input_num(supplierList[counterSupp].num_of_transactions, "Enter number of transactions: ", SIZE_FIVE);

	get_user_input_num(supplierList[counterSupp].sumOf_num_of_transactions, "Enter sum of transactions: ", SIZE_TEN);

	counterSupp++;
	printf("new Supplier added\n");
	return 0;
}

/* return 3 greatest suppliers*/
void threeGreatestSuppliers( char* num1, char* num2, char* num3)
{
	int i;
	
	printf("Three greatest supliers are:\n ");
	for (i = 0; i < counterSupp; i++)
	{
		if (!strcmp(supplierList[i].sumOf_num_of_transactions, num1))
		{
			printf("%s\n ", supplierList[i].au_dealer_number);		
		}
		if (!strcmp(supplierList[i].sumOf_num_of_transactions, num2))
		{
			printf("%s\n ", supplierList[i].au_dealer_number);	
		}
		if (!strcmp(supplierList[i].sumOf_num_of_transactions, num3))
		{
			printf("%s\n ", supplierList[i].au_dealer_number);	
		}
	}
}


/* delete one supplier by given name*/
int deleteSupplier (char* suplier_name)
{
	int i;
	if (!isValid_sizeName(suplier_name , 5))
	{
		return 0;
	}

	for (i = 0; i < counterSupp; i++)
	{
		if (!strcmp(supplierList[i].suplier_name, suplier_name))
		{
			initSupplier(i);
			supplierList[i] = supplierList[counterSupp-1];
			counterSupp--;
			return 1;
		}
	}
	return 0;
}	

/* delete all suppliers*/
int deleteAllSuppliers ()
{
	int i;
	for (i = 0; i < counterSupp; i++)
	{
		initSupplier(i);
	}
	counterSupp = 0;
	return 0;
}