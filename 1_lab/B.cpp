#include <iostream>

using namespace std;


int summator(int count)
{
    long long sum = 0;

    while (count != 0)
    {
        sum += count % 10;
        count /= 10;
    }

    return sum;
}


int main()
{
    int Elems[3];
    cin >> Elems[0] >> Elems[1];
    Elems[2] = summator(Elems[0] + Elems[1]);

    long long sum = 0;

    for (int i = 0; i < 2; ++i)
    {
        sum += summator(Elems[i]);
    }

    if (sum == Elems[2])
    {
        cout << "YES";
    }
    else{
        cout << "NO";
    }


    return 0;
}