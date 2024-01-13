#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "towers.h"

int main(int argc, char **argv)
{   int i,n, from, dest; /*
    for( i =1; i < argc; i++){
		if(argv[i] < 0 || ((isdigit(argv[i])) == 0))
		{
		   printf("The peg numbers can't be less than 0.");
		   exit(1);
		}
		if((*argv[2] > 3) || (*argv [3] > 3))
	    {
		printf("The peg numbers entered can only be between 1 and 3. ");
		exit(1);
	    }	
	    else if(argc >4)
	    {
		printf("You can't enter more than four command line arguments.");
		exit(1);
	    }
	} */
	if(argc == 1){
      n = 3;
      from = 1;
      dest = 2;  
	  towers(n, from, dest);
    }
    else if( argc ==2){ 
	  n = atoi(argv[1]);
	  towers(n, 1, 2);
	}
	else if( argc ==4){
	  n = atoi(argv[1]);
	  from = atoi(argv[2]);
	  dest = atoi(argv[3]);
	  towers(n, from, dest);
	}
    exit(0);
}

