#ifndef BUFFER
#define BUFFER

#include <cstddef>
#include <iterator>

template<class T>
class Buffer {
private:
    T *_elements = nullptr;
    size_t _bufferSize = 0;
    size_t _maxCapacity = 0;
    size_t _bufferBegin = 0;
    size_t _bufferEnd = 0;
public:

    Buffer(size_t capacity) {
        _maxCapacity = capacity + 1;
        _elements = new T[capacity + 1];
        _bufferSize = 0;
        _bufferBegin = 0;
        _bufferEnd = 0;
    }

    ~Buffer() {
        delete[] _elements;
    }

    T &operator[](size_t index) const {
        if (_bufferSize == 0)
            throw std::out_of_range("Empty buffer");
        if (index >= _bufferSize)
            throw std::out_of_range("Index is out of range");
        return _elements[((index % _bufferSize) + _bufferBegin) % _maxCapacity];
    }

    void AddFront(T front) {
        _bufferBegin = (_maxCapacity + _bufferBegin - 1) % _maxCapacity;
        _elements[_bufferBegin] = front;

        if (_bufferSize == _maxCapacity - 1)
            _bufferEnd = (_maxCapacity + _bufferEnd - 1) % _maxCapacity;
        else
            _bufferSize++;
    }

    void AddLast(T last) {
        _elements[_bufferEnd] = last;
        _bufferEnd = (_bufferEnd + 1) % _maxCapacity;

        if (_bufferSize == _maxCapacity - 1)
            _bufferBegin = (_bufferBegin + 1) % _maxCapacity;
        else
            _bufferSize++;
    }

    void DelFront() {
        if (_bufferSize > 0) {
            _bufferSize--;
            _bufferBegin = (_bufferBegin + 1) % _maxCapacity;
        }
        else{
            throw std::out_of_range("Empty buffer");
        }
    }

    void DelLast() {
        if (_bufferSize > 0) {
            _bufferSize--;
            _bufferEnd = (_maxCapacity + _bufferEnd - 1) % _maxCapacity;
        }
        else{
            throw std::out_of_range("Empty buffer");
        }
    }

    void ChangeCapacity(size_t requiredCapacity) {
        if (requiredCapacity < _bufferSize)
            throw std::logic_error("Required capacity is not enough");
        T *tmpElements = new T[requiredCapacity + 1];
        for (size_t i = 0; i < _bufferSize; i++)
            tmpElements[i] = _elements[i];
        delete[] _elements;
        _elements = tmpElements;
        _maxCapacity = requiredCapacity + 1;
        _bufferBegin = 0;
        _bufferEnd = _bufferSize % _maxCapacity;
    }

    class Iterator{
    private:
        size_t _size;
        size_t _index;
        size_t _start;
        T *_elements = nullptr;
    public:
        typedef std::random_access_iterator_tag Category;
        typedef T Type;
        typedef std::ptrdiff_t DifferenceType;
        typedef T* Pointer;
        typedef T& Reference;

        Iterator (T *tempElements, size_t tempSize, size_t tempIndex, size_t tempStart) {
            _elements = tempElements;
            _size = tempSize;
            _index = tempIndex;
            _start = tempStart;
        }

        Iterator &operator+=(DifferenceType tempNum) {
            _index += tempNum;
            return *this;
        }

        Iterator operator+(DifferenceType tempNum) const {
            Iterator temp = *this;
            temp += tempNum;
            return temp;
        }

        Iterator &operator-=(DifferenceType tempNum) {
            _index -= tempNum;
            return *this;
        }

        Iterator operator-(DifferenceType tempNum) const {
            Iterator temp = *this;
            temp -= tempNum;
            return temp;
        }

        DifferenceType operator-(const Iterator &tempNum) const {
            return _index - tempNum._index;
        }

        Reference operator*() {
            return _elements[(_start + _index) % _size];
        }

        Pointer operator->() {
            return _elements + (_start + _index) % _size;
        }

        bool operator==(const Iterator &other) const {
            return _index == other._index;
        }

        bool operator!=(const Iterator &other) const {
            return _index != other._index;
        }

        bool operator<(const Iterator &other) const {
            return _index < other._index;
        }

        bool operator>(const Iterator &other) const {
            return _index > other._index;
        }

        bool operator<=(const Iterator &other) const {
            return _index <= other._index;
        }

        bool operator>=(const Iterator &other) const {
            return _index >= other._index;
        }
    };

    Iterator begin() const {
        return Iterator(_elements, _maxCapacity, 0, _bufferBegin);
    }

    Iterator end() const {
        return Iterator(_elements, _maxCapacity, _bufferSize, _bufferBegin);
    }

    T first() const {
        return _elements[_bufferBegin];
    }

    T last() const {
        return _elements[(_bufferSize + _bufferBegin - 1) % _maxCapacity];
    }

};

#endif