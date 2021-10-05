#include<bits/stdc++.h>
using namespace std;
int specPair(vector<vector<int>> arr,int n){
    vector<vector<int>> ans(n); //initializing ans with n rows
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i].push_back(0); //inserting n 0's in every row
        }
    }
    int mx=INT_MIN;
    for(int j=n-1;j>-1;j--){
        ans[n-1][j]=max(arr[n-1][j],mx); // every element of last row will
        // contain max element from arr[n-1][n-1] till its position
    }
    mx=INT_MIN;
    for(int i=n-1;i>-1;i--){
        ans[i][n-1]=max(arr[i][n-1],mx);
        // every element of last column will contain the max element from 
        // arr[n-1][n-1] till its position
    }
        for(int j=n-2;j>-1;j--){
            for(int i=n-2;i>-1;i--){
                ans[i][j]=max(arr[i][j],max(ans[i][j+1],ans[i+1][j]));
                // every ans[i][j] stores max element in the part of matrix
                // from row = i and col =j till row = n-1 and col = n-1
            }
        }
    int res=INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            res=max(res,ans[i+1][j+1]-arr[i][j]);
            // for each i,j value at ans[i+1][j+1] stores the max element
            // in the elements with row>i and col>j
        }
    }
    return res;
}
int main(){
    vector<vector<int>> vec={{1,2,-1,-4,20},{-8,-3,4,2,1},{3,8,6,1,3},{-4,-1,1,7,-6},{0,-4,10,-5,1}};
    int res=specPair(vec,5);
    cout<<res<<endl;
}