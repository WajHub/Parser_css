//
// Created by huber on 23.03.2023.
//
#pragma once

#include <iostream>

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

        int get_amount() {
            int z = 0;
            for (int i = 0; i < LENGTH; i++) if (exist[i]) z++;
            return z;
        }

        bool isEmpty() {
            if (get_amount() == 0) return true;
            return false;
        }

        T get_element(int n) {
            return array[--n];
        }

        friend std::ostream &operator<<(std::ostream &out, const Node &node) {
            out << "  Node contais: " << std::endl;
            for (int i = 0; i < node.counter; i++) {
                out << "    " << i + 1 << ". " << node.array[i] << std::endl;
            }
            return out;
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

    friend std::ostream &operator<<(std::ostream &out, const List &list) {
        typename List<T>::Node *tmp = list.head;
        while (tmp != nullptr) {
            out << "List contains: " << std::endl;
            out << *tmp;
            tmp = tmp->next;
        }
        return out;
    }

    int get_amount();

    bool exist_element(int n);

    T& get_element(int n);

    ~List();
};

template<typename T>
T& List<T>::get_element(int n) {
    Node *tmp = head;
    while (tmp != nullptr) {
        if (LENGTH < n) {
            n = n - tmp->counter;
            tmp = tmp->next;
        } else {
            return tmp->array[--n];
        }
    }
    return tmp->array[0];
}

template<typename T>
bool List<T>::exist_element(int n) {
    if (head != nullptr) {
        Node *tmp = head;
        while (tmp != nullptr) {
            if (LENGTH < n) {
                n = n - tmp->counter;
                tmp = tmp->next;
            } else {
                return tmp->exist[--n];
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
