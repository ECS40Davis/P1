#ifndef VECTOR_H
#define VECTOR_H
#include "City.h"

class Vector
{
    public:
    
        City *cityArray;
        int size;
        int count;
    
        // sets default values
        void initialize();
    
        // double array size if necessary
        void resize();
    
        // reads airportsLL.txt, calls City's readAirport()
        void readAirports();
    
        // read line from citypopulations.csv + store data in cityArray
        void readCities();
        
        // return city index in cityArray that has specified airport, else -1
        int findAirport(char *airportName);
        
        void cleanCities();
    
        // calls City's calcDistance()
        double calcDistance(char *abv1, char *abv2);
        
        double calcPopulation(char *abv1, char*abv2);
    
        // kills memory leaks or unrecoverable space
        void deallocate();
        
        char *returnname(char *abv1);
        
        char *returnStateName(char *abv1);
        
}; //endclass
                      
#endif
