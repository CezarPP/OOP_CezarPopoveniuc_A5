#pragma once

#include <bits/stdc++.h>

template<typename T>
bool standard_compare(const T &a, const T &b) {
    return a < b;
}

template<typename T>
bool standardIsGood(const T &a, const T &b) {
    return a == b;
}

template<typename T>

struct Vector {
    unsigned int size;
    T *v;

    Vector() {
        size = 0;
        v = nullptr;
    }

    ~Vector() {
        delete[] v;
    }

    void push(const T &x) {
        size++;
        if (__builtin_popcount(size) == 1) {
            T *aux = new T[size * 2];
            for (int i = 0; i < size - 1; i++)
                aux[i] = v[i];
            aux[size - 1] = x;
            delete[] v;
            v = aux;
        } else
            v[size - 1] = x;

    }

    T pop() {
        return v[size - 1];
    }

    void remove(unsigned int index) {
        if (index >= size)
            return;
        for (unsigned int i = index; i < size - 1; i++)
            v[i] = v[i + 1];
        size--;
    }

    T &get(unsigned int index) {
        if (index >= size)
            return v[0];
        return v[index];
    }

    void set(unsigned int index, const T &x) {
        if (index >= size)
            return;
        v[index] = x;
    }

    void insert(const T &x, unsigned int index) {
        size++;
        if (index >= size)
            return;
        if (__builtin_popcount(size) == 1) {
            int *aux = new T[size * 2];
            for (unsigned int i = 0; i < size - 1; i++)
                aux[i] = v[i];
            for (unsigned int i = size - 1; i > index; i--)
                aux[i] = aux[i - 1];
            aux[index] = x;
            delete[] v;
            v = aux;
        } else {
            for (unsigned int i = size - 1; i > index; i--)
                v[i] = v[i - 1];
            v[index] = x;
        }
    }

    unsigned int count() {
        return size;
    }

    void sort(bool(*cmp)(const T &, const T &) = standard_compare<T>) {
        if (cmp == nullptr)
            cmp = standard_compare<T>;
        std::sort(v, v + size, cmp);
    }

    int firstIndexOf(const T &x, bool(*isGood)(const T &, const T &) = standardIsGood<T>) {
        if (isGood == nullptr)
            isGood = standardIsGood<T>;
        for (int i = 0; i < size; i++)
            if (isGood(x, v[i]))
                return i;
        return -1;
    }

    void print() {
        // doesn't work for all types, obviously
        for (int i = 0; i < size; i++)
            std::cout << v[i] << ' ';
        std::cout << '\n';
    }
};
