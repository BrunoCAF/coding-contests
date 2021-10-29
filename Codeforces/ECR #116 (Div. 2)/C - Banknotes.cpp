#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000


int T;
int N;
long K;
int denom[10];

long x, v;
int n;

string resp;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %ld", &N, &K);
        for(int i = 0; i < N; scanf("%d", denom+i++));

        resp = "";
        if(N == 1){
            resp = to_string(K+1);
        }else{
            for(int i = 0; (i < N-1) && K; i++){
                //cout << "resp = " << resp << endl;
                v = (long) pow(10, denom[i+1]-denom[i]) - 1;
                x = min(K, v);
                K -= x;
                if(K) resp = to_string(x) + resp;
            }
            if(K == 0 && x == v)
                resp = to_string(1) + to_string(x) + resp;
            else
                resp = to_string(K ? K+1 : ++x) + resp;
        }

        cout << resp << endl;
    }
    
    return 0;
}