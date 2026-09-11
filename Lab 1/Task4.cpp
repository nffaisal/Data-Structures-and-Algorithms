#include<iostream>
using namespace std;

int main(){
    int numbers[8];
    cout<<"Enter Numbers: \n";
    for(int i=0; i <8; i++){
        cin>> numbers[i];
    }
    int smallest = numbers[0];
    int largest = numbers[0];
    int largestIndex = 0;
    int smallestIndex = 0;
    for(int i=0; i<8;i++){
        if(smallest>numbers[i]){
            smallest =numbers[i];
            smallestIndex =i; //this will be the first occurence
        }
        if(largest< numbers[i]){
            largest =numbers[i]; 
            largestIndex =i; //first occurence index
        }
    }
    cout<<"smallest Number is: "<< smallest<< endl;
    cout<<"first occurence at index: "<<smallestIndex<<endl;
    cout<<"Largest Number is: "<< largest<<endl;
    cout<<"first occurence at index: "<<largestIndex<<endl;
}