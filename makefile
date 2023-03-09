cfetch: ./src/cfetch.o ./src/modules/model.o
	g++ -o cfetch ./src/cfetch.o ./src/modules/model.o

cfetch.o: ./src/cfetch.cpp
	g++ -c ./src/cfetch.cpp

./src/model.o:
	g++ -c ./src/modules/model.cpp
