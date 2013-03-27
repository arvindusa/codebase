#ifndef AGEPROPERTY_H
#include "ageProperty.h"
#endif
#include <iostream>
namespace InheritenceApproach{
	void Age::print(int index) const{
		std::cout << "Element at index number " << index 
			<< " is an Age " << d_age
			<< std::endl;
	}
}
