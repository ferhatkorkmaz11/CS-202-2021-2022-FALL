/**
* Author : Ferhat Korkmaz
* ID: 21901940
* Section : 01
* Assignment : 4
*/
#include <iostream>
enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
const int DELETED = -1;
const int EMPTY = 0;
const int OCCUPIED = 1;
class HashTable
{
public:
	HashTable( const int tableSize, const CollisionStrategy option );
	~HashTable();
	bool insert( const int item );
	bool remove( const int item );
	bool search( const int item, int& numProbes );
	void display();
    void analyze( int& numSuccProbes, int& numUnsuccProbes );

private:
	struct hashItem
	{
		int item;
		int locationStatus; //-1 deleted, 0 empty, 1 occupied.
	};
    const int f(int i, int key);
    const int hash1(const int item);
    const int hash2(const int item);
	hashItem** hashArray;
	CollisionStrategy strategy;
	int tableSize;
	int noOfFreeSpace;


};

