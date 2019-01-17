//
// Created by Jackie Wang on 2019-01-17.
//
#include "Read.hpp"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void read() {
    double sum = 0;
    double highest = 0;
    double lowest = 90;
    double median;
    vector<double> list;
    int count;
    double num;
    ifstream read("../Readings.txt");
    while (read) {
        read >> count >> num;
        sum += num;
        list.push_back(num);
        if (num > highest) {
            highest = num;
        }
        if (num < lowest) {
            lowest = num;
        }
    }
    sort(list.begin(), list.end());
    if (count % 2 == 0) {
        median = ((list[count / 2] + list[count / 2 + 1]) / 2);
    } else {
        median = list[count / 2 + 0.5];
    }

    cout << "There are " << count << " readings." << endl;
    cout << "The average reading is " << sum / count << "." << endl;
    cout << "The highest reading is " << highest << "." << endl;
    cout << "The lowest reading is " << lowest << "." << endl;
    cout << "The median reading is " << median << "." << endl;

    read.close();
}
