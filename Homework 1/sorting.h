/**
*Title: Algorithm Efficiency and Sorting
*Author: Ferhat Korkmaz
*ID: 21901940
*Section: 1
*Assignment: 1
*Description: Header file for the sorting.cpp. Function prototypes are here.
*/
#include <cmath>
#include <time.h>  // for timer
#include <stdlib.h>  //random
#include <iostream> //cout
#include <stdio.h>
#include <cstring> //string constant seperator
void insertionSort( int *arr , int arraysize , int &compCount , int &moveCount );
void quickSort( int* arr, int first, int last, int& compCount, int &moveCount );
void mergeSort( int* arr, int first, int last, int &compCount , int &moveCount );
void radixSort( int *arr , int arraySize );
void printArray(int *arr, int arraySize);
void performanceAnalysis();