#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <Linked_List.h>

int main(){
    LinkedList list_a;
    /*
    list_a.InsertFront(100);
    list_a.InsertFront(11);
    list_a.InsertFront(25);
    list_a.InsertTail(999);
    list_a.InsertFront(25);
    list_a.InsertTail(71);
    list_a.InsertFront(50);
    */
    LinkedListNode* new_100_node = new LinkedListNode(100, "new_100_node");
    LinkedListNode* new_11_node  = new LinkedListNode(11, "new_11_node");
    LinkedListNode* new_25_node  = new LinkedListNode(25, "new_25_node");
    LinkedListNode* new_999_node = new LinkedListNode(999, "new_999_node");
    LinkedListNode* new_25_node2  = new LinkedListNode(25, "new_25_node2");
    LinkedListNode* new_71_node  = new LinkedListNode(71, "new_71_node");
    LinkedListNode* new_50_node  = new LinkedListNode(50, "new_50_node");

    list_a.InsertFront(new_100_node);
    list_a.InsertFront(new_11_node);
    list_a.InsertFront(new_25_node);
    list_a.InsertTail(new_999_node);
    list_a.InsertFront(new_25_node2);
    list_a.InsertTail(new_71_node);
    list_a.InsertFront(new_50_node);

    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Reverse-------"<<std::endl;
    list_a.Reverse();
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Delete 25-------"<<std::endl;
    list_a.Delete(25);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Delete 50-------"<<std::endl;
//    list_a.Delete(50);
    list_a.Delete(new_50_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Delete 999-------"<<std::endl;
//    list_a.Delete(999);
    list_a.Delete(new_999_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Delete 71-------"<<std::endl;
//    list_a.Delete(71);
    list_a.Delete(new_71_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Delete 100-------"<<std::endl;
//    list_a.Delete(100);
    list_a.Delete(new_100_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------InsertArbitrary (0, 5555)-------"<<std::endl;
    LinkedListNode* new_5555_node = new LinkedListNode(5555, "new_5555_node");
    list_a.InsertArbitrary(0, new_5555_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------InsertArbitrary (1, 9487)-------"<<std::endl;
    LinkedListNode* new_9487_node = new LinkedListNode(9487, "new_9487_node");
    list_a.InsertArbitrary(1, new_9487_node);
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------Reverse-------"<<std::endl;
    list_a.Reverse();
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    std::cout<<"-------CleanAll-------"<<std::endl;
    list_a.CleanAll();
    list_a.PrintList(true, true, true);
    std::cout<<"size = "<<list_a.GetListSize()<<std::endl;
    return EXIT_SUCCESS;
}
