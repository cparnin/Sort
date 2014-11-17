/*************************************************
 
Name:  Chad Parnin
Date:  11/13/14
File:  quicksort.cpp
Description:  Quicksort implementation on array
 
*************************************************/

#include <iostream>
//#include <pthread.h>
#include <sys/time.h>
#include <ctime> // REMOVE BEFORE TURNING IN

//int partition ( int p[], int first, int last ); // Median of Three partition (slower)
void swap ( int &a, int &b );
void quicksort ( int p[], int first, int last );

int main()
{
    srand(time(NULL)); // seed RNG - REMOVE BEFORE TURNING IN

    struct timeval before, after; // timing variables
    double timing;
    
    std::cout << "Size of array?\n";
    int sizeOfArray;
    std::cin >> sizeOfArray;
    int *p = new int[sizeOfArray]; // create dynamic array
    for (int i = 0; i < sizeOfArray; ++i)
        //std::cin >> p[i]; // used for cin redirection (Linux = ./a.out < test.txt)
        p[i] = rand() % 100; // randomize the array - REMOVE BEFORE TURNING IN
    
    gettimeofday(&before, 0); // start timing
    quicksort(p, 0, sizeOfArray-1); // sort it
    gettimeofday(&after, 0); // end timing
    
    timing = (double) ((double)after.tv_sec +
                      (double)after.tv_usec/(1000*1000)) -
                      (double) ((double)before.tv_sec +
                      (double)before.tv_usec/(1000*1000));
    
    //for (int i = 0; i < sizeOfArray; ++i) // output array
      //  std::cout << p[i] << std::endl;
    
    std::cout << "Quicksort took " << timing << "seconds\n"; // output timing information
 
    delete [] p; // delete dynamic array
    
    return 0;
}

void swap ( int &a, int &b )
{
    int c = a;
    a = b;
    b = c;
}

void quicksort(int p[], int first, int last)
{
    if (last <= first)
        return;
    //int median = (p[first] + p[last] + p[(first+last)/2]) / 3;
    //swap(p[first],median);
    int pivot = p[first];
    int i=first+1, j=last;
    while (i<j)
    {
        while (p[i] < pivot && i<j)
            i++;
        while (p[j] > pivot)
            j--;
        if (i<j)
            swap(p[i++], p[j--]);
    }
    if (p[j] > pivot)
        j--;
    swap(p[j], p[first]);
    quicksort(p, first, j-1);
    quicksort(p, j+1, last);
} // quicksort()


//int partition ( int p[], int first, int last )
//{
//    int pivot, mid = ( first + last ) / 2;
//    /* Largest of two */
//    pivot = p[first] > p[mid] ? first : mid;
//    
//    /* Smallest of remaining */
//    if ( p[pivot] > p[last] )
//        pivot = last;
//    swap ( p[pivot], p[first] );
//    pivot = first;
//    while ( first < last )
//    {
//        if ( p[first] <= p[last] )
//            swap ( p[pivot++], p[first] );
//        ++first;
//    }
//    swap ( p[pivot], p[last] );
//    return pivot;
//}

//void quicksort ( int p[], int first, int last )
//{
//    if ( first < last )
//    {
//        int pivot = partition ( p, first, last );
//        quicksort ( p, first, pivot - 1 );
//        quicksort ( p, pivot + 1, last );
//    }
//}






