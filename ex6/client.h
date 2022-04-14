#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include "get_input.h"
#include "car.h"

#define M 8000


typedef struct
{
	char* first_name;
	char* last_name;
	char client_id[10];
	char rented_car_id[8];
	char rent_date[11];
	int car_rent_time;
	char rent_price[4];

}client;

typedef struct client_node
{
	client data;
	struct client_node* left;
	struct client_node* right;
} client_node;

typedef struct client_node_list
{
	client data;
	struct client_node* next;
} client_node_list;

client_node* root_client;
client_node_list* head;

/* defines array of client list*/
void createClientList ();

void getNewClient(client*);
/* return if added succed or not*/
bool addNewClient (client_node** tree, client* new_client_data);

/* search if value in tree */
bool searchClient(client_node* tree, char* id);

client_node* findClientById (client_node** tree, char* id);

client_node* findClientByRentDate (client_node** tree, char* date);
	
/* return number of clients with the same production year*/
int clientNumberWithGivenCarYear (client_node* client_tree, car_node* car_tree, char* year, int counter);

/* get minimum node value */
client_node* minValueClientNode(client_node* tree);

/* delete car by client id */
client_node* deleteClient (client_node* tree, char* ID);

/* return "1" if all clients deleted*/
void deleteAllClients(client_node** tree_ref);

#endif