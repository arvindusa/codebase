// process_mix_of_items.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

typedef enum {
    id_phone_extension,
    id_age,
    id_house_number
} id_kind;

typedef struct {

    id_kind id;

    unsigned int areaCode;

    unsigned long sevenDigitNumber;

} phone_extension;

typedef struct {

    id_kind id;

    unsigned int ageYears;

} age;

typedef struct {

    id_kind id;

    unsigned long houseNumber;

} house_number;

int holdCommandWindow()
{
    std::string str;
    std::cout << "\nHit Enter To End Program ";
    std::getline(std::cin,str);
    return 0;
}

void showData(void *data[], int nData)
{
    std::cout << "\n";

    for ( int i=0; i < nData; ++i ) {

        id_kind id = *(reinterpret_cast<const id_kind*>(data[i]));

        std::cout << "Element index number " << i << " is a "; 

        switch ( id ) {
        
        case id_phone_extension:

            const phone_extension *pPhone;
                
            pPhone = reinterpret_cast<const phone_extension*>(data[i]);

            std::cout << "Phone extension (" << pPhone->areaCode << ") " << pPhone->sevenDigitNumber << "\n";

            break;

        case id_age:
            
            const age *pAge;
            
            pAge = reinterpret_cast<const age*>(data[i]);

            std::cout << "Age " << pAge->ageYears << "\n";

            break;

        case id_house_number:

            const house_number *pHouse;
            
            pHouse = reinterpret_cast<const house_number*>(data[i]);

            std::cout << "House number " << pHouse->houseNumber << "\n";
            
            break;
        }
    }
}

int main()
{
    phone_extension ph1 = { id_phone_extension, 313, 4567892 };
    phone_extension ph2 = { id_phone_extension, 800, 3334455 };

    age age1 = { id_age, 39 };
    age age2 = { id_age, 21 };

    house_number hn1 = { id_house_number, 44842 };

    void* data[5];

    data[0] = &ph1;
    data[1] = &ph2;
    data[2] = &age1;
    data[3] = &hn1;
    data[4] = &age2;

    showData(data,5);

	return holdCommandWindow();
}
