#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dup = n;
    int revNum = 0;
    int sum = 0; 
    int cnt = 0 ;
    for(int i = 1 ; i*i<n ; i++){
        if(n%i==0){
            cnt++;
            cout<<i<<" ";
            if((n/i) != i ) cnt++;
        }
    }cout<<endl;
    if(cnt == 2)cout<<"true";
    else cout<<"false";
    cout<<endl;
    while(n>0){
        int ld = n % 10;
        sum = sum + (ld*ld*ld);
        revNum = (revNum * 10 ) + ld;
        n = n / 10;
    }
    cout<<revNum<<endl;
    if ( dup == revNum) cout<< "true";
    else cout<<"false";
    cout<<endl;
    if ( dup == sum) cout<< "true";
    else cout<<"false";
    
}