BIN=./bin/
SRC=./src/

$(BIN)cfetch: $(SRC)/cfetch.o $(SRC)/modules/model.o $(SRC)/modules/ram.o
	g++ -o $(BIN)/cfetch $(SRC)/cfetch.o $(SRC)/modules/model.o $(SRC)/modules/ram.o

$(SRC)cfetch.o: $(SRC)/cfetch.cpp
	g++ -c $(SRC)cfetch.cpp

$(SRC)modules/model.o: $(SRC)/modules/model.cpp $(SRC)/modules/modules.h
	g++ -c $(SRC)/modules/model.cpp

$(SRC)modules/ram.o: $(SRC)/modules/ram.cpp $(SRC)/modules/modules.h
	g++ -c $(SRC)/modules/ram.cpp

clean:
	rm $(SRC)/cfetch.o $(SRC)/modules/model.o $(SRC)/modules/ram.o
