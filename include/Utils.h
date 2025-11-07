#ifndef UTILS_H
#define UTILS_H
#include <ctime>
#include <iostream>
#pragma once

const int WIDTH = 7;
const int HEIGHT = 6;

inline void showTime() {
    time_t tt;
    struct tm *ti = localtime(&tt);
    std::cout << "Day = " << asctime(ti);
}

#endif
