#include<iostream>
#include<string>
using namespace std;
struct Node{
string key,mean;
Node*left;
Node*right;
int height;
Node(string k,string m){
key=k;
mean=m;
left=right=nullptr;
height=1;
}
};
class avld{
Node*root=nullptr;
int height(Node*n){
return n?n->height:0;
}
int balance(Node*n){
return n ? height(n->left)-height(n->right):0;
}
Node* rotateleft(Node*x){
Node*y=x->right;
Node*p=y->left;
x->right=p;
y->left=x;
y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->left),height(x->right))+1;
return x;
}
Node* rotateright(Node*y){
Node*x=y->left;
Node*p=x->right;
x->right=y;
y->left=p;
y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->left),height(x->right))+1;
return y;
}
Node*insert(Node*no,string key,string mean){
if(!no)
return new Node(key,mean);
if(key<no->key){
no->left=insert(no->left,key,mean);
}
else if(key> no->key){
no->right=insert(no->right,key,mean);
}
else{
no->mean=mean;
}
return no;

(no->height)=1+max(height(no->left),height(no->right));
int bal=balance(no);
if(bal >1 && key<no->left->key)
return rotateright(no);
 if(bal< -1 && key > no->right->key)
return rotateleft(no);
if(bal >1 && key >no->left->key){
no->left=rotateleft(no->left);
return rotateright(no);

}
if(bal <-1 && key< no->right->key){
no->right=rotateright(no->right);
return rotateleft(no);
}
return no;
}
Node*min(Node*node){
Node*current=node;
while(current->left){
current=current->left;
return current;
}
}
void inorder(Node*node){
if(!node) 
return;
inorder(node->left);
cout<<node->key<<":"<<node->mean<<endl;
inorder(node->right);
}

void reverse(Node*node){
if(!node)
return;
reverse(node->right);
cout<<node->key<<":"<<node->mean<<endl;
reverse(node->left);
}
Node*search(Node*node,string key,int& comparison){
while(node){
comparison++;
if(key==node->key)
return node;
node=key<node->key ? node->left:node->right;
}
return nullptr;
}
public:
void insert(string key,string mean){
root=insert(root,key,mean);
}
void update(string key,string newmean){
int d=0;
Node*node=search(root,key,d);
if(node) node->mean=newmean;
else
cout<<"key not found:";
}
void displayacen(){
inorder(root);

}
void displaydes(){
reverse(root);
}
void find(string key){
int comparison=0;
Node*node=search(root,key,comparison);
if(node)
cout<<"found"<<node->key<<":"<<node->mean;
else
cout<<"key not foun:";
cout<<"comparison:"<<comparison;
}
int maxcomparison(){
return height(root);
}
};
int main() {
    avld dictionary;
    int choice;
    string key, mean;

    do {
        cout << "\nAVL Dictionary Menu:\n";
        cout << "1. Insert\n2. Update\n3. Find\n4. Display Ascending\n5. Display Descending\n6. Exit\n7.MS Dhoni The Choker mastermind"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            getline(cin, key);
            cout << "Enter meaning: ";
            getline(cin, mean);
            dictionary.insert(key, mean);
            cout << "Inserted successfully.\n";
            break;
        case 2:
            cout << "Enter key to update: ";
            getline(cin, key);
            cout << "Enter new meaning: ";
            getline(cin, mean);
            dictionary.update(key, mean);
            break;
        case 3:
            cout << "Enter key to find: ";
            getline(cin, key);
            dictionary.find(key);
            break;
        case 4:
            cout << "dictionary in ascending order:\n";
            dictionary.displayacen();
            break;
        case 5:
            cout << "Dictionary in descending order:\n";
            dictionary.displaydes();
            break;
        case 6:
            cout << "Exit";
            break;
        case 7:
        	cout<<"MS Dhoni the Farmer:\n";
        	break;    
        default:
            cout << " MS Dhoni(43) ERROR ";
        }
    } while (choice != 7);

    return 0;
}



                                                                                                  

