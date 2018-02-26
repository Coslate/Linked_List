#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <cstdlib>
#include <string>
class LinkedList;

class LinkedListNode{
        int data;
        std::string name;
        LinkedListNode* next;
    public : 
        LinkedListNode() : data(0), name("NULL"), next(NULL){};
        LinkedListNode(const int value) : data(value), name("NULL"), next(NULL){};
        LinkedListNode(const int value, const std::string val_str) : data(value), name(val_str), next(NULL){};

        inline int              GetData(){return data;};
        inline std::string      GetName(){return name;};
        inline LinkedListNode*  GetNext(){return next;};

        inline void             SetData(const int val){data = val;};
        inline void             SetName(const std::string val){name = val;};
        inline void             SetNext(LinkedListNode* const val){next = val;};

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
        void InsertFront(LinkedListNode* const inserted_node);
        void InsertTail(const int value);
        void InsertTail(LinkedListNode* const inserted_node);
        void InsertArbitrary(const int loc, const int value);//count from 0
        void InsertArbitrary(const int loc, LinkedListNode* const inserted_node);//count from 0
        void Reverse();
        void Delete(const int value);
        void Delete(LinkedListNode* const deleted_node);
        void CleanAll();
        void PrintList(const bool debug_addr = false, const bool debug_name = false, const bool debug_key = true);
        void GetAllData(int* const input_arr);

        inline int              GetListSize(){return size_of_list;};
        inline LinkedListNode*  GetFristNode(){return first;};
        inline LinkedListNode*  GetLastNode(){return last;};
};

#endif
