/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : Driver for Min, Max, and Median Heaps.
*/
#include "MedianHeap.h"
#include <iostream>
using namespace std;

int main()
{
	const string  SEPERATOR = "~~~~~~~~~~~~~~~~~~~~~~";
	cout << SEPERATOR << " MAX HEAP DRIVER STARTS " << SEPERATOR << endl;
	MaxHeap maxHeap;
	maxHeap.insert(13);
	maxHeap.insert(-12);
	maxHeap.insert(41);
	maxHeap.insert(7);
	maxHeap.insert(19);
	maxHeap.insert(67);
	maxHeap.insert(-33);
	maxHeap.insert(-42);
	maxHeap.insert(6);
	maxHeap.insert(128);
	maxHeap.insert(11111);
	maxHeap.insert(-101);
	maxHeap.printHeap();
	cout << "Size is: " << maxHeap.size() <<endl;
	cout << "Peeking max: " << maxHeap.peek() << endl;
	int extractionMax = maxHeap.extractMax();
	cout << "Extracting max: " << extractionMax <<endl;
	maxHeap.printHeap();
	cout << "Size is: " << maxHeap.size() <<endl;
	cout << SEPERATOR << " MAX HEAP DRIVER ENDS " << SEPERATOR << endl;
	cout << SEPERATOR << " MIN HEAP DRIVER STARTS " << SEPERATOR << endl;
	MinHeap minHeap;
	minHeap.insert(13);
	minHeap.insert(-12);
	minHeap.insert(41);
	minHeap.insert(7);
	minHeap.insert(19);
	minHeap.insert(67);
	minHeap.insert(-33);
	minHeap.insert(-42);
	minHeap.insert(6);
	minHeap.insert(128);
	minHeap.insert(11111);
	minHeap.insert(-101);
	minHeap.printHeap();
	cout << "Size is: " << minHeap.size() <<endl;
	cout << "Peeking min: " << minHeap.peek() << endl;
	int extractionMin = minHeap.extractMin();
	cout << "Extracting min: " << extractionMin <<endl;
	minHeap.printHeap();
	cout << SEPERATOR << " MIN HEAP DRIVER ENDS " << SEPERATOR << endl;
	cout << SEPERATOR << " MEDIAN HEAP DRIVER STARTS " << SEPERATOR << endl;
	MedianHeap medianHeap;
	medianHeap.insert(13);
	medianHeap.insert(-12);
	medianHeap.insert(41);
	medianHeap.insert(7);
	medianHeap.insert(19);
	medianHeap.insert(67);
	medianHeap.insert(-33);
	medianHeap.insert(-42);
	medianHeap.insert(6);
	medianHeap.insert(128);
	medianHeap.insert(11111);
	medianHeap.insert(-101);
	cout << "Median is: " << medianHeap.findMedian() << endl;
	cout << SEPERATOR << " MEDIAN HEAP DRIVER ENDS " << SEPERATOR << endl;
	return 0;
}