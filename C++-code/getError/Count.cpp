//
//  Count.cpp
//  getError
//
//  Created by 阮明哲 on 2018/7/23.
//  Copyright © 2018年 steve.ruan. All rights reserved.
//

#include "Count.hpp"

using namespace std;
using namespace Eigen;

class Point{
public:string x;
public:string y;
public:string z;
};


class newPoint{
    public:double x;
    public:double y;
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
extern Error error;



template <class Type>
Type stringToNum(const string& str){
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}



void CountForAverage(){     //用来计算平均值
    queue<double> averagestorages;      //用来暂时存贮数据
    int divisor = 0;
    
    for (int q = 0; q < error.pointOne.size() ; q++) {          //计算一开始两点的误差值
        double pointsError = sqrt(pow(stringToNum<double>(error.pointOne[q].x) - stringToNum<double>(error.pointSecond[q].x), 2) + pow(stringToNum<double>(error.pointOne[q].y) - stringToNum<double>(error.pointSecond[q].y), 2));
        cout<<pointsError<<endl;
        averagestorages.push(pointsError);
        
    }
    
    
    for (int m = 0; m < error.pointOne.size(); m++) {        //计算平均值
        error.average = error.average + averagestorages.front();
        divisor = m + 1;
        error.individualError.push_back(averagestorages.front());
        averagestorages.pop();
    }
    error.average = error.average/divisor;
    cout<<"This is an average value:  "<<error.average<<endl;
    
}



void CountForOther(){               //用来计算最大值、最小值、第一四等分点、第二四等分点
    sort(error.individualError.begin(), error.individualError.end());
    for (vector<double>::iterator k = error.individualError.begin(); k != error.individualError.end(); k++){
//        cout<<*k<<endl;              //  important
    }
    cout<<"This is an min value:  "<<error.individualError.front()<<endl;
    cout <<"This is an max value:  "<<error.individualError.back() <<endl;
    
    if(error.individualError.size() % 2 ==0 ){  // 偶数
        
        cout<<"This is an firstQuarter value:  "<<error.individualError.at(error.individualError.size() * 1 / 4) <<endl;
        cout<<"This is an thirdQuarter value:  "<<error.individualError.at(error.individualError.size() * 3 / 4) <<endl;
    }
    
    
    if(error.individualError.size() % 2 ==1 ){  // 奇数
        
        cout<<"This is an firstQuarter value:  "<<error.individualError.at((error.individualError.size() + 1) * 1 / 4) <<endl;
        cout<<"This is an thirdQuarter value:  "<<error.individualError.at((error.individualError.size() + 1) * 3 / 4) <<endl;
    }
    
    
}



void Matching(){
    queue<double> averagestorages;
    queue<newPoint> resultstorages;
    int divisor = 0;
    newPoint resultpoint;

    MatrixXd result(2,1);
    MatrixXd ret(2, 2);
    
    /**********************        在每一组数据中，都有各自的ret值，需要改变        ***********************/
    
    ret<< 1, -0.00000000000000598889140,         -0.000000000000000717530292,1;
    
//    cout<<ret<<endl;
    
    for (int k = 0; k < error.pointSecond.size(); k++) {
        MatrixXd p(2,1);
        p<<stringToNum<double>(error.pointSecond.at(k).x),      stringToNum<double>(error.pointSecond.at(k).y);
        result = ret * p;
        
        result(0,0) = result(0,0) ;
        result(1,0) = result(1,0) ;
        
        resultpoint.x = result(0,0);
        resultpoint.y = result(1,0);
//        cout<<result(0,0)<<endl;
//        cout<<result(1,0)<<endl;
//        cout<<result(0,0)<<endl;
//        cout<<resultpoint.x<<endl;
        resultstorages.push(resultpoint);
//        cout<<resultstorages.front().x<<endl;
//        cout<<resultstorages.front().y<<endl;
        
    }
    
    for (int q = 0; q < error.pointOne.size() ; q++) {
        double pointsError = sqrt(pow(stringToNum<double>(error.pointOne[q].x) - resultstorages.front().x, 2) + pow(stringToNum<double>(error.pointOne[q].y) - resultstorages.front().y, 2));
        averagestorages.push(pointsError);
//        cout<<error.pointOne[q].x<<"   ### "  <<resultstorages.front().x<<endl;
//        cout<<error.pointOne[q].y<<"   ### "  <<resultstorages.front().y<<endl;
        cout<<pointsError<<endl;
        resultstorages.pop();
    }
    
    for (int m = 0; m < error.pointOne.size(); m++) {
        error.average = error.average + averagestorages.front();
        divisor = m + 1;
        error.individualError.push_back(averagestorages.front());
        averagestorages.pop();
    }

    
    
    error.average = error.average/divisor;
    cout<<"This is an average value:  "<<error.average<<endl;
    
}






void MatchingSift(){
    queue<double> averagestorages;
    queue<newPoint> resultstorages;
    int divisor = 0;
    newPoint resultpoint;
    
    MatrixXd result(2,1);
    MatrixXd ret(2, 2);
    
    /**********************        在每一组数据中，都有各自的ret值，需要改变        ***********************/
    
    ret<< 1.00000458, 0.000000755837092,         0.0000301476440,0.999993921;
    
//    cout<<ret<<endl;
    
    for (int k = 0; k < error.pointSecond.size(); k++) {
        MatrixXd p(2,1);
        p<<stringToNum<double>(error.pointOne.at(k).x),      stringToNum<double>(error.pointOne.at(k).y);
        result = ret * p;
        
        
        result(0,0) = result(0,0) -575.002307;
        result(1,0) = result(1,0) -9.99621299;
        
        
        
        resultpoint.x = result(0,0);
        resultpoint.y = result(1,0);
        //        cout<<result(0,0)<<endl;
        //        cout<<result(1,0)<<endl;
        //        cout<<result(0,0)<<endl;
        //        cout<<resultpoint.x<<endl;
        resultstorages.push(resultpoint);
        //        cout<<resultstorages.front().x<<endl;
        //        cout<<resultstorages.front().y<<endl;
        
    }
    
    for (int q = 0; q < error.pointOne.size() ; q++) {
        double pointsError = sqrt(pow(stringToNum<double>(error.pointSecond[q].x) - resultstorages.front().x, 2) + pow(stringToNum<double>(error.pointSecond[q].y) - resultstorages.front().y, 2));
        averagestorages.push(pointsError);
        //        cout<<error.pointOne[q].x<<"   ### "  <<resultstorages.front().x<<endl;
        //        cout<<error.pointOne[q].y<<"   ### "  <<resultstorages.front().y<<endl;
        cout<<pointsError<<endl;
        resultstorages.pop();
    }
    
    for (int m = 0; m < error.pointOne.size(); m++) {
        error.average = error.average + averagestorages.front();
        divisor = m + 1;
        error.individualError.push_back(averagestorages.front());
        averagestorages.pop();
    }
    
    
    
    error.average = error.average/divisor;
    cout<<"This is an average value:  "<<error.average<<endl;
    
}







