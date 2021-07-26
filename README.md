# list_set_map

# Шаблонный тип двунаправленный список myList <br />
Внутри реализован класс двунаправленного итератора
для работы myList с алгоритмами из STL. <br />
Реализованные функции: <br />
void push_forward(const T& value); <br />
void insert(myIterator pos, const T& value); <br />
void errase(const T& value); <br />
bool empty(); <br />
size_t size(); <br />
myIterator find(const T& value); <br />
template <typename T> <br />
ostream& operator<<(ostream &out, const myList<T> &l);

# Шаблонный тип упорядоченного множества mySet <br /> 
Реализован на основе
myList<T> <br />
Реализованные функции: <br />
void insert(const T& value); <br />
typename myList<T>::myIterator find(const T& key); <br />
size_t erase(const T& key); <br />
void erase(typename myList<T>::myIterator it); <br />
bool empty(); <br />
size_t size(); <br />
template <typename T>
ostream& operator<<(ostream& out, const mySet<T>& s) <br />

# Шаблонный тип myMap <br /> 
Реализован на основе mySet<pair<K, V> > <br />
Реализованные функции: <br />
void insert(const K& key, const V& value); <br />
V& operator[](const K& key); <br />
V& at(const K& key); <br />
void erase(const K& key); <br />
typename myList<pair<K, V> >::myIterator find(const K& key); <br />
size_t size(); <br />
template <typename K, typename V>
ostream& operator<<(ostream& out, const myMap<K, V> &m)
