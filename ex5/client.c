#include "client.h"
#include "car.h"

client_node* getNewclient ();

/*defines array of client list*/
void createClientList ()
{
	head_client = NULL;
	printf("create client list\n");
}

bool addNewClient ()
{
	client_node* h = head_client;
	client_node* tmp = getNewclient();

	if (head_client == NULL)
	{
		head_client = tmp;
		return true;
	}
	while (h != NULL)
	{
		/* insert new client to list*/
		if (h->next == NULL)
		{
			h->next = tmp;
			break;
		}
		h = h->next;
	}
	
	printf("new client added\n");
	return true;
}

client_node* getNewclient ()
{
	client_node* tmp = ALLOC(client_node, sizeof(client_node));
	tmp->next = NULL;

	get_user_input_unlimitStr (tmp->data.first_name, "Enter first name: ");

	get_user_input_unlimitStr (tmp->data.last_name, "Enter last name: ");

	get_user_input_num(tmp->data.client_id, "Enter client id: ", SIZE_NINE);

    get_user_input_num(tmp->data.rented_car_id, "Enter rented car id: ", SIZE_SEVEN);

	tmp->data.rent_date = getInput_rentDate();

	getInput_carRentTime(tmp->data.car_rent_time);

	get_user_input_num(tmp->data.rent_price, "Enter car rent price: ", SIZE_THREE);

	return tmp;

}

/*return number of clients with the same production year*/
int clientNumberWithGivenCarYear () {

	int countclient = 0;
	char* producYear = (char*)malloc(sizeof(char)*5);
	client_node* tmp = head_client;
	car_node* tmp_car = head;
	printf("Insert car production year to check: ");
	scanf("%s", producYear);

	if (!isValid_intLen(producYear , 4))
	{
		printf("invalid input\n");
		return 0;
	}
	
	while (tmp != NULL)
	{
		while (tmp_car != NULL)
		{
			if (!strcmp(tmp_car->data.car_id, tmp->data.rented_car_id))
			{
				if (!strcmp(producYear, tmp_car->data.production_year))
				{
					countclient++;
				}
			}
			tmp_car = tmp_car->next;
		}
		tmp = tmp->next;

	}
	return countclient;
}

/* print client list by given date. only for DAVIS company*/
#ifdef DAVIS
void printClientCarsForGivenRentDate()
{
	int dd, mm, yy;
	client_node* tmp = head_client;
	

	while (tmp != NULL)
	{
		if(!strcmp(tmp->data.rent_date, (dd,mm,yy)))
		{
            printf("%s %s - %s\n",tmp->data.first_name, tmp->data.last_name, tmp->data.rented_car_id);
        }
        tmp = tmp->next;
    }
}
#endif
/*return "1" if deleted succed*/
void deleteClient () {

	client_node* tmp = head_client;
	client_node* prev;

	char* clientID = (char*)malloc(sizeof(char)*10);

	printf("Enter client ID to delete: ");
	scanf("%s", clientID);

	if (!isValid_intLen(clientID , SIZE_NINE))
	{
		printf("invalid input\n");
		return;
	}

	/* if head node need to be deleted*/
	if (tmp != NULL && (!strcmp(tmp->data.client_id, clientID)))
	{
		head_client = tmp->next;
		free(tmp);
		return;
	}

	/* find node with car id*/
	while (tmp != NULL && (strcmp(tmp->data.client_id, clientID)))
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

/* return "1" if all clients deleted*/
void deleteAllClients ()
{
	while (head_client != NULL)
	{
		free(head_client);
		head_client = head_client->next;
	}

	if (head_client == NULL)
		return;
}