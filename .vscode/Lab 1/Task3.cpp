#include<iostream>
using namespace std;

class student{ // class student with attributes rollNumber and marks
    public:
      int rollNumber;
      int marks;
    
     void display(){
        cout<<"Roll Number: "<<rollNumber<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
};
int main(){
   student s1;  //created two students
   student s2;
   s1.rollNumber =1;   //assigning roll numbers and marks to each
   s1.marks = 75;
   s2.rollNumber=2;
   s2.marks = 90;
   //calling display function now
   s1.display();
   s2.display();
   cout<<"after changing marks: \n";
   s1.marks =80; //changing s1 marks to 80
   s1.display();
   s2.display();

}