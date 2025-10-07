#include <iostream>
#include <vector>
using namespace std;

long long fact(int x){ /// __int128
    if (x == 0)
        return 1;
    return fact(x - 1) * x;
}

int main()
{
    int n;
    cin >> n;
    vector < long long > a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * i;
    cout << a[n] << endl;
    cout << fact(n) << endl;
    return 0;
}
