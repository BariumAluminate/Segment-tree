#include <bits/stdc++.h>
const int maxN=2e5+7;
using namespace std;
int a[maxN];
long long st[4*maxN];
void build(int id,int l,int r){
    if(l==r){
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
void update(int id,int l,int r,int i,int val){
    if(i < l || i > r) return;
    if(l == r){
        st[id]=val;
        return;
    }
    int mid = (l+r) >>1;
    update(2*id,l,mid,i,val);
    update(2*id+1,mid+1,r,i,val);
    st[id]=st[2*id]+st[2*id+1];
}
long long get(int id,int l,int r,int u,int v){
    if(l > v|| r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid=(l+r)>>1;
    long long get1 = get(2*id ,l , mid, u , v);
    long long get2= get(2*id+1 ,mid+1 ,r ,u ,v);
    return get1+get2;
}
int main(){
    int n,q,type,x,y;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        cin>>type>>x>>y;
        if(type==1) update(1,1,n,x,y);
        else cout<<get(1,1,n,x,y)<<endl;
    }
}
