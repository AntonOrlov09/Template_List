#pragma once
#include "../include/Linked_List.hpp"

static void test_Linked_List() {
   Linked_List<int> list1 = {1,2,3,4,5,6,7,8,9};
   assert(list1.Length() == 9);
    Linked_List<int> list2;
    Linked_List<int> list3;
    assert(0 == list2.Length());
    list2.Append(1);
    list2.Append(25);
    list3.Append(10);
    assert(1 == list3.Length());
    list2.Prepend(100);
    assert(100 == list2[0]);
    list3.Append(1000);
    list3.InsertAt(0, 0);
    assert(0 == list3[1]);
    assert(1000 == list3.Pop());
    assert(100 == list2.Dequeue());
    list2.RemoveAt(0);
    assert(25 == list2[0]);
    list3.RemoveAll();
    assert(0 == list3.Length());
    list3.Append(30);
    list3.Append(90);
    list2.AppendAll(list3);
    list1.AppendAll(list2);
    assert(12 == list1.Length());
    assert(3 == list2.Length());
    assert(30 == list2[1]);
    for (auto & el: list1) {
        std::cout<< el << " ";
    }
    std::cout<<std::endl;
    for (auto el=list1.begin(); el!=list1.end(); el++) {
        std::cout<<*el<<" ";
    }
    std::cout<<std::endl;
}