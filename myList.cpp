#include "myList.h"
#include <algorithm>
#include <iostream>


using namespace std;

int main(){
    myList<int> l;
    l.push_forward(2);
   l.insert(l.end(), 8);
   l.insert(l.end(), 10);
   l.insert(l.end(), 12);
   cout << l << endl;
    return 0;
}