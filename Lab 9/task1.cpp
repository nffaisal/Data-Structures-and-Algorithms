#include<iostream>
#include<queue>
using namespace std;
/* I used Linked List implementation as it does not require resizing of lists
 once capacity is reached and it allows for o(n) traversal*/

struct Student{ //contains all the students details
    string name;
    int rollno;
    Student *next;

};

class HelpDesk{ //class containing all the functions
private:
    Student *head;
    queue<int> request;

public:
    HelpDesk(){ //constructor initializing the private data types
    head=NULL;
    }
    ~HelpDesk() {

    Student* curr = head;

    while(curr != nullptr) {

        Student* temp = curr;

        curr = curr->next;

        delete temp;
    }

    head = nullptr;
}
    void AddStudent() {

    int rollno;
    string name;

    cout << "\nEnter Student's Name: ";
    cin >> name;

    cout << "\nEnter Student's Roll Number: ";
    cin >> rollno;

    // Check duplicate
    if(SearchStudent(rollno)) {
        cout << "\nStudent Already Exists!";
        return;
    }

    // Create new node
    Student* newStudent = new Student();

    newStudent->name = name;
    newStudent->rollno = rollno;
    newStudent->next = nullptr;

    // If list is empty
    if(head == nullptr) {
        head = newStudent;
    }

    else {

        Student* curr = head;

        // Traverse to last node
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        // Connect new node
        curr->next = newStudent;
    }
    cout << "\nStudent Added Successfully!";
}
    bool empty(){
        return head ==nullptr;
    }
    bool SearchStudent(int rollno){
        Student *curr=nullptr;
        if(empty()){
        // No students Registered yet 
         return false;
        }
        curr=head;
        while(curr !=nullptr){ //loop through to find if student is duplicate
            if(curr->rollno == rollno){
                 return true;
            }
            curr=curr->next;
            }
        return false;
    }
    void DisplayStudents(){ //displays all the current students and their details
        Student *curr =head;
        int count =1;
        if(empty()){
         cout<<"\n No students Registered! ";}
        while(curr !=nullptr){ //Looping through all the students
            cout<<endl<<count
            <<" Name: "<< curr->name
            <<" Roll No: "<<curr->rollno;
            count++;
            curr=curr->next;
        }  
        delete curr;
        curr=nullptr;  
    }

    void AddRequest() { // Add the request to the queue

        int rollno;

        cout << "\nEnter Student Roll Number: ";
        cin >> rollno;

        if (!SearchStudent(rollno)) {
            cout << "\nStudent is not registered!";
            return;
        }

        request.push(rollno);
        cout << "\nHelp Request Added!";
    }
    void ServeRequest(){
        if(request.empty()){
            cout<<"\nNo Pending Requests!";
            return;
        }
        cout<<"\nServing Student Number "<<request.front()<<" : ";
        request.pop();
        cout<<"\n Request Served ";

    }
    
    //Can further add display queue function
};
class Menu{
    private:
        int choice;
        HelpDesk HelpDesk1;
    public:
    void display(){ //Menu for rotating options
        
        int rollno;
        bool found;
          cout << "\n--Student Help Desk--\n";
        do{      
        cout << "\n1. Add Student ";
        cout << "\n2. Search Student";
        cout << "\n3. Display Students";
        cout << "\n4. Add  Requests";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            HelpDesk1.AddStudent();
            break;
        case 2:
            cout<<"\nEnter the Student's Roll Number: ";
            cin>>rollno;
             found= HelpDesk1.SearchStudent(rollno);
            if(found){
                cout<<"\nStudent was found!";
            }else{
                cout<<"\nStudent was Not found!";
            }
            
            break;
        case 3: //case 3
            HelpDesk1.DisplayStudents(); break;
        case 4:
            HelpDesk1.AddRequest();
            break;
        default:
            break;
        }
        }while(choice!= 5);

    }
};
int main(){
    Menu newMenu;
    newMenu.display(); //run the looping menu
}