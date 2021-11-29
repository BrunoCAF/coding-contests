#include<bits/stdc++.h>
using namespace std;

#define Nmax 200000

int t;
int N;

long long T;

typedef pair<int, int> pll;

int X[Nmax+1];
vector<pll> A;

bool compA(pll a, pll b){return a.first > b.first;}

int main(){
    scanf("%d", &t);
    for(; t--; T = 0, A.clear()){
        scanf("%d", &N);
        
        for(int n = 0, a; n < N; n++) {
            scanf("%d", &a); A.push_back({a,n});
        }
        sort(A.begin(), A.end(), compA);
        //for(int i = 0; i < N; i++) printf("(%d, %d) ", A[i].first, A[i].second); cout << endl;
        for(int i = 0, j = 1; i < N; i++, j = (j > 0) ? -j : 1-j){
            X[A[i].second] = j;
            T += 2 * abs(j) * ((long long) A[i].first);
        }
        //for(int i = 0; i < N; i++) printf("(%d, %d) ", X[i].first, X[i].second); cout << endl;
        
        printf("%lld\n0 ", T);
        for(int i = 0; i < N; i++) printf("%d%c", X[i], (i != N-1) ? ' ' : '\n');
    }
    
    return 0;
}