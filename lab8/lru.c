#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {//to 
    int pageno;
    int index; // keeps track of most recent page
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file

    int i, j;
    int totalFaults = 0; // keeps track of the total page faults
    int oldest; // keeps track of the oldest page index
    int oldestPos; // keeps track of the oldest page position
    int placeInArray = 0;    
    int totalRequests = 0;

    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
	 cache[i].index = 0;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
	totalRequests++;
    	/*		
		Page Replacement Implementation Goes Here 
    	*/
	for(i = 0; i < C_SIZE; i++) // increment through cache array
	{
		oldest = cache[i].index; // assign temporary oldest index
		if(cache[i].pageno == page_num) // already in cache array
		{
			for(j = 0; j < C_SIZE; j++) // increment index of all items in array
			{
				if(cache[j].index < cache[i].index)
					cache[j].index++;
			}
			cache[i].index = 0; // reset index of item i
			break;
		}
		else if(i == C_SIZE - 1) // array is full and page_num is not already in array
		{
			totalFaults++; // increment number of faults
			for(j = 0; j < C_SIZE; j++) // increment index of all items in array
			{
				cache[j].index++;
			}
			for(j = 0; j < C_SIZE; j++) // increment through cache array
			{
				if(cache[j].index > oldest) // an older item than the current oldest is found
				{
					oldestPos = j; // update the position of oldest item
					oldest = cache[j].index; // update oldest
				}
			}
			cache[oldestPos].pageno = page_num; // replace oldest item
			cache[oldestPos].index = 0; // reset index of the oldest item
		}
	}
			
					
    }
    float hitRate =  ((totalRequests - totalFaults) / (float) totalRequests);
    printf("%d Total Page Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hitrate\n", hitRate);
    return 0;



}
