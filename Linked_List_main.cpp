#include <iostream>
#include <cstdlib>
#include <Linked_List.h>

int main(){
    LinkedList list_a;
    list_a.InsertFront(100);
    list_a.InsertFront(11);
    list_a.InsertFront(25);
    list_a.InsertTail(999);
    list_a.InsertFront(25);
    list_a.InsertTail(71);
    list_a.InsertFront(50);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Reverse-------"<<std::endl;
    list_a.Reverse();
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Delete 25-------"<<std::endl;
    list_a.Delete(25);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Delete 50-------"<<std::endl;
    list_a.Delete(50);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Delete 999-------"<<std::endl;
    list_a.Delete(999);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Delete 71-------"<<std::endl;
    list_a.Delete(71);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Delete 100-------"<<std::endl;
    list_a.Delete(100);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------InsertArbitrary (0, 5555)-------"<<std::endl;
    list_a.InsertArbitrary(0, 5555);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------InsertArbitrary (1, 9487)-------"<<std::endl;
    list_a.InsertArbitrary(1, 9487);
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------Reverse-------"<<std::endl;
    list_a.Reverse();
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    std::cout<<"-------CleanAll-------"<<std::endl;
    list_a.CleanAll();
    list_a.PrintList(true);
    std::cout<<"size = "<<list_a.ReturnListSize()<<std::endl;
    return EXIT_SUCCESS;
}
