#ifndef PROPERTYCONTAINER_H
#include "propertyContainer.h"
#endif
#ifndef PHONEDERIVED_H
#include "phoneProperty.h"
#endif
#ifndef AGEDERIVED_H
#include "ageProperty.h"
#endif
#ifndef HOUSEDERIVED_H
#include "houseProperty.h"
#endif

namespace InheritenceApproach{
	typedef std::vector<Property*> Container;
	Container PropertyContainer::items;
	void PropertyContainer::showData(){
		int i=1;
		Container::const_iterator it;
		for(it=items.begin(); 
			it!= items.end(); ++it){
			(*it)->print(i);	
			i++;
		}
	}
	void PropertyContainer::add(Property* item){
		items.push_back(item);
	}
}
