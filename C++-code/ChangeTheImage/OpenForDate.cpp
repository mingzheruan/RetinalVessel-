//
//  OpenForDate.cpp
//  ChangeTheImage
//
//  Created by 阮明哲 on 2019/4/20.
//  Copyright © 2019 steve.ruan. All rights reserved.
//

#include "OpenForDate.hpp"

using namespace std;


int line =655;
int row =695;

int lineA = line - 1 ;
int rowA  = row - 1 ;


class point{
public: int x;
public: int y;
};

point First,Last;
vector<vector<int>> A(line,vector<int>(row));



void OpenForDate(){
    
    string pathA = "/Users/ruanmingzhe/Desktop/Data/data6/image2skeletonData";
    
    
    ifstream infile;//定义读取文件流，相对于程序来说是in
    infile.open(pathA+".txt");//打开文件
    for (int i = 0; i < line; i++)//定义行循环
    {
        for (int j = 0; j < row; j++)//定义列循环
        {
            infile >> A[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
        }
    }
    infile.close();//读取完成之后关闭文件
    

    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (A[i][j]==0) {
                First.x=i;
                First.y=j;
                goto one;
            }
        }
    }
    
one:
    cout<<First.x<<" "<<First.y<<endl;
    
    
    
    
    for (int i = lineA; i > 0; i--)
    {
        for (int j = rowA; j > 0; j--)
        {
            if (A[i][j]==0) {
                Last.x=i;
                Last.y=j;
                goto second;
            }
        }
    }
second:
    cout<<Last.x<<" "<<Last.y<<endl;
    
    
    
    for (int i = 0; i < First.x; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (A[i][j]==1) {
                A[i][j]=0;
            }
        }
    }
    
    
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < First.y; j++)
        {
            if (A[i][j]==1) {
                A[i][j]=0;
            }
        }
    }
    
    
    
    for (int i = lineA; i > Last.x; i--)
    {
        for (int j = rowA; j > 0; j--)
        {
            if (A[i][j]==1) {
                A[i][j]=0;
            }
        }
    }
    
    for (int i = lineA; i > 0; i--)
    {
        for (int j = rowA; j > Last.y; j--)
        {
            if (A[i][j]==1) {
                A[i][j]=0;
            }
        }
    }
    
    
    
    ofstream writeA;
    writeA.open(pathA+"Change" + ".txt");
    for (int i=0;i<line;i++){
        for (int j=0;j<row;j++){
            writeA<<A[i][j]<<" ";
            // cout<<A[i][j]<<endl;
            
        }
        writeA<<"\n";
    }
    
    writeA.close();
}

