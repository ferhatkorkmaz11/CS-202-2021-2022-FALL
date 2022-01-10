/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : MedianHeap Header.
*/
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"


class MedianHeap {
public:
    MedianHeap();                // default constructor
    // copy constructor and destructor are supplied by the compiler
	void insert(int value);
	int findMedian();
protected:
	void rebuild();
private:
	MaxHeap max;
	MinHeap min;
};
