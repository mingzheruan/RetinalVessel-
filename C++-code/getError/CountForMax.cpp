//
//  CountForMax.cpp
//  getError
//
//  Created by 阮明哲 on 2018/7/23.
//  Copyright © 2018年 steve.ruan. All rights reserved.
//

#include "CountForMax.hpp"
using namespace std;

class Point{
public:string x;
public:string y;
};


class  Error{
public:double average;
public:double max;
public:double min;
public:double firstQuarter;
public:double thirdQuarter;
public:vector<Point> pointOne;
public:vector<Point> pointSecond;
public:vector<int> individualError;
};


extern Error error;

void CountForMax(){
    cout<<"hello"<<endl;
    cout<<error.pointOne.front().x<<endl;
    cout<<error.pointSecond.front().x<<endl;
}
