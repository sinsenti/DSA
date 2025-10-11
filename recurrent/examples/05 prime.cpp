#include <iostream>
using namespace std;

int main()
{
    int n, kol = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0){
            kol++;
            break;
        }
    if (n > 1 && kol == 0)
        cout << "YES";
    else
        cout << "NO";

    /*
    for (int i = 1; i <= n; i++)
        if (n % i == 0){
            kol++;
            if (kol > 2)
                break;
        }
    if (kol == 2)
        cout << "YES";
    else
        cout << "NO";
    */
    return 0;
}
