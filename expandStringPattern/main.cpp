/*
* author: venkatvi
* date: 18 March 2013
* This program converts a given input string
* of pattern "A2B3C4" to 
* AABBBCCCC
* The given array have enough empty spaces to
* to fit the expanded array
*/
#include <iostream>
#include <stdlib.h>
#define SIZE 12
using namespace std;
int main(int argc, char*argv[]){
	char A[]={'D','2','B', '3', 'C','4','E','2',' ',' ',' ',' ' };
	std::cout << "Array: '" ;
	for( int l=0; l < SIZE; l++){
		std::cout << A[l] <<'_';
	}
	std::cout << "'" << std::endl;

	int i=0;
	for (; i<SIZE; i++){
		if(A[i] == ' '){
			break;
		}
	}
	int j=SIZE-1;
	while (i >= 2){
		char c_expand=A[i-2];
		int t_expand=A[i-1]-48;
		int emptySpaces=j-i+1;
		A[i-2]=' ';
		A[i-1]=' ';
		for(j; j >= 0 ; j--){
			if (t_expand > 0){
				A[j]=c_expand;
				t_expand--;
			}
			else{
				break;
			}
		}
		int j1=j;
		for(j1; j1>=0; j1--){
			if (A[j1] == ' '){
				continue;
			}
			else{
				break;
			}
		}
		i=j1+1;
		std::cout << "Array: '" ;
		for( int l=0; l < SIZE; l++){
			std::cout << A[l] <<'_';
		}
		std::cout << "'" << std::endl;
	}
}

