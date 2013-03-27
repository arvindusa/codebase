#ifndef CHAMELEON_H
#define CHAMELEON_H
#ifndef INVALIDEXCEPTION_H
#include "invalidException.h"
#endif
#include <map>
#include <typeinfo>
#include <iostream>
namespace ChameleonApproach{

	enum Action{SET, GET, DELETE};
	class Item{
		public:
			Item(){}
			template<class T>Item(const T& t){
				value(0, t,SET);
			} 
			template<class T>operator T() const 
				throw (Invalid_Type_Exception&){
					return const_cast<Item*>(this)->template value<T>();
			}
			template<class T> T operator=(const T &t){
				return value(0, t,SET); 
			}
			template<class T> void print(){
				T t=const_cast<Item*>(this)->template value<T>();
				value(0, t, GET);
			}
		private:
			template <class T>T value(int dummy, T t=T(), 
					Action action=GET) 
				throw (Invalid_Type_Exception&);

			typedef void(Item::*FuncPtr)(void);
			template<class T>void deleteValue();
			FuncPtr deleteFuncPtr;
		
	};
template<class T>
inline void Item::deleteValue()
{
	static T t;
	value(t, DELETE);
}
template<class T>
T Item::value(int dummy, T t, Action action) throw (Invalid_Type_Exception&){
	static std::map<Item*, T> values;
	std::cout << values.size() << std::endl;
	typedef typename std::map<Item*, T>::iterator myit;
	myit it;
	for(it=values.begin(); it!=values.end(); ++it){
		std::cout << (*it).first << "-" << (*it).second << std::endl;
	}
	switch(action){
		case GET:{
			if(values.count(this)){
				std::cout << "getting: " << values[this] << std::endl;
				return values[this];
			}
			else{
				std::cout << "Item not found" << std::endl;
				return 0;
				//throw Invalid_Type_Exception(typeid(T).name());
			}
		}	
		case SET:{
			std::cout << "I am setting here" <<  t << std::endl;
			values[this]=t;

			std::cout << values.size() << std::endl;

	/*		if (deleteFuncPtr==NULL){
				deleteFuncPtr=&deleteValue<T>();
			}
			else if(deleteFuncPtr != (FuncPtr)&deleteValue<T>){
				(this->*deleteFuncPtr)();
				deleteFuncPtr=&deleteValue<T>();
			}*/
			return values[this];
		}
/*		case DELETE:{
			if(values.count(this)) return values.erase(this);
			return t;
		}*/
	};
}

}	
#endif
