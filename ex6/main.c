#include "car.h"
#include "client.h"
#include "supplier.h"
int main ()
{
    int counter = 0, numTransactions = 0;
    int choice, choice_car, choice_sup, choice_client, i; 
    char engine_cap[5], car_id[8], producYear[5], client_id[10], au_dealer_num[11];
    char** three;

    while (choice != 4)
    {
        printf("'1' for car.\n'2' for supplier.\n'3' for client.\n'4' for exit.\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                while (choice_car != 5)
                {
                    printf("Cars manager\n Press '1' to add a new car\n Press '2' to get the number of cars with the same engine capacity\n Press '3' to delete car\n Press '4' to delete all cars\n Press '5' for exit.\n");
                    scanf("%d",&choice_car);
                    switch(choice_car)
                    {
                        case 1:
                            addNewCar(&root, NULL);
                            break;
                        case 2:
                            
                        
                            do
                            {
                                printf("Please insert engine capacity to check: ");
                                scanf("%s", engine_cap);
                        
                            } while (!isValid_intLen(engine_cap , 4));

                            printf("cars with same engine capacity: %d\n", carNumberWithGivenCapacity(root, engine_cap, counter));
                            break;
                        case 3:
                            do
                            {
                                printf("Enter car ID to delete: ");
                                scanf("%s", car_id);
                            }
                            while (!isValid_intLen(car_id , 7));

                            deleteCar(root, car_id);
                            printf("car '%s' deleted\n", car_id);
                            break;

                        case 4:
                            deleteAllCars(&root);
                            break;

                        case 5:
                            break;

                        default:
                            printf("\nYou entered a wrong number.\n\n");
                    }
                }
                break;

            case 2:
                while (choice_sup != 7)
                {
                    printf("Suppliers manager \n Press '1' to add a new supplier\n Press '2' to get three greatest suppliers list\n Press '3' to print all suppliers\n Press '4' to delete supplier \n Press '5' to delete all suppliers\n Press '6' for average of suppliers money\n Press '7' for exit.\n");
                    scanf("%d",&choice_sup);

                    switch(choice_sup)
                    {
                        case 1:
                            addNewSupplier(&root_sup, NULL);
                            break;
                        
                        case 2:
                            
                            three = threeGreatestSuppliers(root_sup);
                            for (i = 0; i < 3; i++)
                                printf("%s\n",three[0]);


                        case 3:
                            printSuppliers(root_sup);
                            break;

                        case 4:
                            do{
                                printf("Enter supplier to delete: ");
                                scanf("%s", au_dealer_num);

                            }while (!isValid_intLen(au_dealer_num, 10));

                            deleteSupplier(root_sup, au_dealer_num);
                            break;
                        
                        case 5:
                            deleteAllSuppliers(&root_sup);
                            break;
                        
                        case 6:
                            printf("Average is: %.2f", averageOfSupplierMoney(root_sup, &numTransactions));
                            break;
                        
                        case 7:
                            break;

                        default:
                            printf("\nYou entered a wrong number.\n\n");
                    }
                }
                break;
            case 3:
                while (choice_client != 7)
                {
                    printf("clients manager \n Press '1' to add a new client\n Press '2' to get number of clients with given car year\n Press '3' to print clients cars with the same given date\n Press '4' to find client\n Press '5' delete client \n Press '6' to delete all clients\n Press '7' for exit.\n");
                    scanf("%d",&choice_client);
                    switch(choice_client)
                    {
                        case 1:
                            addNewClient(&root_client, NULL);
                            break;

                        case 2:
                            
                            do{
                                printf("Insert car production year to check: ");
                                scanf("%s", producYear);

                            } while (!isValid_intLen(producYear , 4));

                            printf("Clients with same production year: %d\n",  clientNumberWithGivenCarYear(root_client, root, producYear, counter));
                            break;
                        
                        case 3:
                            break;

                        case 4:
                            break;

                        case 5:
                            do{
                                printf("Enter client id to delete: ");
                                scanf("%s", client_id);

                            }while (!isValid_intLen(client_id, 9));

                            deleteClient(root_client, client_id);
                            break;

                        case 6:
                            deleteAllClients(&root_client);
                            break;

                        case 7:
                            break;

                        default:
                            printf("\nYou entered a wrong number.\n\n");
                    }
                }
                break;
        }
    }
    return 0;
}