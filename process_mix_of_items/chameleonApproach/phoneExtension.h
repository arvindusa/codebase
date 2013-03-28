#ifndef PHONEEXT_H
#define PHONEEXT_H
#include <iostream>
namespace ChameleonApproach{
class PhoneExtension{
    public:
            PhoneExtension(){}
            PhoneExtension(unsigned int areaCode, unsigned long
                    sevenDigitNumber):d_areaCode(areaCode),
            d_sevenDigitNumber(sevenDigitNumber){}
            PhoneExtension(int areaCode, long
                    sevenDigitNumber):d_areaCode(areaCode),d_sevenDigitNumber(sevenDigitNumber){}
            unsigned long getSevenDigitNumber() const;
            unsigned int getAreaCode() const;
            friend std::ostream& operator<<(std::ostream& out, 
                    const PhoneExtension& phoneExt);
     private:
            unsigned long d_sevenDigitNumber;
            unsigned int d_areaCode;
};
}
#endif
