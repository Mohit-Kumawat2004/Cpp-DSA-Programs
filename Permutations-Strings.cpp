
#include <bits/stdc++.h>
using namespace std; 

// Print all the permutations
void getResult(string input, int l, int r)
{
   // Base case
   if (l == r)
   {
       cout << input << ", ";
       return;
   }
  
   // All combinations
   for (int i = l; i <= r; i++)
   {
       // Swap
       swap(input[l], input[i]);

       // Recursive call
       getResult(input, l + 1 , r);

       // Swap (backtracking)
       swap(input[l], input[i]);
   }
   
   return;
}

int main()
{
   string input = "code";
   int n = input.length();
 
   cout << "All Permutations:- " << endl;
   getResult(input, 0, n - 1);
   return 0;
}
