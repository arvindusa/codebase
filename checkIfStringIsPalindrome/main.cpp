/*
* Program checks if a given string is a palindrome,
* input "malayalam"
* output: yes
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
using namespace std;
int main(int argc, char*argv[]){
	std::cout << "Enter a string: " << std::endl;
	std::string inputStr;
	std::cin >> inputStr;
	const char *cstring=inputStr.c_str();
	bool isPalindrome=true;
	int s=inputStr.size();
	int i=0, j=s-1;
	while (i < s/2 && j > s/2){
		if(*(cstring+i) == *(cstring+j)){
			i++;
			j--;
			continue;
		}
		else{
			std::cout << "String is not a Palindrome" << std::endl;
			isPalindrome=false;
			break;
		}  
	}
	if(isPalindrome){
		std::cout << "String is a Palindrome" <<std::endl;
	}

}
