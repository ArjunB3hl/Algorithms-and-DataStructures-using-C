#include "mySort.h"

void merge(int arr[],int a1, int b1, int a2,int b2)
{
	int temp[MAX_SIZE_N_TO_SORT]; //the array that will be used for merging
	int a,b,c;
	a = a1;
	b = a2;
	c = 0;
	
	while(a<=b1 && b<=b2) // while the elements are in both lists
	{
		if(myCompare(arr[a],arr[b]) < 0)
			temp[c++] = arr[a++];
		else
			temp[c++] = arr[b++];		
    }
	
	while(a<=b1) //copying remaining elements of the first list
		myCopy(&arr[a++],&temp[c++]) ;
	while(b<=b2) //copying remaining elements of the second list
		myCopy(&arr[b++],&temp[c++]);
		
	for(a=a1,c=0;a<=b2;a++,c++)//swapping the elements from temp[] to arr[]
	mySwap(&arr[a],&temp[c]);
}
void mySort(int array[], unsigned int first, unsigned int last)
{ 
    int middle;

    if(first < last)
    {
       middle = (first+last)/2;
       mySort(array,first,middle);
	   mySort(array,middle+1,last);
	   merge(array,first,middle,middle+1,last);
    }
}

