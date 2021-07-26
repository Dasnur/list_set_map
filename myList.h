#pragma once
#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>


using namespace std;

template <typename T>
class myList{
public:
    struct Node {
        T value;
        Node* next = nullptr;
        Node *prev = nullptr;
    };

    ~myList(){
        auto th = head;
        while (th != tail){
            auto tmp = th;
            th = th->next;
            delete (tmp);
        }
    }

    class myIterator{
        Node* node;
    public:
        typedef typename std::iterator<std::bidirectional_iterator_tag, Node*>::difference_type difference_type;
        typedef typename std::iterator<std::bidirectional_iterator_tag, Node*>::value_type value_type;
        typedef typename std::iterator<std::bidirectional_iterator_tag, Node*>::reference reference;
        typedef typename std::iterator<std::bidirectional_iterator_tag, Node*>::pointer pointer;
        typedef typename std::iterator<std::bidirectional_iterator_tag, Node*>::iterator_category iterator_category;
        myIterator(Node* tmp){
            node = tmp;
        }
        T& operator*(){
            return node->value;
        }

        const T& operator*() const{
            return node->value;
        }

        bool operator==(const myIterator& it) const{
            return it.node == this->node;
        }

        myIterator operator++(){
            myIterator it(node);
            node = node->next;
            return it;
        }

        myIterator operator--(){
            myIterator it(node);
            node = node->prev;
            return it;
        }

        myIterator& operator++(int){
            node = node->next;
            return *this;
        }

        myIterator& operator--(int){
            node = node->prev;
            return *this;
        }

        Node* operator->(){
            return this->node;
        }

        bool operator!=(myIterator it){
            return it.node !=this->node;
        }

        Node* getNode(){
            return node;
        }

    };
    void push_forward(const T& value){
        if (head == nullptr){
            head = new Node;
            tail = new Node;
            head->value = value;
            tail->prev = head;
            head->next = tail;
            head->prev = nullptr;
            _size = 1;
            return ;
        }
        Node *node = new Node;
        node->value = value;
        node->next = head;
        head->prev = node;
        head = node;
        _size++;
    }

    void insert(myIterator pos, const T& value){
        if (pos == begin()){
            push_forward(value);
            return ;
        }
        Node *node = new Node;
        node->value = value;
        node->next = pos.getNode();
        pos->prev->next = node;
        node->prev = pos->prev;
        pos->prev = node;
        _size++;
    }

    void errase(const T& value){
        if (head == nullptr)
            return ;
        myIterator tmp = find(value);
        if (tmp != end()){
            if (!tmp->prev && !tmp->next){
                delete (tmp.getNode());
                head = nullptr;
                _size--;
                return ;
            }
            if (!tmp->prev && tmp->next){
                tmp->next->prev = nullptr;
                head = tmp->next;
                delete (tmp.getNode());
                _size--;
                return ;
            }
            if (tmp->prev && !tmp->next){
                tmp->prev->next = nullptr;
                delete (tmp.getNode());
                _size--;
                return ;
            }
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete(tmp.getNode());
            _size--;
            return ;
        }
        else
            return ;
    }

    bool empty(){
        if (head == tail)
            return true;
        return false;
    }

    size_t size(){
        return _size;
    }

    myIterator find(const T& value){
        Node *arr = head;
        while (arr != tail){
            if (arr->value == value)
                return myIterator(arr);
            arr = arr->next;
        }
        return end();
    }

    myIterator end(){
        return move(myIterator(tail));
    }

    myIterator begin(){
        return move(myIterator(head));
    }

    const myIterator begin() const {
        return myIterator(head);
    }

    const myIterator end() const {
        return myIterator(tail);
    }

private:
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t _size;
};

template <typename T>
ostream& operator<<(ostream &out, const myList<T> &l){
    auto th = l.begin();
    while (th != l.end()){
        cout << th->value << " ";
        th = th->next;
    }
    return out;
}
