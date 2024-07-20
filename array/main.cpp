#include <iostream>
#include <string>
#include <cstddef> // size_t


template <typename T, size_t N>
struct Array {
    using value_type = T;
    using size_type = size_t;
    using iterator = T*;
    using const_iterator = T const *;

    T m_elements[N];

    T& operator[](size_type index) {
        return m_elements[index];
    }

//    T& operator[](Array *this, int index) {
//        return m_elements[index];
//    }

    T const &operator[](size_type index) const {
        return m_elements[index];
    }

//    T const & operator[](Array const *this, int index) {
//        return m_elements[index];
//    }

    T &at(size_type index) {
        if (index >= N) {
            [[unlikely]] throw std::runtime_error("Index out of range! index: " + std::to_string(index));
        }
        return m_elements[index];
    }

    [[nodiscard]] T const &at(size_type index) const {
        if (index >= N) {
            [[unlikely]] throw std::runtime_error("Index out of range! index: " + std::to_string(index));
        }
        return m_elements[index];
    }


    static constexpr size_type size() {
        return N;
    }

    void print() const {
        for (int i = 0; i < N; i++) {
            std::cout << m_elements[i] << " ";
        }
        std::cout << std::endl;
    }

    iterator begin() {
        return m_elements;
    }

    iterator end() {
        return m_elements + N;
    }

    [[nodiscard]] const_iterator begin() const {
        return m_elements;
    }

    [[nodiscard]] const_iterator end() const {
        return m_elements + N;
    }


};


void func(Array<int, 10>& a) {
    Array<int8_t, std::decay_t<decltype(a)>::size()> b{0};
    size_t count = 0;
    for (auto &ai: a) {
        ai = count++;
    }
}

int main() {
    Array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    arr[0] = 10;
    arr.print();
    func(arr);
    arr.print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}