#ifndef VECTOR_H
#define	VECTOR_H
// Author Sean Davis

#include "city.h"
#include "plane.h"

class Vector
{
  // City Declaration
  City *cityArray;
  int size;
  int count;
  void resize();
  
  // Plane Declaration
  Plane *planeArray;
  
public:
  Vector();
  ~Vector();
  // For City
  void calcAirportTraffic(int index) const;
  void calcDistance(int index1, int index2) const;
  void cleanCities();
  int findAirport(const char *airport) const;
  void readAirports();
  void readCities();
  
  // For Plane
  int readPlanes();
};  // class Vector

#endif	// VECTOR_H 

