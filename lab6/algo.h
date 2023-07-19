#ifndef ALGO
#define ALGO

template <typename Iterator, typename Condition>
bool AnyOf(Iterator begin, Iterator end, Condition condition) {
    if (begin == end) {
        return false;
    }
    for (auto it = begin; it != end; it++) {
        if (condition(*it)) {
            return true;
        }
    }
    return false;
}

template <typename Iterator, typename Condition>
bool OneOf(Iterator begin, Iterator end, Condition condition) {
    if (begin == end) {
        return false;
    }
    int amount = 0;
    for (auto it = begin; it != end; it++) {
        if (condition(*it)) {
            amount++;
        }
    }
    if (amount == 1){
        return true;
    }
    return false;
}

template <typename Iterator, typename Condition>
bool IsPalindrome(Iterator begin, Iterator end, Condition condition) {
    if (begin == end) {
        return false;
    }
    auto it2 = end;
    for (auto it = begin; it != end; it++) {
        if (condition(*it) && condition(*it2)) {
            if (it == it2){
                return true;
            }
            if (*it != *it2){
                return false;
            }
        }
        else{
            return false;
        }
        it2--;
    }
    return true;
}

#endif