#include "smartPointer.h"
#include <iostream>

using namespace std;

int  main(){
    int *ptr_a = new int(5);
    int *ptr_b = new int(3);
    smartPointer<int> th(ptr_a);
    smartPointer<int> a(th);
    smartPointer<int> b(ptr_b);
    b = a;
}