
#include "car.h"

extern int counter;
car_node* getNewCar();
void initCar(int i);

/*create car list*/
void createCarList ()
{
	head = NULL;
	printf("create car list\n");
}
/* initialize car list*/
/*void initCar(int i){

	carList[i].car_id[0] = '\0';
	carList[i].chassis[0] = '\0';
	carList[i].manufacturer_name[0] = '\0';
	carList[i].model_name[0] = '\0';
	carList[i].color[0] = '\0';
	carList[i].production_year[0] = '\0';
	carList[i].entry_road_year[0] = '\0';
	carList[i].supplier_price = 0;
	carList[i].current_price = 0;
	carList[i].engine_capacity[0] = '\0';
}*/

/* return "1" if succed*/


bool addNewCar ()
{
	car_node* h = head;

	car_node* tmp = getNewCar();
	int tmp_prodeYear = atoi(tmp->data.production_year);
	if (head == NULL){
		head = tmp ;
		return true;
	}



	while (h != NULL ){
		
		/*if the new node insert to begin*/
		if (tmp_prodeYear < atoi (h->data.production_year)) {
			tmp = head;
			head = tmp;
			break;
		}
			/*if the new node insert to middel*/
		if (h->next != NULL && atoi (h->next->data.production_year) > tmp_prodeYear){
				tmp = h->next;
				h->next = tmp;
				break;
		}

		/*if the new node insert to end*/

		if (h->next == NULL){
			h->next = tmp;
			break;
		}
		h = h->next;
	}

	
	counter++;
	return true;
}

void printCarList(){

car_node* tmp = head;

while (tmp != NULL){
	printf("%s -->" , tmp->data.production_year);
	tmp = tmp->next;
	}
}


car_node* getNewCar(){

	car_node* tmp = (car_node*)malloc(sizeof(car_node));
	tmp->next = NULL;

	get_user_input_num(tmp->data.car_id, "Enter car id: ", 7);

	get_user_input_num(tmp->data.production_year, "Enter production year: ", 4);
	get_user_input_num(tmp->data.chassis, "Enter car chassis number: ", SIZE_FIVE);

	get_user_input_string(tmp->data.manufacturer_name, "Enter manufacturer name: ", SIZE_TEN);
	get_user_input_string(tmp->data.model_name, "Enter model name: ", SIZE_TEN);
	get_user_input_string(tmp->data.color, "Enter color: ", SIZE_SEVEN);

	get_user_input_num(tmp->data.entry_road_year, "Enter entry road year: ", 4);
	tmp->data.supplier_price   = get_user_input_num_flex("Enter suplier price: ", SIZE_SEVEN);
	tmp->data.current_price    = get_user_input_num_flex("Enter current price: ", SIZE_SEVEN);
	get_user_input_num(tmp->data.engine_capacity, "Enter engine capacity: ", 4);

	return tmp;
}

/* return number of cars with same engine capacity*/
/*int carNumberWithGivenCapacity (const char* engine_cap) {

	int countCar = 0;
	int i;

	if (!isValid_intLen(engine_cap , 4))
		return 0;
	for (i=0 ; i < counter; i++){
		
		if (!strcmp(carList[i].engine_capacity, engine_cap)) 
		 	countCar++;
	}
	return countCar;
}*/

/*int carNumberWithGivenYear (const char* year)
{
	int countCar = 0;
	int j;

	if (!isValid_intLen(year , SIZE_FIVE-1))
		return 0;
	
	for (j=0 ; j < counter; j++)
		if (!strcmp(carList[j].production_year, year))
			countCar++;

	return countCar;
}*/

/* return if "1" if succed*/
/*int deleteCar (const char* carID)
{
	int i;

	if (!isValid_intLen(carID , SIZE_SEVEN)){
		printf("invalid input\n");
		return 0;
	}
	
	for (i = 0; i < counter; i++)
	{ 
		
		if (!strcmp(carList[i].car_id, carID))	
		{
			initCar(i);
			carList[i] = carList[counter-1];
			counter--;
			printf("car %s deleted\n",carID);
			return 1;
		}
	}
	return 0;
}*/

/* return "1" if succed*/ 
int deleteAllCars () 
{
	int  i;
	for (i = 0; i < counter; i++)
	{
		initCar(i);
	}
	counter = 0;
	printf("All cars are deleted\n");

	return 0;	
}