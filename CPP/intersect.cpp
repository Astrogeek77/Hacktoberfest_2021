// Intersection of sorted arrys (without duplication)


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int mergearr(int a[],int b[],int n,int m){
    
    int x=0,y=0;

    while(x<n and y<m){
        if(a[x] < b[y]){
            x++;
        }

        else if(a[x] > b[y]){
            y++;
        }
        else{
            cout<<b[y]<<" ";
            y++;
            x++;
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];   
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }

    mergearr(a,b,n,m);
}