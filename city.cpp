//Style: 0 out of 9
//Design: 18 out of 23
//Const: 1 out of 7
//Operation: 11 out of 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cstring>
#include <iostream>
#include "city.h"

#define R 3963

void City::initialize()
{
    this->name = (char *) malloc(sizeof(char) * 50);
    this->state = (char *) malloc(sizeof(char) * 50);
    this->airport = (char *) malloc(sizeof(char) * 50);
    this->longitude = 0.0;
    this->latitude = 0.0;
    this->population = 0;
    
} // initialize()

void City::readAirport(char *airports)
{
    if (airports)
    {
        char tempairport[100];
        sscanf(airports, "%s  %f  %f  %[^,]%*c", tempairport, &latitude, &longitude, name);
        std::string s (tempairport);
        this->airport = strdup(s.substr(1, 3).c_str());
        
    }	
} // readAirport()

void City::readCities(char *n, char *st, float pop)
{
    this->name = n;
    this->state = st;
    this->population = pop;
    
} // readCities()
                      
bool City::isEqual(City city2)
{
    if (strcmp(city2.name, this->name) == 0)
	return true;
    return false;
        
} // isEqual()
                      
void City::copyLocation(City city2)
{
    this->airport = city2.airport;
    this->latitude = city2.latitude;
    this->longitude = city2.longitude;    
    
} // copyLocation()
                      
void City::deallocate()
{
    
    free(name);
    free(state);
    //free(airport);
        
} // deallocate()
                      
void City::setAirport(char *airportName)
{    
    this->airport = airportName;
}
                      
bool City::hasAirport()
{
    char c;
    int i = 0;
    
    while (this->airport[i])
    {
	c = this->airport[i];

	if (!isupper(c))
            return false;
	i++;
    }
    
    return true;
    
} // hasAirport()
                      
double City::calcDistance(City city2)
{
    return (acos(sin(this->latitude * M_PI/180) * sin(city2.latitude * M_PI/180)
               + cos(this->latitude * M_PI/180) * cos(city2.latitude * M_PI/180)
               * cos(this->longitude * M_PI/180 - city2.longitude * M_PI/180))) * R;

} // calcDistance()

double City::calcPopulation(City city2)
{
    return (this->population * city2.population) / 250000000 ;
    
}

