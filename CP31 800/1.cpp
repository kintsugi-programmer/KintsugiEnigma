#include<bits/stdc++.h>
using namespace std;
int main(){
int testcases;
cin>>testcases;
for ( int i=1;i<=testcases;i++){
int boxes=0;
int maxlength=0;
cin>>boxes>>maxlength;
vector<int> arr(boxes); // int arr[]; is invalid, array not dynamic
for (int i1=1;i1<=boxes;i1++){cin>>arr[i1-1];}
vector<int> sortedarr = arr;
sort(sortedarr.begin(),sortedarr.end()); // if (arr != arr.sort(arr.begin(), arr.end())) direct is invalid
if (maxlength==1){if (arr!=sortedarr){cout<<"NO"<<endl;}
// forgot to YES at maxlength=1 and sorted
else{cout<<"YES"<<endl;}
}
else{cout<<"YES"<<endl;}



}
return 0;
}