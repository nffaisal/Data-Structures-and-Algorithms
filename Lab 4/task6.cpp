#include<iostream>
using namespace std;


struct Node{  //Node structure
    int data;
    Node * next;
};

class List{ //list holding head and all functions regarding nodes
    private:
        Node * head = nullptr;
    
    public:

       void clearList(){
         Node *current =head;
         while(current !=nullptr){
             Node * nextNode =current; //each current node is stored
             current = current->next;  //move onto the next node
             delete nextNode; //delete the current node
         }
         head =nullptr;  //ensuring the head pointer variable does not point to anything
        }

        void PrintList(){
            Node *current=head;
            cout<<"\nList: ";
             if(current == NULL){  //if list is empty
                 cout<<" Empty List...";
                 return;
                 }
            while(current !=nullptr){  //moving until we print all variables
                 cout<<current->data <<" ";
                 current =current->next;
            }
        }
        
        void AddNode(int data){   //adding a node at any point
            Node *current = head;
             if(current == NULL){  //if an empty list
                 head =new Node;
                 head->data=data;
                 head->next=nullptr;
                 return;
                 }
             while(current->next != nullptr){ //moving till the last node
                current = current ->next;
             }
             current->next =new Node;  //replacing the nullptr  of the last node and connecting to new node
             current->next->data=data;  //adding the new added nodes data
             current->next->next=nullptr;  //ensuring the new node is not pointing to anything
        }
        
        int countNodes(){   //counting all nodes
            Node *current=head;
            int count=0;
            while(current != nullptr){ //increasing the counter
                current= current->next;
                count++;
            }
            return count;
        }
        void searchNode(int searchData){ //searching for the correct data
            Node *current =head;
            int pos=1;
            while(current !=nullptr){
                if(current->data ==searchData){
                    cout<<"\nFound! at Node: "<<pos;
                    return;
                }
                current=current->next;
                pos++;
            }
            cout<<"\nValue Not Found..";
        }
        void deleteNode(int data){ // deleting a node at any point function
            Node * current = head;
            Node *delNode= nullptr;
            Node * previous=nullptr;
            if(current == NULL){  //if list is empty
                 cout<<" No Nodes to delete...";
                 return;
                 }
            while(current !=nullptr){   //searching for that data
                if(current->data ==data){   //checking if the pointers data is the same or not
                    if(current==head){ //if deleting start node
                        head =current->next;
                        delNode =current;
                        delete delNode;
                        return;
                    }
                    //if deleting middle node or end node
                    delNode =current;
                    previous->next= current->next;
                    delete delNode;
                    return;
                }
                //moving both pointers forward
                previous =current;
                current=current->next;   
            }
             cout<<"\nData Not Found..";
        }
        void insertAtBeginning(int data){  //simply make a new node and then get its pointer to point to the head 
            Node *newStart = new Node;
            newStart->next =head;
            newStart->data =data;
            head =newStart;  //get our variable head to point to the new beginning node
        }
        void printSecondNode(){  //Printing Second Node Function
            Node* current =head;
            int pos =1;
            int total =countNodes();
            if(total <2){
                cout<<"\nFewer Than 2 Nodes "<<endl;
                return;
            }
            while(pos !=2){
                current =current->next;
                pos++;
            }
            cout<<"The Second Node is "<<current->data<<endl;

        }
};

void Menu(){
    cout<<"Starting Node Program\n";
    List myList;
    int option,value;
    do{
        cout<<"Choose A Function: \n";
        cout<<"1. Add A node at the end:\n";
        cout<<"2. Delete a node: \n";
        cout<<"3. Print Second Node: \n";
        cout<<"4. Print all Nodes: \n";
        cout<<"5. Search A value: \n";
        cout<<"6. Count All Nodes: \n";
        cout<<"7. Add a Node at the start: \n";
        cout<<"8. Exit Program: \n";
        cout<<"Option: ";
        cin>>option;
        switch(option){
            case 1:
               cout<<"\nEnter a value: ";
               cin>>value;
               myList.AddNode(value);
               break;
            case 2:
                cout<<"\nEnter a value: ";
                cin>>value;
                myList.deleteNode(value);
                break;
            case 5: 
                cout<<"\nEnter a value: ";
                cin>>value;
                myList.searchNode(value);
                break;
            case 7:
             cout<<"\nEnter a value: ";
             cin>>value;
                myList.insertAtBeginning(value);
                break;
            case 3:
                 myList.printSecondNode();
                 break;
            case 4:
                 myList.PrintList();
                 break;
            case 6:
                myList.countNodes();
                 break;
            case 8:
                 myList.clearList();
                 cout<<"\nExiting Program...";
                 break;   
            default:
                cout<<"Invalid Option!\n";                   
        };

    }while(option !=8);
}
int main(){
   Menu();  
}