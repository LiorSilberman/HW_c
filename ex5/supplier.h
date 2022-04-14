#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"
#define K 50

typedef struct 
{
	char au_dealer_number[11];
	char* suplier_name;
	char suplier_phone_number[11];
	char num_of_transactions[6];
	char sumOf_num_of_transactions[11];
	
} supplier;

typedef struct supplier_node
{
	supplier data;
	struct supplier_node* next;
} supplier_node;

supplier_node* head_sup;

/* defines an array of company suppliers */
void createSupplierList ();

/* return "1" if new supplier added*/
bool addNewSupplier ();

/* return 3 greatest au dealer number*/
char** threeGreatestSuppliers();

char** threeGreatestSuppliers_REC (supplier_node* tmp, int counter);

/* print all suppliers details. work only with DAVIS company*/
#ifdef DAVIS
void printSuppliers ();
#endif

/* return "1" if delete succed*/
void deleteSupplier ();

/* return "1" if succed*/
void deleteAllSuppliers ();


#endif