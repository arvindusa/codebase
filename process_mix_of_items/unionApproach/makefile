all: unionApproach

unionApproach: unionApproach.o unionHeader.o
		g++ unionApproach.o unionHeader.o -o unionApproach

unionApproach.o: unionApproach.cpp
		g++ -c unionApproach.cpp

unionHeader.o: unionHeader.cpp
		g++ -c unionHeader.cpp

clean:
	rm -rf *o unionApproach

