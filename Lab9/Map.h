#pragma once

#include <utility>
#include <tuple>

using namespace std;
constexpr int MAX_SIZE = 1024;

template<typename KeyType, typename ValueType>
class Iterator {
public:
    pair<KeyType, ValueType> *p = nullptr;
    int index = 0;

    bool operator!=(Iterator<KeyType, ValueType> otherIt) {
        return p != otherIt.p;
    }

    void operator++() {
        p++;
        index++;
    }

    tuple<KeyType, ValueType, int> operator*() const {
        return make_tuple(p->first, p->second, index);
    }
};

template<typename KeyType, typename ValueType>
class Map {
private:
    pair<KeyType, ValueType> v[MAX_SIZE];
    int size = 0;
public:
    bool Get(const KeyType &key, ValueType &value) {
        for (int i = 0; i < size; i++)
            if (key == v[i].first) {
                value = v[i].second;
                return true;
            }
        return false;
    }

    int Count() const {
        return size;
    }

    Iterator<KeyType, ValueType> begin() {
        Iterator<KeyType, ValueType> auxIt;
        auxIt.index = 0;
        auxIt.p = &v[0];
        return auxIt;
    }

    Iterator<KeyType, ValueType> end() {
        Iterator<KeyType, ValueType> auxIt;
        auxIt.index = size;
        auxIt.p = &v[size];
        return auxIt;
    }

    ValueType &operator[](KeyType key) {
        for (int i = 0; i < size; i++)
            if (v[i].first == key)
                return v[i].second;
        size++;
        v[size - 1].first = key;
        return v[size - 1].second;
    }

    bool Includes(const Map<KeyType, ValueType> &map) {
        for (auto[key, value, index]: map) {
            bool foundKey = false;
            for (int i = 0; i < size && !foundKey; i++)
                if (v[i].first == key)
                    foundKey = true;
            if (!foundKey)
                return false;
        }
        return true;
    }

    void Delete(const KeyType &key) {
        for (int i = 0; i < size; i++)
            if (v[i].first == key) {
                for (int j = i; j < size - 1; j++)
                    v[j] = v[j + 1];
                size--;
                break;
            }
    }

    void Set(const KeyType &key, const ValueType &value) {
        for (int i = 0; i < size; i++)
            if (v[i].first == key) {
                v[i].second = value;
                return;
            }
        v[size] = {key, value};
        size++;
    }
};