#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>
#include "get_input.h"
#define K 50

typedef struct 
{
	char au_dealer_number[10+1];
	/*char test[1];*/
	char sumOf_num_of_transactions[10+1];
	/*char test2[1];*/
	char num_of_transactions[5+1];
	/*char test3[1];*/
	char suplier_name[5+1];
	/**char test4[1];*/
	char suplier_phone_number[10+1];
/*	char test5[1];*/
	
} supplier;

supplier supplierList[K];
int counterSupp;

/* defines an array of company suppliers */
void createSupplierList ();

/* return "1" if new supplier added*/
int addNewSupplier ();

/* return 3 greatest au dealer number*/
void threeGreatestSuppliers(char* num1, char* num2, char* num3);

/* return "1" if delete succed*/
int deleteSupplier (char* suplier_name);

/* return "1" if succed*/
int deleteAllSuppliers ();


#endif