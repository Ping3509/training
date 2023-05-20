//贪心

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]<m){
                cnt++;
                i++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}