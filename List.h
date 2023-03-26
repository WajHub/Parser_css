//
// Created by huber on 23.03.2023.
//

#ifndef PARSER_CSS_LIST_H
#define PARSER_CSS_LIST_H

#define LENGTH  8
template <typename T>
class Node {
    T array[LENGTH];
    int counter;
    Node *next;
    Node *prev;
public:
    Node(){
        counter=0;
        next=0;
        prev=0;
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




#endif //PARSER_CSS_LIST_H
