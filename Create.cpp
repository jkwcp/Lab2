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
using namespace std;

const int UPPER = 1024;
const int LOWER = 512;
const int MAX = 90;
const int MIN = 50;

void create() {
    ofstream file("../Readings.txt", fstream::out);
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(LOWER,UPPER);
    srand((unsigned) time(NULL));
    int x = distribution(generator);//512 + rand() % (UPPER - LOWER);
    for (int i = 0; i < x; i++) {
        file << i << " " << fixed << setprecision(3) << MIN + rand() / (double) (RAND_MAX / (MAX - MIN)) << "\n";
    }
    file.close();
}