flags = -Wall -Werror -MP -MMD
bus = build/src
bis = bin
but = build/test
bit = bin/test.exe

all: clean bin/main.exe $(bit) ./$(bit)

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

$(bit): $(but)/func_tests.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o
	g++ $(flags) $(but)/func_tests.o $(bus)/per.o $(bus)/calc.o $(bus)/square.o -o $(bit)

$(but)/func_tests.o: test/func_tests.cpp
	g++ $(flags) -I thirdparty -I src -c test/func_tests.cpp -o $(but)/func_tests.o

clean:
	rm -rf $(bus)/*.o
	rm -rf $(bus)/*.d
	rm -rf $(but)/*.o
	rm -rf $(but)/*.d

.PHONY: all clean
