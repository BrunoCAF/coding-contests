#include<bits/stdc++.h>
using namespace std;

#define Nmax 10000


int T;
string S;
int N, D, M;
long long int C;
bool ans, stop;
int i;

int main(){
    scanf("%d", &T);
    for(int t = 1;t <= T; t++){
        scanf("%d %d %lld %d", &N, &D, &C, &M);
        cin >> S;
        ans = true; stop = false;
        for(i = 0; i < S.length(); i++){
            if(S[i] == 'C'){
                if(C-- <= 0) {
                    stop = true;
                    break;
                }
            }else{
                C += M;
                if(D-- <= 0){
                    ans = false;
                    break;
                }
            }   
        }
        if(ans && stop){
            for(; i < S.length(); i++){
                if(S[i] == 'D') {ans = false; break;}
            }
        }
        
        printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
    }
    
    return 0;
}