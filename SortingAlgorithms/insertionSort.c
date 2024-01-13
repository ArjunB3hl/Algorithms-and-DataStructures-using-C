#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
       int i,j,temp_var;
	  	for( i =first; i <= last; i++)
		{
		   temp_var = array[i];
		   j = i -1;
		   while( j >=0 && (myCompare(array[j],temp_var)>0))
		   {
				mySwap(&array[j+1], &array[j]);
				j = j - 1;
		    }
		   myCopy(&temp_var,&array[j + 1]);
        }
}
