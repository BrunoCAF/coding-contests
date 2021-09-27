#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>

#define M 1000000007
#define Nmax 100000

using namespace std;


long long int resp;
char S[Nmax];
bool limit;

int main() {
    int T, N, K; cin >> T;
    
    for(int t = 0; t < T; t++){
        cin >> N >> K;
        cin >> S;
        
        resp = 0;
        limit = false;
        for(int i = 0; i < N; i++){
            if(i < (N+1)/2){
                resp = resp + (((S[i] - 'a') % M) * ((long long int) pow(K, ((N-1)/2 - i))) % M) % M;
            }else if (i >= (N+1)/2){
                if(S[i] > S[N-1-i]) {limit = true; break;}
                if(S[i] < S[N-1-i]) break;
            }
        }
        
        if(limit == true) resp++;
        
        cout << "Case #" << t+1 << ": " << resp % M << endl;
    }
}
