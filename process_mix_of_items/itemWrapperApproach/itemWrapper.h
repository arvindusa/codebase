#ifndef ITEMWRAPPER_H
#define ITEMWRAPPER_H
/*
* ItemWrapper approach:
* Idea: member variable is either 
* 	a) union of three Items 
* or  	b) make it an unsigned long array of two items
*	Assumption: all items are of type unsigned long
*	(items of type which downcast from unsigned long
*	are also contained in vector of unsigned long)
*/
#include <vector>
namespace ItemWrapperApproach{
	enum ItemType { PHONE=1, AGE=2, HOUSE=3};	
	typedef enum ItemType ItemType;
	class ItemWrapper{
		public:
			ItemWrapper(int areaCode, int sevenDigitNumber);
			ItemWrapper(short age);
			ItemWrapper(int houseNumber);

			ItemWrapper(unsigned int areaCode, unsigned long sevenDigitNumber);
			ItemWrapper(unsigned long houseNumber);
			ItemWrapper(unsigned int age);
			void print() const;
		private:
			ItemType d_type;
			std::vector<unsigned long> d_item;
			void printPhone() const;
			void printHouse() const;
			void printAge() const;
	};
}
#endif
