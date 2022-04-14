#include "car.h"
#include "supplier.h"
#include "client.h"

int main ()
{

    createCarList();
    addNewCar();
    addNewCar();
    printCarList();
    /* check supplier functions
    addNewSupplier();
    addNewSupplier();
    addNewSupplier();
    */
  /*  deleteSupplier("lior");
    threeGreatestSuppliers("1111111111", "1111111112", "1111111113");*/
    
    
    /* check car and client functions*/
    /*
    if(!addNewCar())
        return 1;
    if(!addNewCar())
        return 1;
    printf("\ncar with same capacity: %d\n",carNumberWithGivenCapacity("1111"));
    deleteCar("1234567");
    printf("\ncar with same capacity: %d\n",carNumberWithGivenCapacity("1111"));

    addNewClient();
    addNewClient();
    printf("there are %d clients with same year.\n", clientNumberWithGivenCarYear("2020"));
    deleteAllClients();
    printf("there are %d clients with same year.\n", clientNumberWithGivenCarYear("2020"));
*/
    return 0;
}