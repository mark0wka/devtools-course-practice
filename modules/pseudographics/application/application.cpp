// Copyright 2021 Chistov Vladimir

#include "include/application.h"

#include <iostream>

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
