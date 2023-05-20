#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){ 
   

    priority_queue<long long,vector<long long>,greater<long long> > q;//从小到大
    int n;
    while(cin>>n) {
        int temp,ans=0;
        for(int i=0; i<n; i++) {
            cin>>temp;
            q.emplace(temp);
        }
        while(q.size()>1){
            long long a=q.top();
            q.pop();
            long long b=q.top();
            q.pop();
            ans+=a+b;
            q.emplace(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
} 

