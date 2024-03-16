#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// version 0.6

void restart();

void printLogo()
{
    string line = "";
    ifstream infile;
    // infile.open("mpcalc-ascii-speed.txt");
    infile.open("mpcalc-ascii-alligator2.txt");
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            cout << line << endl;
        }
    }
}

void calculator()
{
    cout << "       WIP" << endl;
    double result;
}

void gauss()
{
    cout << " Gauss sum is the sum of all positive integers up to a number n. \nPlease choose the number n:" << endl;
    int n;
    cin >> n;
    double result = n * (n + 1) / 2;
    cout << "Result is " << result << endl;
}

void factorial()
{
    int n;
    int result = 1;
    cout << "       The factorial of a positive integer n is the product of all the positive integers less than or equal to n."
         << " \n Please choose the number n : " << endl;
    cin >>
        n;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    cout << "Result is " << result << endl;
}

void expo()
{
    double base;
    int exponent; // make double
    double result = 1;

    cout << "       Please choose the base number:" << endl;
    cin >> base;
    cout << "       Please choose the exponent:" << endl;
    cin >> exponent;

    if (base == 0)
    {
        result = 0;
    }
    else
    {
        for (double i = 1; i <= exponent; i++)
        {
            result = result * base;
        }
    }
    cout << "Result is " << result << endl;
}

void root()
{
    cout << "       WIP" << endl;
    double result;
}
int main()
{
    printLogo();

    cout << "       Choose function: \n\n       1) Calculator(WIP) \n       2) Gauss sum "
         << "\n       3) Factorial \n       4) Exponentiation \n       5) nth Root(WIP)" << endl;
    int functionId;
    cin >> functionId;

    system("CLS");
    printLogo();

    switch (functionId)
    {
    case 1:
        calculator();
        restart();
        break;
    case 2:
        gauss();
        restart();
        break;
    case 3:
        factorial();
        restart();
        break;
    case 4:
        expo();
        restart();
        break;
    case 5:
        root();
        restart();
        break;
    default:
        restart();
        break;
    }
}

void restart()
{
    cout << "Type 'c' to clear or 'm' to go to menu" << endl;
    string restartInput;
    cin >> restartInput;

    if (restartInput == "r")
    {
        system("CLS");
        main();
    }
    else if (restartInput == "m")
    {
        system("CLS");
        main();
    }
}
