/*
 
Name:  Chad Parnin
Date:  11/12/14.
File:  quicksort.cpp
Description:
 
*/

#include <iostream>
#include <fstream>
#include <pthread.h>
// not using namespace to speed up a bit (?)

int partition ( int *p[], int first, int last );
void swap ( int *a, int *b );
void quicksort ( int *p[], int first, int last );

//int is_sorted ( int a[], int n )
//{
//    int i;
//    for ( i = 0; i < n - 1; i++ )
//    {
//        if ( a[i] > a[i + 1] )
//            return 0;
//    }
//    return 1;
//}


int main()
{
    std::ifstream infile;
    infile.open("test500.txt");
    
    if (infile.good())
    {
        int *p;
        int sizeOfArray;
        std::cout << "Size of array?\n";
        std::cin >> sizeOfArray;
        p = new int[sizeOfArray];

        for (int i = 0; i < sizeOfArray; ++i)
        {
            infile.get() >> p[i];
        }
        
        
        
        delete [] p;
        infile.close();
        
    }
    else
        std::cout << "Error Reading File/n";
    
    return 0;
}

int partition ( int *p[], int first, int last )
{
    int pivot, mid = ( first + last ) / 2;
    /* Largest of two */
    pivot = p[first] > p[mid] ? first : mid;
    
    /* Smallest of remaining */
    if ( p[pivot] > p[last] )
        pivot = last;
    swap ( p[pivot], p[first] );
    pivot = first;
    while ( first < last )
    {
        if ( p[first] <= p[last] )
            swap ( p[pivot++], p[first] );
        ++first;
    }
    swap ( p[pivot], p[last] );
    return pivot;
}

void swap ( int *a, int *b )
{
    int c = *a;
    *a = *b;
    *b = c;
}

void quicksort ( int *p[], int first, int last )
{
    if ( first < last )
    {
        int pivot = partition ( p, first, last );
        quicksort ( p, first, pivot - 1 );
        quicksort ( p, pivot + 1, last );
    }
}


/*

 #include <iostream>
 2 #include <time.h>
 3 #include <sys/time.h>
 4 using namespace std;
 5
 6 void test_1(int x[]);
 7 void test_2(int y[]);
 8
 9 int main()
 10 {
 11     struct timeval b,e;
 12     gettimeofday (&b, NULL);
 13
 14     int num[2000000] = {0};
 15     for (int i = 0; i < 2000000; i++)
 16     num[i] = i+1;
 17
 18     test_1(num);
 19     test_2(num);
 20
 21     gettimeofday (&e, NULL);
 22     cout << "It took " << ( ( e.tv_sec - b.tv_sec ) + ( e.tv_usec - b.tv_us    ec ) * 1e-6) << " seconds." << endl << endl;
 23
 24     return 0;
 25 }
 26
 27 void test_1(int x[])
 28 {
 29     int sum1 = 0;
 30     for (int i = 0; i < 1000000; i++)
 31     sum1 += x[i];
 32     cout << sum1 << endl;
 33 }
 34
 35 void test_2(int y[])
 36 {
 37     int sum2 = 0;
 38     for (int i = 1000000; i < 2000000; i++)
 39     sum2 += y[i];
 40     cout << sum2 << endl;
 41 }
 
 */