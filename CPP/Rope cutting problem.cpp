/*
Problem : 
We are given a rope of length n , we are to cut it into maximum number of pieces such that each of them have length either a , b or  c . 

Inputs :
n = > length of rope
a , b , c => possible legths of each piece

outputs : Maximum number of pieces

Sample i/p's:

i/p: 5 3 1 2
o/p: 5

i/p: 5 4 2 6
o/p: -1 (as we will have atleast one odd length piece)

*/
#include <iostream>
using namespace std;
int cut(int, int, int, int);

int cut(int n, int a, int b, int c)
{
    //if length of the remaining rope is 0 , return 0
    if (n == 0)
        return 0;

    //if length of remaining rope after cutting a piece of given lenght is less than , return -1
    if (n < 0)
        return -1;
    //assign value of  maximum possible pieces in the res variable
    int res = max(cut(n - a, a, b, c), max(cut(n - b, a, b, c), cut(n - c, a, b, c)));
    //in case the rope cant be cut into pieces of given lengths , return -1 , else return res+1
    if (res == -1)
        return -1;
    else
        return res + 1;
}

int main()
{
    //input the length of rope and possible lenghts
    int n, a, b, c;
    cout << "Enter the values of n , a , b , c " << endl;
    cin >> n >> a >> b >> c;
    cout << "No. of pieces are : " << cut(n, a, b, c);
}
