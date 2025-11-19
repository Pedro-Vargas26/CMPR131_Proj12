
#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>
#include <exception>

template<typename T>
int binary_search(const T* haystack, std::size_t arrSize, const T& needle) noexcept;

template<typename T>
class DynamicArray {
private:
    T* p_ptr;
    std::size_t arrSize;
    std::size_t arrCapacity;
    bool isSorted;
public:
    DynamicArray();
    DynamicArray(const DynamicArray&);
    ~DynamicArray();

    const T* data() const noexcept;

    void append(const T&) noexcept;
    void sorted_insert(const T&) noexcept;
    bool exists(const T&) const noexcept;
    bool empty() const noexcept;
    bool sorted()const noexcept;

    int remove(const T&) noexcept;
    int remove(const T&, bool) noexcept;
    void clear() noexcept;
    void sort();

    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    int find(const T&) const noexcept;

    T& operator[](int index);
    const T& operator[](int index) const;

    friend int binary_search<T>(const T*, size_t, const T&) noexcept;
};

template <typename T>
int binary_search(const T* haystack, size_t arrSize, const T& needle) noexcept {
    if (!haystack || arrSize == 0)
        return 0;

    std::size_t low = 0;
    std::size_t high = arrSize;

    while (low < high) {
        std::size_t mid = (low + high) / 2;
        if (haystack[mid] < needle)
            low = mid + 1;
        else
            high = mid;
    }

    return static_cast<int>(low);
}

#endif
