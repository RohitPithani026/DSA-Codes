#include<iostream>
using namespace std;

void f(int i,int n){
    if(i>n) return;
    cout<<"Rohit";
    cout<<endl;
    f(i+1,n);
}

void print(int i,int no){
    if(i>no) return;
    cout<<i;
    cout<<endl;
    print(i+1,no);
}

void reverse(int i,int b){
    if(i<1) return;
    cout<<i;
    cout<<endl;
    reverse(i-1,b);
}

void normal(int i,int c){
    if(i<1) return;
    normal(i-1,c);
    cout<<i<<endl;
}

void reverseBacktrack(int i,int d){
    if(i<1) return;
    reverse(i+1,d);
    cout<<i;
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the no of times the name to be printed : ";
    cin>>n;
    f(1,n);
    int no;
    cout<<"Enter the no of times the number to be printed : ";
    cin>>no;
    print(1,no);
    int b;
    cout<<"Enter the no of times the number to be printed in reverse : ";
    cin>>b;
    reverse(b,b);
    int c;
    cout<<"Enter the no of times the number to be printed in normal : ";
    cin>>c;
    normal(c,c);
    int d;
    cout<<"Enter the no of times the number to be printed in reverse backtrack : ";
    cin>>d;
    reverseBacktrack(d,d);
}