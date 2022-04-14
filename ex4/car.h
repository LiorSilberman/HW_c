#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"
#define N 10000

typedef struct 
{
	char car_id[8];

	char chassis[6];

	char manufacturer_name[100];
	
	char model_name[100]; /* ??????????????*/
	
	char production_year[5];

	char color[100];

	char engine_capacity[5];	

	char entry_road_year[5];
	
	int supplier_price;

	int current_price;

}car;

typedef struct car_node{
	car data;
	struct car_node* next;
}car_node;

car_node* head = NULL;
int counter;

void printCarList();

/*create car list*/
void createCarList ();

/*return "1" if succed*/
bool addNewCar ();


/* return number of cars with same engine capacity*/
/*int carNumberWithGivenCapacity (const char* engine_capacity);*/

/*int carNumberWithGivenYear (const char* year);*/

/* return if "1" if succed*/
/*int deleteCar (const char* car_id);*/

/*/ return "1" if succed */
int deleteAllCars ();



#endif