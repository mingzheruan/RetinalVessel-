//
//  sort.cpp
//  FinalVesselSegmentation
//
//  Created by 阮明哲 on 2018/6/2.
//  Copyright © 2018年 steve.ruan. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <malloc/malloc.h>
#include <map>
#include<vector>
#include<iostream>
#include<queue>
#include<iomanip>
#include<fstream>
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

#define W 90  // the number of core points    改点的个数

int A[W]={0};

int i;
int j;
int number = 0;   //  步数
int direction = 0; //   判断有多少端点
int sum = 0;    //周围8个空为1的总个数 == 一个交点对应关系点的数量
queue<Tree> acrossPointsTree;   //临时存交叉点
queue<Tree> foreverAcrossPointsTree;   //存交叉点
queue<Tree> dataWriteTree;  //写入数据
int edgenumber = 0;

string path ="/Users/ruanmingzhe/Desktop/Data/data6/image2skeletonDataChangeCorenode.txt";

void OpenTxtToArray(){
  /*  FILE *fp;
    if((fp=fopen("/Users/ruanmingzhe/Desktop/icbeb/DATAS/data1/skeletonCorenodeSecond.txt","rt"))==NULL){
        printf("cannot open file\n");
    }
    
    for (int i=0;i<W ; i++){    // 输入到数组A[]中
        fscanf(fp,"%d",&A[i]);
        if (A[i] == 1) {
            cout<<setw(3)<<setfill('0')<<i<<setw(3)<<setfill('0')<<j<<"000"<<'\n';
        }
    }
    
   */
    ifstream infile;//定义读取文件流，相对于程序来说是in
    infile.open(path);//打开文件
    
    for (int i=0;i<W ; i++){    // 输入到数组A[]中
        infile>>A[i];
        if (A[i] == 1) {
            cout<<setw(3)<<setfill('0')<<i<<setw(3)<<setfill('0')<<j<<"000"<<'\n';
        }
    }
    
    
    
    
    infile.close();//读取完成之后关闭文件
    
    
    
    
    
    
    
    
}











void sort(){
    for (int i = 0;i < W; i++){
        for (int j = 0; j < W; j++) {
            if(A[i] < A[j]){
                int temp;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void show(){
    
    ofstream writesort;
    writesort.open(path);
    
    for (int i=0;i<W ; i++){
        writesort<<setw(9)<<setfill('0')<<A[i]<<'\n';
    }
}


int main(){
    OpenTxtToArray();
    sort();
    show();
    return 0;
}
