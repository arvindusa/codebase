#ifndef ITEM_H
#include "item.h"
#endif
#ifndef AGE_H
#include "age.h"
#endif
#ifndef PHONEEXT_H
#include "phoneExtension.h"
#endif
#ifndef HOUSE_H
#include "house.h"
#endif
#ifndef ITEMCONT_H
#include "itemContainer.h"
#endif
#include <iostream>
#include <vector>
using namespace ChameleonApproach;
using namespace std;

int main(int argc, char*argv[]){
    PhoneExtension ph1(313,4567892);
    PhoneExtension ph2(800, 3334455);

    Age a1(39);
    Age a2(21);

    House h1(44842);

    ItemContainer::add(ph1);
    ItemContainer::add(ph2);
    ItemContainer::add(a1);
    ItemContainer::add(h1);
    ItemContainer::add(a2);

    ItemContainer::printItems();
    ItemContainer::exit();
}

