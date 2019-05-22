//
//  sort.cpp
//  FinalVesselSegmentation
//
//  Created by 阮明哲 on 2018/6/2.
//  Copyright © 2018年 steve.ruan. All rights reserved.
//

#include "sort.hpp"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <malloc/malloc.h>
#include <map>
#include<vector>
#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;


class point
{
public:int x;
public:int y;
};


class Tree
{
public: point start;
public:vector<point> interpoints;  //存交点
public:int aroundnumber;   //一个交点周围的路径数
};

vector<Tree> trees= vector<Tree>();

vector<point> points = vector<point>();

#define M 605
#define N 700
int A[M][N]={0};
int B[M][N]={0};         // B数组用来存贮走过的路并将1改为2，
char C[M][N]={0};
int i;
int j;
int number = 0;   //  步数
int direction = 0; //   判断有多少端点
int sum = 0;    //周围8个空为1的总个数 == 一个交点对应关系点的数量
queue<Tree> acrossPointsTree;   //临时存交叉点
queue<Tree> foreverAcrossPointsTree;   //存交叉点
queue<Tree> dataWriteTree;  //写入数据
int edgenumber = 0;
void OpenTxtToArray()
{
    FILE *fp;
    if((fp=fopen("/Users/ruanmingzhe/Desktop/datas/data1/numpyhSkeletonsecond.txt","rt"))==NULL)
    {
        printf("cannot open file\n");
    }
    
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            
            fscanf(fp,"%d",&A[i][j]);
            B[i][j]=A[i][j];
            C[i][j]=A[i][j];
            if (A[i][j] == 1) {
                cout<<setw(3)<<setfill('0')<<i<<setw(3)<<setfill('0')<<j<<"000"<<'\n';
            }
            
        }
        fscanf(fp,"\n");
    }
}

int main(){
    return 0;
}
