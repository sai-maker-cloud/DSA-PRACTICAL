#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
int n;
cout<<"enter a number of students:";
cin>>n;
vector<int>marks(n);
cout<<"enter a marks of students:";
for(int i=0;i<n;i++){
cin>>marks[i];
}
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
for(int i=0;i<n;i++){
maxheap.push(marks[i]);
minheap.push(marks[i]);
}
cout<<"maximum marks obtained:"<<maxheap.top()<<endl;
cout<<"minimum marks obtained:"<<minheap.top()<<endl;
return 0;
}
"built in function code donot use for practical exam use heap2.cpp"
