#include<bits/stdc++.h>
using namespace std;
int main(){
    int tests=0;
    cin>>tests;
    while (tests--){
        int num=0; 
        cin>>num; //1
        if ((num+1)%3==0 or (num-1)%3==0 ){cout<<"First"<<endl;}
        else {cout<<"Second"<<endl;}       
    }
    return 0;
}