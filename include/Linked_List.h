#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <cstdlib>
class LinkedList;

class LinkedListNode{
        int data;
        LinkedListNode* next;
    public : 
        LinkedListNode() : data(0), next(NULL){};
        LinkedListNode(const int value) : data(value), next(NULL){};

        friend class LinkedList;
};

class LinkedList{
        LinkedListNode* first;
        LinkedListNode* last;
        int size_of_list;
    public : 
        LinkedList() : first(NULL), last(NULL), size_of_list(0){};
        ~LinkedList();

        void InsertFront(const int value);
        void InsertTail(const int value);
        void InsertArbitrary(const int loc, const int value);//count from 0
        void Reverse();
        void Delete(const int value);
        void CleanAll();
        void PrintList(const bool debug_addr = false);
        int ReturnListSize();
        void ReturnAllData(int* const input_arr);
};

#endif
