#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>

#define K 50

typedef struct 
{
	int au_dealer_number;
	char suplier_name[5];
	int suplier_phone_number;
	int num_of_transactions;
	int sumOf_num_of_transactions;
	
} suplier;

/* defines an array of company suppliers */
void createSupplierList ();

/* return "1" if new supplier added*/
int addNewSupplier ();

/*  return 3 greatest au dealer number*/
int threeGreatestSuppliers (int au_dealer_number);

/*  return "1" if delete succed*/
int deleteSupplier (char* suplier_name);

/*  return "1" if succed*/
int deleteAllSuppliers ();


#endif