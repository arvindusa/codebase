#ifndef PHONEDERIVED_H
#include "phoneProperty.h"
#endif
#include <iostream>
namespace InheritenceApproach{
	void Phone::print(int index) const {
		std::cout << "Element at index number " << index 
			<< " is a Phone Extension (" << d_areaCode << ")" 
				<< d_sevenDigitNumber << std::endl;
	}
}
