#include <bits/stdc++.h>
const int maxN=1e5+7;
const int inf=1e9+7;
using namespace std;
int a[maxN],st[4*maxN],n;
void build(int id,int l,int r){
    if(l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=max(st[2*id],st[2*id+1]);
}
void update(int id,int l,int r,int u,int val){
    if(l>u||u>r) return;
    if(l==r) {
        st[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,u,val);
    update(2*id+1,mid+1,r,u,val);
    st[id]=max(st[2*id],st[2*id+1]);
}
int get(int id,int l,int r,int u,int v){
    if(l>v||r<u) return -inf;
    if(u<=l&&v>=r) return st[id];
    int mid=(l+r)>>1;
    int get1=get(2*id,l,mid,u,v);
    int get2=get(2*id+1,mid+1,r,u,v);
    return max(get1,get2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    int q,type,x,y;cin>>q;
    while(q--){
        cin>>type>>x>>y;
        if(type==1) {
            update(1,1,n,x,y);
        }
        else cout<<get(1,1,n,x,y)<<endl;
    }
}
