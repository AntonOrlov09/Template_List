#pragma once

#include <iostream>
#include <cassert>

// В узле списка хранится само значение value и указатель на следующий узел.
// Эту структуру пользователи списка не должны видеть, так как она относится к внутренней реализации.
template<typename T>
struct Node {
    T value_; // само значение, которое хранит узел
    struct Node<T>* next_; // указатель на следующий узел
};

// Пользовательская структура, которая скрывает механизм хранения данных.
template<typename T>
class Linked_List {
    Node<T> *head_ = nullptr; // указатель на голову списка
    Node<T> *tail_ = nullptr; // указатель на хвост списка
    // если нужно, то добавьте дополнительные поля
public:
    explicit Linked_List() : head_(nullptr), tail_(nullptr) {}


    void Append(T value) {
        Node<T> *tmp = new Node<T>;
        tmp->next_ = nullptr;
        tmp->value_ = value;
        if (head_ == nullptr) {
            head_ = tmp;
            tail_ = tmp;
        } else {
            tail_->next_ = tmp;
            tail_ = tmp;
        }
    }

    void Prepend(T value) {
        if (head_ == nullptr) {
            auto *tmp =new Node<T>;
            tmp->value_ = value;
            tmp->next_ = nullptr;
           head_ = tmp;
            tail_ = tmp;
            return;
        }
        auto *tmp = new Node<T>;
        tmp->value_ = value;
        tmp->next_ = head_;
        head_ = tmp;
    }

    void AppendAll(const Linked_List &that) {
        for (int i = 0; i < that.Length(); i++) {
            Append(that[i]);
        }
    }

    void InsertAt(int index,T value) {
        auto *ptr = head_;
        int c = 0;
        while (c != index) {
            ptr = ptr->next_;
            c++;
        }
        auto *tmp = new Node<T>;
        tmp->value_= value;
        tmp->next_ = ptr->next_;
        ptr->next_ = tmp;
    }

    void RemoveAt(int index) {
        auto *tmp = head_;
        if (index == 0) {
            head_ = head_->next_;
            tmp->next_ = nullptr;
            delete(tmp);
            return;
        }
        Node<T> *ptr = nullptr;
        int c = 0;
        while (c != index) {
            if (c == index - 1) {
                ptr = tmp;
            }
            tmp = tmp->next_;
            c++;
        }
        ptr->next_ = tmp->next_;
        tmp->next_ = nullptr;
        delete(tmp);
    }

    void RemoveAll() {
        auto *tmp = head_;
        while (tmp != nullptr) {
            tmp = tmp->next_;
            delete(head_);
            head_ = tmp;
        }
        tail_ = nullptr;
    }

    int Pop() {
        int c = Length();
        T a;
        auto *ptr = head_;
        for (int i = 0; i < c - 1; i++) {
            tail_ = ptr;
            ptr = ptr->next_;
        }
        tail_->next_ = nullptr;
        a = ptr->value_;
        delete (ptr);
        return a;
    }

    int Dequeue() {
        T a;
        auto *tmp = head_;
        head_ = head_->next_;
        tmp->next_ = nullptr;
        a = tmp->value_;
       delete (tmp);
        return a;
    }

    int Length() const {
        if (head_ == nullptr) {
            return 0;
        }
        Node<T> *tmp = head_;
        int count = 0;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next_;
        }
        return count;
    }

    T& operator[](int index) const {
        assert(head_ != nullptr && index < Length());
        auto * tmp = head_;
        for (int i = 0; i< index; i++) {
            tmp = tmp->next_;
        }
        return tmp->value_;
    }
    ~Linked_List() {
        auto tmp = head_;
        while (tmp != nullptr) {
            tmp = tmp->next_;
            delete(head_);
            head_ = tmp;
        }
        std::cout << "~Linked_List" << std::endl;
    }
};