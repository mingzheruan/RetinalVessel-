//
//  main.cpp
//  JudgeLineAndRow
//
//  Created by 阮明哲 on 2019/4/10.
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

using namespace std;

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

int main(){
    
    char c;                            //可以得到数据行数
    //    int row  = 0;    //列数
    int line = 0;   //行数
    
    string path = "/Users/ruanmingzhe/Desktop/Data/data5/image2skeletonData.txt";
    
    fstream Final(path,ios::in);
    if (!Final) {
        cerr<< " cannot open filel "  <<endl;
    }
    
    while (Final.get(c)) {
        
        //        if (c == '0' || c == '1') {
        //            row++;
        //        }
        
        if (c == '\n') {
            
            line++;
        }
    }
    //    row = row / (line);
    cout<<"the Final line is: " <<line<<endl;
    //    cout<<"the Final row is: " <<row<<endl;
    Final.close();
    

    char r;                  //可以得到列数
    int row  = 0;    //列数
    //int line = 0;   //行数
    
    fstream rFinal(path,ios::in);
    if (!rFinal) {
        cerr<< " cannot open filel "  <<endl;
    }
    
    while (rFinal.get(r)) {
        
        if (r == '0' || r == '1') {
            row++;
        }
        
        //       if (c == '\n') {
        
        //           line++;
        //       }
    }
    row = row / (line);
    // cout<<"the Final line is: " <<line<<endl;
    cout<<"the rFinal row is: " <<row<<endl;
    rFinal.close();
    
    
    
    
    
    
    
    return 0;
}
