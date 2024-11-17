#include<iostream>
using namespace std;

int sum(int no){
    if(no==0) return 0; 
    else return no+sum(no-1);
}

void parameterized(int i,int sum){
    if(i<1){
        cout<<sum;
        return ;
    }
    parameterized(i-1,sum+1);
}

int fact(int a){
    if(a==0) return 1; 
    else return a*fact(a-1);
}

int main(){
    int n;
    cin>>n;
    parameterized(n,0);
    int no;
    cin>>no;
    cout<<sum(no);
    int a;
    cin>>a;
    cout<<fact(a);
}