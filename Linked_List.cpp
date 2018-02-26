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
void LinkedList::InsertFront(LinkedListNode* const inserted_node){
    LinkedListNode* current = inserted_node; // in heap
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
void LinkedList::InsertTail(LinkedListNode* const inserted_node){
    LinkedListNode* current = inserted_node; //in heap

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
void LinkedList::InsertArbitrary(const int loc, LinkedListNode* const inserted_node){//count from 0
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
                InsertTail(inserted_node);
                break;
            }else if(count_num < loc){
                previous_node = current_node;
                current_node = current_node->next;
                ++count_num;
                continue;
            }else{
                if(loc == 0){
                    InsertFront(inserted_node);
                }else{
                    LinkedListNode* insertion_node = inserted_node;
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
        LinkedListNode** tmp_storage_node = new LinkedListNode* [size_of_list];
        LinkedListNode* current_node = first;
        int count = 0;
        
        while(current_node != NULL){
            tmp_storage_node[count] = current_node;
            ++count;
            current_node = current_node->next;
        }
        
        LinkedListNode* v0 = tmp_storage_node[count-1];
        for(int i=count-2;i>=0;--i){
            v0->next = tmp_storage_node[i];
            v0 = v0->next;
        }
        v0->next = NULL;
        first = tmp_storage_node[count-1];
        last = v0;

        delete [] tmp_storage_node;
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
void LinkedList::Delete(LinkedListNode* const deleted_node){
    if(size_of_list > 0){
        LinkedListNode* previous_node = first;
        LinkedListNode* current_node = first;
        while(current_node != NULL){
            if(current_node == deleted_node){
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
void LinkedList::PrintList(const bool debug_addr, const bool debug_name, const bool debug_key){
    LinkedListNode* first_tmp = first;
    if(debug_key){
        std::cout<<"[";
        while(first != NULL){
            std::cout<<first->data;
            if(first->next != NULL){
                std::cout<<" ";
            }
            first = first->next;
        }
        std::cout<<"]"<<std::endl;
    }
    first = first_tmp;

    if(debug_name){
        std::cout<<"[";
        while(first != NULL){
            std::cout<<first->name;
            if(first->next != NULL){
                std::cout<<" ";
            }
            first = first->next;
        }
        std::cout<<"]"<<std::endl;
    }
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
void LinkedList::GetAllData(int* const input_arr){
    LinkedListNode* current_node = first;
    int count_data = 0;

    while(current_node!=NULL){
        input_arr[count_data] = current_node->data;
        ++count_data;
        current_node = current_node->next;
    }
}


