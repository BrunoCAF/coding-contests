#include<bits/stdc++.h>
using namespace std;

#define Kmax 100000

int T;
int N, L, R, K;
int A[100];

int amount;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d %d", &N, &L, &R, &K);
        for(int n = N; n--;) scanf("%d", &A[N-n-1]);
        
        sort(A, A+N);
        amount = 0;

        //for(int i = 0; i < N; i++) cout << A[i] << " "; cout << endl;

        for(int i = 0; i < N; i++){
            if(K < A[i]) break;
            if(L <= A[i] && A[i] <= R){
                K -= A[i]; amount++;
            }
        }

        printf("%d\n", amount);
    }
    
    return 0;
}