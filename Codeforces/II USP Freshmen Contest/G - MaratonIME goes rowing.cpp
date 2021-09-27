#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>

#define MAX 100010

using namespace std;

char str[MAX];

bool abrindo(char c) {
    return (c == 'A');
}

char fechando(char c) {
    switch (c) {
        case 'A':
            return 'B';
    }
    return '\0';
}

int main() {
    bool ok;
    gets(str);
    ok = true;
    stack<char> s;

    for (int i = 0; str[i] != '\0' && ok; i++) {
        if (abrindo(str[i])) {
            s.push(str[i]);
        } else {
            if (s.empty() || fechando(s.top()) != str[i]) {
                ok = false;
            } else {
                s.pop();
            }
        }
    }
    if (!s.empty()) ok = false;
    puts(ok ? "Sim" : "Nao");
    return 0;
}
