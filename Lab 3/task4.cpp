#include<iostream>
using namespace std;

struct Student{ //student struct/blueprint 
    int rollnumber;
    string fullName;
    float marks[4];
    int n =4;
};

void displayStudent(const Student *student ){ //pointer function
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
void updateMarks(Student *student,float newMarks, int pos){
        student->marks[pos] =newMarks;  
}
int main(){
  Student *s1 =new Student;
  enterDetails(s1);
  displayStudent(s1);
  cout<<"\nEnter  old marks to replace: ";
  int newMarks,oldmarks, index;
  bool found =false;
  cin>>oldmarks;
  for(int i=0; i<s1->n;i++){
    if(s1->marks[i] == oldmarks){
        index =i;
        found =true;
        break;
    }
  }
  cout<<"Enter New Marks: ";
  cin>>newMarks;
  updateMarks(s1,newMarks,index);
  displayStudent(s1);


}