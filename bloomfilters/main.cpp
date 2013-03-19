/*
* Implement Bloom Filters
*  hashes any input string/number into a number from 1...m-1
*  turns on the bit in a bitset 
*  to check if a string has occured before, hash it and map it to
*  bitset to know if this has occured before. 
* guarentees no false negatives
* but false positives can exist - "dogs" is an example case here
*/
#include <iostream>
#include <bitset>
#define MAX 4
#define M 57
#define MAXWORDS 13
using namespace std;
int divHash(const char* str){
	// for all i: sum(str[i]) mod m
	int sum=0;
	for (int i=0; i< MAX; i++){
		sum+= str[i];
	}
	return sum % M;
}
#define seed 131
int multHash(const char *str){
	// m * (kA mod 1)
	unsigned long hash =0;
	for (int i=0; i<MAX;i++){
		hash=(hash*seed) + str[i];
	}
	return hash%M;
}
int hash(int functionId, const char* str){
	switch(functionId){
		case 1: return multHash(str);
		case 2: return divHash(str);
	};
}
std::bitset<M> bloomfilter;
void hashWords(const std::string inputStr[])
{
	for(int i=0; i<MAXWORDS; i++){
		int h1 = hash(1,inputStr[i].c_str());
		int h2 = hash(2, inputStr[i].c_str());
		bloomfilter.set(h1);
		bloomfilter.set(h2);
	}
}
bool hasSeen(const std::string& inputStr){
	int h1=hash(1, inputStr.c_str());
	int h2=hash(2, inputStr.c_str());
	if (bloomfilter.test(h1) && bloomfilter.test(h2)){
		return true;
	}
	return false;
}
int main(int argc, char* argv[]){
	std::string inputStr[]={"able", "band", "bend", "elba", "card", "darn", "grab", "harm", "look", "make", "mate", "peer", "team"};
	hashWords(inputStr);
	for (int i=0; i< MAXWORDS; i++){
		std::cout << inputStr[i] << ":" << hasSeen(inputStr[i]) << std::endl;
	}
	std::cout << "dogs:" << hasSeen("dogs") << std::endl;
	std::cout << "aaaa:" << hasSeen("aaaa") << std::endl;
}
