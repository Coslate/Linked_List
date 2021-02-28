#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <cstdlib>
#include <string>
#include <iostream>
class LinkedList;

class LinkedListNode{
        int data;
        std::string name;
        LinkedListNode* next;
        bool explored;
        int  color;
    public : 
        LinkedListNode() : data(0), name("NULL"), next(NULL), explored(false), color(0){};
        LinkedListNode(const int value) : data(value), name("NULL"), next(NULL), explored(false), color(0){};
        LinkedListNode(const int value, const std::string val_str) : data(value), name(val_str), next(NULL), explored(false), color(0){};
        LinkedListNode(const int value, const std::string val_str, const bool explored) : data(value), name(val_str), next(NULL), explored(explored), color(0){};
        LinkedListNode(const int value, const std::string val_str, const bool explored, const int color) : data(value), name(val_str), next(NULL), explored(explored), color(color){};

        inline int              GetData() const {return data;};
        inline std::string      GetName() const {return name;};
        inline LinkedListNode*  GetNext() const {return next;};
        inline bool             GetExplored() const {return explored;};
        inline int              GetColor() const {return color;};

        inline void             SetData(const int val){data = val;};
        inline void             SetName(const std::string val){name = val;};
        inline void             SetNext(LinkedListNode* const val){next = val;};
        inline void             SetExplored(const bool explored_val){explored = explored_val;};
        inline void             SetColor(const int color_val){color = color_val;};
        inline void             operator=(const int& other2) { data = other2;};

        friend class LinkedList;
};

class LinkedList{
        LinkedListNode* first;
        LinkedListNode* last;
        int size_of_list;
        bool show_debug_msg;
    public : 
        LinkedList() : first(NULL), last(NULL), size_of_list(0), show_debug_msg(false){};
        LinkedList(const bool show_debug_msg) : first(NULL), last(NULL), size_of_list(0), show_debug_msg(show_debug_msg){};
        ~LinkedList();

        void InsertFront(const int value);
        void InsertFront(const int value, const std::string val_str);
        void InsertFront(LinkedListNode* const inserted_node);
        void InsertTail(const int value);
        void InsertTail(const int value, const std::string val_str);
        void InsertTail(LinkedListNode* const inserted_node);
        void InsertArbitrary(const int loc, const int value);//count from 0
        void InsertArbitrary(const int loc, const int value, const std::string val_str);//count from 0
        void InsertArbitrary(const int loc, LinkedListNode* const inserted_node);//count from 0
        void Reverse();
        void Delete(const int value);
        void Delete(LinkedListNode* const deleted_node);
        void CleanAll();
        void PrintList(const bool debug_addr = false, const bool debug_name = false, const bool debug_key = true, const bool debug_explored=false);
        void GetAllData(int* const input_arr);

        inline int              GetListSize(){return size_of_list;};
        inline LinkedListNode*  GetFristNode(){return first;};
        inline LinkedListNode*  GetLastNode(){return last;};
};

static inline std::ostream & operator<<(std::ostream &output, const LinkedListNode &node){ 
    output<<"("<<node.GetName()<<", "<<node.GetData()<<")";
    return output; 
}

/*
static inline void operator=(LinkedListNode& other1, const int& other2) {
    other1.SetData(other2);
}*/

static inline bool operator==(const LinkedListNode& other1, const LinkedListNode& other2) {
    return (other1.GetData() == other2.GetData());
}

static inline bool operator==(const LinkedListNode& other1, const int& other2) {
    return (other1.GetData() == other2);
}

static inline bool operator!=(const LinkedListNode& other1, const LinkedListNode& other2) {
    return (other1.GetData() != other2.GetData());
}

static inline bool operator>(const LinkedListNode& other1, const LinkedListNode& other2) {
    return (other1.GetData() > other2.GetData());
}

static inline bool operator>(const LinkedListNode& other1, const int &other2) {
    return (other1.GetData() > other2);
}

static inline bool operator<(const LinkedListNode& other1, const int &other2) {
    return (other1.GetData() < other2);
}



static inline void CustSwap(LinkedListNode &data1, LinkedListNode &data2){
    std::string tmp_str  = data1.GetName();
    int tmp_data         = data1.GetData();

    data1.SetName(data2.GetName());
    data1.SetData(data2.GetData());
    data2.SetName(tmp_str);
    data2.SetData(tmp_data);
}

#endif
