#include<iostream>
#include<vector>
using namespace std;
class tree{
public:
string name;
vector<tree*>children;
tree(string name){
this->name=name;
}
void addchild(tree*child){
children.push_back(child);
}
void display(int level=0){
for(int i=0;i<level;i++)
cout<<" ";
cout<<name<<endl;
for(tree*child :children){
child->display(level+1);
}

}
};
int main(){

tree* book = new tree("How Universe Works");

    int chnum;
    cout << "Enter the number of chapters: ";
    cin >> chnum;
    cin.ignore(); 
    for (int i = 0; i < chnum; i++) {
        string chname;
        cout << "Enter the name of chapter " << (i + 1) << ": ";
        getline(cin, chname); 
        tree* chapter = new tree(chname);

        int secnum;
        cout << "Enter the number of sections in chapter " << (i + 1) << ": ";
        cin >> secnum;
        cin.ignore(); 
        for (int j = 0; j < secnum; j++) {
            string secname;
            cout << "Enter the name of section " << (j + 1) << ": ";
            getline(cin, secname); 
            tree* section = new tree(secname);

            int subsecnum;
            cout << "Enter the number of subsections in section " << (j + 1) << ": ";
            cin >> subsecnum;
            cin.ignore(); 

            for (int k = 0; k < subsecnum; k++) {
                string subname;
                cout << "Enter the name of subsection " << (k + 1) << ": ";
                getline(cin, subname); 
                tree* subsection = new tree(subname);
                section->addchild(subsection); 
            }
            chapter->addchild(section); 
        }
        book->addchild(chapter); 
    }

    cout << " Displaying Book Structure:";
    book->display(); 
    return 0;
}


