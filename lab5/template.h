#ifndef TEMPLATE
#define TEMPLATE

#include "stdexcept"

template<typename Type>
Type minimum(Type a, Type b)
{
    return (a < b ? a : b);
}


class ArrayException: public std::exception {
public:
    const char* Message;
    explicit ArrayException(const char* message) {
        this->Message = message;
    }

    const char* what() const noexcept override {
        return this->Message;
    }
};

template <int N, class T>
class Array {
private:
    T *_arr = new T[N];
    int _i = 0;

    void _indexOutOfRangeException() {
        throw ArrayException("Out of range");
    }

public:
    Array() = default;
    ~Array() = default;

    void AddToArray(T elem) {
        if (_i < N && _i >= 0) {
            _arr[_i] = elem;
            _i++;
            return;
        }
        _indexOutOfRangeException();
    }

    T GetArrayElement(int index) {
        if (index < N && index >= 0) {
            return _arr[index];
        }
        _indexOutOfRangeException();
    }
};

class ArrayElement{
private:
    int _id;
    int _value;
public:
    ArrayElement(int id, int value);
    ArrayElement() = default;
    ~ArrayElement() = default;
    int GetId() const;
    int GetValue() const;
};

#endif