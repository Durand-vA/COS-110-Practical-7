#ifndef TUPLE_H
#define TUPLE_H

template <class T, class E>
class Tuple {
private:
    T firstValue;
    E secondValue;

public:
    Tuple(T first, E second);
    ~Tuple();
    T getFirst();
    E getSecond();
    bool operator==(Tuple<T, E> &rhs);
};




#endif //TUPLE_H
