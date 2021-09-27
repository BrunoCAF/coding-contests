#include <stdio.h>

int main ()
{

char N[100000];
int iA,iB,iC,iD,iE,iF,iG;

iA=0; iB=0; iC=0; iD=0; iE=0; iF=0; iG=0;

scanf("%s",N);

int i;

for (i=0;N[i]!='\0';i++)
{
    if (i == 0) {
        if (N[i] == 'A') {iA = iA + 1;}
        if (N[i] == 'B') {iB = iB + 1;}
        if (N[i] == 'C') {iC = iC + 1;}
        if (N[i] == 'D') {iD = iD + 1;}
        if (N[i] == 'E') {iE = iE + 1;}
        if (N[i] == 'F') {iF = iF + 1;}
        if (N[i] == 'G') {iG = iG + 1;}
    }
    else {
        if (N[i] == N[i-1]){
            if (N[i] == 'A') {iA = iA + 1;}
            if (N[i] == 'B') {iB = iB + 1;}
            if (N[i] == 'C') {iC = iC + 1;}
            if (N[i] == 'D') {iD = iD + 1;}
            if (N[i] == 'E') {iE = iE + 1;}
            if (N[i] == 'F') {iF = iF + 1;}
            if (N[i] == 'G') {iG = iG + 1;}
        }
        else {
            if (N[i-1] == 'A') {printf("A%d", iA);iA = 0;}
            if (N[i-1] == 'B')  {printf("B%d", iB);iB = 0;}
            if (N[i-1] == 'C')  {printf("C%d", iC);iC = 0;}
            if (N[i-1] == 'D')  {printf("D%d", iD);iD = 0;}
            if (N[i-1] == 'E')  {printf("E%d", iE);iE = 0;}
            if (N[i-1] == 'F')  {printf("F%d", iF);iF = 0;}
            if (N[i-1] == 'G')  {printf("G%d", iG);iG = 0;}
            if (N[i] == 'A') {iA = iA + 1;}
            if (N[i] == 'B') {iB = iB + 1;}
            if (N[i] == 'C') {iC = iC + 1;}
            if (N[i] == 'D') {iD = iD + 1;}
            if (N[i] == 'E') {iE = iE + 1;}
            if (N[i] == 'F') {iF = iF + 1;}
            if (N[i] == 'G') {iG = iG + 1;}
        }
    }
}
if (N[i-1] == 'A') {printf("A%d", iA);}
if (N[i-1] == 'B')  {printf("B%d", iB);}
if (N[i-1] == 'C')  {printf("C%d", iC);}
if (N[i-1] == 'D')  {printf("D%d", iD);}
if (N[i-1] == 'E')  {printf("E%d", iE);}
if (N[i-1] == 'F')  {printf("F%d", iF);}
if (N[i-1] == 'G')  {printf("G%d", iG);}

return 0;
}
