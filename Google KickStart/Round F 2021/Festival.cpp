#include <bits/stdc++.h>

using namespace std;

#define Nmax 500000

int T;
int D, N, K;
int novoN;
int H[Nmax];
vector<int> S[Nmax+1], E[Nmax+1];

long long int HRsegtree[4*Nmax];
int idxsegtree[4*Nmax];

priority_queue<pair< long long int, pair< int, int> >, 
        vector< pair< long long int, pair< int, int> > >, 
        less<pair< long long int, pair< int, int> > > > atracs;

pair< long long int, pair< int, int>> atrac;

long long int currH, maxH;

void updateHRST(int p, int value){
    HRsegtree[p+novoN] = value;
    for(int i = p+novoN; i > 1; i >>= 1)
        HRsegtree[i>>1] = HRsegtree[i] + HRsegtree[i ^ 1];
}

void updateidxST(int p, int value){
    idxsegtree[p+novoN] = value;
    for(int i = p+novoN; i > 1; i >>= 1)
        idxsegtree[i>>1] = idxsegtree[i] + idxsegtree[i ^ 1];
}

long long int queryHRST(int l, int r){
    long long int q = 0;
    for(l += novoN, r += novoN; l < r; l >>= 1, r >>= 1){
        if(l&1) q += HRsegtree[l++];
        if(r&1) q += HRsegtree[--r];
    }
    return q;
}

int queryidxST(){
    int q = K;
    int i = 1;
    if(idxsegtree[i] < K){
        while(true){
            if(i<<1 >= 2*novoN) return i - novoN;

            i = i<<1;
            if(idxsegtree[i | 1] > 0) i |= 1;
        }
    }else{
        while(true){
            if(i<<1 >= 2*novoN) return i - novoN;
            
            i <<= 1;
            if(q > idxsegtree[i]) {
                q -= idxsegtree[i]; 
                i |= 1;
            }
        }
    }
}

int idx;

int main() {
    
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d %d %d", &D, &N, &K);
        novoN = 1 << (int) ceil(log2(N));

        for(int d = 1; d <= D; d++){
            S[d].clear(); E[d].clear();
        }

        for(int i = 0, h, s, e; i < N; i++){
            scanf("%d %d %d", &h, &s, &e);
            atracs.push(make_pair(h, make_pair(s, e)));
        }

        for(int i = 0; i < N; i++){
            atrac = atracs.top(); atracs.pop();
            H[i] = atrac.first;
            S[atrac.second.first].push_back(i);
            E[atrac.second.second+1].push_back(i);
        }
        
        for(int i = 1; i < 2*novoN; i++) idxsegtree[i] = HRsegtree[i] = 0;
        
        maxH = 0; 
        for(int d = 1; d <= D; d++){
            currH = 0;
            //updata as segtrees;
            for(int i : S[d]) {
                updateHRST(i, H[i]);
                updateidxST(i, 1);
            }

            for(int i : E[d]) {
                updateHRST(i, 0);
                updateidxST(i, 0);
            }

            //query na posição da K-esima ativa;
            idx = queryidxST();
            
            //query a soma do intervalo na HRsegtree;
            currH = queryHRST(0, idx) + (idxsegtree[idx+novoN] ? HRsegtree[idx+novoN] : 0);
            
            maxH = max(maxH, currH);   
        }
        printf("Case #%d: %lld\n", t+1, maxH);
    }
    
    return 0;
}