/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : MaxHeap Header.
*/
#include <iostream>
const int MAX_HEAP = 32767;

class MaxHeap {
public:
    MaxHeap();                // default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const int& newItem);
    void heapDelete(int& rootItem);
	void insert (int value ); // inserts integer into heap
	int peek(); // returns the value of the max element
	int extractMax(); // retrieves and removes the max element
	int size(); // returns the number of elements in the heap
	void printHeap(); //prints the heap (helper function.)

protected:
    void heapRebuild(int root);        // Converts the semiheap rooted at 
                            // index root into a heap
private:
	int items[MAX_HEAP];    // array of heap items
    int  length;                // number of heap items
};
