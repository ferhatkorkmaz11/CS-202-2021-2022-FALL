/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : MinHeap Header.
*/
#include <iostream>
const int MAX_HEAPMIN = 32767;

class MinHeap {
public:
    MinHeap();                // default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const int& newItem);
    void heapDelete(int& rootItem);
	void insert (int value ); // inserts integer into heap
	int peek(); // returns the value of the min element
	int extractMin(); // retrieves and removes the min element
	int size(); // returns the number of elements in the heap
	void printHeap(); //prints the heap (helper function.)

protected:
    void heapRebuild(int root);        // Converts the semiheap rooted at 
                            // index root into a heap
private:
	int items[MAX_HEAPMIN];    // array of heap items
    int  length;                // number of heap items
};
