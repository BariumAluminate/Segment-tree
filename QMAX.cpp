#include <bits/stdc++.h>
const int maxN=1e5+7;
using namespace std;
long long a[maxN],st[4*maxN],lazy[4*maxN];
void build(int id,int l,int r){
    if(l==r){
        st[id]=0;
        lazy[id]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=max(st[2*id],st[2*id+1]);
}
void fix(int id,int l,int r){
    if(lazy[id]==0) return;
    st[id]+=lazy[id];
    if(l!=r){
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
    }
    lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,int k){
    fix(id,l,r);
    if(l>v||r<u) return;
    if(u<=l&&r<=v){
        lazy[id]+=k;
        fix(id,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,u,v,k);
    update(2*id+1,mid+1,r,u,v,k);
    st[id]=max(st[2*id],st[2*id+1]);
}
long long get(int id,int l,int r,int u,int v){
    fix(id,l,r);
    if(l>v||r<u) return -1;
    if(u<=l&&r<=v) return st[id];
    int mid=(l+r)>>1;
    long long get1=get(2*id,l,mid,u,v);
    long long get2=get(2*id+1,mid+1,r,u,v);
    return max(get1,get2);
}
int main(){
    int n,m,x,y,k;
    cin>>n>>m;
    build(1,1,n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>k;
        update(1,1,n,x,y,k);
    }
    int p;cin>>p;
    while(p--){
        cin>>x>>y;
        cout<<get(1,1,n,x,y)<<endl;
    }
}
