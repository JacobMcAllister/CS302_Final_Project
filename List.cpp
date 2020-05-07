#ifndef LIST_CPP_
#define LIST_CPP_

#include <iostream>
#include "Node.h"
#include "List.h"
#include "ListInterface.h"
using namespace std;

template <class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
}
template <class T>
List<T>::List(const List<T> & other){
    head = other.head;
    tail = other.tail;
    itemCount = other.itemCount;
    Node<T> * hold = head;
    Node<T> * otherHold = other.head;
    while(otherHold->getNext() != nullptr){
        hold = otherHold;
        hold = hold->getNext();
        otherHold = otherHold->getNext();
    }
}
template <class T>
List<T>::~List(){
    clear();
}
template <class T>
bool List<T>::isEmpty()const{
    if(itemCount == 0){
        return 1;
    }
    else{
        return 0;
    }
}
template <class T>
int List<T>::getLength()const{
    return itemCount;
}
template <class T>
T List<T>::insert(const int index, T & item){

    std::cout << "into insert func" << std::endl;

    if(index == 0){

        if(itemCount == 0){
            head = new Node<T>(item);
            tail = head;
        }
        else{
            head = new Node<T>(item, head);
        }
    }
    else{

        std::cout << "in 'else' statement" << std::endl;

        Node<T> * hold = head;

        std::cout << "created hold ptr" << std::endl;
        for(int i = 0; i < index-1; i++){
            hold = hold->getNext();
        }

        std::cout << "insert func - after the for loop" << std::endl;
        Node<T> *hold2 = hold->getNext();

        std::cout << "before setNext func" << std::endl;

        Node<T> *tempNode = new Node<T>(item);

        std::cout << "created tempNode and inserted item" << std::endl;
        tempNode->setNext(hold2);

        std::cout << "finished creating new 'temp Node' " << std::endl;

        hold->setNext( tempNode );

        std::cout << "end of 'else' statement" << std::endl;
    }
    itemCount++;
    return item;
}
template <class T>
bool List<T>::remove(const int index){
    Node<T> * hold = head;
    if(index == 0){
        hold = head->getNext();
        delete head;
        head = hold;
        itemCount = itemCount - 1;
        return 1;
    }
    else{
        for(int i = 0; i < index; i++){
            hold = hold->getNext();
        }
        Node<T> * toDelete = hold->getNext();
        if(toDelete != tail){
            hold->setNext(toDelete->getNext());
        }
        else{
            tail = hold;
        }
        delete toDelete;
        itemCount = itemCount-1;
        return 1;
    }
}
template <class T>
void List<T>::clear(){
    while(!isEmpty()){
        remove(0);
    }
}
template <class T>
T List<T>::getEntry(const int index){
    if(index == 0){
        T to_return;
        to_return = head->getData();
        return to_return;
    }
    else{
        //cout << "list get entry else statement" << endl;
        Node<T> * hold = head;
        for(int i = 0; i < index; i++){
            //cout << "list get entry for loop" << endl;
            hold = hold->getNext();
            //cout << "got next" << endl;
        }
        //cout << "completed for loop" << endl;
        T to_return;
        //cout << "construced to return" << endl;
        to_return = hold->getData();
        //cout << "constructed to_return" << endl;
        return to_return;
    }
}
template <class T>
T List<T>::replace(int index, T & item){
    Node<T> * hold = head;
    for(int i = 0; i < index; i++){
        hold = hold->getNext();
    }
    hold->setData(item);
    return item;
}

#endif