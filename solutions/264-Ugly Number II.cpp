class Solution {
public:
	int min(int a, int b, int c, int &p){
    	p = 0;
    	if(a > b) a = b, p = 1;
    	if(a > c) a = c, p = 2;
    	return a;
	}

    int nthUglyNumber(int n) {
    	int *ugly = new int[n+1];
    	ugly[1] = 1;
    	int pos[3];
    	pos[0] = 1, pos[1] = 1, pos[2] = 1;
        for(int i = 2; i <= n; i++){
        	int p;
        	int m = min(ugly[pos[0]] * 2, ugly[pos[1]] * 3, ugly[pos[2]] * 5, p); 
        	pos[p]++;
        	if(m != ugly[i-1]) ugly[i] = m;
        	else i--;
        }
        return ugly[n];
    }
};
