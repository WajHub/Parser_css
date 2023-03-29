//
// Created by huber on 23.03.2023.
//
#include <iostream>
using namespace std;

#ifndef PARSER_CSS_LIST_H
#define PARSER_CSS_LIST_H

#define LENGTH  8

template <typename T>
class List {
private:
    class Node {
    public:
        T array[LENGTH];
        int counter;
        Node *next;
        Node *prev;
        Node(){
            counter=0;
            array[counter++]=T();
            next= nullptr;
            prev= nullptr;
        }
        Node(T &obj){
            counter=0;
            array[counter++]=obj;
            next= nullptr;
            prev= nullptr;
        }
        void add(T &obj){
            if(counter<LENGTH) {
                   array[counter++]=obj;
            }
        }
        int getCounter(){
            return counter;
        }
        void print(){
            cout<<"  Node contais: "<<endl;
            for(int i=0;i<counter;i++){
                cout<<"    "<<i+1<<". "<<array[i]<<endl;
            }
        }
        ~Node(){
            next= nullptr;
            prev= nullptr;
        }
    };
    Node *head;
    Node *tail;
public:
    List();
    void push(T &obj);
    void print();
    ~List();
};

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void List<T>::push(T &obj) {
    if(head == nullptr) {
        Node *n = new Node(obj);
        head = n;
        tail = head;
    }
    else if(tail->getCounter()<LENGTH){
       tail->add(obj);
    }
    else{
        Node*n = new Node(obj);
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

template<typename T>
void List<T>::print() {
    Node *tmp = head;
    while(tmp!= nullptr) {
        cout << "List contain: " << endl;
        tmp->print();
        tmp=tmp->next;
    }
}

template<typename T>
List<T>::~List() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}


#endif //PARSER_CSS_LIST_H
