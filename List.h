//
// Created by huber on 23.03.2023.
//
#pragma once

#include <iostream>
#include "String.h"
#ifndef PARSER_CSS_LIST_H
#define PARSER_CSS_LIST_H

#define LENGTH  8

template<typename T>
class List {
private:
    class Node {
    public:
        T array[LENGTH];
        bool exist[LENGTH];
        int counter;
        Node *next;
        Node *prev;

        Node() {
            counter = 0;
            array[counter++] = T();
            for (int i = 0; i < LENGTH; i++) exist[i] = false;
            next = nullptr;
            prev = nullptr;
        }
        Node(T &obj) {
            counter = 0;
            for (int i = 0; i < LENGTH; i++) exist[i] = false;
            exist[counter] = true;
            array[counter++] = obj;
            next = nullptr;
            prev = nullptr;
        }
        void add(T &obj) {
            if (counter < LENGTH) {
                exist[counter] = true;
                array[counter++] = obj;
            }
        }
        int getCounter() {
            return counter;
        }
        const T *getArray() const {
            return array;
        }
        int get_amount() {
            int z = 0;
            for (int i = 0; i < LENGTH; i++) if (exist[i]) z++;
            return z;
        }
        bool isEmpty() {
            if (get_amount() == 0) return true;
            return false;
        }
        T &get_element(int n) {
            int tmp=n;
            for(int i=0;i<tmp;i++){
                if(exist[i]){
                    n--;
                    if(n==0) return array[i];
                }
                else tmp++;
            }
        }
        bool exist_element(int n){
            int tmp=n;
            for(int i=0;i<tmp;i++){
                if(exist[i]){
                    n--;
                    if(n==0) return exist[i];
                }
                else tmp++;
            }
        }
        T& get_element_(int n){
            for(int i=LENGTH-1;i>=0;i--){
                if(exist[i]){
                    n--;
                    if(n==0) return array[i];
                }
            }
        }
        bool exist_element_(int n){
            for(int i=LENGTH-1;i>=0;i--){
                if(exist[i]){
                    n--;
                    if(n==0) return exist[i];
                }
            }
        }
        friend std::ostream &operator<<(std::ostream &out, const Node &node) {
            out << "  Node contais: " << std::endl;
            for (int i = 0; i < node.counter; i++) {
                out << "    " << i + 1 << ". " << node.array[i] << std::endl;
            }
            return out;
        }
        void delete_all(){
            for(int i=0;i<LENGTH;i++){
                if(exist[i]){
                    exist[i]=false;
                    array[i]=T();
                }
            }
        }
        bool delete_element(int n){
            int tmp=n;
            for(int i=0;i<tmp;i++){
                if(exist[i]){
                    n--;
                    if(n==0){
                        array[i]=T();
                        exist[i]= false;
                        return true;
                    }
                }
            }
            return false;
        }
        ~Node() {
            next = nullptr;
            prev = nullptr;
        }
    };
    Node *head;
    Node *tail;
public:
    List();

    void push(T &obj);

    bool delete_element(int n);

    void delete_all();

    friend std::ostream &operator<<(std::ostream &out, const List &list) {
        Node *tmp = list.head;
        while (tmp != nullptr) {
            out << "List contains: " << std::endl;
            out << *tmp;
            tmp = tmp->next;
        }
        return out;
    }

    Node *getHead() const {
        return head;
    }

    Node *getTail() const {
        return tail;
    }

    int get_amount();

    bool isEmpty();

    bool exist_element(int n);
    T& get_element(int n);

    //funckja pobiera elementy od konca (dla komendy E)
    T& get_element_(int n);
    bool exist_element_(int n);

    ~List();
};

template<typename T>
void List<T>::delete_all() {
    while (head != nullptr) {
        Node* next = head->next;
        head->delete_all();
        delete head;
        head = next;
    }
}

template<typename T>
bool List<T>::delete_element(int n) {
    bool result=false;
    Node *tmp = head;
    while (tmp != nullptr) {
        if (tmp->counter < n) {
            n = n - tmp->counter;
            tmp = tmp->next;
        } else {
            result = tmp->delete_element(n);
            if(tmp->isEmpty()){
                if(tmp==head && tmp==tail) head= nullptr;
                else if(tmp==head){
                    tmp=head->next;
                    head= tmp;
                    tmp->prev= nullptr;
                }
                else if(tmp==tail){
                    tmp=tail->prev;
                    tail=tmp;
                    tmp->next= nullptr;
                }
                else{
                    Node *current=tmp->prev;
                    current->next=tmp->next;
                    current=tmp->next;
                    current->prev=tmp->prev;
                    tmp= nullptr;
                }
                return result;
            }
            else return result;
        }
    }
    return result;
}

template<typename T>
bool List<T>::isEmpty() {
    Node *tmp=head;
    while(tmp!= nullptr){
        if(tmp->isEmpty())return true;
        return false;
    }
    return true;
}

template<typename T>
bool List<T>::exist_element_(int n) {
    if (tail != nullptr) {
        Node *tmp = tail;
        while (tmp != nullptr) {
            if (tmp->counter < n) {
                n = n - tmp->counter;
                tmp = tmp->prev;
            } else {
                return tmp->exist_element_(n);
            }
        }
        return false;
    }
    return false;
}

template<typename T>
T &List<T>::get_element_(int n) {
    Node *tmp = tail;
    while (tmp != nullptr) {
        if (LENGTH < n) {
            n = n - LENGTH;
            tmp = tmp->prev;
        } else {
            return tmp->get_element_(n);
        }
    }
    return tmp->array[0];
}


template<typename T>
T& List<T>::get_element(int n) {
    Node *tmp = head;
    while (tmp != nullptr) {
        if (tmp->counter < n) {
            n = n - tmp->counter;
            tmp = tmp->next;
        } else {
            return tmp->get_element(n);
        }
    }
    return tmp->array[0];
}

template<typename T>
bool List<T>::exist_element(int n) {
    if (head != nullptr) {
        Node *tmp = head;
        while (tmp != nullptr) {
            if (tmp->counter < n) {
                n = n - tmp->counter;
                tmp = tmp->next;
            } else {
                return tmp->exist_element(n);
            }
        }
        return false;
    }
    return false;
}
template<typename T>
int List<T>::get_amount() {
    int amount = 0;
    if (head != nullptr) {
        Node *tmp = head;
        while (tmp != nullptr) {
            amount = amount + tmp->get_amount();
            tmp = tmp->next;
        }
        return amount;
    }
    return 0;
}

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void List<T>::push(T &obj) {
    if (head == nullptr) {
        Node *n = new Node(obj);
        head = n;
        tail = head;
    } else if (tail->getCounter() < LENGTH) {
        tail->add(obj);
    } else {
        Node *n = new Node(obj);
        tail->next = n;
        n->prev = tail;
        tail = n;
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
