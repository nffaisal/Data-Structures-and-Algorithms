#include<iostream>
using namespace std;
  
  void print(int arr[], int n){   //printing array function
        int total= 0;
     for(int i =0; i<n;i++){     //displaying all values
        cout<<*(arr + i) << " ";
    }
   cout<<endl;
}
int main(){
    int sales[2][3];
    int(*rowptr)[3] =sales;
    int totalBranch[2] ={0};
    int totalDay[3] ={0};
    cout<<"enter Sales: ";
    
    for(int i=0; i<2; i++){ //read in values  
        for(int k =0; k<3; k++){
         cin>>*(*(rowptr +i)+k);
         
         if(*(*(rowptr + i )+ k) < 0){
            cout<<"Negative number entered.\n";
         }
         totalBranch[i] += *(*(rowptr +i ) +k); //calculating total branch
         totalDay[k] +=*(*(rowptr +i) +k);  //calculating total day
        }
    }

    cout<<"Displayed;\n";
     for(int i=0; i<2; i++){ //display values
        for(int k =0; k<3; k++){
            cout<< *(*(rowptr +i)+k)<<" ";
           
        }
        cout<<endl;
    }
    cout<<"total for each branch: ";   
    print(totalBranch, 2);
        cout<<"total for each day: ";
    print(totalDay, 3);
    
}