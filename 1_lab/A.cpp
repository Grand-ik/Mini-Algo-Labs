#include <iostream>

using namespace std;


bool checker = true;



void printer(int count, char variable)
{
    char sign = '+';

    if (!checker)
    {
        switch (count)
        {
            case 0: {break;}
            case 1:
            {
                cout << sign << variable;
                checker = false;
                break;  
            }
            case (-1):
            {
                cout << "-" << variable;
                checker = false;
                break;
            }
            default:
            {
                if (count > 0)
                {
                    cout << sign << count << variable;
                }
                else
                {
                    cout << count << variable;
                }
                checker = false;
                break;
            }
        }
    }
    else
    {
        switch (count)
        {
            case 0: {break;}
            case 1:
            {
                cout << variable;
                checker = false;
                break;  
            }
            case (-1):
            {
                cout << "-" << variable;
                checker = false;
                break;
            }
            default:
            {
                if (count > 0)
                {
                    cout << count << variable;
                }
                else
                {
                    cout << count << variable;
                }
                checker = false;
                break;
            }
        }
    }
}


int main()
{
    int values[3];
    cin >> values[2] >> values[0] >> values[1];

    char var_names[2] = {'x', 'y'};


    if (values[2] != 0)
    {
        cout << values[2];
        checker = false;
    }
    


    for (int i = 0; i < 2; ++i)
    {
        printer(values[i], var_names[i]);
    }

    if (checker)
    {
        cout << 0;
    }


    return 0;
}