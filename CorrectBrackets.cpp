﻿#include <iostream>
#include <string>
#include "Application.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "expected filename\n";
        return 1;
    }
    Application app = Application(std::string(argv[1]));
    return 0;
    
}


