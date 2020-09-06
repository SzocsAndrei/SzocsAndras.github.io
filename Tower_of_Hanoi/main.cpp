//Student Project made by Szocs Andras

#include <iostream>
#include <string>
using namespace std;

//Alghoritm for solving using recursion
void solve (int n, const string &A, const string &B ,const string &C){
    if(n>0){
        static int counter {1};
        solve((n-1),A,C,B);
        cout<<counter<<".Move first disk from "<<A<<" to "<<C<<endl;
        counter++;
        solve((n-1),B,A,C);
    }
}

int main()
{
    int n {};
    const string A {"Tower A"};
    const string B {"Tower B"};
    const string C {"Tower C"};
	cout<<"This apllication will display all the moves to solve the tower of Hanoi problem"<<endl
            <<"Please enter the number of disks of the Hanai tower : ";
    cin >> n;
    solve(n,A,B,C);
            
	return 0;
}
