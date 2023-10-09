#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <cstddef>
#include "Dictionary.h"

template<class T, class E>
Dictionary<T, E>::Dictionary() {
    currSize = 0;
    keys = NULL;
    values = NULL;
}

template<class T, class E>
Dictionary<T, E>::~Dictionary() {
    if (currSize != 0) {
        if (keys != NULL)
            delete[] keys;
        if (values != NULL)
            delete[] values;
    }
}

template<class T, class E>
int index(Dictionary<T, E>& dict, T key) {
    int currSize = dict.size();
    if (currSize == 0) {
        return -1;
    }
    T* keys = dict.getKeys();

    if (keys == NULL)
        return -1;

    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            return i;
        }
    }
     return -1;
}

template<class T, class E>
void Dictionary<T, E>::set(T key, E value) {
    int idx = index(*this, key);
    if (idx == -1) {
        T* newKeys = new T[currSize + 1];
        E* newVals = new E[currSize + 1];

        if (currSize != 0 && keys != NULL && values != NULL)
            for (int i = 0; i < currSize; i++) {
                newKeys[i] = keys[i];
                newVals[i] = values[i];
            }
        newKeys[currSize] = key;
        newVals[currSize] = value;

        if (currSize != 0) {
            delete[] keys;
            delete[] values;
        }
        keys = newKeys;
        values = newVals;
        currSize++;
    } else {
        values[idx] = value;
    }
}
/**
 * Returns the value associated with the key.
 * If the key is not found, returns the default value of the value type.
 * @tparam T Class of the key
 * @tparam E Class of the value
 * @param key Key ot find
 * @return Value at key, or default value
 */
template<class T, class E>
E Dictionary<T, E>::at(T key) {
    int idx = index(*this, key);
    if (idx == -1) {
        return E();
    } else {
        return values[idx];
    }
}
/**
 * Removes the key and value at the given key.
 * If the key does not exist, do nothing
 * @tparam T Class of the key
 * @tparam E Class of the value
 * @param key Key to remove
 */
template<class T, class E>
void Dictionary<T, E>::removeAt(T key) {
    int idx = index(*this, key);

    if (idx == -1)
        return;

    if (currSize == 1 && idx == 0) {
        delete [] keys;
        delete [] values;
        keys= NULL;
        values = NULL;
        currSize = 0;
        return;
    }

    T* newKeys = new T[currSize - 1];
    E* newVals = new E[currSize - 1];

    int count = 0;

    for (int i = 0; i < currSize-1; i++) {
        if (i == idx)
            count++;
        newKeys[i] = keys[count];
        newVals[i] = values[count];
        count++;
    }

    delete[] keys;
    delete[] values;

    keys = newKeys;
    values = newVals;
    currSize--;
}

template<class E>
int indexOfVal(E val, E* vals, int size) {
    if (size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (vals[i] == val) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
void Dictionary<T, E>::remove(E value) {
    int index = indexOfVal(value, values, currSize);

    while (index != -1) {
        removeAt(keys[index]);

        index = indexOfVal(value, values, currSize);
    }
}

template<class T, class E>
bool Dictionary<T, E>::exists(T key) {
    return (index(*this, key) != -1);
}

template<class T, class E>
Tuple<int, T*> Dictionary<T, E>::keysWithValue(E value) {
    int count = 0;
    for (int i = 0; i < currSize; i++) {
        if (values[i] == value) {
            count++;
        }
    }

    T* out = new T[count];

    int k = 0;

    if (count != 0) {
        for (int i = 0; i < currSize; i++) {
            if (values[i] == value) {
                out[k] = keys[i];
                k++;
            }
        }
    }

    return Tuple<int, T*>(count, out);
}

template<class T, class E>
void Dictionary<T, E>::swap(T firstKey, T secondKey) {
    int index1 = index(*this, firstKey);
    int index2 = index(*this, secondKey);

    if (index1 == -1 || index2 == -1) {
        return;
    }

    E tempE = values[index2];

    values[index1] = values[index2];
    values[index2] = tempE;
}

template<class T, class E>
void Dictionary<T, E>::clear() {
    if (currSize != 0 && keys != NULL && values != NULL) {
        delete[] keys;
        delete[] values;
    }
    keys = NULL;
    values = NULL;
    currSize = 0;
}

template<class T, class E>
T* Dictionary<T, E>::getKeys() {
    return keys;
}

template<class T, class E>
int Dictionary<T, E>::size() {
    return currSize;
}

#endif //DICTIONARY_CPP