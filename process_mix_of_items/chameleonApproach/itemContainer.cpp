#ifndef ITEMCONT_H
#include "itemContainer.h"
#endif
#include <iostream>
namespace ChameleonApproach{
    typedef std::vector<Item*> Items;
    Items ItemContainer::d_items;
    void ItemContainer::add(House h){
        Item* houseItem=new Item(h);
        ItemContainer::add(houseItem);
    }
    void ItemContainer::add(PhoneExtension ph){
        Item* phoneExtensionItem=new Item(ph);
        ItemContainer::add(phoneExtensionItem);
    }
    void ItemContainer::add(Age ag){
        Item* ageItem=new Item(ag);
        ItemContainer::add(ageItem);
    }
    void ItemContainer::add(Item* p){
        ItemContainer::d_items.push_back(p);
    }
    void ItemContainer::printItems(){
        Items::iterator it;
        int i=1;
        for(it=ItemContainer::d_items.begin();
                it!=ItemContainer::d_items.end();
                ++it){
            std::cout << "Element at index number " << i << " is ";
            (*it)->print();
            i++;
        }
    }
    void ItemContainer::exit(){
        Items::iterator it;
        for(it=ItemContainer::d_items.begin();
                it!=ItemContainer::d_items.end();
                ++it){
            Item* p = (*it);
            delete p;
        }
    }
}
