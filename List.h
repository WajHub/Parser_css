//
// Created by huber on 23.03.2023.
//
#include <iostream>
using namespace std;

#ifndef PARSER_CSS_LIST_H
#define PARSER_CSS_LIST_H

#define LENGTH  8
template <typename T>
class Node {
    T array[LENGTH];
    int counter;
public:
    Node<T> *next;
    Node<T> *prev;
    Node(){
        counter=0;
        next= nullptr;
        prev= nullptr;
    }
    void add(T obj){
        if(counter<LENGTH) array[counter++]=obj;
    }
    int getCounter(){
        return counter;
    }
    void print(){
        cout<<"Node contais: "<<endl;
        for(int i=0;i<counter;i++){
            cout<<array[i];
        }
    }
};

template <typename T> class List {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    List();
    void push(T obj);
    void print();
};

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void List<T>::push(T obj) {
    if(head == nullptr) {
        head = new Node<T>();
        head->add(obj);
        tail = head;
    }
    else if(tail->getCounter()<LENGTH){
        tail->add(obj);
    }
    else{
        Node<T>*n = new Node<T>();
        n->add(obj);
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

template<typename T>
void List<T>::print() {
    cout<<"List contain: ";
    cout<<head->print();

}

#endif //PARSER_CSS_LIST_H
