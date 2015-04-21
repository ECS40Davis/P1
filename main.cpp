//Style: 0 out of 9
//Design: 14 out of 23
//Const: 1 out of 7
//Operation: 11 out of 11

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
    double passengers;
    double distance;
    
    while (1)
    {
        printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
        scanf("%s %s", abv1, abv2);
    
        distance = cities->calcDistance(abv1, abv2);
        passengers = cities->calcPopulation(abv1, abv2);
        if (distance < 100)
            passengers = 0;
        if (strcmp(abv1, "XXX") == 0 && strcmp(abv2, "XXX") == 0)
        {
            break;
        }
        
        if (strcmp(cities->returnStateName(abv1),"State Name Not Found") == 0 && strcmp(cities->returnStateName(abv2),"State Name Not Found") != 0)
        {
            printf("%s is not a valid airport.\n", abv1);
            continue;
        }

        if (strcmp(cities->returnStateName(abv1),"State Name Not Found") == 0 && strcmp(cities->returnStateName(abv2),"State Name Not Found") == 0)
        {
            printf("%s is not a valid airport.\n", abv1);
            printf("%s is not a valid airport.\n", abv2);
            continue;
        }
        
        if (strcmp(cities->returnStateName(abv1),"State Name Not Found") != 0 && strcmp(cities->returnStateName(abv2),"State Name Not Found") == 0)
        {
            printf("%s is not a valid airport.\n", abv2);
            continue;
        }
        
        if (strcmp(cities->returnStateName(abv1),"State Name Not Found") != 0 && strcmp(cities->returnStateName(abv2),"State Name Not Found") != 0)
        {    printf("%.0f passengers fly the %.0f miles from\n", floor(passengers), floor(distance));
             printf("%s,%s to %s,%s\n", cities->returnname(abv1), 
                cities->returnStateName(abv1), 
                cities->returnname(abv2), 
                cities->returnStateName(abv2));
   
        }
    }        
} // run()
