#pragma once

template<class T>
struct Link {
    T data;
    Link* next = nullptr;
};

template<class T>
class LinkList {
public:
    void Insert(size_t _targetIndex, T _value) {
        Link<T>* link = new Link();
        link->data = _value;

        
    }
private:
    Link<T>* m_head;
};