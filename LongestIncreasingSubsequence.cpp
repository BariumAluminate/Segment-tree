#include <bits/stdc++.h>
const int maxN=1e6+7;
using namespace std;
int a[maxN],st[4*maxN],d=0;
int n;
void nen(){
    set <int> s;
    vector<int>b;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    d=s.size();
    for(int x:s){
        b.push_back(x);
    }
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    }
}
void build(int id,int l,int r){
    if(l==r) {
        st[id]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
void update(int id,int l,int r,int num,int val){
    if(l==num&&r==num){
        st[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(num<=mid){
        update(2*id,l,mid,num,val);
    }
    else{
        update(2*id+1,mid+1,r,num,val);
    }
    st[id]=max(st[2*id],st[2*id+1]);
}
int get(int id,int l,int r,int v){
    if(l>=v) return 0;
    if(r<v) return st[id];
    int mid=(l+r)>>1;
    int get1=get(2*id,l,mid,v);
    int get2=get(2*id+1,mid+1,r,v);
    return max(get1,get2);
}
int main(){
    st[0]=0;
    cin>>n;
    int ans=-1,k;
    build(1,1,n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    nen();
    for(int i=0;i<n;i++){
        k=get(1,1,d,a[i])+1;
        ans=max(ans,k);
        update(1,1,d,a[i],k);
    }
    cout<<ans;
}
