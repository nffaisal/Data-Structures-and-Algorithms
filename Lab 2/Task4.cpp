#include<iostream>
using namespace std;
int main(){

    int row,col; //row and columns
    
    cout<<"Enter Student amount: ";
    cin>> row;
    cout<<"Enter Number of Subjects: "; 
    cin>>col;
    if(row<0 ||col<0){ cout<<"invalid entry"; return 1;}  //validation

   int* studentTotal = new int[row]();
   int* subjectTotal = new int[col]();

    int** marks = new int*[row];
    for(int i = 0; i < row; i++) {  //pointers to each column
     marks[i] = new int[col];
   }  
    for(int i=0;i<row; i++){   //getting each students total and getting them entered as well
        cout<<"enter Student "<<i +1<<" marks: ";
        for(int j=0;j<col; j++){
            cin>>*(*(marks+i)+j);

            studentTotal[i] += (*(*marks +i)+j);
        }
        cout<<endl;
    }
    cout<<"Marks Sheet: \n";
     for(int i=0;i<row; i++){   //Displaying Students Marks:
        cout<<"Student "<<i+1<<" : ";
        for(int j=0;j<col; j++){
            cout<<(*(*marks+i)+j)<< " ";
        }
        cout<<endl;
    }
        
    int highestMarks =0;
    int highestMarksIndex =0;
    cout<<"\nTotals: ";
    for(int i=0; i<row; i++){   //determining which student has the highest marks 
       cout<<studentTotal[i]<<" ";
        if(studentTotal[i]>highestMarks){ 
            highestMarks =studentTotal[i];
            highestMarksIndex =i;
        }
    }
    cout<<" Top Student: ";
    for(int i = 0; i < row; i++) {
     if(studentTotal[i] == highestMarks) {
        cout << i + 1 << " ";
    }
}

    for(int i = 0; i < row; i++) { //deleting pointer
    delete[] marks[i];
}

delete[] marks;
marks =nullptr;


}