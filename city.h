#ifndef CITY_H
#define CITY_H

#include <stdlib.h>

class City
{
    public:        

        float longitude;
        float latitude;
        char *name;
        char *state;
        char *airport;
        float population;
    
        // sets default values
        void initialize();
    
        // parses line from airportsLL.txt
        void readAirport(char *airports);
    
        // parses line from citypopulations.csv
        void readCities(char *name, char *state, float population);
            
        // true if cities have identical names
        bool isEqual(City city2);
        
        //set airport of local City variable of findAirport()
        void setAirport(char *airportName);
    
        // DO THIS ONE LATER
        void copyLocation(City city2);
    
        // true if city has airport
        bool hasAirport();
    
        // calculate distance between airports
        double calcDistance(City city2);
        
        double calcPopulation(City city2);
    
        // kills memory leaks or unrecoverable space
        void deallocate();
        
}; //endclass


#endif
