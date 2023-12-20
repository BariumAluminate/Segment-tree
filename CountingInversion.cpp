#include <bits/stdc++.h>
const int maxN=1e5+7;
using namespace std;
int st[4*maxN];
void build(int id,int l,int r){
    if(l==r) {
        st[id]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
void update(int id,int l,int r,int num){
    if(l==num&&r==num){
        st[id]++;
        return;
    }
    int mid=(l+r)>>1;
    if(mid<num){
        update(2*id+1,mid+1,r,num);
    }
    else {
        update(2*id,l,mid,num);
    }
    st[id]=st[2*id]+st[2*id+1];
}
int get(int id,int l,int r,int v){
    if(l>v) return 0;
    if(r<=v) return st[id];
    int mid=(l+r)>>1;
    int get1=get(2*id,l,mid,v);
    int get2=get(2*id+1,mid+1,r,v);
    return get1+get2;
}
int main(){
    int n,ans=0;
    cin>>n;
    int a[n];
    set<int> s;
    build(1,1,n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    vector <int> b;
    for(int x:s) b.push_back(x);
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    }
    for(int i=0;i<n;i++){
        ans+=get(1,1,n,a[i]);
        update(1,1,n,a[i]);
    }
    cout<<ans;
}
