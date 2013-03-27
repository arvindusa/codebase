#include <iostream>
#ifndef ITEMWRAPPER_H
#include "itemWrapper.h"
#endif
#include <vector>
using namespace std;
using namespace ItemWrapperApproach;
void showData(std::vector<ItemWrapper>& pItems) {
	std::vector<ItemWrapper>::const_iterator it;
	int i=1;
	for(it=pItems.begin(); it!=pItems.end(); ++it){
		std::cout << "Element index number " << i << " is a "; 
		(*it).print();
		i++;
	}
}
int main (int argc, char*argv[]){

	ItemWrapper ph1(313,7834923);
	ItemWrapper ph2(313,3334455);
	ItemWrapper age1((short)39);
	ItemWrapper age2((short)21);
	ItemWrapper hn1(44842);
	
	std::vector<ItemWrapper> items;
	items.push_back(ph1);
	items.push_back(ph2);
	items.push_back(age1);
	items.push_back(hn1);
	items.push_back(age2);
	
	showData(items);
}
