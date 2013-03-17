#ifndef ClassB
#include "B.h"
#endif
#ifndef ClassA
#include "A.h"
#endif
#ifndef CLASSC
#define CLASSC
class ClassC:public ClassB{
	public:
		ClassC():ClassB(){ std::cout << "I am C " << std::endl;}
	private:
		ClassA a;
};
#endif
