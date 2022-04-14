#include "client.h"
#include "car.h"

extern client clientList[M];
extern int counterClient;
void initClient(int i);

/*defines array of client list*/
void createClientList ()
{
	int  i;
	counterClient = 0;
	for (i = 0; i < M; i++)
	{
		initClient(i);
	}
}

/*return if added succed or not*/
void initClient (int i) {
	clientList[i].first_name[0] = '\0';
	clientList[i].last_name[0] = '\0';
	clientList[i].client_id[0] = '\0';
	clientList[i].rented_car_id[0] = '\0';
	clientList[i].rent_date = 0;
	clientList[i].car_rent_time = 0;
	clientList[i].rent_price[0] = '\0';
}

int addNewClient ()
{
	
	get_user_input_string (clientList[counterClient].first_name, "Enter first name: " , SIZE_TWENTY);

	get_user_input_string (clientList[counterClient].first_name, "Enter last name: " , SIZE_TWENTY);

	get_user_input_num(clientList[counterClient].client_id, "Enter client id: ", SIZE_NINE);

    get_user_input_num(clientList[counterClient].rented_car_id, "Enter rented car id: ", SIZE_SEVEN);

	clientList[counterClient].rent_date = getInput_rentDate();

	getInput_carRentTime(clientList[counterClient].car_rent_time);

	get_user_input_num(clientList[counterClient].rent_price, "Enter car rent price: ", SIZE_THREE);
	
	counterClient++;
	printf("new client added\n");
	return 0;
}
	
/*return number of clients with the same production year*/
/*int clientNumberWithGivenCarYear (char* year) {
	int countClient = 0 ,i,j;
	if (!isValid_intLen(year , 4)){
		printf("invalid input\n");
		return 0;
	}

	for (i=0 ; i < counter; i++)
	{
		if (!strcmp(carList[i].production_year, year))
		{
			for (j=0; j < counterClient; j++)
			{
				if (!strcmp(carList[i].car_id, clientList[j].rented_car_id))
				{
					countClient++;
				}
			}
		}
	}
	return countClient;
}*/

/*return "1" if deleted succed*/
int deleteClient (char* client_id) {

	int i;
	if (!isValid_intLen(client_id , SIZE_NINE)){
		printf("invalid input\n");
		return 0;
	}
	
	for (i = 0; i < counterClient; i++)
	{
		if (!strcmp(clientList[i].client_id, client_id))
		{
			initClient(i);
			clientList[i] = clientList[counterClient-1];
			counterClient--;
			return 0;
		}
	}
	return 1;
}

/* return "1" if all clients deleted*/
int deleteAllClients ()
{
	int  i;
	for (i = 0; i < counterClient; i++)
	{
		initClient(i);
	}
	counterClient = 0;
	return 0;	
}