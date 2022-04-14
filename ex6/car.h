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
	char* manufacturer_name;
	char* model_name;
	char production_year[5];
	char* color;
	char engine_capacity[5];	
	char entry_road_year[5];
	int supplier_price;
	int current_price;
}car;

typedef struct car_node
{
	car data;
	struct car_node* left;
	struct car_node* right;
}car_node;

car_node* root;


void createCarList ();

bool addNewCar (car_node**, car*);
void getNewCar(car*);
car_node* search(car_node* tree, char* id);
car_node* minValueNode(car_node* tree);

car_node* deleteCar (car_node*, char* car_id);

/* Deletes a tree and sets the root as NULL */
void deleteAllCars(struct car_node** tree_ref);

int carNumberWithGivenCapacity(car_node*, char*, int);


#endif