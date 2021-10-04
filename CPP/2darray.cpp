#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    //taking numbers from user 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //printing array
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){      //1st
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //printing reverse array
    for(int i=0; i<n; i++)
    {
        for(int j=m-1; j>=0; j--){
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;

}