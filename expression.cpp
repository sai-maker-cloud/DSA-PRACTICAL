
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
bool isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
Node* tree(const string& prefix) {
    stack<Node*> st;
    int n = prefix.length();
    for (int i = n - 1; i >= 0; i--) {
        if (isoperator(prefix[i])) {
            Node* node = new Node(prefix[i]);           
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
            st.push(node);
        } else {            
            st.push(new Node(prefix[i]));
        }
    }    
    return st.top();
}
void post(Node* root) {
    if (!root) {
        return;
    }    
    stack<Node*> s1, s2;
    s1.push(root);  
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);               
        if (node->left) { 
            s1.push(node->left);
        }
        if (node->right) { 
            s1.push(node->right);
        }
    }      
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}
int main() {
string prefix;
    cout<<"enter a prefix string to convert postoreder:";
    cin>>prefix;
    Node* root = tree(prefix);
    post(root);
    return 0;
}

