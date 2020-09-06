//Study prokject made by Szocs Andras
#include <iostream>
#include <string>
using namespace std;

void permutations(string perm, int k);

int main()
{   string permstring {"ABC"};
    int k {0};
    cout<<"Enter a string of up to 20 characters :"<<endl;
    getline(cin,permstring);
    cout<<"=============================="<<endl;

    permutations(permstring,k);
	return 0;
}

void permutations(string perm, int k){
    static char *res = new char [perm.size()];
    static int A [20] {0};
    if(!perm[k]){
        res[k] = '\0';
        cout<<res<<endl;
    }else{
    for(int i {0}; i < perm.size(); i++){
        if(A[i] == 0){
            res[k] = perm[i];
            A[i] = 1;
            permutations(perm, k+1);
            A[i] = 0;
        }
       }
    }
    delete [] res;
}