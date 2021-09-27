#include <stdio.h>
#include <math.h>

typedef struct pessoa {
    int x;
    int y;
    int r;
} pessoa;

float distancia(pessoa p1, pessoa p2){
    float a;
    a = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    a = sqrt(a);
    return a;
}

int main(){
    int n;
    scanf("%d", &n);
    pessoa pessoas[n];
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &pessoas[i].x, &pessoas[i].y, &pessoas[i].r);
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (distancia(pessoas[i], pessoas[j]) == (pessoas[i].r + pessoas[j].r)){
                printf("%d %d\n", i+1, j+1);
            }
        }
    }
}
