#ifndef ITEMCONT_H
#define ITEMCONT_H
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
#include <vector>
namespace ChameleonApproach{
    struct ItemContainer{
        public:
            static void add(House h);
            static void add(Age a);
            static void add(PhoneExtension ph);
            static void printItems() ;
            static void exit();
        private:
            static void add(Item* p);
            static std::vector<Item*> d_items;
    };

}
#endif
