#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1;
        int a1[n1];
        for(int i=0;i<n1;i++){
            cin>>a1[i];
        }
        cin>>n2;
        int a2[n2];
        for(int i=0;i<n2;i++){
            cin>>a2[i];
        }
        cin>>n3;
        int a3[n3];
        for(int i=0;i<n3;i++){
            cin>>a3[i];
        }
        int x=0,y=0,z=0;
        while(x<n1 and y<n2 and z<n3){
            if(a1[x]==a2[y] and a2[y]==a3[z]){
                cout<<a1[x]<<" ";
                x++;y++;z++;
            }
            else if(a1[x]<a2[y]){
                x++;
            }
            else if(a2[y]<a3[z]){
                y++;
            }
            else{
                z++;
            }
        }

        
    }
}