#include <iostream>
using namespace std;
#include <string>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int b ;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n ; i++) {
        
        b=b*10+arr[i]%10;   

    }
      cout <<"value of b is " << b << endl;
    return 0;
}



/*

Output : 

value of b is 12345


=== Code Execution Successful ===

*/


/*
Another Method : 
    int array[]={1,2,3,4,5};
    string a;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n ; i++) {
       a += to_string(arr[i]);
    }
    cout <<"value of a is "<<a<<endl;

*/



