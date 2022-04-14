
#include "car.h"


void getNewCar(car* new_car);

void createCarList ()
{
	root = NULL;
	printf("car list created\n");
}

bool addNewCar (car_node** tree, car* new_car_data)
{
	/* create new car */
	if (new_car_data == NULL)
	{
		new_car_data = ALLOC(car, sizeof(car));
		getNewCar(new_car_data);
	}

	/* tree is empty? insert new car to root */
	if (*tree == NULL)
	{
		car_node* new_car = ALLOC(car_node, sizeof(car_node));
		new_car->data = *new_car_data;
		new_car->left = NULL;
		new_car->right = NULL;
		*tree = new_car;

		return true;
	}

	/* find place to add new car by car id */
	if (atoi(new_car_data->car_id) < atoi((*tree)->data.car_id))
	{
		addNewCar(&(*tree)->left, new_car_data);
		return true;
	}

	else if (atoi(new_car_data->car_id) > atoi((*tree)->data.car_id))
	{
		addNewCar(&(*tree)->right, new_car_data);
		return true;
	}
	return false;
}

void getNewCar(car* new_car)
{
	/* populate new car data */
	get_user_input_num        (new_car->car_id,            "Enter car id: ", 7);
	get_user_input_num        (new_car->chassis,           "Enter car chassis number: ", SIZE_FIVE);
	get_user_input_num        (new_car->production_year,   "Enter production year: ", 4);
	get_user_input_unlimitStr (new_car->manufacturer_name, "Enter manufacturer name: ");
	get_user_input_unlimitStr (new_car->model_name,        "Enter model name: ");
	get_user_input_unlimitStr (new_car->color,             "Enter color: ");
	get_user_input_num        (new_car->entry_road_year,   "Enter entry road year: ", 4);
	new_car->supplier_price   = get_user_input_num_flex("Enter suplier price: ", SIZE_SEVEN);
	new_car->current_price    = get_user_input_num_flex("Enter current price: ", SIZE_SEVEN);
	get_user_input_num        (new_car->engine_capacity,   "Enter engine capacity: ", 4);
}

int carNumberWithGivenCapacity(car_node* tree, char* engine_cap, int counter)
{
	if (!tree)
		return counter;

	if (!strcmp(tree->data.engine_capacity, engine_cap))
		counter++;

	counter = carNumberWithGivenCapacity(tree->left, engine_cap, counter);
	counter = carNumberWithGivenCapacity(tree->right, engine_cap, counter);
	
	return counter;
}


car_node* minValueNode(car_node* tree)
{
    car_node* current = tree;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

car_node* deleteCar (car_node* tree, char* car_id)
{
	if (tree == NULL)
	{
		return tree;
	}

	if (atoi(car_id) < atoi(tree->data.car_id))
        tree->left = deleteCar(tree->left, car_id);


	else if (atoi(car_id) > atoi(tree->data.car_id))
        tree->right = deleteCar(tree->right, car_id);
	
	else {
        /* node with only one child or no child */
        if (tree->left == NULL)
		{
            root = tree->right;
            free(tree);
            return root;
		}
        else if (tree->right == NULL)
		{
            free(tree);
            root = tree->left;
            return root;
        }

		root = minValueNode(tree->right);
		memcpy(&(tree->data.car_id), &(root->data.car_id), 8);
		tree->right = deleteCar(tree->right, root->data.car_id);
    }

    return tree;
}

void _deleteAllCars (car_node* tree)
{
	/* delete all cars from tree */
	if (tree == NULL)
		return;
	
	_deleteAllCars(tree->left);
	_deleteAllCars(tree->right);

	free(tree);
}

void deleteAllCars(car_node** tree_ref)
{
  _deleteAllCars(*tree_ref);
  *tree_ref = NULL;
}