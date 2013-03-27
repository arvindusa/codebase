#include <iostream>
#include <boost/any.hpp>
#include <string>
#include <vector>
using namespace std;
template <typename T>
void add(T& a, boost::any& new_any){
	new_any=&a;
}
int main(int argc, char* argv[]){
	std::cout << "Boot" << std::endl;
	int a=0;
	float b=2.121;
	std::string c="alpha";
	typedef std::vector<boost::any> any;
	any items;
	boost::any a1, b1, c1;
	add(a, a1);
	add(b, b1);
	add(c, c1);
	items.push_back(a1);
	items.push_back(b1);
	items.push_back(c1);
}
