#ifndef TUPLE_CPP
#define TUPLE_CPP

#include "Tuple.h"

template<class T, class E>
Tuple<T, E>::Tuple(T first, E second) {
    firstValue = first;
    secondValue = second;
}

template<class T, class E>
Tuple<T, E>::~Tuple() {

}

template<class T, class E>
T Tuple<T, E>::getFirst() {
    return firstValue;
}

template<class T, class E>
E Tuple<T, E>::getSecond() {
    return secondValue;
}

template<class T, class E>
bool Tuple<T, E>::operator==(Tuple<T, E> rhs) {
    return this->firstValue == rhs.firstValue && this->secondValue == rhs.secondValue;
}


#endif //TUPLE_CPP