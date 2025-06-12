#include<bits/stdc++.h>
using namespace std;


int main(){
    int tests;
    cin>>tests;

    for(int i1=0; i1<tests; i1++){

        int lenarr;
        cin>>lenarr;
        vector<string> arr(lenarr);
        string cinner;
        cin>>cinner;// bhai you are input whole string ,not char
        int con=0;
        int dot=0;
        for ( int i=0;i<lenarr;i++){
            arr[i]=cinner[i]; //This is correct now only because you switched to string. If it was int, it would be invalid.

            if (arr[i] == "."){con++;dot++;
            if (con==3){break;} // if i don't break then at next #, 3 will reset :) and only 3 number is enough to fill all :)
            }
            else if (arr[i] == "#"){con=0;}
        
        }
        if (con==3){cout<<2<<endl;}//ie at 3 ... , 2 will works for all :)
        else {cout<<dot<<endl;}
    }
return 0;
}
