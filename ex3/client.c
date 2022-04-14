#include "client.h"

extern client clientList[M];
extern int counterClient;
void initClient(int i);

/*defines array of client list*/
void createClientList ()
{
	int i;
	counterClient = 0;
	for (i = 0; i < M; i++)
	{
		initClient(i);

	}
}

void initClient(int i)
{
	clientList[i].first_name[0] = '\0';
	clientList[i].last_name[0] = '\0';
	clientList[i].client_id = 0;
	clientList[i].rented_car_id = 0;
	clientList[i].rent_date = 0;
	clientList[i].car_rent_time = 0;
	clientList[i].rent_price = 0;
}
/*return if added succed or not*/
int addNewClient ()
{
	getInput_firstName(clientList[counterClient].first_name);
	getInput_lastName(clientList[counterClient].last_name);
	getInput_clientID(clientList[counterClient].client_id);
	getInput_rentedCarID(clientList[counterClient].rented_car_id);
	getInput_rentDate(clientList[counterClient].rent_date);
	getInput_carRentTime(clientList[counterClient].car_rent_time);
	getInput_rentPrice(clientList[counterClient].rent_price);
	counterClient++;
	printf("New client added\n");
	return 1;
}

/* return "1" if deleted succed*/
int deleteClient (int client_id)
{
	int i;
	if (!isValid_intLen(client_id , SIZE_NINE))
	{
		printf("invalid input\n");
		return 0;
	}
	for (i = 0; i < counterClient; i++)
	{
		if (client_id == clientList[i].client_id)
		{
				initClient(i);
				clientList[i] = clientList[counterClient-1];
				counterClient--;
				return 1;
		}
	}
	printf("client with ID = %d deleted\n",client_id);
	return 0;
}

/* return "1" if all clients deleted*/
int deleteAllClients ()
{
	int i;
	for (i = 0; i < M; i++)
	{
		initClient(i);
	}
	counterClient = 0;
	printf("All clients deleted\n");

	return 0;	
}