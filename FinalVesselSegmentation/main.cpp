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

#define M 655    //——————————————————————————————————————————————行  需要手动输入
#define N 695       //———————————————————————————————————————————列  需要手动输入
int A[M][N]={0};         
int B[M][N]={0};         // B数组用来存贮走过的路并将1改为2，
int C[M][N]={0};        //
int i;
int j;
int number = 0;   //  步数
int pointsnumber = 0;   //  交点数量
int direction = 0; //   判断有多少端点
int sum = 0;    //周围8个空为1的总个数 == 一个交点对应关系点的数量
queue<Tree> acrossPointsTree;   //临时存交叉点
queue<Tree> foreverAcrossPointsTree;   //存交叉点
queue<Tree> dataWriteTree;  //写入数据
int edgenumber = 0;





//主要任务，判断当一个点完成路径后跳到下一点

string path = "/Users/ruanmingzhe/Desktop/Data/data1/image1skeletonDataChange";
/********************************
 OpenTxtToArray
 main fuction:  打开txt文件并将值转递给数组
 description:   none
 
 
 ********************************/


void OpenTxtToArray()
{
    
    
    ifstream infile;//定义读取文件流，相对于程序来说是in
    infile.open(path+".txt");//打开文件
    
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            
            infile >> A[i][j];
            B[i][j]=A[i][j];
            C[i][j]=A[i][j];
            if (A[i][j] == 1) {
            }
            
        }
    }
    infile.close();//读取完成之后关闭文件
}


/********************************
 convert
 main fuction:  将0赋值给C
 description:   none
 
 
 ********************************/


void covert(){
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            C[i][j]=0;
        }
    }
}



/********************************
 judgepointsdirection
 main fuction:  判断端点
 description:   none
 
 
 ********************************/


void judgepointsdirection(){
    
    //******************************************         输出端点         *********************************************
    ofstream writedirection;
    writedirection.open( path + "nodeDirection.txt");
    //
    
    
    
    
    Tree tree;
    for(int i = 0 ; i<M ; i++){
        for (int j =0; j<N; j++) {
            
            if (A[i][j]==1) {
                sum = A[i-1][j-1] + A[i-1][j] +A[i-1][j+1] +A[i][j-1] +A[i][j+1] +A[i+1][j-1] +A[i+1][j] +A[i+1][j+1];
                
                if (sum==1) {                   //判断   端点
                    writedirection<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    direction  = direction + 1;
                }
            }
        }
    }
    writedirection.close();
}




/********************************
 judgepointsandstore
 main fuction:  将所有的交点找到并存入队列
 description:   none
 
 
 ********************************/





void judgepointsandstore(){
    
    
    
    //******************************************         输出交点         *********************************************
    ofstream writeacrosspoints;
    writeacrosspoints.open(path+ "nodeData.txt");
    //
    
    
    
    Tree tree;
    for(int i = 0 ; i<M ; i++){
        for (int j =0; j<N; j++) {
            
            if (A[i][j]==1) {
                sum = A[i-1][j-1] + A[i-1][j] +A[i-1][j+1] +A[i][j-1] +A[i][j+1] +A[i+1][j-1] +A[i+1][j] +A[i+1][j+1];
                
                if (A[i-1][j-1] + A[i-1][j] != 2 && A[i-1][j] + A[i-1][j+1] != 2 && A[i-1][j+1] + A[i][j+1] != 2 && A[i][j+1] + A[i+1][j+1] != 2 && A[i+1][j+1] + A[i+1][j] != 2 && A[i+1][j] + A[i+1][j-1] != 2 && A[i+1][j-1] + A[i][j-1] != 2 && A[i][j-1] + A[i-1][j-1] != 2 && sum ==3) {
                    tree.start.x =  i;
                    tree.start.y =  j;
                    tree.aroundnumber = sum;
                    acrossPointsTree.push(tree);
                    dataWriteTree.push(tree);
                    writeacrosspoints<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    
                    
                    number = number + 1;
                    pointsnumber = pointsnumber + 1;
                    
                }
                
                if (sum>=4 && A[i-1][j-1] + A[i-1][j] != 2 && A[i-1][j] + A[i-1][j+1] != 2 && A[i-1][j+1] + A[i][j+1] != 2 && A[i][j+1] + A[i+1][j+1] != 2 && A[i+1][j+1] + A[i+1][j] != 2 && A[i+1][j] + A[i+1][j-1] != 2 && A[i+1][j-1] + A[i][j-1] != 2 && A[i][j-1] + A[i-1][j-1] != 2 ) {
                    tree.start.x =  i;
                    tree.start.y =  j;
                    writeacrosspoints<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    
                    //cout<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    
                    tree.aroundnumber = sum - 1;
                    acrossPointsTree.push(tree);
                    dataWriteTree.push(tree);
                    number = number + 1;
                    pointsnumber = pointsnumber + 1;
                }
                
                if (sum==1) {
                    tree.start.x =  i;
                    tree.start.y =  j;
                    tree.aroundnumber = sum;
                    acrossPointsTree.push(tree);
                    writeacrosspoints<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    
                    //cout<<setw(3)<<setfill('0')<<i<<";"<<setw(3)<<setfill('0')<<j<<endl;
                    
                    dataWriteTree.push(tree);
                    number = number + 1;
                    pointsnumber = pointsnumber + 1;
                }
            }
        }
    }
    writeacrosspoints.close();
}



/********************************
 judgepoints
 main fuction:  判断所有的点
 description:   none
 
 
 ********************************/


void judgepoints(){
    if (A[i][j]==1) {
        sum = A[i-1][j-1] + A[i-1][j] +A[i-1][j+1] +A[i][j-1] +A[i][j+1] +A[i+1][j-1] +A[i+1][j] +A[i+1][j+1];
        
        
        
        /* -------------------  当一个点周围点的和大于等于3时，这个点为交点   --------------------*/
        
        
        
        if (A[i-1][j-1] + A[i-1][j] != 2 && A[i-1][j] + A[i-1][j+1] != 2 && A[i-1][j+1] + A[i][j+1] != 2 && A[i][j+1] + A[i+1][j+1] != 2 && A[i+1][j+1] + A[i+1][j] != 2 && A[i+1][j] + A[i+1][j-1] != 2 && A[i+1][j-1] + A[i][j-1] != 2 && A[i][j-1] + A[i-1][j-1] != 2 && sum >= 3) {
            point a {
                i,j
            };
            C[i][j] = 3;
            
            
            acrossPointsTree.front().interpoints.push_back(a);
            
            
            
            if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
                return;
            }
            
            
            i = acrossPointsTree.front().start.x;
            j = acrossPointsTree.front().start.y;
            
            
            return;
        }
        
        
        
        
        /* -------------------  当一个点周围点的和等于1时，这个点为端点   --------------------*/
        
        
        if (sum==1) {
            point a {
                i,j
            };
            C[i][j] = 3;
            
            //            cout<<i<<" "<<j<<"交点"<<endl;
            
            acrossPointsTree.front().interpoints.push_back(a);
            
            
            if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
                
                //                cout<<acrossPointsTree.front().aroundnumber<<" 关联点已经全部存入      路径数 "<<acrossPointsTree.front().interpoints.size()<<" 节点数 "<<endl;
                return;
            }
            
            
            i = acrossPointsTree.front().start.x;
            j = acrossPointsTree.front().start.y;
            
            return;
        }
        
    }
}


/********************************
 judgetrace
 main fuction:  得到起始点坐标，开始对该点进行遍历
 description:   none
 
 
 ********************************/

void judgetrace()
{
    //    cout<<i<<"  "<<j<<"\n"<<endl;
    C[i][j]=3;
    if (A[i-1][j]==1  &&  C[i-1][j]!=3 )
    {
        i = i-1;
        j = j;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i-1][j+1]==1  &&  C[i-1][j+1]!=3)
    {
        i = i-1;
        j = j+1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i][j+1]==1 &&  C[i][j+1]!=3)
    {
        i = i;
        j = j+1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i+1][j+1]==1  &&  C[i+1][j+1]!=3 )
    {
        i = i+1;
        j = j+1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i+1][j]==1  &&  C[i+1][j]!=3)
    {
        i = i+1;
        j = j;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i+1][j-1]==1   &&   C[i+1][j-1]!=3)
    {
        
        i = i+1;
        j = j-1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if ( A[i][j-1]==1   &&   C[i][j-1]!=3)
    {
        i = i;
        j = j-1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
    }
    else if (A[i-1][j-1]==1  &&  C[i-1][j-1]!=3)
    {
        
        i = i-1;
        j = j-1;
        judgepoints();
        if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
            return;
        }
        judgetrace();
        
    }
    
}



/********************************
 whetherfinish
 main fuction:  判断每一个点的路径是否遍历完，若遍历完，调findinterrelationship函数，否则继续遍历
 description:   none
 
 ********************************/

void whetherfinish(){
    
    judgetrace();
    if (acrossPointsTree.front().aroundnumber == acrossPointsTree.front().interpoints.size()) {
        for (int i = 0; i< M; i++) {
            for (int j = 0; j<N; j++) {
                if (C[i][j]==3){
                    C[i][j] = 1;
                }
            }
        }
        return;
    }
    
}


/********************************
 findinterrelationship
 main fuction:  循环number（交点的个数）次， 每一个点的每一条路径都遍历完之后调回这个函数
 description:   none
 
 
 ********************************/



void findinterrelationship(){
    for (int k=0; k<number; k++) {
        i = acrossPointsTree.front().start.x;
        j = acrossPointsTree.front().start.y;
        
        whetherfinish();
        foreverAcrossPointsTree.push(acrossPointsTree.front());
        acrossPointsTree.pop();
    }
    
    
}


/********************************
 traverseInterpoints
 main fuction:  遍历所有的相关邻点
 description:   none
 
 
 ********************************/



void traverseInterpoints()
{
    for (size_t i = 0; i < foreverAcrossPointsTree.front().interpoints.size(); i++) {
        cout << foreverAcrossPointsTree.front().interpoints.at(i).x<<" "<<foreverAcrossPointsTree.front().interpoints.at(i).y<<" \n";
    }
    cout<<"i love you"<<endl;
}




/********************************
 showinterrelationship
 main fuction:  输出所有交点的相邻关系点
 description:   none
 ********************************/

void showinterrelationship(){
    
    
    //******************************************         输出关系边         *********************************************
    ofstream writeedgedata;
    writeedgedata.open(path+ "edgeData.txt");
    //
    
    
    for (int k = 0; k<number; k++) {
        
        for (size_t i = 0; i < foreverAcrossPointsTree.front().interpoints.size(); i++) {
            writeedgedata<<setw(3)<<setfill('0')<<foreverAcrossPointsTree.front().start.x<<";"<<setw(3)<<setfill('0')<<foreverAcrossPointsTree.front().start.y<<","<<setw(3)<<setfill('0')<< foreverAcrossPointsTree.front().interpoints.at(i).x<<";"<<setw(3)<<setfill('0')<<foreverAcrossPointsTree.front().interpoints.at(i).y<<"\n";
            
            edgenumber = edgenumber + 1;
        }
        
        foreverAcrossPointsTree.pop();
    }
    writeedgedata.close();
    
}



int main()
{
    OpenTxtToArray();
    
    judgepointsdirection();
    cout<<" 已输出端点数量  "<<endl;
    cout<<" 端点数量："<<direction<<endl;
    
    
    
    judgepointsandstore();
    cout<<" 已输出交点数量  "<<endl;
    cout<<" 交点数量: "<<pointsnumber<<endl;
    
    
    
    findinterrelationship();
    showinterrelationship();
    cout<<" 已输出关系边数量  "<<endl;
    cout<<" 关系边数量："<<edgenumber<<endl;
    
    
    
    
}
