#ifndef HOUSEDERIVED_H
#define HOUSEDERIVED_H
#ifndef BASE_H
#include "property.h"
#endif
namespace InheritenceApproach{
	class House:public Property{
		public:
			House(int houseNumber):Property(),d_houseNumber(houseNumber){}
			~House();
			void print(int index) const;
		private:
			unsigned long d_houseNumber;
	};
}
#endif
