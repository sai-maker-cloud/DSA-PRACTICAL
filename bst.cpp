#include<iostream>
using namespace std;
struct Node{
int data;
Node*left;
Node*right;
Node(int value){
data=value;
left=nullptr;
right=nullptr;
}
};
Node*insert(Node*root,int value){
if(root==nullptr){
return new Node(value);
}
if(value < root->data){
root->left=insert(root->left,value);
}
else{
root->right=insert(root->right,value);
}
return root;
}
int findh(Node*root){
if(root==nullptr)

return 0;
else if(root->left==nullptr && root->right==nullptr)
return 0;

return (1 + max(findh(root->left),findh(root->right)));

}
int minimum(Node*root){
while(root->left != nullptr){
root=root->left;
}
return root->data;
}
Node*mirror(Node*root){
if(root==nullptr){
return nullptr;
}
Node*temp=root->left;
root->left=mirror(root->right);
root->right=mirror(temp);

return root;
}
bool search(Node*root,int key){
if(root==nullptr){
return false;
}
if(key== root->data){
return true;
}
else if(key <root->data){
return search(root->left,key);
}
else{
return search(root->right,key);
}
}
void inorder(Node*root){
if(root==nullptr){
return;
}
inorder(root->left);
cout<<root->data;
inorder(root->right);
}
int main() {
    Node* root = nullptr;
    int n, value, key;

    cout << "enter the number of nodes to insert: ";
    cin >> n;

    cout << "enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    cout << "enter the key to search: ";
    cin >> key;
    if (search(root, key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    cout << "minimum value in BST: " << minimum(root) << endl;
    cout << "height of the BST: " << findh(root) << endl;

    cout << "mirroring the BST..." << endl;
    root = mirror(root);

    cout << "inorder traversal of the mirrored BST: ";
    inorder(root);
    cout << endl;


    return 0;
}


