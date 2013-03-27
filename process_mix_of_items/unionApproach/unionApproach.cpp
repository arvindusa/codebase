#include <iostream>
#ifndef UNIONHEADER_H
#include "unionHeader.h"
#endif
#include <vector>
using namespace std;
int main(int argc, char* argv[]){
	using namespace UnionApproach;
	SItem ph1={PHONE, {313,4567892}};
	SItem ph2={PHONE, {800,3334455}};
	SItem age1={AGE, 39};
	SItem house1={HOUSE, 44842};
	SItem age2={AGE, 21};

	std::vector<SItem> data;
	data.push_back(ph1);
	data.push_back(ph2);
	data.push_back(age1);
	data.push_back(house1);
	data.push_back(age2);
	
	showData(data);
}
