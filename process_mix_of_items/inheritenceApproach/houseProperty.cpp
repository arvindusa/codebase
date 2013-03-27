#ifndef HOUSEPROPERTY_H
#include "houseProperty.h"
#endif
#include <iostream>
namespace InheritenceApproach{
	void House::print(int index) const {
		std::cout << "Element at index number " << index 
			<< " is a House number " << d_houseNumber 
			<< std::endl;
	}
}
