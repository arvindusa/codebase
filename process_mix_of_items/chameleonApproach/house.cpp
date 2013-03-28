#ifndef HOUSE_H
#include "house.h"
#endif
namespace ChameleonApproach{
    std::ostream& operator<<(std::ostream& out, const House& pHouse){
        return out << "a House Number " << pHouse.getHouseNumber() <<
            std::endl;
    }
    unsigned long House::getHouseNumber() const {
        return d_houseNumber;
    }
}
