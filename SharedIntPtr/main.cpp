#ifndef SHAREDPTR
#include "sharedIntPtr.h"
#endif
#include <iostream>
using namespace std;
int main(int argc, char*argv[]){
	SharedIntPtr a(new int);
	SharedIntPtr b(a);
	a.setValue(5);

	std::cout << a.print() << std::endl;
	std::cout << b.print() << std::endl;

	std::cout << "Reset a" << std::endl;
	a.reset();
//	std::cout << a.print() << std::endl;
	std::cout << b.print() << std::endl;

	std::cout << "Reset b" << std::endl;
	b.reset();
	std::cout << b.print() << std::endl;
}

