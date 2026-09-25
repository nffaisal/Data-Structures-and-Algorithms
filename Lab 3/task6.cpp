#include<iostream>
using namespace std;

struct Student{ //student struct/blueprint 
    int rollnumber;
    string fullName;
    float marks[4];
    int n =4;
};
               //Function To display Details
void displayStudent(const Student *student ){ 
    cout<<"\n   STUDENT DETAILS:   "<<endl;
    cout<<"Full Name:  "<< student->fullName<<endl;
    cout<<"Roll Number:  "<<student->rollnumber<<endl;
    cout<<"Marks: ";
    for(int i=0; i<student->n ; i++){
        cout<<student->marks[i]<<" ";
    }
}
//update marks Function 
void updateMarks(Student *student){
    int oldmarks,index,newMarks;
    bool found =false;
     cout<<"\nEnter  old marks to replace: ";
     cin>>oldmarks;

  for(int i=0; i<student->n;i++){  //CHECKING IF OLDMARKS exist
    if(student->marks[i] == oldmarks){
        index =i;
        found =true;
        break;
    }
  }
   if(found) {

        cout << "Enter New Marks: ";
        cin >> newMarks;

        student->marks[index] = newMarks;

        cout << "Marks updated successfully!\n";
    }
    else {
        cout << "Mark not found!\n";
    }
}
               //Function To enter details
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
                                 //Create Record
Student* createRecord(){   

    Student *student = new Student;

    enterDetails(student);

    return student;
}

                      //function to delete a record
void deleteRecord(Student *&student) { 

    if(student != nullptr) {

        delete student;
        student = nullptr;

        cout << "Record deleted successfully!\n";
    }
    else {
        cout << "No record to delete.\n";
    }
}

                                // Menu storing options 
void Menu(Student *&student) {

    int option;

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Create a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Display a record\n";
        cout << "4. Update marks\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";

        cin >> option;

        switch(option) {

            case 1:
                if(student == nullptr) {
                    student = createRecord();
                }
                else {
                    cout << "A record already exists.\n";
                }
                break;

            case 2:
                deleteRecord(student);
                break;

            case 3:
                displayIfExists(student);
                break;

            case 4:
                if(student != nullptr) {
                    updateMarks(student);
                }
                else {
                    cout << "No record available.\n";
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid option!\n";
        }

    } while(option != 5);
}




int main() {

    Student *s1 = nullptr;

    Menu(s1);

    return 0;
}