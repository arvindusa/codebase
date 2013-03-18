#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
#define MAX 2
int numPermutation=0;
std::set<int>globalPermutations;
int printPermutations(int used, std::set<int>usedArray, int newNumber){
	if (used == MAX){
		std::set<int>::iterator it;
		std::stringstream s;
		for(it=usedArray.begin(); it != usedArray.end(); ++it){
			s<< *it;
		}
		int permutation=atoi(s.str().c_str());
		globalPermutations.insert(permutation);
		return 1;
	}
	else{	
		int i=0; 
		int prevUsedArraySize=usedArray.size();
		usedArray.insert(newNumber);
		if (prevUsedArraySize == usedArray.size() - 1)
		{	
			//element inserted
			used++;
			for(i; i!= newNumber, i<= 9; i++){
				if(printPermutations(used, usedArray, i)){
					break;
				}
			}
		}
		return 0;
	}	
}

int main(int argc, char *argv[]){
	std::set <int> usedArray;
	for(int i=1; i <= 9; i ++ ){
		printPermutations(0, usedArray, i);
	}
	std::set<int>::iterator it;
	for(it=globalPermutations.begin(); it!=globalPermutations.end();++it){
		std::cout << *it << std::endl;
	}

}

