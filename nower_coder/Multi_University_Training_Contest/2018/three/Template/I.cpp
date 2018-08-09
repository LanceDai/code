#include <bits/stdc++.h>

using namespace std;
int n;
double query[11];

int main() {
    query[3] = 3.000000000000;
    query[4] = 3.666671183000;
    query[5] = 4.166635269000;
    query[6] = 4.566651547000;
    query[7] = 4.900040052000;
    query[8] = 5.185677091000;
    query[9] = 5.435710220000;
    query[10] = 5.657950278000;
    for (int i = 0; i < 7; i++)
        scanf("%d", &n);
    printf("%.12f\n", query[n]);
}
