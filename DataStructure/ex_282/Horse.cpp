#include<iostream>
#include<queue>
#include<cstring>
#include <malloc.h>
using namespace std;
const int maxn=500;

queue<pair<int,int> >q;//马能走到的棋盘上的坐标

bool vis[maxn][maxn];//表示是否已经访问过
int n,m,sx,sy,len[maxn][maxn];//表示马到达该坐标处的最少步数
int dis[8][2]={1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1};//马可以走的八个方向


void bfs(){
    q.push(make_pair(sx,sy));//入队
    vis[sx][sy]=1;//标记已经访问过
    while(!q.empty()){
        //取队首元素
        int x=q.front().first;
        int y=q.front().second;
        q.pop();//出队
        for(int i=0;i<8;i++){//遍历可走的方向
            int dx=x+dis[i][0];
            int dy=y+dis[i][1];
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!vis[dx][dy]){//可达点
                vis[dx][dy]=1;//标记已访问过
                len[dx][dy]=len[x][y]+1;//距离加1
                q.push(make_pair(dx,dy)); //以该点起点
            }
        }
    }
}
int main(){
    int num;//终点个数
    cin>>n>>m>>sx>>sy>>num;//输入棋盘大小，马的初始位置
    int arr[100][2];//终点坐标序列
    for (int k = 0; k <num ; ++k) {
        cin>>arr[k][0]>>arr[k][1];
    }
    memset(len,-1,sizeof(len));//初始距离为-1，表示不能到达
    len[sx][sy]=0;//起点到起点距离为0

    //bfs求解马到棋盘上任意一点的最少步数
    bfs();
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<len[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<num;i++){
            cout<<len[arr[i][0]][arr[i][1]];
        cout<<endl;
    }
}
