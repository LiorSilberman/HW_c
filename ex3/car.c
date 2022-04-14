
#include "car.h"
extern car carList[N];
extern int counter;
void initCar(int i);

/* create car list*/
void createCarList () 
{
	int  i;
	counter = 0;
	for (i = 0; i < N; i++)
	{
		initCar(i);
	}
}

void initCar(int i){

	carList[i].car_id = 0;
	carList[i].chassis = 0;
	carList[i].manufacturer_name[0] = '\0';
	carList[i].model_name[0] = '\0';
	carList[i].color[0] = '\0';
	carList[i].production_year = 0;
	carList[i].entry_road_year = 0;
	carList[i].supplier_price = 0;
	carList[i].current_price = 0;
	carList[i].engine_capacity = 0;
}

/* return "1" if succed*/
int addNewCar ()
{
	
	carList[counter].car_id = getInput_carID();
	
	carList[counter].chassis = getInput_chassis();
	
	getInput_manufacturerName(carList[counter].manufacturer_name);
	
	getInput_modelName(carList[counter].model_name);
	
	getInput_color(carList[counter].color);
	
	carList[counter].production_year = getInput_productionYear ();

    carList[counter].entry_road_year = getInput_entryRoadYear();

	carList[counter].supplier_price = getInput_supplierPrice();

	carList[counter].current_price = getInput_currentPrice();

	carList[counter].engine_capacity = getInput_engineCapacity();
	
	counter++;
	printf("new car added\n");
	return 1;
}

/*  return number of cars with same engine capacity*/
int carNumberWithGivenCapacity (int engine_cap) {

	int countCar = 0 ,i;
	if (!isValid_intLen(engine_cap , SIZE_FIVE-1)){
		printf("invalid input\n");
		return -1;
	}
	for (i=0 ; i < counter; i++){
		if ( carList[i].engine_capacity == engine_cap )
			countCar++;
	}
	return countCar;

}

/*return number of clients with the same production year*/
int carNumberWithGivenYear (int year)
{
	int countCar = 0 ,i;
	if (!isValid_intLen(year , SIZE_FIVE-1)){
		printf("invalid input\n");
		return -1;
	}
	for (i=0 ; i < counter; i++){
		if ( carList[i].production_year == year)
			countCar++;
	}
	return countCar;

}

/*  return if "1" if succed*/
int deleteCar (int carID)
{
	int i;
	if (!isValid_intLen(carID , SIZE_SEVEN)){
		printf("invalid input\n");
		return 0;
	}

	for (i = 0; i < counter; i++)
	{
		if (carList[i].car_id == carID)
		{
			initCar(i);
			carList[i] = carList[counter-1];
			counter--;
			return 1;
		}
	}
	return 0;
}

/*  return "1" if succed */
int deleteAllCars () 
{
	int  i;
	for (i = 0; i < counter; i++)
	{
		initCar(i);
	}
	counter = 0;
	return 0;	
}