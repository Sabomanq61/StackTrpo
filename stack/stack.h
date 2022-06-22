//
// Created by user on 22.05.2022.
//

#include <cstddef>
#include "stack_exception.h"

#pragma once

namespace stack
{

template<typename T>
struct Node
{
public:
    T key;
    Node* next;

public:
    Node(T key1)
    {
        key = key1;
        next = nullptr;
    }
};

template<typename T>
class Stack
{
private:
    Node<T>* head_;
    std::size_t size_;

public:
    Stack()
    : head_(nullptr)
    , size_(0)
    {
    }

    Stack(const Stack& stack)
    : head_(nullptr)
    , size_(stack.size_)
    {
        for(auto ptr = stack.head_; ptr; ptr = ptr->next)
        {
            auto newNode = new Node<T>(ptr->key);
            newNode->next = head_;
            head_ = newNode;
        }
    }

    Stack(Stack&& stack)
    : head_(nullptr)
    , size_(stack.size_)
    {
        for(auto ptr = head_;stack.head_;ptr = ptr->next, stack.head_ = stack.head_->next)
        {
            ptr = stack.head_;
        }
    }

    ~Stack()
    {
        for (auto ptr = head_; head_; ptr = head_)
        {
            head_ = head_->next;
            delete ptr;
        }
    }

    void push(const T& key)
    {
        auto* node = new Node<T>(key);
        node->next = head_;
        head_ = node;
        size_++;
    }

    T pop()
    {
        if(size_ == 0)
        {
            throw EStackEmpty();
        }

        T result = head_->key;
        auto temp = head_;
        head_ = head_->next;
        delete temp;

        size_--;
        return result;
    }

    std::size_t size()
    {
        return size_;
    }
};

} // namespace stack

