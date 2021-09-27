#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>

#define M 1e12

using namespace std;

long long int G, resp;
double K;
int main() {
    int T; cin >> T;
    
    for(int t = 0; t < T; t++){
        cin >> G;
        resp = 0;
        
        for(long long int a = max(1.0, ceil((sqrt(1+8*G)-1)/2)); a <= G; a++){
            K = (1+sqrt((2*a+1)*(2*a+1) - 8*G))/2;
            if(K == (long long int) K) {
                resp++;
            }
        }
        
        cout << "Case #" << t+1 << ": " << resp << endl;
    }
}
