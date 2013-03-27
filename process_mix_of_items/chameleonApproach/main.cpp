#ifndef CHAMELEON_H
#include "chameleon.h"
#endif
#include <iostream>
#include <vector>
using namespace ChameleonApproach;
using namespace std;
int main(int argc, char*argv[]){
	std::vector<Item> items;
	Item age1(33);
	Item age2(1121);
	age2=age1;
	items.push_back(age1);
	items.push_back(age2);	

	items[0].print();
}

