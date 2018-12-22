//
// Created by omri on 12/15/18.
//

#include "Utils.h"

// turn string to int.
double Utils::to_number(string s) {
    std::string::size_type sz;     // alias of size_t

    return std::stod(s, &sz);
}
/**
 * returns N - 1 = *Np - 1 times true, last time fasle;
*/
bool Utils::getNArguments(int& N) {
    if (N == 0)
        return false;
    N--;
    return true;
}

