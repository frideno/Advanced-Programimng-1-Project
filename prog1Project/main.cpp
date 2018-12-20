#include <iostream>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Interperter.h"

using namespace std;;
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "Databases/SymbolsDB.h"
#include "Enviroment.h"

int main() {

    Enviroment* e = new Enviroment;
    e->operation();
    delete e;


}