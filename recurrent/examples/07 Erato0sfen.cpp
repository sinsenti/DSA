#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, kol = 0;
    n = 10000000; // cin >> n;
    vector < bool > a(n + 1, true);
    a[0] = a[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (a[i])
            for (int j = i * i; j <= n; j += i)
                a[j] = false;
    for (int i = 0; i <= n; i++)
        if (a[i])
            kol++; // cout << i << " ";
    cout << kol;
    return 0;
}
