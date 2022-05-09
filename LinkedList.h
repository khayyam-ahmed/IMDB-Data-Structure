#pragma once

#include <iostream>
#include <type_traits>
#include "Movie.h"

using namespace std;

template<class Data>
class ListNode {
public:
    Data* data;
    ListNode<Data>* next;
    ListNode<Data>* prev;
    ListNode(Data* data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template<class Data>
class LinkedList {
public:
    int size;
    ListNode<Data>* first;
    ListNode<Data>* last;
    ListNode<Data>* PredLoc_;
    ListNode<Data>* Loc_;
    //Creating a Linked List
    LinkedList() {
        size = 0;
        first = NULL;
        last = NULL;
        PredLoc_ = NULL;
        Loc_ = NULL;
    }
    //Getter and Setter for size;
    int Size() { return size; }


    //**** 1- IsEmpty will tell whether the list is empty or not ****//
    bool IsEmpty() {
        return first == NULL;
    }
    //**** 2- Insert At Front function ****//
    ListNode<Data>* InsertAtFront(Data* data) {
        ListNode<Data>* newnode = new ListNode<Data>(data);
        if (IsEmpty()) {
            first = newnode;
            last = newnode;
        }
        else {
            newnode->next = first;
            first->prev = newnode;
            first = newnode;
        }
        return newnode;
    }

    //**** 3- Inserting data at tail End ****//
    ListNode<Data>* InsertAtEnd(Data* data) {
        ListNode<Data>* newnode = new ListNode<Data>(data);
        if (IsEmpty()) {
            first = newnode;
            last = newnode;
        }
        else {
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
            last->next = NULL;
        }
        return newnode;
    }

    //**** 4- Search function will set datas for Loc_ and PredLoc_ ****//
    template<typename type>
    void Search(type* data) {
        Loc_ = first;
        PredLoc_ = NULL;


        if constexpr (is_same_v < type, string > || is_same_v < type, int >) {
            auto name = data;
            while (Loc_ != NULL && name.compare(Loc_->data) > 0) {
                PredLoc_ = Loc_;
                Loc_ = Loc_->next;
            }
            if (Loc_ != NULL && Loc_->data != name) {
                Loc_ = NULL;
            }
        }
        else {
            auto name = data->name;
            while (Loc_ != NULL && name.compare(Loc_->data->name) > 0) {
                PredLoc_ = Loc_;
                Loc_ = Loc_->next;
            }
            if (Loc_ != NULL && Loc_->data->name != name) {
                Loc_ = NULL;
            }
        }
    }

    //**** 5- Insertion in a Sorted way ****//
    ListNode<Data>* InsertSorted(Data* data) {
        ListNode<Data>* newnode = new ListNode<Data>(data);
        size++;
        if (IsEmpty()) {
            return InsertAtFront(data);
        }
        else {
            Search<Data>(data);
            if (Loc_ != NULL) {
                delete newnode;
                size--;
                return Loc_;
            }
            else {
                if (PredLoc_ == NULL) {
                    return InsertAtFront(data);
                }
                else if (PredLoc_ == last) {
                    return InsertAtEnd(data);
                }
                else {
                    newnode->next = PredLoc_->next;
                    newnode->prev = PredLoc_;
                    PredLoc_->next->prev = newnode;
                    PredLoc_->next = newnode;
                    return newnode;
                }
            }
        }
    }

    //Printing List

    void PrintList() {
        //if (typeid(T) == typeid(Movie1)){        
        if constexpr (is_same_v < Data, Movie >) {
            ListNode <Data>* temp = first;
            if (!IsEmpty()) {
                while (temp != NULL) {
                    cout << temp->data->name << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;

            }
            else {
                cout << "List is empty ";
            }
        }
        else {
            ListNode<Data>* temp = first;
            if (!IsEmpty()) {
                while (temp != NULL) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;

            }
            else {
                cout << "List is empty ";
            }
        }
    }

    void deleteList() {
        ListNode<Data>* tmp = first;
        while (!IsEmpty()) {
            tmp = first;
            first = first->next;
            delete tmp;
        }
    }
};