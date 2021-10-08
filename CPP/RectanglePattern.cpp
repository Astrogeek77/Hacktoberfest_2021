// here we write a program using loops to print a rectangle pattern where number of rows and columns will be enterd by the user

#include<iostream>
using namespace std;
int main(){
    int numberOfRows, numberOfColumns;
    cout<<"Enter number of rows: ";
    cin>>numberOfRows;
    cout<<"Enter number of columns: ";
    cin>>numberOfColumns;
    for (int i = 1; i <= numberOfRows; i++)
    {
        for (int j = 1; j <= numberOfColumns; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}