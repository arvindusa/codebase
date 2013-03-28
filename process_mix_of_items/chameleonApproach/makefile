all: chameleon

chameleon: main.o invalidException.o itemContainer.o item.o house.o age.o phoneExtension.o
	g++ main.o invalidException.o itemContainer.o item.o house.o age.o phoneExtension.o -o chameleon

main.o: main.cpp
	g++ -c main.cpp

invalidException.o: invalidException.cpp
		g++ -c invalidException.cpp

itemContainer.o: itemContainer.cpp
		g++ -c itemContainer.cpp

item.o: item.cpp
	g++ -c item.cpp

house.o:house.cpp
	g++ -c house.cpp

age.o: age.cpp
	g++ -c age.cpp

phoneExtension.o: phoneExtension.cpp
		g++ -c phoneExtension.cpp

clean:
	rm -rf *o chameleon
