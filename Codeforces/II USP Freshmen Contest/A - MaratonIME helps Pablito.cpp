#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;

long long int mdc(long long int x, long long int y){return y ? mdc(y, x % y) : x;}

int main() {
    int t;
    cin >> t;
    long long int u[100000], v[100000];
    for(int i = 0; i < t; i++){
        cin >> u[i] >> v[i];
        cout << ( (mdc(u[i], v[i]) == 1) ? "Nao" : "Sim") << endl;
    }
    return 0;
}