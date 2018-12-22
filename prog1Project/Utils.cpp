//
// Created by omri on 12/15/18.
//

#include "Utils.h"

// turn string to int.
double Utils::to_number(string s) {
    std::string::size_type sz;     // alias of size_t

    return std::stod(s, &sz);
}

bool Utils::getNArguments(int& N) {
    if (N == 0)
        return false;
    N--;
    return true;
}

vector<string> Utils::split(string str, char token) {

    vector<string> splited;

    int i = 0, j = 0;

    while (i < str.length()) {

        j = i;
        while (j < str.length() && str[j] != token) {
            j++;
        }

        // if found at j, cut the substring from i to j and push it to splited vector.
        splited.push_back(str.substr(i, j - i));
        i = j + 1;
    }
    return splited;
}

