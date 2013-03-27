#ifndef PROPERTYCONTAINER_H
#define PROPERTYCONTAINER_H
#ifndef BASE_H
#include "property.h"
#endif
#include <vector>
namespace InheritenceApproach{
	struct PropertyContainer{
		public:
			static void showData();
			static void add(Property* );	
			static std::vector<Property*> getContainer();
		private:
			static std::vector<Property*> items;
	};
}
#endif
