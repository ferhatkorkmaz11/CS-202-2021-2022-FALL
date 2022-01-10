/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : MinHeap implementation.
*/
#include "MinHeap.h"
using namespace std;
MinHeap::MinHeap() : length(0) 
{

}

bool MinHeap::heapIsEmpty() const 
{
    return (length == 0);
}

void MinHeap::insert(int value) 
{

    if (!(length >= MAX_HEAPMIN))
    {

		// Place the new item at the end of the heap
		items[length] = value;

		// Trickle new item up to its proper position
		int place = length;
		int parent = (place - 1)/2;
		while ( (place > 0) && (items[place] < items[parent]) ) 
		{
			int temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;	
			place = parent;
			parent = (place - 1)/2;
			
		}
		++length;
	}
     
}

void MinHeap::heapDelete(int&rootItem)
 {
	if(!heapIsEmpty())
	{
        rootItem = items[0];
        items[0] = items[--length];
        heapRebuild(0);
    }
}

void MinHeap::heapRebuild(int root) 
{   
    int child = 2 * root + 1;     // index of root's left child, if any
    if ( child < length )
	{        
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < length) && (items[rightChild] < items[child]) )
			child = rightChild;     // index of larger child

        // If root’s item is smaller than larger child, swap values
        if ( items[root] > items[child] ) 
		{
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
	}
}

int MinHeap::peek()
{
	if(length != 0)
		return items[0];
	return -1;
}

int MinHeap::extractMin()
{
	if(length == 0) //empty
		return -1;

	int result = peek();
	heapDelete(result);
	return result;
}

int MinHeap::size()
{
	return length;
}

void MinHeap::printHeap()
{
	cout << "{";
	for(int i = 0; length > i; i++)
	{
		if(i == length - 1)
			cout << items[i] << "}" << endl;
		else
			cout << items[i] << ", ";
	
	}
}