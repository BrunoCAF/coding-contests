class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int r, l;
        int f = 0, t = 0;
        for(r = 0, l = 0; l < answerKey.size(); l++){
            if(answerKey[l] == 'F') f++;
            
            if(f > k)
                if(answerKey[r++] == 'F') 
                    f--;
            
            
            //cout << answerKey << endl;
            //for(int j = 0; j < answerKey.size(); j++)
            //    printf("%c", (j == r || j == l) ? ((r==l) ? 'j' : ((j==r) ? 'r' : 'l')) : ' ');
            //printf("\nf = %d %c %d = k\n\n", f, (f < k) ? '<' : ((f == k) ? '=' : '>'), k);
        }
        int contT = l-r;
        
        for(r = 0, l = 0; l < answerKey.size(); l++){
            if(answerKey[l] == 'T') t++;
            
            if(t > k)
                if(answerKey[r++] == 'T') 
                    t--;
            
            
            //cout << answerKey << endl;
            //for(int j = 0; j < answerKey.size(); j++)
            //    printf("%c", (j == r || j == l) ? ((r==l) ? 'j' : ((j==r) ? 'r' : 'l')) : ' ');
            //printf("\nt = %d %c %d = k\n\n", t, (t < k) ? '<' : ((t == k) ? '=' : '>'), k);
        }
        int contF = l-r;
        
        return max(contT, contF);
        
    }
};