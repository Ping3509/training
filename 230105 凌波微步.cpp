#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        set<int>st;
        int m;cin>>m;
        while(m--){
            int x;cin>>x;
            st.insert(x);
        }
        int s=st.size();
        cout<<s<<endl;
    }
    return 0;
}