all: fat.o pri.o
	g++ fat.o pri.o main.cpp -o main
pri.o: pri.h
	g++ -c pri.cpp
fat.o: fat.h
	g++ -c fat.cpp
clean:
	rm -rf *.o