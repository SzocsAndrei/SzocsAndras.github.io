//Study project made by Szocs.
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort( int A [], int n);
int main()
{
    int A [] {1,2,3,4,5,6,7,8,9,10,};
    int n = (sizeof(A)/sizeof(A[0]));
    
    cout<<"Initial Array : "<<endl;
     for(auto nr : A){
     cout<<nr<<" ";}
     cout<<endl;
     
   random_shuffle(begin(A), end(A));
   
   cout<<"Shuffled Array : "<<endl;
   for(auto nr : A){
     cout<<nr<<" ";}
     cout<<endl;
     
    cout<<"Sorted Array : "<<endl;
   bubble_sort(A,n);
   for(auto nr : A){
       cout<<nr<<" ";}
   cout<<endl;
	return 0;
}

void bubble_sort(int A [], int n){
    int flag {}; int buff {}; 
    for(int i = 0; i < n-1 ; i++){
        flag = 0;
        for(int j = 0; j < n-i-1; j++){
        if(A[j] > A[j+1]){
             buff = A[j];
             A[j] = A[j+1];
             A[j+1] = buff;
             flag = 1;
           }
        }
         //if(flag == 0) return;
    }
}
  