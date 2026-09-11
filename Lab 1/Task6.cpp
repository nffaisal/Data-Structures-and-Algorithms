#include<iostream>
using namespace std;

int main(){
     int numbers[10];
    int count =0;

    // Read 10 integers
    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    } 

    for(int i =0; i<10; i++){
        bool unique =true;  // asssume it is unique
        for (int k=0; k < count; k++){   //if number is repeated then we break out of loop and it is not unique
            if(numbers[i] == numbers[k]){
                unique =false;
                break;
        }
    }
         if(unique){ //however if number not repeated we add it to the count position as a unique number
        numbers[count] = numbers[i];
        count++;
       }
       
    }
    for (int i = 0; i < count; i++) { //loop through the new array
        cout << numbers[i]<< " ";
    }
    cout << "\nCount: " << count << endl;
   
    }
