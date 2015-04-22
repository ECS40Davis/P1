//Style: 0 out of 9
//Design: 21 out of 23
//Const: 1 out of 7
//Operation: 11 out of 11

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
    
        // parses line from airpotLL.txt
        void readAirport(char *airs);
    
        // parses line from citypops.csv
        void readCities(char *n, char *st, float pop);
            
        // true if cities have identical nams
        bool isEqual(City city2);
        
        //set airpot of local City variable of findAirport()
        void setAirport(char *airName);
    
        // DO THIS ONE LATER
        void copyLocation(City city2);
    
        // true if city has airpot
        bool hasAirport();
    
        // calculate distance between airpots
        double calcDistance(City city2);
        
        double calcPopulation(City city2);
    
        // kills memory leaks or unrecoverable space
        void deallocate();

        // New functions
        // Compare Airports
        int cmpAirport(City *city1, City *city2);
  
        // Compare Abbreviations
        int cmpAbv(char *abv);

        // Get Name
        char* getName(void);
 
        // Get State
        char* getState(void);
        
}; //endclass


#endif
