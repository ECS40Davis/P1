#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "city.h"
#include <fstream>
                      
void Vector::initialize()
{
    count = 0;
    size = 10;
    cityArray = (City*) malloc(10 * sizeof(City));
        
} // initialize()
                      
void Vector::resize()
{
  if (count == size)
  {
    City *newSpace = (City*) malloc(2 * size * sizeof(City));
    
    for (int i = 0; i < size; i++)
    {
        newSpace[i] = cityArray[i];
        //cityArray[i].deallocate();
        
    } //for loop
    //todo: delete entire cityArray
    cityArray = newSpace;
    size *= 2;
      
  } //if

} // resize()
                      
void Vector::readAirports()
{
    
    //supposed to call isEqual() and copyLocation()
    std::fstream file;
    std::string line;
    char airport[100];
    float latitude;
    float longitude;
    char name[100];
    
    file.open("airportsLL.txt");
    
    while(std::getline(file, line))
    {
        char *cstring = strdup(line.c_str());
       
        int fsf = sscanf(cstring, "%s  %f  %f  %[^\n]%*c", 
                airport, &latitude, &longitude, name);
        
        if (fsf == 4)
        {
            strtok(name, ",");
            strtok(NULL, "/0");
            City tempCity;
            tempCity.initialize();
            tempCity.readAirport(cstring);
            
            for (int i = 0; i < count; i++)
            {
                
                if (tempCity.isEqual(cityArray[i]))
                {
                    cityArray[i].copyLocation(tempCity);
                } //if
            } //for
        } //if
    } //while
} // readAirports()

void Vector::readCities()
{
    char *name;
    char *state;
    int population;
    std::fstream file;
    std::string line;
    
    file.open("citypopulations.csv");
   
    while(std::getline(file, line))
    {
        char *cstring = strdup(line.c_str());
    
        name = strtok(cstring, ",");
        state = strtok(NULL, ",");
        population = atoi(strtok(NULL, "\n"));
        
        City newCity;
        newCity.initialize();
        newCity.readCities(name, state, population);
        
    
        this->cityArray[count] = newCity;
        count++;
        //printf("%s, ", name);
        //printf("%s, ", state);
        //printf("%d\n", population);
        this->resize();
    } //while
                
} // readCities()
                      
int Vector::findAirport(char *airportName)
{
    City city1;
    city1.initialize();
    city1.setAirport(airportName);
    
    for (int i = 0; i < this->count; i++)
    {
        City city2 = cityArray[i];
     
        if (strcmp(city1.airport, city2.airport) == 0)
        {
            return i;
        } //if
        
    } //for
    
    return -1;
} //int Vector::findAirport                  

void Vector::cleanCities()
{
    int airportCount = 0;   
    
    City *newSpace = (City*) malloc(size * sizeof(City));
    
    for (int i = 0; i < size; i++)
    {
        
        if (cityArray[i].hasAirport())
        {
            newSpace[airportCount] = cityArray[i];
            cityArray[i].deallocate();
            airportCount++;
            
        } //if
        
    } //for
//todo: delete entire cityArray
    count = airportCount;
    cityArray = newSpace;
} //end cleanCity

double Vector::calcDistance(char *abv1, char *abv2)
{
    int index = findAirport(abv1);
    City city1 = cityArray[index];
    
    int index2 = findAirport(abv2);
    City city2 = cityArray[index2];
    
    return city1.calcDistance(city2);
    
    //return cityArray[findAirport(abv1)].calcDistance(cityArray[findAirport(abv2)])
    
} // calcDistance()
                      
double Vector::calcPopulation(char *abv1, char*abv2)
{
    int index = findAirport(abv1);
    City city1 = cityArray[index];
    
    int index2 = findAirport(abv2);
    City city2 = cityArray[index2];
    
    return city1.calcPopulation(city2);
} //calcPop

void Vector::deallocate()
{
    
    for (int i = 0; i < count; i++)
        cityArray[i].deallocate();
    
    free(cityArray);
        
} // deallocate()

char* Vector::returnname(char *abv1)
{
    //takes in abbreviation, searches thru array for abv, return name of abv
    for (int i = 0; i < count; i++)
        if (strcmp(abv1, cityArray[i].airport) == 0)
            return cityArray[i].name;
    return strdup("City Name Not Found");
    
} //returnname

char* Vector::returnStateName(char *abv1)
{
    for (int i = 0; i < count; i++)
        if (strcmp(abv1, cityArray[i].airport) == 0)
            return cityArray[i].state;
    return strdup("State Name Not Found");
} //returnStateName

