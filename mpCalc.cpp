#include <iostream>

using namespace std;

int gauss(int n)
{
    int result = n * (n + 1) / 2;
    return result;
}

int main()
{

    int functionId;
    cout << "Choose function: \n 1) Calculator(WIP) \n 2) Gauss sum \n 3) Factorial \n 4) Exponentiation \n 5) ------(WIP)" << endl;
    cin >> functionId;

    if (functionId == 1)
    {
        // calc();
    }
    else if (functionId == 2)
    {
        system("CLS");
        int n;
        cout << " Gauss sum is the sum of all positive integers up to a number n. \n Please choose the number n:" << endl;
        cin >> n;
        cout << "Result is " << gauss(n) << endl;

        string restartCommand;
        cout << "Type 'r' to restart" << endl;
        cin >> restartCommand;

        if (restartCommand == "r")
        {
            system("CLS");
            main();
        }
    }
    else if (functionId == 3)
    {
        system("CLS");
        int n;
        int result = 1;
        cout << "The factorial of a positive integer n is the product of all the positive integers less than or equal to n. \n Please choose the number n:" << endl;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            result = result * i;
        }

        cout << "Result is " << result << endl;
        string restartCommand;
        cout << "Type 'r' to restart" << endl;
        cin >> restartCommand;

        if (restartCommand == "r")
        {
            system("CLS");
            main();
        }
    }
    else if (functionId == 4)
    {
        system("CLS");

        double base;
        int exponent; // make double
        double result = 1;

        cout << "Please choose the base number:" << endl;
        cin >> base;
        cout << "Please choose the exponent:" << endl;
        cin >> exponent;

        for (double i = 1; i <= exponent; i++)
        {
            result = result * base;
        }

        cout << "Result is " << result << endl;
        string restartCommand;
        cout << "Type 'r' to restart" << endl;
        cin >> restartCommand;

        if (restartCommand == "r")
        {
            system("CLS");
            main();
        }
    }
    else if (functionId == 5)
    {
        // root();
    }
    else
    {
        system("CLS");
        main();
    }
}
