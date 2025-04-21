#include<iostream>
#include<string.h>
using namespace std;
const int maxcity=50;
struct Node{
    int time;
    char city[50];
    Node*next;
};
class flight{
    Node*list[maxcity];
    char cities[maxcity][50];
    int numc;
    public:
    flight(){
    numc=0;

    for(int i=0;i<maxcity;i++){
        list[i]=NULL;
    }
    }
    void addcity(){
        cout<<"enter a number of cities:";
        cin>>numc;
        cin.ignore();
        cout<<"enter a name of cities:";

        for(int i=0;i<numc;i++){
            cin.getline(cities[i],50);
        }
        for(int i=0;i<numc;i++){
            for(int j=0;j<numc;j++){
            if(i==j)continue;
                char ch;
                cout<<"flight is present between"<<" "<<cities[i]<<" " <<"and"<<" "<<cities[j]<<" "<<"if yes or not(y/n)";
                cin>>ch;
                if(ch=='y'){
                    int time;
                    cout<<"enter a time required for going to:"<<" "<<cities[i]<<" "<<"to"<<" "<<cities[j]<<endl;
                    cin>>time;
                    Node *newNode=new Node;
                    newNode->time=time;
                    strcpy(newNode->city,cities[j]);
                    newNode->next=list[i];
                    list[i]=newNode;
                }
            }
        }
    }
    void display(){
        cout<<"flight from source to destination:";
        for(int i=0;i<numc;i++){
            cout<<cities[i]<<"->";
            Node* temp = list[i];
            while (temp) {
                cout << temp->city << " (" << temp->time << " min) -> ";
                temp = temp->next;
            }
           

            
        }
        

    }
};

    int main() {
        int choice;
        flight flightGraph;
    
        do {
        
            cout << "1. enter flight routes\n";
            cout << "2. display flight connections\n";
            cout << "enter your choice: ";
            cin >> choice;
    
            switch (choice) {
                case 1:
                    flightGraph.addcity();
                    break;
                case 2:
                    flightGraph.display();
                    break;
               
                default:
                    cout << "Invalid choice:";
                    break;
                    
            }
                    
}while(choice!=3);
        
return 0;
        
    }


