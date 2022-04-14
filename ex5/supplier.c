
#include "supplier.h"
supplier_node* getNewSupplier();

/*create supplier list*/
void createSupplierList () 
{
	head_sup = NULL;
	printf("create supplier list\n");
}

bool addNewSupplier ()
{
	supplier_node* h = head_sup;
	supplier_node* tmp = getNewSupplier();
	int tmp_sum_transactions = atoi (tmp->data.sumOf_num_of_transactions);

	if (head_sup == NULL)
	{
		head_sup = tmp;
		return true;
	}

	while (h != NULL)
	{

		/*if the new node insert to begin*/
		if (tmp_sum_transactions > atoi (head_sup->data.sumOf_num_of_transactions))
		{
			tmp->next = head_sup;
			head_sup = tmp;
			break;
		}
		/*if the new node insert to middel*/
		if (h->next != NULL && atoi(h->next->data.sumOf_num_of_transactions) < tmp_sum_transactions)
		{
			tmp->next = h->next;
			h->next = tmp;
			break;
		}

		/*if the new node insert to end*/
		if (h->next == NULL)
		{
			h->next = tmp;
			break;
		}
		h = h->next;
	}

	return true;


		
}
/* get input from user and add new supplier*/
supplier_node* getNewSupplier ()
{
	supplier_node* tmp = ALLOC(supplier_node,sizeof(supplier_node));
	tmp->next = NULL;

	get_user_input_num(tmp->data.au_dealer_number, "Enter authorized dealer number: ", SIZE_TEN);

	get_user_input_unlimitStr(tmp->data.suplier_name,"Enter suplier name: ");

	get_user_input_num(tmp->data.suplier_phone_number, "Enter phone number: ", SIZE_TEN);

    get_user_input_num(tmp->data.num_of_transactions, "Enter number of transactions: ", SIZE_FIVE);

	get_user_input_num(tmp->data.sumOf_num_of_transactions, "Enter sum of transactions: ", SIZE_TEN);

	printf("new Supplier added\n");
	return tmp;
}

/* return 3 greatest suppliers*/
char** threeGreatestSuppliers ()
{
	int i,j = 0;
	supplier_node* tmp = head_sup;
	char** lst = ACLLOC(char*, 3, sizeof(char)*11);
	for (i = 0; i < 3; i++) {lst[i] = ACLLOC(char, 1, 11);}
	
	printf("Three greatest suppliers are: \n");

	while (tmp != NULL && j < 3)
	{
		lst[j] = tmp->data.au_dealer_number;
		tmp = tmp->next;
		j++;
	}
	return lst;
}

char** threeGreatestSuppliers_REC (supplier_node* tmp, int counter)
{
	int i;
	char** lst = ACLLOC(char*, 3, sizeof(char) * 10), **temp;
    for(i = 0; i < 3; i++) {lst[i] = ACLLOC(char, 1, 11);}

	/* if lined list is empty*/
	if (head_sup == NULL)
		return lst;

	/* if we got to the end*/
	if(counter == 3 || tmp->next == NULL)
	{
        lst[counter] = tmp->data.au_dealer_number;
        return lst;
	}
	lst[counter] = tmp->data.au_dealer_number;
    tmp = tmp->next;
	temp = threeGreatestSuppliers_REC(tmp, counter+1);

	for(i = 0; i < 3; i++)
	{
        if (!strcmp(lst[i], "") && strcmp(temp[i], ""))
            lst[i] = temp[i];
    }

    return lst;
}
#ifdef DAVIS
void printSuppliers (supplier_node* tmp)
{
	while (tmp != NULL)
	{
		printf("name: %s\ndealer number: %s\nPhone number: %s\nNum of transactions: %s\nSum of transactions: %s\n\n",
		 tmp->data.suplier_name, tmp->data.au_dealer_number, tmp->data.suplier_phone_number, tmp->data.num_of_transactions, tmp->data.sumOf_num_of_transactions);
		 tmp = tmp->next;
	} 
}
#endif
/* delete one supplier by given name*/
void deleteSupplier ()

{
	supplier_node* tmp = head_sup;
	supplier_node* prev;
	char* au_dealer_num = (char*)malloc(sizeof(char)*11);

	printf("Enter supplier to delete: ");
	scanf("%s", au_dealer_num);

	if (!isValid_intLen(au_dealer_num, 10))
		return;

	/* if head node need to be deleted*/
	if (tmp != NULL && (!strcmp(tmp->data.au_dealer_number, au_dealer_num)))
	{
		head_sup = tmp->next;
		free(tmp);
		return;
	}
	/* find node with car id*/
	while (tmp != NULL && (strcmp(tmp->data.au_dealer_number, au_dealer_num)))
	{
		prev = tmp;
		tmp = tmp->next;
	}

	/* key found?*/
	if (tmp == NULL)
		return;

	/* kepp track of list*/
	prev->next = tmp->next;

	/* delete node*/
	free(tmp);
}

/* delete all suppliers*/
void deleteAllSuppliers ()
{
	while (head_sup != NULL)
	{
		free(head_sup);
		head_sup = head_sup->next;
	}

	if (head_sup == NULL)
		return;
}