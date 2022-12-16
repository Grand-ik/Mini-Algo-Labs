/*
    Дано натуральное число n (n<10000). Верно ли что
    это число содержит три одинаковые цифры?
    (например, 6766, 4555, 888).
*/

#include <iostream>

using namespace std;


int amount_c(int count)
{
    int iter_f, iter_s;
    iter_f = iter_s = 0;
    int first, second;
    first = second = -1;

    int m;
    while (count > 0)
    {
        m = count % 10;

        if (first)

        count /= 10;
    }

    return iter;
}


int main()
{
    int n;
    cin >> n;

    if (n < 111)
    {
        cout << "No ;)";
        return 0;
    }

    (amount_c(n) == 3) ? cout << "Yes :)" : cout << "No ;(";


    return 0;
}