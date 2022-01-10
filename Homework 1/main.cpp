/**
*Title: Algorithm Efficiency and Sorting
*Author: Ferhat Korkmaz
*ID: 21901940
*Section: 1
*Assignment: 1
*Description: main.cpp that can run sorting algorithms and performanceAnalysis method.
*/
#include "sorting.h"

using namespace std;
int main()
{

	int arr[9] = {3, 6, 1, 4, 5, 9 , 7, 2,8};
	printArray(arr, 9);
    int move = 0;
    int comp = 0;
	quickSort(arr, 0,8, comp, move);
	printArray(arr, 9);
	cout << "Move: " << move <<endl; 
	cout << "Comp: " << comp <<endl; 

    return 0;
}
