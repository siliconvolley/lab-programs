#include<iostream>
using namespace std;

int pow(int n, int p){
    if(p == 1)
        return n;
    else
        return (n * (pow(n, p-1)));
}

int rev(int num){
    int reverse = 0, rem, base = 1;
    if(num == 0)
        return reverse;
    else{
        rem = num / 10;
        num = num / 10;
        base = base * 10;
        reverse = rev(num + rem*base);
    }
    
}
int main(){
    int n, p;
    cout<<"Enter Number and its Power: "<<endl;
    cin>>n>>p;
    cout<<pow(n, p)<<endl;

int num;
    cout<<"Enter Number to be Reversed: "<<endl;
    cin>>num;
    cout<<"Reverse of "<<num<<" is "<<rev(num)<<endl;
    return 0;
}

while(num != 0){
    rem = num / 10;
    num = num / 10;
    base = base * 10;
    rev = rev + rem * base;
}