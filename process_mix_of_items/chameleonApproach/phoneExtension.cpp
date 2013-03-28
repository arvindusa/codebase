#ifndef PHONEEXT_H
#include "phoneExtension.h"
#endif
namespace ChameleonApproach{
    std::ostream& operator<<(std::ostream& pout, 
            const PhoneExtension& phoneExt){
        return pout << "a Phone Extension (" << phoneExt.getAreaCode() 
            << ") " << phoneExt.getSevenDigitNumber() << std::endl;
    }
   unsigned long PhoneExtension::getSevenDigitNumber() const {
       return d_sevenDigitNumber;
   }
   unsigned int PhoneExtension::getAreaCode() const {
       return d_areaCode;
   }
}
