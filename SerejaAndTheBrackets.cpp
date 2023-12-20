#include <bits/stdc++.h>
using namespace std;
string s;
int n;
struct Node{
    int open,close,optiomal;
    Node (int o,int c,int opt){
        open=o;
        close=c;
        optiomal=opt;
    }
    friend Node operator +(const Node& left, const Node& right){
        Node sth;
    }
};
int main(){
    cin>>s;
    n=s.length();
}
