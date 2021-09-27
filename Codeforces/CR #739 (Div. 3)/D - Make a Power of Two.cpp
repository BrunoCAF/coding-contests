#include <bits/stdc++.h>

using namespace std;

int t, m;
long int n;
int x;

int dist(long int n, long long int k){
    stringstream ss, sss;
    ss << n;
    string ns = ss.str();
    sss << k;
    string ks = sss.str();
    int dist = 0;
    int i, j;
    for(i = 0, j = 0; i < ns.length() && j < ks.length(); i++){
        if(ns[i] != ks[j]) dist++;
        else j++;
    }
    dist += (ks.length() - j) + (ns.length() - i);
    //cout << ks << ": " << dist << endl;
    return dist;
}

int main() {
    cin >> t;

    for(int j = 0; j < t; j++){
        cin >> n;
        x = 3 * (int) log2(n);
        // m <= #n_10 + 1 apaga tudo e bota 1,2,4 ou 8
        m = dist(n, (long long int) 1 << x);
        for(int k = 0; ((long long int ) 1 << k) > 0; k++)
            m = min(m, dist(n, (long long int) 1 << k));


        cout << m << endl;
    }
    
    

    return 0;
}