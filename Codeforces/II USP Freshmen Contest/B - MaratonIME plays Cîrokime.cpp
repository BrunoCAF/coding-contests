#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>

#define MEX 100000

using namespace std;

int main(){
    long int n;
    cin >> n;
    long long int e[MEX];
    for(long int i = 0; i < n; i++){
        cin >> e[i];
    }
    cout << (int)(log2l(n)) + 1 << endl;
    
    return 0;
}
