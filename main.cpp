#include <iostream>
using namespace std;
class Animal{
	public:
		Animal() { std::cout << "Calling Animal " << std::endl; }
		Animal(const Animal &p){
			std::cout << "Calling Animal CC" << std::endl; 
		}
		virtual void render() { std::cout << "Animal" << std::endl; }
};
class Tiger:public Animal{
	public:
		Tiger():Animal() {std::cout << "Calling Tiger() " << std::endl; }
		Tiger(const Tiger &t){
			std::cout <<" Calling Tiger CC" << std::endl;
		}
		virtual void render() { std::cout << "Tiger" << std::endl; }
};
int main (int argc, char* argv[]){
	Tiger kitty;
	std::cout << "-----------Tiger Created ----------" << std::endl;
	Animal *beast=&kitty;
	std::cout << "__Assigned kitty to beast __" << std::endl;
	beast->render();

	std::cout <<" ____________________" <<std::endl;
	Animal beast1=kitty;
	beast1.render();
}

