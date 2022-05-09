
#pragma once

#include <iostream>
#include <type_traits>

using namespace std;

template<class Data, class Key>
class ListNode_Pair {
public:
    Data* data;
    Key key;
    ListNode_Pair<Data, Key>* next;
    ListNode_Pair<Data, Key>* prev;
    ListNode_Pair(Key key, Data* data) {
        this->key = key;
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template<class Data, class Key>
class LinkedList_Pair {
public:
    int size;
    ListNode_Pair<Data, Key>* first;
    ListNode_Pair<Data, Key>* last;
    ListNode_Pair<Data, Key>* PredLoc_;
    ListNode_Pair<Data, Key>* Loc_;
    //Creating a Linked List
    LinkedList_Pair() {
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
    ListNode_Pair<Data, Key>* InsertAtFront(Key key, Data* data) {
        ListNode_Pair<Data, Key>* newnode = new ListNode_Pair<Data, Key>(key, data);
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
    ListNode_Pair<Data, Key>* InsertAtEnd(Key key, Data* data) {
        ListNode_Pair<Data, Key>* newnode = new ListNode_Pair<Data, Key>(key, data);
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
    void Search(Key key) {
        Loc_ = first;
        PredLoc_ = NULL;

        while (Loc_ != NULL && key.compare(Loc_->key) > 0) {
            PredLoc_ = Loc_;
            Loc_ = Loc_->next;
        }
        if (Loc_ != NULL && Loc_->key != key) {
            Loc_ = NULL;
        }
    }

    //**** 5- Insertion in a Sorted way ****//
    ListNode_Pair<Data, Key>* InsertSorted(Key key, Data* data) {
        ListNode_Pair<Data, Key>* newnode = new ListNode_Pair<Data, Key>(key, data);
        size++;
        if (IsEmpty()) {
            return InsertAtFront(key, data);
        }
        else {
            Search(key);
            if (Loc_ != NULL) {
                delete newnode;
                size--;
                return Loc_;
            }
            else {
                if (PredLoc_ == NULL) {
                    return InsertAtFront(key, data);
                }
                else if (PredLoc_ == last) {
                    return InsertAtEnd(key, data);
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

    void deleteList() {
        ListNode_Pair<Data, Key>* tmp = first;
        while (!IsEmpty()) {
            tmp = first;
            first = first->next;
            delete tmp;
        }
    }
};