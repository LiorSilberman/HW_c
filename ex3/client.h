#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include "get_input.h"
#define M 8000


typedef struct
{
	char first_name[20];
	char last_name[20];
	int client_id;
	int rented_car_id;
	int rent_date;
	int car_rent_time;
	int rent_price;
	
	
}client;

client clientList[M];
int counterClient;

/* defines array of client list*/
void createClientList ();

/* return if added succed or not*/
int addNewClient ();
	
/*return number of clients with the same production year*/
int clientNumberWithGivenCarYear ();

/*return "1" if deleted succed*/
int deleteClient (int client_id);

/* return "1" if all clients deleted*/
int deleteAllClients ();


#endif