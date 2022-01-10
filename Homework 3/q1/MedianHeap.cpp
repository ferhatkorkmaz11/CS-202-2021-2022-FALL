/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : MedianHeap implementation.
*/
#include "MedianHeap.h"
using namespace std;
MedianHeap::MedianHeap()
{
	//An empty constructor, I guess?
}

//Find the current median, if the value that is going to be inserted is bigger than it, insert it into min heap. Else, vice versa. Then, rebuild.
void MedianHeap::insert(int value)
{
	cout << "Inserting " << value << " into the MaxHeap." << endl; 
	int median = findMedian();
	if(value > median)
		min.insert(value);
	else
		max.insert(value);
	rebuild();
}

//If min size is bigger, median is in min heap, if max size is bigger it is in max heap, else it is their sum divided by two.
int MedianHeap::findMedian()
{
	int minSize = min.size();
	int maxSize = max.size();
	if(minSize == 0 && maxSize == 0)
		return 0;
	if(minSize > maxSize)
		return min.peek();
	if(maxSize > minSize)
		return max.peek();
	return (min.peek() + max.peek()) / 2;
}

//If one of them has a size that is two or more bigger, we rebuild by moving element from one to another.
void MedianHeap::rebuild()
{
	int minSize = min.size();
	int maxSize = max.size();
	int temp = 0;
	if(minSize > maxSize + 1)
	{
		temp = min.extractMin();
		max.insert(temp);
	}
	if(maxSize > minSize + 1)
	{
		temp = max.extractMax();
		min.insert(temp);
	}
}