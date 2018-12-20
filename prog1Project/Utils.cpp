//
// Created by omri on 12/15/18.
//

#include "Utils.h"

// turn string to int.
int Utils::to_int(string s) {
    return stoi(s, nullptr, 10);
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

