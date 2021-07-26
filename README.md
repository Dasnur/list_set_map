# list_set_map

Шаблонный тип двунаправленный список myList
Внутри реализован класс двунаправленного итератора
для работы myList с алгоритмами из STL.
Реализованные функции:
void push_forward(const T& value);
void insert(myIterator pos, const T& value);
void errase(const T& value);
bool empty();
size_t size();
myIterator find(const T& value)
template <typename T>
ostream& operator<<(ostream &out, const myList<T> &l)

Шаблонный тип упорядоченного множества mySet реализован на основе
myList<T>
Реализованные функции:
void insert(const T& value);
typename myList<T>::myIterator find(const T& key);
size_t erase(const T& key);
void erase(typename myList<T>::myIterator it);
bool empty();
size_t size();
template <typename T>
ostream& operator<<(ostream& out, const mySet<T>& s)

Шаблонный тип myMap реализован на основе mySet<pair<K, V> >
Реализованные функции:
void insert(const K& key, const V& value);
V& operator[](const K& key);
V& at(const K& key);
void erase(const K& key);
typename myList<pair<K, V> >::myIterator find(const K& key);
size_t size();
template <typename K, typename V>
ostream& operator<<(ostream& out, const myMap<K, V> &m)
