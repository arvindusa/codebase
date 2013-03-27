all: itemWrapper

itemWrapper: main.o itemWrapper.o
		g++ main.o itemWrapper.o -o itemWrapper

main.o: main.cpp
	g++ -c main.cpp

itemWrapper.o: itemWrapper.cpp
	g++ -c itemWrapper.cpp

clean:
	rm -rf *o 
