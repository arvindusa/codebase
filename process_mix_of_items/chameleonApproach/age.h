#ifndef AGE_H
#define AGE_H
#include <iostream>
namespace ChameleonApproach{
    class Age{
        public:
                Age() {}
                Age(int age):d_age(age){}
                Age(unsigned int age):d_age(age){}
                friend std::ostream& operator<<(std::ostream& out, 
                        const Age&age);
                unsigned int getAge() const;
         private:
                unsigned int d_age;
    };
}
#endif
