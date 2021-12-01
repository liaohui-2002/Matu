//
// Created by liaohui on 2021/11/17.
//
#include <iostream>
#include <cstring>
using namespace std;

class User{
    char name[1000][10];
    char pass[1000][10];
    static int cnt;
public:
    User(char *na, char *pa){
        int i = 0;
        ++cnt;
        for(i = 0; na[i] != '\0'; ++i)name[cnt][i] = na[i];name[cnt][i] = '\0';
        for(i = 0; pa[i] != '\0'; ++i)pass[cnt][i] = pa[i]; pass[cnt][i] = '\0';
    }
    void AddUser(char *na, char *pa){
        int i = 0;
        ++cnt;

        for(i = 0; na[i] != '\0'; ++i)name[cnt][i] = na[i];name[cnt][i] = '\0';
        for(i = 0; pa[i] != '\0'; ++i)pass[cnt][i] = pa[i]; pass[cnt][i] = '\0';
    }
    int login(char *na, char *pa){
        bool f = 1;
        for(int i = 1; i <= cnt; ++i){
            f = 1;
            int len = max(strlen(name[i]), strlen(na));
            for(int j = 0; j < len; ++j){
                if(name[i][j] != na[j]){
                    f = 0;
                    break;
                }
            }
            if(!f)continue;
            len = max(strlen(pass[i]), strlen(na));
            for(int j = 0; j < len; ++j){
                if(pass[i][j] != pa[j]){
                    f = 0;
                    break;
                }
            }
            if(f)return i;
        }
        if(f == 0)return -1;
    }
};
int User:: cnt = 0;
int main(){
    char name[10],name1[10],pass[10],pass1[10];
    cin>>name>>pass>>name1>>pass1;
    User user("LiWei", "liwei101");
    user.AddUser(name,pass);
    if (user.login(name1,pass1) >=0)
    {
        cout<<"Success Login!"<<endl;
    }
    else{
        cout<<"Login failed!"<<endl;
    }
    return 0;
}