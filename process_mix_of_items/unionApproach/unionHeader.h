#ifndef UNIONHEADER_H
#define UNIONHEADER_H
#define PH_EXT_COUNT 2
#include <vector>
namespace UnionApproach{
/*
* APPROACH:
* Maintain a vector of SItems, where
* SItem = struct of two elements: itemType, Item
* Item = Union of phoneExtension, age and house numbers
*/
	enum ItemType {PHONE=1, AGE=2, HOUSE=3};
	
	struct PhoneExtension{
		unsigned int d_areaCode;
		unsigned long d_sevenDigitNumber;
	};

	union Item{
		struct PhoneExtension d_phoneExtension;
		unsigned int d_age;
		unsigned long d_houseNumber;
	};
	typedef enum ItemType ItemType;
	
	struct ItemS{
		ItemType d_type;
		union Item d_item;
	};
	typedef struct ItemS SItem;
	
	void showData(const std::vector<SItem>& data) ;
	void printItem(const SItem& item) ;
	void print(const struct PhoneExtension& phoneExtension) ;
	void print(const unsigned int age) ;
	void print(const unsigned long houseNumber) ;
}
#endif
