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

};

int main(){
   List myList;
    myList.clearList;
    myList.CreateThreeNodes;
    myList.PrintList;

}