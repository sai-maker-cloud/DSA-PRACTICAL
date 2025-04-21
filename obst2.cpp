#include <iostream>
#include <queue>
#include <climits> 
using namespace std;

const int maxn = 100;

int w[maxn][maxn];
int c[maxn][maxn];
int r[maxn][maxn];
int p[maxn], q[maxn];

int findmin(int i, int j) {
int k, minIndex = i; 
int min = INT_MAX;   
for (k = i+1; k <= j; k++) {
int temp = (k == i ? 0 : c[i][k - 1]) + (k == j ? 0 : c[k + 1][j]) + w[i][j];
if (temp < min) {
min = temp;
minIndex = k;
        }
    }
return minIndex;
}

void buildtree(int n) {
int j;
for (int i = 0; i < n; i++) {
w[i][i] = q[i];
int k=findmin(i,j);
c[i][i] = q[i];
r[i][i] = k;
    }
for (int L = 2; L <= n; L++) {
for (int i = 0; i <= n - L; i++) {
int j = i + L - 1;
w[i][j] = 0;
for (int k = i; k <= j; k++) {
                w[i][j] = w[i][j]+p[k] + q[k];
            }
            int min = INT_MAX, minIndex;
            for (int k = i; k <= j; k++) {
                int temp = (k == i ? 0 : c[i][k - 1]) + (k == j ? 0 : c[k + 1][j]) + w[i][j];
                if (temp < min) {
                    min = temp;
                    minIndex = k;
                }
            }
            c[i][j] = min;
            r[i][j] = minIndex;
        }
    }
}

void printTable(int n) {
    cout << "Table for Optimal Binary Search Tree:" << endl;
    cout << "| i | j | Root | Cost | Weight | Left Child | Right Child |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int root = r[i][j];
            int leftChild = (root > i) ? root - 1 : -1; 
            int rightChild = (root < j) ? root + 1 : -1; 

            cout << "| " << i << " | " << j << " | " << root << " | " << c[i][j] 
                 << " | " << w[i][j] << " | ";
            if (leftChild == -1) {
                cout << "-";
            } else {
                cout << leftChild;
            }
            cout << " | ";
            if (rightChild == -1) {
                cout << "-";
            } else {
                cout << rightChild;
            }
            cout << " |" << endl;
        }
    }
}


void getdata(int& n) {
    cout << "Enter the number of keys: ";
    cin >> n;
    cout << "Enter the keys (not used in this example):" << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
    }
    cout << "Enter the probabilities of successful search:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << "Enter the probabilities of unsuccessful search:" << endl;
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }
}

void display(int n) {
    queue<pair<int, int>> q;
    q.push({0, n - 1}); 

    while (!q.empty()) {
        int node = q.front().first;
        int span = q.front().second;
        q.pop();

        cout << "Node: " << node << " (Root of subtree from " << node << " to " << span << ")" << endl;

        if (node != span) {
            int root = r[node][span];
            if (root > node) {
                q.push({node, root - 1}); 
            }
            if (root < span) {
                q.push({root + 1, span}); 
            }
        }
    }
}

int main() {
    int n;
    getdata(n);
    buildtree(n);
    printTable(n);
    display(n);
    return 0;
}

