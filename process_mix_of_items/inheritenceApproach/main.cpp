#include <iostream>
#ifndef PHONEDERIVED_H
#include "phoneProperty.h"
#endif
#ifndef AGEDERIVED_H
#include "ageProperty.h"
#endif
#ifndef HOUSEDERIVED_H
#include "houseProperty.h"
#endif
#ifndef PROPERTYCONTAINER_H
#include "propertyContainer.h"
#endif
using namespace std;
using namespace InheritenceApproach;
int main(int argc, char* argv[]){
	Phone* ph1= new Phone(313,5467892);
	Phone* ph2= new Phone(800,3334455);
	Age* a1= new Age(39);
	Age* a2= new Age(21);
	House* h1= new House(44842);

	PropertyContainer::add(ph1);
	PropertyContainer::add(ph2);
	PropertyContainer::add(a1);
	PropertyContainer::add(h1);
	PropertyContainer::add(a2);
	
	PropertyContainer::showData();
}
