flags = -Wall -Werror
bus = build/src
bis = bin

all: bin/main.exe

bin/main.exe: $(bus)/main.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o
	g++ $(flags) $(bus)/main.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o -o bin/main.exe -lm

$(bus)/main.o: src/main.cpp
	g++ $(flags) -c src/main.cpp -o $(bus)/main.o

$(bus)/per.o: src/per.cpp
	g++ $(flags) -c src/per.cpp -o $(bus)/per.o

$(bus)/calc.o: src/calc.cpp
	g++ $(flags) -c src/calc.cpp -o $(bus)/calc.o -lm

$(bus)/square.o: src/square.cpp
	g++ $(flags) -c src/square.cpp -o $(bus)/square.o -lm

clean:
	rm -rf $(bus)/*.o
	rm -rf bin/*

.PHONY: all clean
