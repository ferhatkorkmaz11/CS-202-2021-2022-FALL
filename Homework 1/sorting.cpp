/**
*Title: Algorithm Efficiency and Sorting
*Author: Ferhat Korkmaz
*ID: 21901940
*Section: 1
*Assignment: 1
*Description: This is a cpp file that can define various of sorting methods as well as helper methods to them. Also, we can see performance analysis for each algorithm.
*/
#include "sorting.h"

using namespace std;
const int DIVISOR = 100;      //change this if you get 0.000 ms output. I dont get it on my pc, but valgrind takes a lot to run so i decreased it to 3.
void insertionSort(int *arr, int arraysize, int &compCount,
                   int &moveCount)     // I edited the slide's version a little bit in order to keep track of move and comp
{
    for (int unsorted = 1; unsorted < arraysize; unsorted++)
    {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        for( ;(loc > 0) && (arr[loc - 1] > nextItem); loc-- )
        {
            arr[loc] = arr[loc - 1];
            compCount++;
            moveCount++;
        }
        compCount++;
        arr[loc] = nextItem;
        moveCount++;
		cout << "Unsorted: " << unsorted << " Su an M ve C: " << moveCount << ", " << compCount << endl; 
    }
}

void merge(int theArray[], int first, int mid, int last, int &compCount, int &moveCount)    // from the slide
{
    int tempArray[30000];     // temporary array

    int first1 = first;     // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1; // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        compCount++;
        if (theArray[first1] < theArray[first2])
        {
            moveCount++;
            tempArray[index] = theArray[first1];
            ++first1;
        } else
        {
            moveCount++;
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount++;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount++;
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
        moveCount++;
    }

}  // end merge


void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount)       // from the slide
{
    if (first < last)
    {

        int mid = (first + last) / 2;     // index of midpoint

        mergeSort(arr, first, mid, compCount, moveCount);

        mergeSort(arr, mid + 1, last, compCount, moveCount);

        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount)  // from the slide
{
    pivotIndex = first;
    int pivot = arr[pivotIndex];
    //moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (; firstUnknown <= last; firstUnknown++)
    {
        compCount++;
        if (arr[firstUnknown] < pivot)
        {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
    }
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 3;
}

void quickSort(int *arr, int first, int last, int &compCount, int &moveCount)       // from the slide
{
    int pivotIndex;

    if (first < last)
    {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }

}

int digitNumber(int number) // this is a function that can determine how many digits on a given number (helper for radix)
{
    int result = 0;
    if (number < 0)
        result = 1;
    while (int(number != 0))
    {
        number = number / 10;
        result++;
    }
    return result;
}

int maxDigitInAnArray(int *arr, int n)  // longest number (helper for radix sort)
{
    int max = digitNumber(arr[0]);
    for (int i = 1; n > i; i++)
    {
        if (max < digitNumber(arr[i]))
            max = digitNumber(arr[i]);
    }
    return max;
}

void radixSort(int *arr, int arraySize, int max)        //actual implementation
{
    for (int i = 0; i < max; i++)
    {
        int twoDimensionalArray[10][arraySize];     // This will be used while grouping the elements
        int counter[10] = {0};                      // Counter of each digit

        for (int j = 0; j < arraySize; j++)
        {
            int lastDigit = ((int) (arr[j] / pow(10, i))) % 10;         // getting the last digit
            int position = counter[((int) (arr[j] / pow(10, i))) % 10];       // counter ++
            twoDimensionalArray[lastDigit][position] = arr[j];          // group the entries and determine each belong to where
            counter[(int) (arr[j] / pow(10, i)) % 10] =
                    position + 1;        // increase the number where its current digit belongs to
        }

        int curPos = 0;
        for (int j = 0; j < 10; j++)
        {
            int cur = 0;
            while (cur < counter[j])
            {
                arr[curPos++] = twoDimensionalArray[j][cur];
                cur++;
            }
        }
    }
}

void radixSort(int *arr, int arraySize)     //transform normal func call into with max digit one
{
    int max = maxDigitInAnArray(arr, arraySize);
    radixSort(arr, arraySize, max);
}


void printArray(int *arr, int arraySize)        //prints the array in the form of [a, b, c, d]
{
    cout << "[";
    for (int i = 0; arraySize > i; i++)
    {
        if (i == arraySize - 1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << "]\n";
}

void initArray(int *arr, int size)      //sets the array with random integers between the values [0, 10*size]
{
    srand(time(0));

    for (int i = 0; size > i; i++)
    {
        int cur = rand() % (10 * size);
        arr[i] = cur;
    }
}

void performanceAnalysis()      //this function tests the sorting times in different sized arrays as well as the comparison and move values in various sorting algorithms.
{
    const int sizes[8] = {2000, 6000, 10000, 14000, 18000, 22000, 26000, 30000};
    const string SEPERATOR = "-----------------------------------------------------";
    cout << SEPERATOR << endl;

    // INSERTION SORT TEST BEGINS
    cout << "Part a - Time analysis of Insertion  Sort" << endl;
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");
    //cout << "Array Size\t\t Time Elapsed(ms)\t   compCount\t\t  moveCount\n";

    for (int i = 0; 8 > i; i++)
    {
        int *curArray = new int[sizes[i]];
        //initArray(curArray, sizes[i]);
        int move = 0;
        int comp = 0;
        double timeElapsed = 0.0;
        clock_t startTime = clock();
        for(int j = 0; 3 > j; j++)
        {
            move = 0;
            comp = 0;
            initArray(curArray, sizes[i]);
            insertionSort(curArray, sizes[i], move, comp);
        }
        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= 3;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, comp, move);
        //cout << sizes[i] << "\t\t\t " << timeElapsed << "\t\t  " << comp << "\t\t  " << move << endl;
        delete[] curArray;      //deallocation
    }
    cout << SEPERATOR << endl;
    //INSERTION SORT TEST ENDS

    //MERGE SORT TEST BEGINS
    cout << "Part b - Time analysis of Merge Sort" << endl;
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");
    //cout << "Array Size\t\t Time Elapsed(ms)\t   compCount\t\t  moveCount\n";
    for (int i = 0; 8 > i; i++)
    {
        int *curArray = new int[sizes[i]];
        int move = 0;
        int comp = 0;
        double timeElapsed = 0.0;
        clock_t startTime = clock();

        for (int j = 0; DIVISOR > j; j++)  //Run 1000 times and divide the time elapsed by 1000. This approach works fine (without 0ms outputs) for my pc. It can depend.
        {
            move = 0;
            comp = 0;
            initArray(curArray, sizes[i]);
            mergeSort(curArray, 0, sizes[i] - 1, move, comp);
        }
        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, comp, move);
        //cout << sizes[i] << "\t\t\t " << timeElapsed << "\t\t  " << comp << "\t\t  " << move << endl;
        delete[] curArray;  //deallocation
    }

    cout << SEPERATOR << endl;
    //MERGE SORT TEST ENDS

    //QUICK SORT TEST BEGINS
    cout << "Part c - Time analysis of Quick Sort" << endl;
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");
    //cout << "Array Size\t\t Time Elapsed(ms)\t   compCount\t\t  moveCount\n";
    for (int i = 0; 8 > i; i++)
    {
        int *curArray = new int[sizes[i]];
        double timeElapsed = 0.0;
        int move = 0;
        int comp = 0;
        clock_t startTime = clock();
        for (int j = 0; DIVISOR > j; j++)  //Run 1000 times and divide the time elapsed by 1000. This approach works fine (without 0ms outputs) for my pc. It can depend.
        {
            move = 0;
            comp = 0;
            initArray(curArray, sizes[i]);
            quickSort(curArray, 0, sizes[i] - 1, move, comp);
        }
        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, comp, move);
        //cout << sizes[i] << "\t\t\t " << timeElapsed << "\t\t  " << comp << "\t\t  " << move << endl;
        delete[] curArray;  //deallocation
    }
    cout << SEPERATOR << endl;
    //QUICK SORT TEST ENDS

    //RADIX SORT TEST BEGINS
    cout << "Part d - Time analysis of Radix Sort" << endl;
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");
    //cout << "Array Size\t\t Time Elapsed(ms)\t   compCount\t\t  moveCount\n";
    for (int i = 0; 8 > i; i++)
    {
        int *curArray = new int[sizes[i]];
        double timeElapsed = 0.0;
        clock_t startTime = clock();

        for (int j = 0; DIVISOR > j; j++)  //Run 1000 times and divide the time elapsed by 1000. This approach works fine (without 0ms outputs) for my pc. It can depend.
        {
            initArray(curArray, sizes[i]);
            radixSort(curArray, sizes[i]);
        }

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;
        printf("%-20d\t%-20.10f\t%-20s\t%-20s\n", sizes[i], timeElapsed, "NOT MEASURED", "NOT MEASURED");
        //cout << sizes[i] << "\t\t\t " << timeElapsed << "\t\t  " << "NOT MEASURED" << "\t\t  " << "NOT MEASURED" << endl;
        delete[] curArray;  //deallocation
    }
    cout << SEPERATOR << endl;
    //RADIX SORT TEST ENDS
    //ALL OF THE TESTS END
}


