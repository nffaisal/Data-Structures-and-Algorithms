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
        void searchNode(int searchData){
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
        void insertAtBeginning(int data){  //simply make a new node and then get its pointer to point to the head 
            Node *newStart = new Node;
            newStart->next =head;
            newStart->data =data;
            head =newStart;  //get our variable head to point to the new beginning node
        }

};

int main(){
   List myList; //initialized List
   myList.clearList();
   myList.insertAtBeginning(10);
   myList.insertAtBeginning(20);
   myList.AddNode(30);
   myList.PrintList();
 
    
}