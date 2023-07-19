#ifndef LAB2_SEPARATOR_H
#define LAB2_SEPARATOR_H

#include <iostream>
#include "string"
#include <vector>

class Separator {
private:
    std::string str, sep;
    std::string tmp;
    std::vector <std::string> result;
public:
    Separator();
    Separator(std::string s, std::string c);

    void Separate();
    void Result();

};


#endif //LAB2_SEPARATOR_H
