flags = -Wall -Werror -MP -MMD -std=c++14
bus = build/src
bis = bin
but = build/test
bit = bin/test

all: clean1 bin/main.exe $(bit) run clean2

bin/main.exe: $(bus)/main.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o $(bus)/cordy.o $(bus)/rad.o
	g++ $(flags) $(bus)/main.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o $(bus)/cordy.o $(bus)/rad.o -o bin/main.exe -lm

$(bus)/main.o: src/main.cpp
	g++ $(flags) -c src/main.cpp -o $(bus)/main.o

$(bus)/per.o: src/per.cpp
	g++ $(flags) -c src/per.cpp -o $(bus)/per.o

$(bus)/calc.o: src/calc.cpp
	g++ $(flags) -c src/calc.cpp -o $(bus)/calc.o -lm

$(bus)/square.o: src/square.cpp
	g++ $(flags) -c src/square.cpp -o $(bus)/square.o -lm

$(bus)/cordy.o: src/cordy.cpp
	g++ $(flags) -c src/cordy.cpp -o $(bus)/cordy.o -lm

$(bus)/rad.o: src/rad.cpp
	g++ $(flags) -c src/rad.cpp -o $(bus)/rad.o -lm

$(bit): $(but)/func_tests.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o $(bus)/cordy.o $(bus)/rad.o
	g++ $(flags) $(but)/func_tests.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o $(bus)/cordy.o $(bus)/rad.o -o $(bit) -lm

$(but)/func_tests.o: test/func_tests.cpp
	g++ $(flags) -I thirdparty -I src -c test/func_tests.cpp -o $(but)/func_tests.o -lm

run: $(bit)
	./$(bit)

clean1:
	rm -rf $(bus)/*.o
	rm -rf $(bus)/*.d
	rm -rf $(but)/*.o
	rm -rf $(but)/*.d
	rm -rf $(bis)/*.exe

clean2:
	rm -rf $(bus)/*.o
	rm -rf $(bus)/*.d
	rm -rf $(but)/*.o
	rm -rf $(but)/*.d
	rm -rf $(bis)/*.exe
	
.PHONY: all clean
