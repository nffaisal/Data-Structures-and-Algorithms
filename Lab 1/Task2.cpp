#include<iostream>
using namespace std;

int main(){
    int numbers[5];
    int total =0;
    cout<<" Enter Numbers: \n";
    for(int i=0; i<5; i++){ //a loop to read a number into the array
        cin>> numbers[i];
    }
    for(int i=0;i<5;i++){ // a loop to add all numbers into the total
      total =total + numbers[i];
    }
    cout<<"the total is ";  // printing the total
    cout<<total;
}