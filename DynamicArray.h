#pragma once
#include <cstddef>
#include <exception>
#include <iostream>

template<typename T>
class DynamicArray
{
private:
    T* p_ptr;
    int  arrSize;
    int  arrCapacity;
    bool isSorted;

public:

    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();


    void append(const T& obj) noexcept;
    void clear() noexcept;
    int  find(const T& needle) const noexcept;
    bool exists(const T& needle) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;


    void sort();
    bool sorted() const noexcept;
    void sorted_insert(const T& obj) noexcept;


    int remove(const T& needle) noexcept;
    int remove(const T& needle, bool allOrOne) noexcept;

    void sortedInsert(const T& value);


    T& operator[](int index);
    const T& operator[](int index) const;


    const T* data() const noexcept;
};


#include "DynamicArray.cpp"
