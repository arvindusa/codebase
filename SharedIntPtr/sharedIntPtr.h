#ifndef SHAREDPTR
#define SHAREDPTR
#include <iostream>
class SharedIntPtr{
	public:
		SharedIntPtr(int *p): ptr(p), referenceCount(new int (1)){};
		SharedIntPtr(const SharedIntPtr &p){
			ptr=p.ptr;
			referenceCount=p.referenceCount;
			*(referenceCount)++;
		}
		SharedIntPtr &operator=(const SharedIntPtr &p){
			*(referenceCount)--;
			referenceCount=p.referenceCount;
			ptr=p.ptr;
			*(referenceCount)++;
		} 
		~SharedIntPtr(){}
		void reset(){
			if (*(referenceCount) > 1){
				ptr=NULL;
				*(referenceCount)--;
			}
			else if ( *(referenceCount) == 1){
				delete ptr;
				ptr = NULL;
				*(referenceCount)=0;
			}
		}
		void setValue(int p){
		 *ptr = p;
		}
		int print() const {
			return *ptr;
		}
	private:
		int *ptr;
		int *referenceCount;
};
#endif
