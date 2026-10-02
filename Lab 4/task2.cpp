#include<iostream>
using namespace std;


struct Node{  //Node structure
    int data;
    Node * next;
};

class List{
    private:
        Node * head = nullptr;
    
    public:
       void clearList(){
         Node *current =head;
         while(current !=nullptr){
             Node * nextNode =current;
             current = current->next;
             delete nextNode;
         }
         head =nullptr;
        }
        void PrintList(){
            Node *current=head;
            cout<<"\nList: ";
             if(current == NULL){
                 cout<<" Empty List...";
                 return;
                 }
            while(current !=nullptr){ 
                 cout<<current->data <<" ";
                 current =current->next;
            }
        }
        void CreateThreeNodes(){
            Node *temp;  //temporary node for traversal
            cout<<"\nEnter Nodes: ";
            int arr[3];
            head =new Node;
            temp =head;
            for(int i=0;i<3;i++){
                cin>>arr[i];     //entering the data
                temp->data=arr[i];     //stored in the node
                if(i<2){                  //create new node if array not fully traversed yet
                   temp->next =new Node;
                temp =temp->next;
                }
                temp->next =nullptr;      //at the end of the array
            }
        }
        void AddNode(int data){
            Node *current = head;
             if(current == NULL){
                 head =new Node;
                 head->data=data;
                 head->next=nullptr;
                 return;
                 }
             while(current->next != nullptr){
                current = current ->next;
             }
             current->next =new Node;
             current->next->data=data;
             current->next->next=nullptr;
        }
        int countNodes(){
            Node *current=head;
            int count=0;
            while(current != nullptr){ //increasing the counter
                current= current->next;
                count++;
            }
            return count;
        }

};

int main(){
   List myList;
    cout<<"Enter a non-negative integer: ";
    int n,value;
    cin>>n;
    if(n<0){
        cout<<" Oops Negative Number entered..\n";
    }
    cout<<"Enter Values: ";
    for(int i=0;i<n;i++){
        cin>>value;
        myList.AddNode(value);
    }
    myList.PrintList();
    myList.countNodes();
}