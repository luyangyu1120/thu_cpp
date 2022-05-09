#include<iostream>
using namespace std;

int main(){
    int a[10],b[10];
    for(int i=0;i<10;i++){
        a[i]=i*2-1;
        b[9-i]=a[i];
    }
    for(int j=0;j<10;j++){
        cout<<"a["<<j<<"]="<<a[j]<<endl;
    }
    for(int j=0;j<10;j++){
        cout<<"b["<<j<<"]="<<b[j]<<endl;
    }
    return 0;
}