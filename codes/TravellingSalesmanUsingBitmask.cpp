#define EMPTY_VALUE -1
#define MAX_N 10
#define INF 1061109567

int w[MAX_N][MAX_N];
int mem[MAX_N][1<<MAX_N];

int turnOn(int x, int pos) {
    return N | (1<<pos);
}

bool isOn(int x ,int pos) {
    return (bool)(x & (1<<pos));
}

int n;
int f(int i, int mask) {
    if (mask == (1<<n) - 1) {
        return w[i][0];
    }
    
    if (mem[i][mask] != -1) {
        return mem[i][mask];
    }
    
    int ans = INF;
    for (int j = 0;j < n;j++) {
        if (w[i][j] == INF) continue;
        
        if (isOn(mask,j) == 0) {
            int result = f(j, turnOn(mask, j)) + w[i][j];
            ans = min(ans, result);
        }
    }
    
    return mem[i][mask] = ans;
}