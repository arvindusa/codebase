#ifndef UNIONHEADER_H
#include "unionHeader.h"
#endif
#include <iostream>
namespace UnionApproach{
	//prints data from vector of SItem
	void showData(const std::vector<SItem>& data) {
		std::vector<SItem>::const_iterator it;
		int d_counter=0;
		for(it=data.begin(); it!=data.end(); ++it){
			std::cout << "Element Number: " 
				<< d_counter << std::endl;
			d_counter++;
			printItem(*it);
		}
	}
	// prints Item based on its type
	void printItem(const SItem& item) {
		switch(item.d_type){
			case PHONE:
				print(item.d_item.d_phoneExtension);
				break;
			case AGE:
				print(item.d_item.d_age);
				break;
			case HOUSE:
				print(item.d_item.d_houseNumber);
				break;
		};
	}	
	//overloaded print method
	void print(const struct PhoneExtension& phoneExtension){
		std::cout << "Phone Extension (" 
			<< phoneExtension.d_areaCode << ") "
			<< phoneExtension.d_sevenDigitNumber
			<< std::endl;
	}
	void print(const unsigned int age) {
		std::cout << "Age " << age << std::endl;
	}
	void print(const unsigned long houseNumber) {
		std::cout << "House number " << houseNumber << std::endl;
	}

}
