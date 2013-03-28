#ifndef ITEM_H
#define ITEM_H
#ifndef INVALIDEXCEPTION_H
#include "invalidException.h"
#endif
#include <map>
#include <typeinfo>
#include <iostream>
#ifndef AGE_H
#include "age.h"
#endif
#ifndef PHONEEXT_H
#include "phoneExtension.h"
#endif
#ifndef HOUSE_H
#include "house.h"
#endif
namespace ChameleonApproach{

	enum Action{SET, GET, DELETE};
	class Item{
		public:
			Item(){} //default constructor
            ~Item() { 
                if (deletePtr != NULL){
                    (this->*deletePtr)(); 
                }
            }
			template<class T>Item(const T& t){
				value(t,SET);
			} 
			template<class T>operator T() const 
				throw (Invalid_Type_Exception&){
					return const_cast<Item*>(this)->template value<T>();
			}
			template<class T> T operator=(const T &t){
				return value(t,SET); 
			}
            void print()  {
               if(printPtr != NULL){
                    (this->*printPtr)();
               }
            }
		private:
			template <class T>T value(T t=T(), 
					Action action=GET) 
				throw (Invalid_Type_Exception&);

			typedef void(Item::*FuncPtr)(void);
			template<class T>void deleteValue();
            template<class T>void getValue();
            FuncPtr printPtr;
			FuncPtr deletePtr;
		
	};
template<class T>
inline void Item::getValue(){
    static T t;
    T t1 = value(t,GET);
    std::cout << t1 << std::endl;
}
template<class T>
inline void Item::deleteValue()
{
	static T t;
	value(t, DELETE);
}
template<class T>
T Item::value(T t, Action action) throw (Invalid_Type_Exception&){
	static std::map<Item*, T> values;
	switch(action){
		case GET:{
			if(values.count(this)){
				return values[this];
			}
			else{
				std::cout << "Item not found: "<< t << std::endl;
				throw Invalid_Type_Exception(typeid(T).name());
			}
		}	
		case SET:{
			values[this]=t;
            //setting print function pointer. 
            if (printPtr == NULL ) {
                printPtr=&Item::getValue<T>;
            }
            else if(printPtr != (FuncPtr)&Item::getValue<T>){
                    printPtr=&Item::getValue<T>;
            }

            //setting delete function pointer
			if (deletePtr==NULL){
				deletePtr=&Item::deleteValue<T>;
			}
			else if(deletePtr != (FuncPtr)&Item::deleteValue<T>){
				(this->*deletePtr)();
				deletePtr=&Item::deleteValue<T>;
			}
			return values[this];
		}
		case DELETE:{
			if(values.count(this)) {
                values.erase(this);
            }
			return t;
		}
	};
    return t;
}

}	
#endif
