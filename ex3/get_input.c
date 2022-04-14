
#include "get_input.h"

/*  functions to get car details from user.*/

int getInput_carID ()
{
	int id;
	
	do{
		printf("Enter car id\n");
		scanf("%d",&id);
	}while (!isValid_intLen (id, 7));
	
	return id;
	
}

int getInput_chassis ()
{
	int chassis;
	
	do
	{
		printf("Enter chassis number:\n");
		scanf("%d", &chassis);
	}
	while (!isValid_intLen (chassis, 5));
	
	return chassis;
}	
	
int getInput_productionYear ()
{
	int productionYear;
	
	do
	{
		printf("Enter production year:\n");
		scanf("%d", &productionYear);
	}
	while (!isValid_intLen (productionYear, 4));
	
	return productionYear;
}

char* getInput_manufacturerName (char manufacturerName[])
{
	do{
		printf("Enter manufacturer name:\n");
		scanf("%s", manufacturerName);
	}while (!isValid_sizeName (manufacturerName, SIZE_TEN));
	
	return manufacturerName;
}

char* getInput_modelName (char modelName[])
{
	
	do{
		printf("Enter model name:\n");
		scanf("%s", modelName);
	}while (!isValid_sizeName (modelName, SIZE_TEN));
	
	return modelName;
}

char* getInput_color (char color[])
{

	do{
		printf("Enter color:\n");
		scanf("%s", color);
	}while (!isValid_sizeName (color, SIZE_SEVEN));
	
	return color;
}



int getInput_entryRoadYear ()
{
	int entryRoadYear;
	
	do
	{
		printf("Enter entry road year:\n");
		scanf("%d", &entryRoadYear);
	}
	while (!isValid_intLen (entryRoadYear, 4));
	
	return entryRoadYear;
}

int getInput_supplierPrice ()
{
	int suplierPrice;
	
	do																	/*  להשלים*/
	{
		printf("Enter suplier price:\n");
		scanf("%d", &suplierPrice);
	}
	while (!isValid_supplierPrice (suplierPrice));
	
	return suplierPrice;
}

int getInput_currentPrice ()
{
	int currentPrice;
	
	do																	/*  להשלים*/
	{
		printf("Enter current price:\n");
		scanf("%d", &currentPrice);
	}
	while (!isValid_currentPrice (currentPrice));
	
	return currentPrice;
}

int getInput_engineCapacity ()
{
	int engineCapacity;
	
	do
	{
		printf("Enter engine capacity:\n");
		scanf("%d", &engineCapacity);
	}
	while (!isValid_intLen (engineCapacity, 4));
	
	return engineCapacity;
}


/*  functions to get supplier details from user.*/

int getInput_auDealerNumber ()
{
	int auDealerNumber;
	
	do
	{
		printf("Enter authorized dealer number:\n");
		scanf("%d", &auDealerNumber);
	}
	while (!isValid_intLen (auDealerNumber, 10));
	
	return auDealerNumber;
}

char* getInput_suplierName (char suplierName[])
{
	do{
		printf("Enter suplier name:\n");
		scanf("%s", suplierName);
	}while (!isValid_exactName (suplierName, SIZE_FIVE));
	
	return suplierName;
}

int getInput_suplierPhoneNumber ()
{
	int suplierPhoneNumber;
	
	do
	{
		printf("Enter suplier phone number:\n");
		scanf("%d", &suplierPhoneNumber);
	}
	while (!isValid_intLen (suplierPhoneNumber, SIZE_TEN));
	
	return suplierPhoneNumber;
}

int getInput_numOfTransactions ()
{
	int numOfTransactions;
	
	do
	{
		printf("Enter num Of Transactions:\n");
		scanf("%d", &numOfTransactions);
	}
	while (!isValid_intLen (numOfTransactions, SIZE_FIVE));
	
	return numOfTransactions;
}

int getInput_sumOfNumOfTransactions ()
{
	int sumOfNumOfTransactions;
	
	do
	{
		printf("Enter sum of transactions:\n");
		scanf("%d", &sumOfNumOfTransactions);
	}
	while (!isValid_intLen (sumOfNumOfTransactions, SIZE_TEN));
	
	return sumOfNumOfTransactions;
}

/*  functions to get client details from user.*/

char* getInput_firstName (char firstName[])
{
	do{
		printf("Enter first name:\n");
		scanf("%s", firstName);
	}while (!isValid_sizeName (firstName, SIZE_TWENTY));
	
	return firstName;
}


char* getInput_lastName (char lastName[])
{
	do{
		printf("Enter last name:\n");
		scanf("%s", lastName);
	}while (!isValid_sizeName (lastName, SIZE_TWENTY));
	
	return lastName;
}

int getInput_clientID ()
{
	int clientID;
	
	do
	{
		printf("Enter client ID:\n");
		scanf("%d", &clientID);
	}
	while (!isValid_intLen (clientID, SIZE_NINE));
	
	return clientID;
}

int getInput_rentedCarID ()
{
	int rentedCarID;
	
	do
	{
		printf("Enter rented car ID:\n");
		scanf("%d", &rentedCarID);
	}
	while (!isValid_intLen (rentedCarID, SIZE_SEVEN));
	
	return rentedCarID;
}

int getInput_rentDate ()
{
	int rentDate;
	
	do
	{
		printf("Enter rented date:\n");
		scanf("%d", &rentDate);												
	}
	while (!isValid_rentDate (rentDate));
	
	return rentDate;
}

char* getInput_carRentTime ()
{
	/*
	int carRentTimeHour, carRentTimeMinute;
	char timeRent[5];
	
	do
	{
		printf("Enter car rent hour time:\n");
		scanf("%d", &carRentTimeHour);
		printf("Enter car rent minute time:\n");
		scanf("%d", &carRentTimeMinute);
	}
	while (!isValid_carRentTime (carRentTimeHour, carRentTimeMinute));
	
	
		
			
	return carRentTime;
	*/
	return NULL;
}

int getInput_rentPrice ()
{
	int rentPrice;
	
	do
	{
		printf("Enter car rent price:\n");
		scanf("%d", &rentPrice);
	}
	while (!isValid_intLen (rentPrice, SIZE_THREE));
	
	return rentPrice;
}