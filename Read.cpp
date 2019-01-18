//
// Created by Jackie Wang on 2019-01-17.
//
#include "Read.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;
//getMedian
//Pre: count is a positive number
//Return: the median of given vector
double getMedian (vector<double> list, int count);

//report
//Return: void
//Prints messages to the console in required format
void report(int count, double sum, double highest, double lowest, double median);

void read() {
    double sum = 0;
    double highest = 0;
    double lowest = 90;
    vector<double> list; //using vector because the size is unknown at the beginning
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
    read.close();


    double median = getMedian(list, count);
    report(count, sum, highest, lowest, median);
}


double getMedian (vector<double> list, int count){
    double median;
    sort(list.begin(), list.end());
    double middleList = count / 2;
    if (count % 2 == 0) {
        median = ((list[middleList] + list[middleList + 1]) / 2);
    } else {
        median = list[ceil(middleList)];
    }

    return median;
}

void report(int count, double sum, double highest, double lowest, double median){
    cout << "There are " << count << " readings." << endl;
    cout << "The average reading is " << sum / count << "." << endl;
    cout << "The highest reading is " << highest << "." << endl;
    cout << "The lowest reading is " << lowest << "." << endl;
    cout << "The median reading is " << median << "." << endl;
}
