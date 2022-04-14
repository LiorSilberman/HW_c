#ifndef IS_VALID_H
#define IS_VALID_H

#include <string.h>
#include <ctype.h>

int isValid_intLen (int num, int len);

int isValid_sizeName (char* name, int len);

int isValid_exactName (char* name, int len);

int isValid_maxSize (int price);

int isValid_rentDate (int date);

int isValid_carRentTime (int time);

int isValid_supplierPrice (int price);

int isValid_currentPrice (int price);

    
/* functions to check input for car details.*/
/*int isValid_carID (int carID);

int isValid_chassis (int chassis);

int isValid_manufacturerName (char* name);

int isValid_modelName (char* name);

int isValid_color (char* color);

int isValid_productionYear (int year);

int isValid_entryRoadYear (int year);

int isValid_supplierPrice (int price);

int isValid_currentPrice (int price);

int isValid_engineCapacity (int engineCapacity);

//functions to check input for supplier details.

int isValid_auDealerNumber (int number);

int isValid_SuplierName (char* name);

int isValid_SuplierPhoneNumber (int phoneNumber);

int isValid_NumOfTransactions (int number);

int isValid_SumOfNumOfTransactions (int number);

//functions to check input for client details.

int isValid_firstName (char* fName);

int isValid_lastName (char* lName);

int isValid_clientID (int clientID);

int isValid_rentedCarID (int carID);

int isValid_rentDate (int date);

int isValid_carRentTime (int time);

int isValid_rentPrice (int price);
*/

#endif