#ifndef ITEMWRAPPER_H
#include "itemWrapper.h"
#endif
#include <iostream>
namespace ItemWrapperApproach{
	ItemWrapper::ItemWrapper(short age){
		d_type=AGE;
		d_item.push_back(age);
	}
	ItemWrapper::ItemWrapper(int areaCode, int sevenDigitNumber){
		d_type=PHONE;
		d_item.push_back(areaCode);
		d_item.push_back(sevenDigitNumber);
	}
	ItemWrapper::ItemWrapper(int houseNumber){
		d_type=HOUSE;
		d_item.push_back(houseNumber);
	}
	ItemWrapper::ItemWrapper(unsigned int areaCode, unsigned long sevenDigitNumber){
		d_type=PHONE;
		d_item.push_back(areaCode);
		d_item.push_back(sevenDigitNumber);
	}
	ItemWrapper::ItemWrapper(unsigned long houseNumber){
		d_type=HOUSE;
		d_item.push_back(houseNumber);
	}
	ItemWrapper::ItemWrapper(unsigned int age){
		d_type=AGE;
		d_item.push_back(age);
	}
	void ItemWrapper::print() const{
		switch(d_type){
			case PHONE:
				printPhone();
				break;
			case AGE:
				printAge();
				break;
			case HOUSE:
				printHouse();
				break;
		};	
	}
	void ItemWrapper::printHouse() const{
		if(d_item.size() == 1){
			std::cout << "House " << d_item[0] << std::endl;
		}
	}
	void ItemWrapper::printAge() const {
		if(d_item.size() == 1) {
			std::cout << "Age " << d_item[0] << std::endl;
		}
	}
	void ItemWrapper::printPhone() const {
		if(d_item.size() == 2){
			std::cout << "Phone Extension (" << d_item[0] 
			<< ") " << d_item[1] << std::endl;
		}
	}
}
