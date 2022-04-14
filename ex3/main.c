#include "car.h"
#include "client.h"
int main ()
{
	createCarList();
    addNewCar();
    addNewCar();

    printf("num car year = %d\n",carNumberWithGivenYear(1111));
    deleteCar(1234567);
    printf("num car year = %d\n",carNumberWithGivenYear(1111));

    /*createClientList();
    addNewClient();
    addNewClient();
    deleteClient(316456623);*/

    return 0;
}