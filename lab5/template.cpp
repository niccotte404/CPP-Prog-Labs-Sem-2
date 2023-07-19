#include "template.h"

ArrayElement::ArrayElement(int id, int value) {
    _id = id;
    _value = value;
}

int ArrayElement::GetId() const {
    return _id;
}

int ArrayElement::GetValue() const {
    return _value;
}