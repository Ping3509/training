/*Tabris减肥记 贪心
 https://ac.nowcoder.com/acm/contest/49991/A
*  
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    while(n--){
        int w,t;
        cin>>w>>t;
        int cnt=0;
        while(w>120){
            w-=t;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}