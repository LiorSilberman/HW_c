
#include "car.h"

car_node* getNewCar();

/*create car list*/
void createCarList ()
{
	head = NULL;
	printf("create car list\n");
}

/* add new car to list*/
bool addNewCar ()
{
	car_node* h = head;
	car_node* tmp = getNewCar();
	int tmp_prodeYear = atoi(tmp->data.production_year);

	if (head == NULL){
		head = tmp;
		return true;
	}
	
	while (h != NULL ){
		
		/*if the new node insert to begin*/
		if (tmp_prodeYear < atoi(h->data.production_year)) {
			tmp->next = head;
			head = tmp;
			break;
		}
		/*if the new node insert to middel*/
		if (h->next != NULL && atoi (h->next->data.production_year) > tmp_prodeYear){
				tmp->next = h->next;
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

	return true;
}

void printCarList()
{
	car_node* tmp = head;

	while (tmp != NULL){
		printf("%s -->" , tmp->data.production_year);
		tmp = tmp->next;
		}
	printf("\n");
}

car_node* getNewCar()
{
	car_node* tmp = ALLOC(car_node,sizeof(car_node));
	tmp->next = NULL;

	get_user_input_num(tmp->data.car_id, "Enter car id: ", 7);

	get_user_input_num(tmp->data.chassis, "Enter car chassis number: ", SIZE_FIVE);

	get_user_input_num(tmp->data.production_year, "Enter production year: ", 4);

	get_user_input_unlimitStr(tmp->data.manufacturer_name, "Enter manufacturer name: ");

	get_user_input_unlimitStr(tmp->data.model_name, "Enter model name: ");

	get_user_input_unlimitStr(tmp->data.color, "Enter color: ");

	get_user_input_num(tmp->data.entry_road_year, "Enter entry road year: ", 4);

	tmp->data.supplier_price   = get_user_input_num_flex("Enter suplier price: ", SIZE_SEVEN);

	tmp->data.current_price    = get_user_input_num_flex("Enter current price: ", SIZE_SEVEN);

	get_user_input_num(tmp->data.engine_capacity, "Enter engine capacity: ", 4);

	return tmp;
}

/* return number of cars with same engine capacity*/
int carNumberWithGivenCapacity () {

	int countCar = 0;
	char engine_cap[5];
	car_node* tmp = head;
	printf("Please insert engine capacity to check: ");
    scanf("%s", engine_cap);

	if (!isValid_intLen(engine_cap , 4))
		return 0;
	
	while (tmp != NULL)
	{
		if (!strcmp(tmp->data.engine_capacity, engine_cap))
			countCar++;
		
		tmp = tmp->next;
	}
	return countCar;
}

/* return number of cars with same engine capacity with recursion*/
int carNumberWithGivenCapacity_REC (car_node* tmp, int counter, char* engine_cap)
{
	if (tmp == NULL)
		return counter;
	
	if (!strcmp(tmp->data.engine_capacity, engine_cap))
		counter++;

	counter = carNumberWithGivenCapacity_REC (tmp->next, counter, engine_cap);
	return counter;
}

/* return if "1" if succed*/
void deleteCar ()
{
	char carID[8];
	car_node* tmp = head;
	car_node* prev;
	printf("Enter car ID to delete: ");
	scanf("%s", carID);
	if (!isValid_intLen(carID , SIZE_SEVEN)){
		printf("invalid input\n");
		return;
	}
	if (tmp != NULL && (!strcmp(tmp->data.car_id, carID)))
	{
		head = tmp->next;
		free(tmp);
		return;
	}

	/* find node with car id*/
	while (tmp != NULL && (strcmp(tmp->data.car_id, carID)))
	{
		prev = tmp;
		tmp = tmp->next;
	}

	/* key found?*/
	if (tmp == NULL)
		return;

	/* kepp track of list*/
	prev->next = tmp->next;

	/* delete node*/
	free(tmp);
}

/* return "1" if succed*/ 
void deleteAllCars () 
{
	while (head != NULL)
	{
		free(head);
		head = head->next;
	}

	if (head == NULL)
		return;
}

void inverseCarList()
{
    struct car_node* prev = NULL;
    struct car_node* current = head;
    struct car_node* next = NULL;
    while (current != NULL) {
        /* Store next*/
        next = current->next;
 
        /* Reverse current node's pointer*/
        current->next = prev;
 
        /* Move pointers one position ahead.*/
        prev = current;
        current = next;
    }
    head = prev;
}