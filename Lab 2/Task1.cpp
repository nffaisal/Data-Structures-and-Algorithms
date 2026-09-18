#include<iostream>
using namespace std;


  void print(int arr[], int n){
        int total= 0;
     for(int i =0; i<n;i++){     //displaying all values
        cout<<*(arr + i) << " ";
         total += *(arr +i);
    }
    cout<<"\nThe final Total is: "<< total;  //displaying total
}
int main(){

    int sales[5];
    int *p =sales;

    cout<<"Enter Five Values:\n";
    for(int i =0; i<5;i++){
        cin>>*(p + i);
    }
    //PART 1:
    cout<<"\n before adding 2 to the third day:"<<endl;
    print(p, 5);
    
    //adding two to third day
    cout<<"\n After adding two to third day: "<<endl;
    *(p+2) +=2;
    print(p,5);
    
}