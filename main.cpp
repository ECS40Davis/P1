#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include "vector.h"

void run(Vector *cities);
                      
int main()
{
    Vector *cities = new Vector;
	    
    cities->initialize();
    cities->readCities();
    cities->readAirports();
    run(cities);
    
    return 0;
    
} // main()
                      
void run(Vector *cities)
{
    char abv1[10], abv2[10];
    //double passengers;
    //double distance;
    
    while (1)
    {
        printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
        scanf("%s %s", abv1, abv2);

        if (strcmp(abv1, "XXX") == 0 && strcmp(abv2, "XXX") == 0)
            break;
        
        if (strcmp(cities->returnStateName(abv1), "State Name Not Found") == 0)
            printf("%s is not a valid airport.\n", abv1);
        
        if (strcmp(cities->returnStateName(abv2), "State Name Not Found") == 0)
            printf("%s is not a valid airport.\n", abv2);
        
        if (strcmp(cities->returnStateName(abv1), "State Name Not Found") != 0
            && strcmp(cities->returnStateName(abv2),
            "State Name Not Found") != 0)
        {    
                cities->calcDistance(cities, abv1, abv2);
                printf("%s,%s to %s,%s\n", cities->returnname(abv1), 
                cities->returnStateName(abv1), 
                cities->returnname(abv2), 
                cities->returnStateName(abv2));
        }//if (strcmp(cities->return
    }//while(1)      
} // run()
