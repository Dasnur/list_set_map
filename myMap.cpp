#include "myMap.h"
#include <iostream>
#include <map>

using namespace std;

int main(){
    myMap<int, int> m;
    cout << endl;
    m.insert(1, 5);
    m.insert(6, 7);
    m.insert(2, 5);
    m.insert(4, 6);
    cout << m << endl;
    cout << m[4] << endl;
    m[4] = 5;
    cout << m[4] << endl;
    cout << m << endl;
    m.erase(6);
    cout << m << endl;
}