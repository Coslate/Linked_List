#include <iostream>
#include <cstdio>
#include <Linked_List.h>

LinkedList::~LinkedList(){
    CleanAll();
}

void LinkedList::InsertFront(const int value){
    LinkedListNode* current = new LinkedListNode(value); // in heap
    current->next = first;
    first = current;
    ++size_of_list;

    if(size_of_list == 1){
        last = first;
    }
}

void LinkedList::InsertTail(const int value){
    LinkedListNode* current = new LinkedListNode(value); //in heap

    if(size_of_list == 0){
        last = current;
        first = last;
        ++size_of_list;
    }else{
        last->next = current;
        last = current;
        ++size_of_list;
    }
}

void LinkedList::InsertArbitrary(const int loc, const int value){//count from 0
    if(size_of_list < loc){
        std::cout<<"Error : size of the list is not enough, size = "<<size_of_list<<std::endl;
        return;
    }else if(loc < 0){
        std::cout<<"Error : insert location cannot be < 0"<<std::endl;
        return;
    }else{
        int count_num = 0;
        LinkedListNode* current_node = first;
        LinkedListNode* previous_node = first;
        while(current_node != NULL){
            if(loc == size_of_list){
                InsertTail(value);
                break;
            }else if(count_num < loc){
                previous_node = current_node;
                current_node = current_node->next;
                ++count_num;
                continue;
            }else{
                if(loc == 0){
                    InsertFront(value);
                }else{
                    LinkedListNode* insertion_node = new LinkedListNode(value);
                    previous_node->next = insertion_node;
                    insertion_node->next = current_node;
                    ++size_of_list;
                }
                break;
            }
        }
    }
}

void LinkedList::Reverse(){
    if(size_of_list > 0){
        LinkedList* tmp = new LinkedList;
        tmp->InsertFront(first->data);

        LinkedListNode* current_node = first;
        while(current_node->next != NULL){
            tmp->InsertFront(current_node->next->data);
            current_node = current_node->next;
        }
        CleanAll();

        LinkedListNode* tmp_current_node = tmp->first;
        while(tmp_current_node != NULL){
            InsertTail(tmp_current_node->data);
            tmp_current_node = tmp_current_node->next;
        }

        delete tmp;
    }
}

void LinkedList::Delete(const int value){
    if(size_of_list > 0){
        LinkedListNode* previous_node = first;
        LinkedListNode* current_node = first;
        while(current_node != NULL){
            if(current_node->data == value){
                if(current_node == first){
                    previous_node = current_node->next;
                    delete current_node;
                    current_node = previous_node;
                    first = current_node;
                }else if(current_node == last){
                    delete current_node;
                    last = previous_node;
                    current_node = NULL;
                    previous_node->next = NULL;
                }else{
                    previous_node->next = current_node->next;
                    delete current_node;
                    current_node = previous_node->next;
                }
                --size_of_list;
            }else{
                previous_node = current_node;
                current_node = current_node->next;
            }
        }
    }
}

void LinkedList::CleanAll(){
    while(first != NULL){
        LinkedListNode* first_next_tmp = first->next;
        delete first;
        first = first_next_tmp;
        --size_of_list;
    }
    last = NULL;
}

void LinkedList::PrintList(const bool debug_addr){
    LinkedListNode* first_tmp = first;
    std::cout<<"[";
    while(first != NULL){
        std::cout<<first->data;
        if(first->next != NULL){
            std::cout<<" ";
        }
        first = first->next;
    }
    std::cout<<"]"<<std::endl;
    first = first_tmp;

    if(debug_addr){
        std::cout<<"[";
        while(first != NULL){
            std::cout<<first;
            if(first->next != NULL){
                std::cout<<" ";
            }
            first = first->next;
        }
        std::cout<<"]"<<std::endl;
        first = first_tmp;
        std::cout<<"first = "<<first<<std::endl;
        std::cout<<"last = "<<last<<std::endl;
    }
}

int LinkedList::ReturnListSize(){
    return size_of_list;
}

void LinkedList::ReturnAllData(int* const input_arr){
    LinkedListNode* current_node = first;
    int count_data = 0;

    while(current_node!=NULL){
        input_arr[count_data] = current_node->data;
        ++count_data;
        current_node = current_node->next;
    }
}

