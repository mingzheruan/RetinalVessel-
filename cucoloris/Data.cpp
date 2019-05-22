//
//  Data.cpp
//  cucoloris
//
//  Created by 阮明哲 on 2019/4/9.
//  Copyright © 2019 steve.ruan. All rights reserved.
//

#include "Data.hpp"

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

extern Error error;


    string path="/Users/ruanmingzhe/Desktop/Data/data3/image2Data.txt";

void InsertAndSplit(int i,string a[i],int judge){
    
    queue<string> storage;
    
    size_t len = a[i].length();
    for(int index =(int) len-3; index > 0; index -= 3)
        a[i].insert(index, ",");//插入逗号。
    cout<<a[i]<<endl;//输出结果。
    
    
    if (judge == 1) {
        string s = a[i];
        vector<string> rs;
        boost::split( rs, s, boost::is_any_of( "," ), boost::token_compress_on);
        for( vector<string>::iterator it = rs.begin(); it != rs.end(); ++ it ){
            storage.push(*it);
        }
        
        
        Point point;
        point.x = storage.front();
        storage.pop();
        point.y = storage.front();
        storage.pop();
        point.z = storage.front();
        storage.pop();
        error.pointOne.push_back(point);
        
    }
    
    
    
    if (judge == 2) {
        string s = a[i];
        vector<string> rs;
        boost::split( rs, s, boost::is_any_of( "," ), boost::token_compress_on);
        for( vector<string>::iterator it = rs.begin(); it != rs.end(); ++ it ){
            storage.push(*it);
        }
        
        Point point;
        point.x = storage.front();
        storage.pop();
        point.y = storage.front();
        storage.pop();
        point.z = storage.front();
        storage.pop();
        error.pointSecond.push_back(point);
        
        
    }
    
    
}




void InsertAndSplitSift(int i,string a[i],int judge){
    
    queue<string> storage;
    
    if (judge == 1) {
        string s = a[i];
        vector<string> rs;
        boost::split( rs, s, boost::is_any_of( "," ), boost::token_compress_on);
        for( vector<string>::iterator it = rs.begin(); it != rs.end(); ++ it ){
            storage.push(*it);
        }
        
        
        Point point;
        point.x = storage.front();
        storage.pop();
        point.y = storage.front();
        storage.pop();
        point.z = storage.front();
        storage.pop();
        error.pointOne.push_back(point);
        
    }
    
    
    
    if (judge == 2) {
        string s = a[i];
        vector<string> rs;
        boost::split( rs, s, boost::is_any_of( "," ), boost::token_compress_on);
        for( vector<string>::iterator it = rs.begin(); it != rs.end(); ++ it ){
            storage.push(*it);
        }
        
        Point point;
        point.x = storage.front();
        storage.pop();
        point.y = storage.front();
        storage.pop();
        point.z = storage.front();
        storage.pop();
        error.pointSecond.push_back(point);
        
        
    }
    
    
}






void OpenTxtToArray()
{
    

    
    char c;                            //可以得到数据行数
    //    int row  = 0;    //列数
    int line = 0;   //行数
    
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
    
    
    
    
    
    
    
    
    
    
    
    /* --------------------------  读取每行数据  --------------------------*/
    
    /*
     string a[1000];              //采用 string 类型，存100行的文本，不要用数组
     string b[1000];
     int i = 0;
     int j = 0;
     
     
     ifstream infile;
     
     infile.open("/Users/ruanmingzhe/Desktop/icbeb/DATAS/data1/skeletonCorenode.txt",ios::in);
     
     while(!infile.eof())            // 若未到文件结束一直循环
     {
     getline(infile, a[i], '\n');//读取一行，以换行符结束，存入 a[] 中
     //下一行
     
     InsertAndSplit(i,a,1);
     
     
     
     i++;
     }
     infile.close();
     
     
     
     ifstream infileSecond;
     
     infileSecond.open("/Users/ruanmingzhe/Desktop/icbeb/DATAS/data1/skeletonCorenodeSecond.txt",ios::in);
     
     while(!infileSecond.eof())            // 若未到文件结束一直循环
     {
     getline(infileSecond, b[j], '\n');//读取一行，以换行符结束，存入 b[] 中
     
     InsertAndSplit(j,b,2);
     
     j++;                    //下一行
     }
     infileSecond.close();
     
     */
}
