#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include "get_input.h"
#define N 10000

typedef struct 
{
	int car_id;
	int chassis;
	char manufacturer_name[10];
	char model_name[10];
	char color[7];
	int production_year;
	int entry_road_year;
	int supplier_price;
	int current_price;
	int engine_capacity;
	
	
}car;

car carList[N];
int counter;

/* create car list*/
void createCarList ();

/* return "1" if succed*/
int addNewCar ();

/*return number of cars with same engine capacity*/
int carNumberWithGivenCapacity (int engine_capacity);

int carNumberWithGivenYear (int year);

/* return if "1" if succed*/
int deleteCar (int car_id);

/* return "1" if succed */
int deleteAllCars ();



#endif