struct Matrix {
    LL num[3][3]{};

    Matrix() { memset(num, 0, sizeof(num)); }

    Matrix operator*(const Matrix &P) const {
        Matrix ans;
        for (int k = 0; k < 3; k++)
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    ans.num[i][j] = (ans.num[i][j] + num[i][k] * P.num[k][j] % mod) % mod;
        return ans;
    }
};


Matrix matrix_quick_pow(Matrix X, LL m) {
    Matrix ans;
    for (ans = unit; m; m >>= 1, X = X * X)
        if (m & 1)
            ans = ans * X;
    return ans;
}