//
// Created by Jackie Wang on 2019-01-17.
//
#include "Create.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

void create() {
    ofstream file("../Readings.txt", fstream::out);
    srand((unsigned) time(NULL));
    int x = 512 + rand() % (1024 - 512);
    for (int i = 0; i < x; i++) {
        file << i << " " << fixed << setprecision(3) << 50 + rand() / (double) (RAND_MAX / (90 - 50)) << "\n";
    }
}