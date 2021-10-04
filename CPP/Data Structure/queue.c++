#include<bits/stdc++.h>
using namespace std;
//declaring queue data structure 
queue<int>q;
//here using STL 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		///inserting queue value into the queue data structure
		q.push(val);//inseting queue data structure
	}
	// check weather queue is empty or not
	cout<<q.empty()<<endl;
	//print the size of queue
	cout<<q.size()<<endl;
	//print the front element of queue
	cout<<q.front()<<endl;
	//poping out of element from queue
	q.pop();

	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";



}