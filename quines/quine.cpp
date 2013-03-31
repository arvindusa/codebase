#include <iostream>
#include <string>
#define SIZE 19
using namespace std;
int main(int argc, char*argv[]){
	char q=34;
	std::string codeArray[]={
		  "#include <iostream>"
		, "#include <string>"
		, "#define SIZE 19"
		, "using namespace std;"
		, "int main(int argc, char*argv[]){"
		, "	char q=34;"
		, "	std::string codeArray[]={"
		, "	"
		, "	};"
		, "	for(int i=0;i<5;i++){"
		, "		std::cout << codeArray[i] << std::endl;"
		, "	}"
		, "	for(int i=0;i<codeArray.length(); i++){"
		, "		std::cout << codeArray[7] << q << codeArray[i] << q  << ',' << std::endl;"
		, "	}"
		, "	for(int i=6; i< codeArray.length(); i++){"
		, "		std::cout << codeArray[i] << std::endl;"
		, "	}"
		, "}"
		};
	for(int i=0;i<7;i++){
		std::cout << codeArray[i] << std::endl;
	}
	for(int i=0;i<SIZE; i++){
		std::cout << codeArray[7] << q << codeArray[i] << q << ',' << std::endl;
	}
	for(int i=8; i< SIZE; i++){
		std::cout << codeArray[i] << std::endl;
	}
}
