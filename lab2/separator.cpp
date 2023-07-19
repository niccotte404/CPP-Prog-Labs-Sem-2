#include "separator.h"
#include <utility>

Separator::Separator() {
    str = "yes, no: no+ know;under'stood#obvio*usly -(chicke.n)? rom%ku &hel№lo @ye^ah/ 88 $mp !35";
    sep = " ";
}

Separator::Separator(std::string s, std::string c) {
    str = std::move(s);
    sep = std::move(c);
}

void Separator::Separate(){
    tmp = "";
    for (auto sym: str){
        for (auto symSep: sep){
            if (sym != symSep){
                tmp += sym;
            }
            else{
                result.push_back(tmp);
                tmp = "";
                break;
            }
        }
    }
    result.push_back(tmp);
}

void Separator::Result() {
    for (const auto& i: result){
        std::cout << i << std::endl;
    }
}