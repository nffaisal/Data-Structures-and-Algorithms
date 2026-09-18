#include<iostream>
#include<iomanip>
using namespace std;

int main(){
      int n;
      cout<<"Enter N: ";
      cin>>n;
      int total =0; //total number of marks
      int passed =0; //total students passed

      if(n<0 || n>50){ 
        cout<<"error, no allocation or mark input";
        return 1;
    }  //validate n
      int *marks = new int[n]; 

      cout<< "Enter marks: ";
      for(int i=0; i<n; i++){ //entering marks
        cin>>*(marks +i);
        total += *(marks +i );
        
        if(*(marks +i) >=50){ passed +=1; } //checking how many students passed
      }
      double avg= total /n;

      for(int i =0; i<n; i++){  //displaying marks
        cout<<*(marks +i)<< " ";
      }
      cout<<"\nAverage: "<<fixed << setprecision(2)<< avg;
      cout<<"\nPassed Count: "<< passed;

      delete[] marks;
      marks =NULL;


    return 0;
}