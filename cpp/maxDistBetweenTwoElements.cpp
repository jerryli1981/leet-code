// max difference of two elements in the array
// s.t. larger element appears after the smallest
// element in the array

#include <iostream>
using namespace std;

int maxDiff(int arr[],int size) {
   int i;
   int max_diff = arr[1]-arr[0];
   int min_element = arr[0];
   for (i=1;i<size;i++) {
      if (arr[i] > min_element) {
         // diff of current and min element
         int diff = arr[i]-min_element;
         if (diff > max_diff) {
            // update max diff
            max_diff = diff;
         }
      }
      else {
         // update the min element in the array
         min_element = arr[i];
      }
   }
   return max_diff;
}

// main
int main() {
   int arr[] = { 1,4,-2,6,-1,2,7,3,19,-6,11,1 };
   int size = sizeof(arr)/sizeof(arr[0]);
   int max_diff = maxDiff(arr,size);
   cout<<"\nMax difference :: "<<max_diff;
   cout<<endl;
   return 0;
}