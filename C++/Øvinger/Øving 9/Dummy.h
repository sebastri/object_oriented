#include "Matrix.h"

class Dummy {
public:
int *num;
Dummy() {
num = new int{0};
}
Dummy(const Dummy& other){
    num = new int;
    *num = *other.num;
}
Dummy& operator=(Dummy a);
~Dummy() {
delete num;
}
};


void dummyTest();
