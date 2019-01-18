//
// Created by Jackie Wang on 2019-01-17.
//
#include "Create.hpp"
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

//getIntRand
//Pre: min is a positive number
//Pre: max is a positive number
//Return: a random int value between min and max
int getIntRand(int min, int max);

//getDoubleRand
//Pre: min is a positive number
//Pre: max is a positive number
//Return: a random double value between min and max
double getDoubleRand(int min, int max);

using namespace std;

const int UPPER = 1024;
const int LOWER = 512;
const int MAX = 90;
const int MIN = 50;

void create() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(LOWER,UPPER);
    int x = getIntRand(LOWER, UPPER);

    ofstream file("../Readings.txt", fstream::out);
    for (int i = 0; i < x; i++) {
        file << i << " " << fixed << setprecision(3) << getDoubleRand(MIN, MAX) << "\n";
    }
    file.close();
}

int getIntRand(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min,max);
    return dis(gen);
}

double getDoubleRand(int min, int max){
    random_device rdDouble;
    mt19937 gen(rdDouble());
    uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

