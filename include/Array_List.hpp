#pragma once

#include <iostream>
#include <cassert>

template<typename T>
class Array_List {
    T* array_;
    int capacity_;
    int size_;
    int last_index_;
    void allocate_memory() {
        capacity_*=2;
        auto arr=new T[capacity_];
        for (int i=0;i< size_; i++) {
            arr[i] = array_[i];
        }
        delete(array_);
        array_=arr;
    }
    void deallocate_memory() {
        capacity_/=2;
        auto arr=new T[capacity_];
        for (int i=0;i< size_; i++) {
            arr[i] = array_[i];
        }
        delete(array_);
        array_=arr;
    }
public:
    explicit Array_List(int capacity = 2) : capacity_(capacity), size_(0), last_index_(-1) {
         if (capacity < 2) {
             capacity_ = 2;
         }
         array_ = new T[capacity_];
    }
    Array_List(const Array_List<T> &rhs) : capacity_(rhs.capacity_), size_(rhs.size_), last_index_(rhs.last_index_) { // конструктор копирования
        array_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            array_[i] = rhs.array_[i];
        }
    }
    Array_List<T>&operator=(const Array_List<T> &rhs) { //оператор присваивания копированием
        if (this!=&rhs) {
            capacity_ = rhs.capacity_;
            size_ = rhs.size_;
            last_index_ = rhs.last_index_;
            array_ = new T[capacity_];
            for (int i = 0; i < size_; i++) {
                array_[i] = rhs.array_[i];
            }
        }
        return *this;
    }
    Array_List(std::initializer_list<T> elements) { // конструктор, который заполняет список готовыми элементами
        capacity_ = elements.size()*2;
        size_ = elements.size();
        last_index_ = elements.size()-1;
        array_ = new T[capacity_];
        int i = 0;
        for (auto &el : elements) {
            array_[i] = el;
            i++;
        }
    }
    void append(T value) {
        last_index_++;
        size_++;
        array_[last_index_]=value;
        if (size_==capacity_) {
            allocate_memory();
        }
    }
    void prepend(T value) {
        last_index_++;
        size_++;
        for (int i=last_index_-1;i>0;i--) {
            array_[i+1]=array_[i];
        }
        array_[0]=value;
        if (size_==capacity_) {
            allocate_memory();
        }
    }
    void AppendAll(const Array_List<T>& rhs) {
        for (int i=0; i<rhs.size_;i++) {
            append(rhs.array_[i]);
        }
    }
    void InsertAt(int index, T value) {
        assert(index>=0 && index<size_);
        last_index_++;
        size_++;
        for (int i=last_index_;i>index+1;i--) {
            array_[i]=array_[i-1];
        }
        array_[index+1]=value;
        if (size_==capacity_) {
            allocate_memory();
        }
    }
    void RemoveAt(int index) {
        assert(index>=0 && index<size_);
        last_index_--;
        size_--;
        for (int i=index;i<size_;i++)  {
            array_[i]=array_[i+1];
        }
        if (capacity_/size_>=4) {
            deallocate_memory();
        }
    }
    void RemoveAll() {
        last_index_=-1;
         capacity_=2;
         size_=0;
        delete(array_);
        array_ = new T[capacity_];
    }
    T Pop() {
        assert(size_>0);
        last_index_--;
        size_--;
        auto t=array_[last_index_+1];
        array_[last_index_+1]=0;
        if (capacity_/size_>=4) {
            deallocate_memory();
        }
        return t;
    }
    T Dequeue() {
        assert(size_>0);
        last_index_--;
        size_--;
        auto t=array_[0];
        for (int i=0;i<last_index_+1;i++) {
            array_[i]=array_[i+1];
        }
        if (capacity_/size_>=4) {
            deallocate_memory();
        }
        return t;
    }
    [[nodiscard]] int Length() {
        return size_;
    }
    const T&operator[](int index) const {
        assert(index>=0 && index<size_);
        return array_[index];
    }
    const T&operator[](int index)  {
        assert(index>=0 && index<size_);
        return array_[index];
    }
    T* begin() {
        return array_;
    }
    T* end() {
        return array_+size_;
    }
    ~Array_List() {
        std::cout << "~Array_List" << std::endl;
        delete(array_);
    }
};