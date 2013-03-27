all: inheritItems

inheritItems: main.o propertyContainer.o property.o phoneProperty.o houseProperty.o ageProperty.o
		g++ main.o propertyContainer.o property.o phoneProperty.o houseProperty.o ageProperty.o -o inheritItems

main.o: main.cpp
	g++ -c main.cpp

propertyContainer.o:propertyContainer.cpp
		g++ -c propertyContainer.cpp propertyContainer.h

property.o:property.cpp
		g++ -c property.cpp property.h

houseProperty.o:houseProperty.cpp
		g++ -c houseProperty.cpp houseProperty.h

ageProperty.o:ageProperty.cpp
		g++ -c ageProperty.cpp ageProperty.h

phoneProperty.o:phoneProperty.cpp
		g++ -c phoneProperty.cpp phoneProperty.h

clean:
	rm -rf *o inheritItems
