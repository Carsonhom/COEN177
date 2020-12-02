#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int placeInArray = 0; // keeps track of the current cache index
    int totalRequests = 0;    

    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
	totalRequests++;
    	/*
		Page Replacement Implementation Goes Here 
    	*/
	for(i = 0; i < C_SIZE; i++) // increment through entire cache array
	{	
		if(cache[i].pageno == page_num) // page_num already in cache
			break;
		if(i == C_SIZE - 1) // page_num not already in array
		{
			//printf("Page %d caused a page fault\n", page_num);
			totalFaults++; // increment totalFaults
			cache[placeInArray].pageno = page_num; // input page_num into cache array
			placeInArray++; // increment array index
			if(placeInArray == C_SIZE) // reset placeInArray at the end of the cache array
			{
				placeInArray = 0;
			}
		}
	}
    }
    float hitRate = (( totalRequests - totalFaults) / (float) totalRequests);
    printf("%d Total Page Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hit Rate\n", hitRate);
    return 0;



}
