#include<iostream>
using namespace std;

struct Student{
    int rollnumber;
    string fullName;
    float marks[4];
    int n;



};

void displayDetails(Student &student ){
    cout<<"STUDENT DETAILS"<<endl;
    cout<<"Full Name:  "<< student.fullName<<endl;
    cout<<"Roll Number:  "<<student.rollnumber<<endl;
    cout<<"Marks: "<<endl;
    for(int i=0; i<student.n ; i++){
        cout<<student.marks[i]<<" ";
    }
}
void enterDetails(Student &student){
        cout<<"Enter full name: ";
        cin>>student.fullName;
        cout<<"\nEnter Roll Number";
        cin>>student.rollnumber;
        cout<<"\nEnter number of marks: ";
        cin>>student.n;

        cout<<"\nEnter Marks: ";
         for(int i=0; i<student.n ; i++){
        cin>> student.marks[i];
        cout<<" ";
    }

}
int main(){
  Student s1;
  enterDetails(s1);
  displayDetails(s1);


}