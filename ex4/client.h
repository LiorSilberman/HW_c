#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include "get_input.h"

#define M 8000


typedef struct
{
	char client_id[9];
	char test[1];
	char first_name[20];
	char test1[1];
	char last_name[20];
	char test2[1];
	char rented_car_id[7];
	char test3[1];
	int rent_date;
	char test4[1];
	int car_rent_time;
	char test5[1];
	char rent_price[3];
	char test6[1];
	
	
}client;

client clientList[M];
int counterClient;

/* defines array of client list*/
void createClientList ();

/* return if added succed or not*/
int addNewClient ();
	
/* return number of clients with the same production year*/
int clientNumberWithGivenCarYear (char* year);

/* return "1" if deleted succed*/
int deleteClient (char* client_id);

/* return "1" if all clients deleted*/
int deleteAllClients ();


#endif