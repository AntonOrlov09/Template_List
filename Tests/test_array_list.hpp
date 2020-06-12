#pragma once

#include "../include/Array_List.hpp"

static void test_array() {
    Array_List<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Array_List<int> list2;
    Array_List<int> list3 = Array_List<int>(5);
    assert(0 == list2.Length());
    list2.append(1);
    list2.append(25);
    list3.append(10);
    assert(1 == list3.Length());
    list2.prepend(100);
    assert(100 ==  list2[0]);
    list3.append(1000);
    list3.InsertAt(0, 0);
    assert(0 == list3[1]);
    assert(1000 ==  list3.Pop());
    assert(100 == list2.Dequeue());
    list2.RemoveAt(0);
    assert(25 == list2[0]);
    list3.RemoveAll();
    assert(0 == list3.Length());
    list3.append(30);
    list3.append(90);
    list2.AppendAll(list3);
    list1.AppendAll(list2);
    assert(12 == list1.Length());
    assert(3 == list2.Length());
    assert(30 ==list2[1]);
    for (auto& el: list1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    Array_List<int> list = {1,2,3,4,5,6,7,8,9};
    for (auto el = list.begin(); el != list.end(); el++) {
        std::cout << *el << " ";
    }
    std::cout << std::endl;
}
