#include<iostream>
using namespace std;

void reverse(int array[], int start, int end){

    //end case
    if(start>=end){ return;}
    //using a temporary variable we move towards the middle
    int temp =array[start];
    array[start] =array[end];
    array[end] =temp;

    //now we use recursion
    reverse(array, start+1, end -1);
};


int main(){
    int numbers[6];
    for(int i=0; i<6;i++){  //first we take all the entries
        cin>> numbers[i];
    }
   reverse(numbers, 0, 5);
   cout<<"Reversed Array: ";
    for(int i=0; i<6; i++){
        cout<< numbers[i]<<" ";
    }
}