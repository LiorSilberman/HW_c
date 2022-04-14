
#include "supplier.h"


/*create supplier list*/
void createSupplierList () 
{
	root_sup = NULL;
	printf("Supplier list created\n");
}

bool addNewSupplier (supplier_node** tree, supplier* sup_data)
{
	/* create new supplier */
	if (sup_data == NULL)
	{
		sup_data = ALLOC(supplier, sizeof(supplier)+1);

		getNewSupplier(sup_data);
	}

	/* tree is empty? insert new client to root */
	if (*tree == NULL)
	{
		supplier_node* new_supplier = ALLOC(supplier_node, sizeof(supplier_node));
		new_supplier->data = *sup_data;
		new_supplier->left = NULL;
		new_supplier->right = NULL;
		*tree = new_supplier;

		return true;
	}

	if (atoi(sup_data->au_dealer_number) == atoi((*tree)->data.au_dealer_number))
		return false;
	/* find place to add new car by client id */
	if (atoi(sup_data->au_dealer_number) < atoi((*tree)->data.au_dealer_number))
	{
		addNewSupplier(&(*tree)->left, sup_data);
		return true;
	}

	else if (atoi(sup_data->au_dealer_number) > atoi((*tree)->data.au_dealer_number))
	{
		addNewSupplier(&(*tree)->right, sup_data);
		return true;
	}

	return false;
}
/* get input from user and add new supplier*/
void getNewSupplier(supplier* new_supplier)
{
	
	
	/* populate new supplier data */
	get_user_input_num          (new_supplier->au_dealer_number, "Enter authorized dealer number: ", 10);
	get_user_input_unlimitStr   (new_supplier->suplier_name, "Enter suplier name: ");
	get_user_input_num          (new_supplier->suplier_phone_number, "Enter phone number: ", 10);
    get_user_input_num          (new_supplier->num_of_transactions, "Enter number of transactions: ", 5);
	get_user_input_num          (new_supplier->sumOf_num_of_transactions, "Enter sum of transactions: ", 10);
}

/* return 3 greatest suppliers*/
void printSuppliers(supplier_node* tree)
{
    if(!tree){
        return;
    }
    printf("business number:%s name:%s phone:%s deals:%s sum:%s \n", tree->data.au_dealer_number, tree->data.suplier_name, tree->data.suplier_phone_number, tree->data.num_of_transactions, tree->data.sumOf_num_of_transactions);
    printSuppliers(tree->left);
    printSuppliers(tree->right);
}

double averageOfSupplierMoney(supplier_node* head , int* numTransactions){

    int numTransactionsL,numTransactionsR;
    double avgL,avgR;

    if (!head){
        *numTransactions = 0;
        return 0;
    }


	/* calculate sum of transactions from my two child*/
    avgL = averageOfSupplierMoney(head->left , &numTransactionsL);
    avgR = averageOfSupplierMoney(head->right , &numTransactionsR);


    *numTransactions = numTransactionsL+numTransactionsR+1;

    return ((avgL*numTransactionsL + avgR*numTransactionsR + atoi(head->data.sumOf_num_of_transactions))/ *numTransactions);
}

supplier_node* minValueSupplierNode(supplier_node* tree)
{
    supplier_node* current = tree;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

/* delete one supplier by given name*/
supplier_node* deleteSupplier (supplier_node* tree, char* dealer_num)
{
	/*  */
	if (tree == NULL)
		return tree;

	/*  */
	if (atoi(dealer_num) < atoi(tree->data.au_dealer_number))
	{
        tree->left = deleteSupplier(tree->left, dealer_num);

	}
	/*  */
	else if (atoi(dealer_num) > atoi(tree->data.au_dealer_number))
        tree->right = deleteSupplier(tree->right, dealer_num);
	
	else {
        /* node with only one child or no child */
        if (tree->left == NULL)
		{
            root_sup = tree->right;
            free(tree);
            return root_sup;
		}
        else if (tree->right == NULL)
		{
            root_sup = tree->left;
            free(tree);
            return root_sup;
        }

		root_sup = minValueSupplierNode(tree->right);
		memcpy(&(tree->data.au_dealer_number), &(root_sup->data.au_dealer_number), 11);

		tree->right = deleteSupplier(tree->right, root_sup->data.au_dealer_number);
    }

    return tree;
}

/* delete all suppliers*/
void _deleteAllSuppliers (supplier_node* tree)
{
	/* delete all suppliers from tree */
	if (tree == NULL)
		return;
	_deleteAllSuppliers(tree->left);
	_deleteAllSuppliers(tree->right);

	free(tree);
}

void deleteAllSuppliers (supplier_node** ref_tree)
{
	_deleteAllSuppliers(*ref_tree);
  	*ref_tree = NULL;
}

char** threeGreatestSuppliers(supplier_node* head)
{   
    supplier_node* first;
	supplier_node* second;
	supplier_node* third;
	int i;
	char **lst = ACLLOC(char*, 3, sizeof(char) * 10);
    for (i = 0; i < 3; i++) { lst[i] = ACLLOC(char, 1, 11); }
    first = root_sup;
    second=root_sup->right;
    third=root_sup->right->right;
    
    if(root_sup==NULL)
    {
        return lst;
    }
    if(atoi(head->data.sumOf_num_of_transactions) > atoi(first->data.sumOf_num_of_transactions))
    {
        lst[0]=head->data.au_dealer_number;
    }
   else{
       lst[0]=first->data.au_dealer_number;
   }
    if((atoi(head->data.sumOf_num_of_transactions) > atoi(second->data.sumOf_num_of_transactions) && 
        (atoi(head->data.sumOf_num_of_transactions) != atoi(first->data.sumOf_num_of_transactions))))
    {
        lst[1]=head->data.au_dealer_number;
    }
    else{
        lst[1]=second->right->data.au_dealer_number;
    }
    if((atoi(head->data.sumOf_num_of_transactions) > atoi(third->right->right->data.sumOf_num_of_transactions) && 
            (atoi(head->data.sumOf_num_of_transactions) != atoi(first->data.sumOf_num_of_transactions))) &&
            (atoi(head->data.sumOf_num_of_transactions) != atoi(second->data.sumOf_num_of_transactions)))
    {
        lst[2]=head->data.au_dealer_number;
    }
    else{
            lst[2]=third->data.au_dealer_number;  
    }
    threeGreatestSuppliers(head->left);
    threeGreatestSuppliers(head->right);
    return lst;
}