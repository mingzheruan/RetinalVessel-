//
//  main.cpp
//  cucoloris
//
//  Created by 阮明哲 on 2019/4/9.
//  Copyright © 2019 steve.ruan. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc/malloc.h>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <iomanip>
#include <fstream>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <Eigen/Dense>
#include "Sketch.hpp"
#include "Data.hpp"

using namespace std;
using namespace Eigen;

class Point{
public:string x;
public:string y;
public:string z;
};


class  Error{
public:double average;
public:double max;
public:double min;
public:double firstQuarter;
public:double thirdQuarter;
public:vector<Point> pointOne;
public:vector<Point> pointSecond;
public:vector<Point> pointThird;
public:vector<double> individualError;
};

Error error;


void InsertAndSplit();      //插入和分割
void OpenTxtToArray();       //打开txt文件并将值转递给数组
void stringToNum();       //计算得到误差的最大值
void ToArrayForCucoloris();   //
void Cucoloris();         //剪影（将对应位图的数字改变）


int main(){
    OpenTxtToArray();
    Cucoloris();
    cout<<"over"<<endl;
    return 0;
}
