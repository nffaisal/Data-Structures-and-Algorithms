#include<iostream>
using namespace std;

struct Student{ //student struct/blueprint 
    int rollnumber;
    string fullName;
    float marks[4];
    int n =4;
};

void displayDetails(Student *student ){ //pointer function
    cout<<"STUDENT DETAILS:"<<endl;
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
int main(){
  Student *s1 =new Student;
  enterDetails(s1);
  displayDetails(s1); //calling it using address
   delete s1;
   s1 = nullptr;


}