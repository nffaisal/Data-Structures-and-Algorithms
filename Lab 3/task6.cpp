#include<iostream>
using namespace std;

struct Student{ //student struct/blueprint 
    int rollnumber;
    string fullName;
    float marks[4];
    int n =4;
};

void displayStudent(const Student *student ){ //pointer function to display details
    cout<<"\n   STUDENT DETAILS:   "<<endl;
    cout<<"Full Name:  "<< student->fullName<<endl;
    cout<<"Roll Number:  "<<student->rollnumber<<endl;
    cout<<"Marks: ";
    for(int i=0; i<student->n ; i++){
        cout<<student->marks[i]<<" ";
    }
}
void enterDetails(Student *student){
        cout<<"Enter full name: ";  //enter name
        getline(cin, student->fullName); 
        cout<<"Enter Roll Number: "; //enter rollnumber
        cin>>student->rollnumber;

        cout<<"Enter Marks: \n";
         for(int i=0; i<student->n ; i++){ //entering all student marks
        cin>> student->marks[i];
        cout<<" ";
    }

}
void displayIfExists(const Student *s){  //if not null it wil print the details of the student
    if(s != nullptr){
        displayStudent(s);
    }else{
        cout<<"\n  No record Available \n";
    }
}

int main(){
     cout<<"\n Without assigning an object and pointer pointing to NUll: \n ";
     Student *s1 =nullptr;  //pointer points to nothing
     displayIfExists(s1);
     cout<<"\n After assigning an object and entering details: \n ";
     s1 = new Student;  //created an actual struct
     enterDetails(s1);   //entering details
     displayIfExists(s1);
     cout<<"\n After deleting pointer and setting it to null: \n ";
     delete s1;       //deleting pointer and setting it to null
     s1 =nullptr;
     displayIfExists(s1);

}