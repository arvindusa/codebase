#ifndef AGE_H
#include "age.h"
#endif
namespace ChameleonApproach{
    std::ostream& operator<<(std::ostream& pout,
            const Age& age){
        return pout << "an Age " << age.getAge() << std::endl;
    }
    unsigned int Age::getAge() const{
        return d_age;
    }
}
