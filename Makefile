simulator.out: main.o vector.o city.o
	g++ -Wall -ansi -g -o simulator.out main.o vector.o city.o

main.o: main.cpp vector.h
	g++ -Wall -ansi -g -c main.cpp

vector.o: vector.cpp vector.h city.h
	g++ -Wall -ansi -g -c vector.cpp

city.o: city.cpp city.h
	g++ -Wall -ansi -g -c city.cpp

clean: 
	rm simulator.out main.o vector.o city.o
