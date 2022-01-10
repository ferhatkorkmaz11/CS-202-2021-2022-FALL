/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : AVLTree analysis implementation.
*/
#include "analysis.h"
using namespace std;

void performanceAnalysis()
{
	srand((unsigned) time(0));
	
	const int ARRAY_CONSTANT = 1000;			//sizes of avltrees will be 1*ARRAY_CONSTANT, 2*ARRAY_CONSTANT, 3*ARRAY_CONSTANT, ..., 10*ARRAY_CONSTANT
	const int ARRAY_ITEM_UPPER_BOUND = 100000;	//random numbers, ascending numbers, and descending numbers will be generated such a way that they can be maximum ARRAY_ITEM_UPPER_BOUND
	const int ARRAY_ITEM_LOWER_BOUND = 1;		//random numbers, ascending numbers, and descending numbers will be generated such a way that they can be minimum ARRAY_ITEM_LOWER_BOUND
	cout << "Below, you can see number of rotations for each case." << endl;
	printf("%-31s%-31s%-31s%-31s\n", "Array Size", "Random", "Ascending", "Descending");
	for(int i = 1; 10 >= i; i++) //Instead of 10, write 2 in order to wait less while testing it with Valgrind. This will give you only two outputs: First one is array sized 1000 and the second one is array sized 2000.
	{
		int random[ARRAY_CONSTANT * i];
		int ascending[ARRAY_CONSTANT * i];
		int descending[ARRAY_CONSTANT * i];
		AVLTree AVLRandom;
		AVLTree AVLAscending;
		AVLTree AVLDescending;
		
		//initializing the arrays
		for(int j = 0; ARRAY_CONSTANT * i > j; j++)
		{
			int curRand= (rand() % ARRAY_ITEM_UPPER_BOUND) + ARRAY_ITEM_LOWER_BOUND;
			random[j] = curRand;
			curRand= (rand() % ARRAY_ITEM_UPPER_BOUND) + ARRAY_ITEM_LOWER_BOUND;
			ascending[j] = curRand;
			curRand= (rand() % ARRAY_ITEM_UPPER_BOUND) + ARRAY_ITEM_LOWER_BOUND;
			descending[j] = curRand;
		}
		sortArrayAscending(ascending, ARRAY_CONSTANT * i);
		sortArrayDescending(descending, ARRAY_CONSTANT * i);
		
		for(int j = 0; ARRAY_CONSTANT * i > j; j++)
		{
			AVLRandom.insert(random[j]);
			AVLAscending.insert(ascending[j]);
			AVLDescending.insert(descending[j]);
		}
		printf("%-31d%-31d%-31d%-31d\n", ARRAY_CONSTANT * i ,AVLRandom.rotations(), AVLAscending.rotations(), AVLDescending.rotations());
		
	}
}

void sortArrayAscending(int* arr, int n)
{
	int i, j;
    for (i = 0; i < n-1; i++)    
    
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
		{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
            
}

void sortArrayDescending(int* arr, int n)
{
	int i, j;
    for (i = 0; i < n-1; i++)    
    
    for (j = 0; j < n-i-1; j++)
        if (arr[j] < arr[j+1])
        {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
}