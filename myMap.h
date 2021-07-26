#include "myList.h"
#include "mySet.h"
#include <iostream>
#include <map>

using namespace std;

template <typename K, typename V>
class myMap{
    public:
        void insert(const K& key, const V& value){
            auto th = find(key);
            if (th != end())
                th->value.second = value;
            else    
                res.insert(make_pair(key, value));
            return ;
        }

        void erase(const K& key){
            auto th = find(key);
            if (th != end())
                res.erase(th);
            return ;
        }

        typename myList<pair<K, V> >::myIterator find(const K& key){
            auto th = begin();
            while (th != end()){
                if (th->value.first == key)
                    return th;
                th = th->next;
            }
            return th;
        }

        size_t size(){
            return res.size();
        }

        V& operator[](const K& key){
            auto th = res.begin();
            while (th != res.end()){
                if (th->value.first == key){
                    return th->value.second;
                }
                th = th->next;
            }
            res.insert(make_pair(key, 0));
        }

        V& at(const K& key){
            auto th = res.begin();
            while (th != res.end()){
                if (th->value.first == key){
                    return th->value.second;
                }
                th = th->next;
            }
        }

        typename myList<pair<K, V> >::myIterator begin(){
            return res.begin();
        }

        typename myList<pair<K, V> >::myIterator end(){
            return res.end();
        }

        const typename myList<pair<K, V> >::myIterator begin() const{
            return res.begin();
        }

        const typename myList<pair<K, V> >::myIterator end() const{
            return res.end();
        }
    private:
        mySet<pair<K, V> > res;
};

template <typename K, typename V>
ostream& operator<<(ostream& out, const myMap<K, V> &m){
    auto th = m.begin();
    while (th != m.end()){
        cout << th->value.first << " " << th->value.second << endl;
        th = th->next;
    }
    return out;
}
