#ifndef PHONEDERIVED_H
#define PHONEDERIVED_H
#ifndef BASE_H
#include "property.h"
#endif
namespace InheritenceApproach{
	class Phone:public Property{
		public:
			Phone(int areaCode, int sevenDigitNumber):Property(),
					d_areaCode(areaCode), 
					d_sevenDigitNumber(sevenDigitNumber){}
			~Phone();
			void print(int index) const;
		private:
			unsigned int d_areaCode;
			unsigned long d_sevenDigitNumber;
	};
}
#endif
