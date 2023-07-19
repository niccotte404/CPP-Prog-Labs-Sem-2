#include <iostream>
#include "buffer.h"

using namespace std;

int main() {

    Buffer<int> buff (10);
    buff.AddFront(11);
    cout << buff.last() << endl;
    buff.AddLast(12);
    buff[0] = 13;
    cout << buff.first() << endl;
    buff.DelFront();
    cout << buff.first() << endl;
    buff.DelLast();
    for (int i = 0; i < 5; i++){
        buff.AddLast(i);
    }
    cout << *buff.begin() << endl;
    cout << *buff.end() << endl;

    return 0;
}
