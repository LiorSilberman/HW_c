#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include "get_input.h"

#define M 8000


typedef struct
{
	char* first_name;
	char* last_name;
	char client_id[10];
	char rented_car_id[8];
	int rent_date;
	int car_rent_time;
	char rent_price[4];

}client;

typedef struct client_node
{
	client data;
	struct client_node* next;
} client_node;

client_node* head_client;

/* defines array of client list*/
void createClientList ();

/* return if added succed or not*/
bool addNewClient ();
	
/* return number of clients with the same production year*/
int clientNumberWithGivenCarYear ();

/* print client list by given date. only for DAVIS company*/
#ifdef DAVIS
void printClientCarsForGivenRentDate();
#endif
/* return "1" if deleted succed*/
void deleteClient ();

/* return "1" if all clients deleted*/
void deleteAllClients ();


#endif