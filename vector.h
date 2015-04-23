#ifndef VECTOR_H
  #define VECTOR_H
#include "city.h"

class Vector
{
      public:

        City *cityArray;
        int size;
        int count;
    
      

        // sets default values
        void initialize();
    
        // double array siz if necessary
        void resize();
    
        // reads airportsLL.txt, calls City's readAirport()
        void readAirports();
    
        // read line from citypopulations.csv + store data in cityarray
        void readCities();
        
        // return city index in cityarray that has specified airport, else -1
        int findAirport(const char *airportName, const City *cityArr);
        
        void cleanCities();
    
        // calls City's calcDistance()
        void calcDistance(const Vector * vect, char *abv1, char *abv2);
    
        // kills memory leaks or unrecoverable space
        void deallocate();
        
        char *returnname(char *abv1);
        
        char *returnStateName(char *abv1);
        
}; //endclass
                      
#endif
