#include<iostream>
#include<vector>
using namespace std;
void maxhe(vector<int>&arr,int n,int i){
int largest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && arr[left]>arr[largest]){
largest=left;
}
else if(right<n && arr[right]>arr[largest]){
largest=right;
}
if(largest!=i){
swap(arr[i],arr[largest]);
maxhe(arr,n,largest);
}
}
void minhe(vector<int>&arr,int n,int i){
int smallest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && arr[left]<arr[smallest]){
smallest=left;
}
else if(right<n && arr[right]<arr[smallest]){
smallest=right;
}
if(smallest!=i){
swap(arr[i],arr[smallest]);
minhe(arr,n,smallest);
}
}
void heapsort(vector<int>&arr ,int n){
for(int i=n/2-1;i>=0;i--)
maxhe(arr,n,i);
for(int i=n-1;i>0;i--){
swap(arr[0],arr[i]);
maxhe(arr,i,0);
}
}
int main(){
int n;
cout<<"enter a number of students:";
cin>>n;
vector<int>marks(n);
cout<<"enter a marks:";
for(int i=0;i<n;i++){
cin>>marks[i];
}
vector<int>maxheap=marks;
vector<int>minheap=marks;
for(int i=n/2-1;i>=0;i--){
maxhe(maxheap,n,i);
}
for(int i=n/2-1;i>=0;i--){
minhe(minheap,n,i);
}
cout<<"maximum marks:"<<maxheap[0]<<endl;
cout<<"minimum marks:"<<minheap[0]<<endl;
heapsort(marks,n);
cout<<"sorted marks:";
for(int mark:marks)
cout<<mark<<" ";
return 0;
}


