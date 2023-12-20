#include<bits/stdc++.h>
using namespace std;
vector<int> st[30];
void init(int n, int i=1){
    for(int i=0;i<n;i++) st[0].push_back(0);
    for(;st[i-1].size()>1;i++){
        if(st[i-1].size()%2) st[i-1].push_back(0);
        for(int j=0;j<st[i-1].size()/2;j++) st[i].push_back(0);
    }
}
void update(int p, int v){
    st[0][p]=v;
    for(int i=1;st[i].size();i++){
        p/=2;
        st[i][p]=max(st[i-1][p*2],st[i-1][p*2+1]);
    }
}
int mx(int r){
    int mxr=st[0][r];
    for(int i=0;r>0;i++){
        if(r%2) mxr=max(mxr,st[i][r-1]);
        r/=2;
    }
    return mxr;
}
void xuat(int i=0){
    while(st[i].size()){
        for(int j=0;j<st[i].size();j++) cout<<setw(3)<<st[i][j];
        cout<<endl;
        i++;
    }
}
int main(){
    init(7);
    update(3,7);
    update(0,4);
    xuat();
    cout<<mx(2)<<endl;
    update(1,6);
    xuat();
    cout<<mx(2)<<endl;
    cout<<mx(0)<<endl;
}
