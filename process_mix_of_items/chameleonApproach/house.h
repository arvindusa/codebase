#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
namespace ChameleonApproach{
    class House{
        public: 
            House(){}
            House(int houseNumber):d_houseNumber(houseNumber){}
            House(long houseNumber):d_houseNumber(houseNumber){}
            House(unsigned long
                    houseNumber):d_houseNumber(houseNumber){}
            House(unsigned int
                    houseNumber):d_houseNumber(houseNumber){}
            unsigned long getHouseNumber() const;
            friend std::ostream& operator<<(std::ostream &out, const House &pHouse);
        private:
               unsigned long d_houseNumber;
    };
}
#endif
