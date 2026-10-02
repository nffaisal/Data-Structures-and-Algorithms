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
        void printSecondNode(){
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

int main(){
   List myList;
   cout<<"searching an empty List: ";
   myList.searchNode(1);  //searching in an empty list
   cout<<"\nSearching a 1 node List";
   myList.AddNode(10);
   myList.printSecondNode(); 

   myList.searchNode(10);
   cout<<"\nEnter Number of Nodes: ";  //populating the list with 10,20,30,20
   int n; cin>>n;
   int value;
   for(int i=0;i<n;i++){
        cin>>value;
        myList.AddNode(value);
   }
   myList.searchNode(20);  //after a populated list i search for node 20
   myList.searchNode(99);   //searching for 99 in a populated list
    
}