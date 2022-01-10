/**
* Author : Ferhat Korkmaz
* ID: 21901940
* Section : 01
* Assignment : 4
*/
#include "HashTable.h"

using namespace std;

//Constructor of the HashTable
HashTable::HashTable(const int tableSize, const CollisionStrategy option)
{
    this->tableSize = tableSize;
    hashArray = new hashItem *[tableSize];    //dynamically allocating an 1D array.
    for (int i = 0; tableSize > i; i++)
    {
        hashArray[i] = new hashItem();
        hashArray[i]->item = -1;
        hashArray[i]->locationStatus = EMPTY;
    }
    strategy = option;
    noOfFreeSpace = tableSize;
}

//Destructor
HashTable::~HashTable()
{
    for (int i = 0; tableSize > i; i++)
    {
        delete hashArray[i];
    }
    delete[] hashArray;
}

//insertion method
bool HashTable::insert(const int item)
{
    int hashedKey = hash1(item);
    bool returnStat = false;
    if (noOfFreeSpace == 0)		//if it is full
    {
        return returnStat; //false
    }
    if (hashArray[hashedKey]->locationStatus == EMPTY || hashArray[hashedKey]->locationStatus == DELETED) //first probe
    {
        hashArray[hashedKey]->item = item;
        hashArray[hashedKey]->locationStatus = OCCUPIED;
        noOfFreeSpace--;
        returnStat = true;
        return returnStat;
    } else //remaining probes if neccessary
    {
        int probeNumber = 0;
        int i = 1;
        while (((strategy == LINEAR || strategy == DOUBLE) && probeNumber != tableSize) ||
               (strategy == QUADRATIC && probeNumber < tableSize / 2))  //stop condition
        {
            int newKey = f(i, item) + hashedKey;
            if (newKey >= tableSize)
                newKey = newKey % tableSize;
            probeNumber++;

            if (hashArray[newKey]->locationStatus == EMPTY || hashArray[newKey]->locationStatus == DELETED)		//suitable location found
            {
                hashArray[newKey]->item = item;
                hashArray[newKey]->locationStatus = OCCUPIED;
                noOfFreeSpace--;
                returnStat = true;
                break;
            }
            i++;
        }
    }
    return returnStat;		//returning
}

bool HashTable::remove(const int item)
{
    int hashedKey = hash1(item);
    bool returnStat = false;
    if (hashArray[hashedKey]->item == item && hashArray[hashedKey]->locationStatus == OCCUPIED)	//first probe
    {
        hashArray[hashedKey]->locationStatus = DELETED;
        noOfFreeSpace++;
        returnStat = true;
        return returnStat;
    } else		//remaining probes
    {
        int probeNumber = 0;
        int i = 1;
        while (((strategy == LINEAR || strategy == DOUBLE) && probeNumber != tableSize) ||
               (strategy == QUADRATIC && probeNumber < tableSize / 2))  //stop condition
        {
            int newKey = f(i, item) + hashedKey;
            if (newKey >= tableSize)
                newKey = newKey % tableSize;
            probeNumber++;
            if (hashArray[newKey]->locationStatus == EMPTY)
            {
                returnStat = false;
                break;
            }
            if (hashArray[newKey]->item == item && hashArray[newKey]->locationStatus == OCCUPIED)
            {
                hashArray[newKey]->locationStatus = DELETED;
                noOfFreeSpace++;
                returnStat = true;
                break;
            }
            i++;
        }
    }
    return returnStat;

}

bool HashTable::search(const int item, int &numProbes)		
{
    int hashedKey = hash1(item);
    bool returnStat = false;
    if (hashArray[hashedKey]->item == item && hashArray[hashedKey]->locationStatus == OCCUPIED)
    {
        numProbes = 1;
        returnStat = true;
        return returnStat;
    } else if (hashArray[hashedKey]->locationStatus == EMPTY)
    {
        numProbes = 1;
        returnStat = false;
        return returnStat;
    } else
    {
        int probeNumber = 1;
        int i = 1;
        while (((strategy == LINEAR || strategy == DOUBLE) && probeNumber != tableSize) ||
               (strategy == QUADRATIC && probeNumber < tableSize / 2))  //stop condition
        {
            int newKey = f(i, item) + hashedKey;
            if (newKey >= tableSize)
                newKey = newKey % tableSize;

            probeNumber++;
            if (hashArray[newKey]->locationStatus == EMPTY)
            {

                returnStat = false;
                break;
            }
            //probeNumber++;
            if (hashArray[newKey]->item == item && hashArray[newKey]->locationStatus == OCCUPIED)
            {
                returnStat = true;
                break;
            }
            i++;
        }
        numProbes = probeNumber;
    }
    return returnStat;
}

void HashTable::display()
{
    for (int i = 0; tableSize > i; i++)
    {
        if (hashArray[i]->locationStatus == OCCUPIED)
            cout << i << ": " << hashArray[i]->item << endl;
        else
            cout << i << ": " << endl;
    }
}

const int HashTable::hash1(const int item)
{
    return item % tableSize < 0 ? (item % tableSize) + tableSize : item % tableSize;
}

const int HashTable::hash2(const int item)
{
    int reversedNumber = 0;
    int itemTemp = item;
    while (itemTemp > 0)
    {
        reversedNumber = reversedNumber * 10 + itemTemp % 10;
        itemTemp /= 10;
    }
    return reversedNumber;
}

const int HashTable::f(int i, int key)
{
    if (strategy == LINEAR)
        return i;
    if (strategy == QUADRATIC)
        return i * i;
    if (strategy == DOUBLE)
        return i * hash2(key);
}

void HashTable::analyze(int &numSuccProbes, int &numUnsuccProbes)
{
    int suc = 0;
    int unsuc = 0;
    int occupiedSize = tableSize - noOfFreeSpace;
    int occupiedItems[occupiedSize];
    int index = 0;
    for (int i = 0; tableSize > i; i++)
    {
        if (hashArray[i]->locationStatus == OCCUPIED)
        {
            occupiedItems[index] = hashArray[i]->item;
            index++;
        }
    }
    for (int i = 0; occupiedSize > i; i++)
    {
        int curProbe = 0;
        search(occupiedItems[i], curProbe);
        suc += curProbe;
    }
    if (tableSize - noOfFreeSpace != 0)
        numSuccProbes = suc / (tableSize - noOfFreeSpace);
    // unsuc
    int totalProbe = 0;
    for (int j = 0; tableSize > j; j++)
    {
        int curProbe = 1;
        int i = 1;
        if (hashArray[j]->locationStatus == EMPTY)
        {
            totalProbe += curProbe;
        } else
        {
            while ((strategy == LINEAR && curProbe < tableSize) || (strategy == QUADRATIC && curProbe < tableSize / 2))
            {
                int newLoc = (j + f(i, i)) % tableSize;
                curProbe++;
                //cout << "LOCATION THAT WILL BE LOOKED FOR IS " << newLoc << endl;
                if (hashArray[newLoc]->locationStatus == EMPTY)
                {
                    totalProbe += curProbe;
                    //cout << "TOTAL PROBE CUR: " << totalProbe <<endl; //for checking purposes. seems okay to me. you can uncommand and examine if it is working correctly
                    break;
                }
                i++;
            }
        }
    }
    if (strategy != DOUBLE)
        numUnsuccProbes = totalProbe / tableSize;
    else
        numUnsuccProbes = -1;
}
