void getEuler() {
    //欧拉函数值
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}