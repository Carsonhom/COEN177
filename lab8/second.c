#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {//to 
    int pageno;
    int chance;
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file

    int i, j;
    int totalFaults = 0; // keeps track of the total page faults
    int counter = 0;    
    int totalRequests = 0;

    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
	 cache[i].chance = 0;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
    	/*
		Page Replacement Implementation Goes Here 
    	*/
	totalRequests++;
	for(i = 0; i < C_SIZE; i++) // iterate through items in array
	{
		if(cache[i].pageno == page_num) // page_num already exists in cache array
		{
			if(cache[i].chance == 0) // set second chance to 1
				cache[i].chance = 1;
			break;
		}
		else if(i == C_SIZE - 1) // page_num is not already in cache
		{
			totalFaults++; // increment total number of faults
			for(j = counter; j < C_SIZE; j++) // loop through array starting at index counter
			{
				if(cache[j].chance == 1) // check second chance bit
				{
					cache[j].chance = 0; // page j already had a second chance, reset chance bit
					counter++; // increment counter
					if(counter == C_SIZE) // counter reaches end of array
					{
						counter = 0; // reset counter
						j = -1; // reset iterater variable
					}
				}
				else // not second chance
				{
					cache[j].pageno = page_num; // replace pageno
					cache[j].chance = 0; // reset chance
					counter++;
					if(counter == C_SIZE)
					{
						counter = 0;
					}
					break;
				}
			}
		}
	}
		
    }
    float hitRate = ((totalRequests - totalFaults) / (float) totalRequests);
    printf("%d Total Page Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hit Rate\n", hitRate);
    return 0;



}
