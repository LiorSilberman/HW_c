#ifndef GET_INPUT_H
#define GET_INPUT_H
#include <stdio.h>
#include "isValid.h"

#define SIZE_TEN 10
#define SIZE_SEVEN 7
#define SIZE_FIVE 5
#define SIZE_TWENTY 20
#define SIZE_NINE 9
#define	SIZE_THREE 3


/*  functions to get car details from user.*/

int getInput_carID ();

int getInput_chassis ();

char* getInput_manufacturerName ();

char* getInput_modelName ();

char* getInput_color ();

int getInput_productionYear ();

int getInput_entryRoadYear ();

int getInput_supplierPrice ();

int getInput_currentPrice ();

int getInput_engineCapacity ();

/*  functions to get supplier details from user.*/

int getInput_auDealerNumber ();

char* getInput_SuplierName ();

int getInput_SuplierPhoneNumber ();

int getInput_NumOfTransactions ();

int getInput_SumOfNumOfTransactions ();

/*  functions to get client details from user.*/

char* getInput_firstName ();

char* getInput_lastName ();

int getInput_clientID ();

int getInput_rentedCarID ();

int getInput_rentDate ();

char* getInput_carRentTime ();

int getInput_rentPrice ();


#endif