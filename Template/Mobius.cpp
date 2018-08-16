void getMobius(){
    //莫比乌斯μ数组
    Mobius[1] = 1;
    for (int i = 1; i < MAXN; ++i)
        for (int j = 2 * i; j < MAXN; j += i) Mobius[j] -= Mobius[i];
}

