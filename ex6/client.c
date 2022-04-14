#include "client.h"


void getNewClient (client* new_client);

/*defines array of client list*/
void createClientList ()
{
	root = NULL;
	printf("Client list created\n");
}

bool addNewClient (client_node** tree, client* new_client_data)
{
	/* create new client */
	if (new_client_data == NULL)
	{
		new_client_data = ALLOC(client, sizeof(client));
		getNewClient(new_client_data);
	}

	/* tree is empty? insert new client to root */
	if (*tree == NULL)
	{
		client_node* new_client = ALLOC(client_node, sizeof(client_node));
		new_client->data = *new_client_data;
		new_client->left = NULL;
		new_client->right = NULL;
		*tree = new_client;

		return true;
	}

	/* find place to add new car by client id */
	if (atoi(new_client_data->client_id) < atoi((*tree)->data.client_id))
		addNewClient(&(*tree)->left, new_client_data);

	else if (atoi(new_client_data->client_id) > atoi((*tree)->data.client_id))
		addNewClient(&(*tree)->right, new_client_data);

	return false;
}

void getNewClient (client* new_client)
{
	/* populate new client data */
	get_user_input_unlimitStr (new_client->first_name, "Enter first name: ");
	get_user_input_unlimitStr (new_client->last_name, "Enter last name: ");
	get_user_input_num        (new_client->client_id, "Enter client id: ", SIZE_NINE);
    get_user_input_num        (new_client->rented_car_id, "Enter rented car id: ", SIZE_SEVEN);
	getInput_rentDate         (new_client->rent_date, "Enter date (DD/MM/YYYY format): ");
	getInput_carRentTime      (new_client->car_rent_time);
	get_user_input_num        (new_client->rent_price, "Enter car rent price: ", SIZE_THREE);
}

bool searchClient(client_node* tree, char* id)
{
    if (tree == NULL)
        return false;

    if(atoi(id) < atoi(tree->data.rented_car_id))
        searchClient(tree->left, id);

    else if(atoi(id) > atoi(tree->data.rented_car_id))
        searchClient(tree->right, id);

    else if (atoi(id) == atoi(tree->data.rented_car_id))
	{
        return true;
	}

	return false;
}



/*return number of clients with the same production year*/
int clientNumberWithGivenCarYear (client_node* client_tree, car_node* car_tree, char* year, int counter)
{
	if (car_tree)
	{
		if (!strcmp(car_tree->data.production_year, year))
		{
			memcpy(client_tree->data.rented_car_id, car_tree->data.car_id, 10);
			if (searchClient(client_tree, car_tree->data.car_id))
			{
				counter++;
			}
		}
		counter = clientNumberWithGivenCarYear (client_tree, car_tree->left, year, counter);
		counter = clientNumberWithGivenCarYear (client_tree, car_tree->right, year, counter);
	}
		
	return counter;
}

client_node* findClientById (client_node** tree, char* id)
{
	if (!(*tree))
	{
        return NULL;
	}
	if (atoi(id) == atoi((*tree)->data.client_id))
	{
        return *tree;
	}
    else if(atoi(id) < atoi((*tree)->data.client_id))
	{
        findClientById(&((*tree)->left), id);
	}
    else if(atoi(id) > atoi((*tree)->data.client_id))
	{
        findClientById(&((*tree)->right), id);
	}
	return NULL;
}


client_node* minValueClientNode(client_node* tree)
{
    client_node* current = tree;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

/*return "1" if deleted succed*/
client_node* deleteClient (client_node* tree, char* ID)
{
	/*  */
	if (tree == NULL)
		return tree;

	/*  */
	if (atoi(ID) < atoi(tree->data.client_id))
	{
        tree->left = deleteClient(tree->left, ID);

	}
	/*  */
	else if (atoi(ID) > atoi(tree->data.client_id))
        tree->right = deleteClient(tree->right, ID);
	
	else {
        /* node with only one child or no child */
        if (tree->left == NULL)
		{
            root_client = tree->right;
            free(tree);
            return root_client;
		}
        else if (tree->right == NULL)
		{
            root_client = tree->left;
            free(tree);
            return root_client;
        }

		root_client = minValueClientNode(tree->right);
		memcpy(&(tree->data.client_id), &(root_client->data.client_id), 10);

		tree->right = deleteClient(tree->right, root_client->data.client_id);
    }

    return tree;
}

/* return "1" if all clients deleted*/
void _deleteAllClients (client_node* tree)
{
	/* delete all clients from tree */
	if (tree == NULL)
		return;
	_deleteAllClients(tree->left);
	_deleteAllClients(tree->right);

	free(tree);
		
}

void deleteAllClients(client_node** tree_ref)
{
  	_deleteAllClients(*tree_ref);
  	*tree_ref = NULL;
}