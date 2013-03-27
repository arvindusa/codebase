#ifndef INVALIDEXCEPTION_H
#define INVALIDEXCEPTION_H
#include<string>
namespace ChameleonApproach{
	class Invalid_Type_Exception{
		public:
			Invalid_Type_Exception(const std::string &s) {errorType=s;}
			std::string getError() const { return errorType; }
		private:
			std::string errorType;
	};
}
#endif
