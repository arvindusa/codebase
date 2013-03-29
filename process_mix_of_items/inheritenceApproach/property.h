#ifndef BASE_H
#define BASE_H
namespace InheritenceApproach{
	class Property{
		public:
			virtual ~Property(){};
			virtual void print(int index) const=0;
	};
}
#endif
