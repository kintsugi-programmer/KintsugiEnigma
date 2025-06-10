#include<bits/stdc++.h>
using namespace std;


int main(){
int tests;
cin>>tests;
for(int testcases=0;testcases<tests;testcases++){
int stations, x;
cin>> stations >> x;
vector<int> arr(stations);
for(int count=0; count<stations; count++){
    cin>> arr[count];
}

int d1=arr[0]-0;
int d2=(x-arr[stations-1])*2;
int d3=0;
for(int count=0; count<stations-1; count++){ // also stations-1 as arr[count+1] would not go outside bound
    // d3=max(arr[count],arr[count+1]); Invalid we have to compare past distance bw stations to new distance, NOT to compare station number
    d3=max(d3,(arr[count+1]-arr[count]));
}
int d4=max(d1,d2);
cout<<max(d4,d3)<<endl;

}
return 0;
}