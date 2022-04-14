#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"

typedef struct 
{
	char au_dealer_number[11];
	char suplier_name[6];
	char suplier_phone_number[11];
	char num_of_transactions[6];
	char sumOf_num_of_transactions[11];
	
} supplier;

typedef struct supplier_node
{
	supplier data;
	struct supplier_node* left;
	struct supplier_node* right;
} supplier_node;

supplier_node* root_sup;
supplier* sup_data;



/* defines an array of company suppliers */
void createSupplierList ();


/* return "1" if new supplier added*/
bool addNewSupplier (supplier_node** tree, supplier* data);
void getNewSupplier(supplier*);

/* return 3 greatest au dealer number*/
char** threeGreatestSuppliers(supplier_node*);

/* return "1" if delete succed*/
supplier_node* deleteSupplier (supplier_node*, char*);

/* return "1" if succed*/
void deleteAllSuppliers (supplier_node**);
void _deleteAllSuppliers (supplier_node*);

double averageOfSupplierMoney (supplier_node*, int*);

void printSuppliers(supplier_node* tree);
#endif