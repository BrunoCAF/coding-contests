#include <bits/stdc++.h>

using namespace std;

#define Nmax 500000

int T;
int N;
string S;

int bins[Nmax];
int nbins;

long long int dist;

int main() {
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        cin >> S;
        dist = 0;
        
        nbins = 0;
        for(int i = 0; i < N; i++) 
            if(S[i] == '1') 
                bins[nbins++] = i;
                
        for(int i = 0; i < bins[0]; i++)
            dist += bins[0] - i;
        
        for(int j = 1; j < nbins; j++)
            for(int i = bins[j-1]; i < bins[j]; i++)
                dist += min(i - bins[j-1], bins[j] - i);
        
        for(int i = bins[nbins-1]; i < N; i++)
            dist += i - bins[nbins-1];
        
        cout << "Case #" << t+1 << ": " << dist << endl;
    }
    
    return 0;
}