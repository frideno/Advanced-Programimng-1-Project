//
// Created by omri on 12/15/18.
//

#include "Utils.h"

// turn string to int.
int Utils::to_int(string s) {
    return stoi(s, nullptr, 10);
}


bool Utils::getNArguments(int N) {

    static int count = N;

    // if the count reached to 0, can stop.
    if (count == 0)
        return false;

    // else, the count decrease by 1, and can get another arg.
    count --;
    return true;
}

