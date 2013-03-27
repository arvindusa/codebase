#ifndef AGEDERIVED_H
#define AGEDERIVED_H
#ifndef BASE_H
#include "property.h"
#endif
namespace InheritenceApproach{
	class Age:public Property{
		public:
			Age(int age):Property(),
				d_age(age){}
			~Age();
			void print(int index) const;
		private:
			unsigned int d_age;	
	};
}
#endif
