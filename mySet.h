#pragma once
#include "myList.h"
#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
class mySet{
public:
    typename myList<T>::myIterator end(){
        return res.end();
    }

    typename myList<T>::myIterator begin(){
        return res.begin();
    }

    const typename myList<T>::myIterator begin() const {
        return res.begin();
    }

    const typename myList<T>::myIterator end() const{
        return res.end();
    }

    void insert(const T& value){
        if (res.empty()){
            res.push_forward(value);
            return ;
        }
        auto th = res.begin();
        while (th != res.end() && value > th->value)
            th = th->next;
        if (th != res.end() && value == th->value)
            return ;
        res.insert(th, value);
    }

    typename myList<T>::myIterator find(const T& key){
        auto th = res.begin();
        while (th != res.end()){
            if (th->value == key)
                return th;
            th = th->next;
        }
        return th;
    }

    size_t erase(const T& key){
        auto it = find(key);
        if (it == res.end())
            return (size_t)0;
        this->erase(it);
        return (size_t)1;
    }

    void erase(typename myList<T>::myIterator it){
        res.errase(it->value);
    }

    bool empty(){
        return (res.empty());
    }

    size_t size(){
        return res.size();
    }

private:
    myList<T> res;
};

template <typename T>
ostream& operator<<(ostream& out, const mySet<T>& s){
    auto th = s.begin();
    while (th != s.end()){
        cout << th->value << " ";
        th = th->next;
    }
    return out;
}
