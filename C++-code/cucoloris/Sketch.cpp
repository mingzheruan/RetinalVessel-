//
//  Sketch.cpp
//  getError
//
//  Created by 阮明哲 on 2019/4/9.
//  Copyright © 2019 steve.ruan. All rights reserved.
//

#include "Sketch.hpp"

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

queue<newPoint> PointsOne;   //临时队列


string filename = "/Users/ruanmingzhe/Desktop/Data/data6/";

/********************************
 Cucoloris
 main fuction:
 description:   none
 
 
 ********************************/

void Cucoloris(){
    
    
    int line =584;
    int row =565;
    int lineB = line;
    int rowB = row;
    
    
    vector<vector<int>> A(line,vector<int>(row));
    vector<vector<int>> B(line,vector<int>(row));
    vector<vector<int>> C(line,vector<int>(row));
    vector<vector<int>> D(line,vector<int>(row));
    
    
    ifstream infile;//定义读取文件流，相对于程序来说是in
    infile.open(filename + "image1Data.txt");//打开文件
    for (int i = 0; i < line; i++)//定义行循环
    {
        for (int j = 0; j < row; j++)//定义列循环
        {
            infile >> A[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
            C[i][j] =A[i][j];
        }
    }
    infile.close();//读取完成之后关闭文件
    
    
    
    
    
    ifstream infileB;//定义读取文件流，相对于程序来说是in
    infileB.open(filename+"image2Data.txt");//打开文件
    for (int i = 0; i < lineB; i++)//定义行循环
    {
        for (int j = 0; j < rowB; j++)//定义列循环
        {
            infileB >> B[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
        }
    }
    infileB.close();//读取完成之后关闭文件
    
    
    MatrixXd result(2,1);
    MatrixXd ret(2, 2);
    newPoint coordinate;
    
    /**********************        在每一组数据中，都有各自的ret值，需要改变        ***********************/
    
    ret<< 1, 0,         0,1;
    
    //    cout<<ret<<endl;
    
    
    for(int i=0;i<line;i++)
    {
        for(int j=0;j<row;j++)
        {
            if (B[i][j]==1) {
                coordinate.x =i;
                coordinate.y =j;
                
                MatrixXd p(2,1);
                p<<(coordinate.x),(coordinate.y);
                result = ret * p;
                coordinate.x = (int)result(0,0);
                coordinate.y = (int)result(1,0);
                //                C[coordinate.x][coordinate.y] = 1;
                PointsOne.push(coordinate);
            }
            
        }
    }
    
//        int number =(int)PointsOne.size();
//
//        for (int i=0;i<number;i++){
//                D[PointsOne.front().x][PointsOne.front().y]=1;
//                PointsOne.pop();
//        }
//
//
//
//        ofstream writeC;
//        writeC.open("/Users/ruanmingzhe/Desktop/icbeb/DATAS/data2/ruanC.txt");
//
//        for (int i=0;i<line;i++){
//            for (int j=0;j<row;j++){
//                writeC<<D[i][j]<<" ";
//                // cout<<A[i][j]<<endl;
//
//            }
//            writeC<<"\n";
//        }
//
//        writeC.close();
//
    
    
    cout<<A[81][120]<<" "<<B[81][120]<<endl;

    int number =(int)PointsOne.size();

    for (int i=0;i<number;i++){

        for(int i=0;i<line;i++)
        {
            for(int j=0;j<row;j++)
            {

                if(PointsOne.front().x  == i &&  PointsOne.front().y== j){
                    C[i][j] = 0;
//                    cout<<i<<" "<<j<<endl;
//                    cout<<PointsOne.size()<<endl;
                    goto one;

                }
            }

        }
    one:
        PointsOne.pop();

    }


    
    
    
    ofstream writeforcucoloris;
    writeforcucoloris.open(filename+"ruan.txt");
    for (int i=0;i<line;i++){
        for (int j=0;j<row;j++){
            writeforcucoloris<<C[i][j]<<" ";
            // cout<<A[i][j]<<endl;
            
        }
        writeforcucoloris<<"\n";
    }
    
    writeforcucoloris.close();
    
}
