#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// version 0.6

void restart();

void printLogo()
{
    string line = "";
    ifstream infile;
    // infile.open("mpcalc-ascii-speed.txt"); //alternative logo
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
    cout << "\tWIP" << endl;
    double result;
}

void gauss()
{
    cout << "\tGauss sum is the sum of all positive integers up to a number n. \n\tPlease choose the number n:" << endl;
    int n;
    cin >> n;
    double result = n * (n + 1) / 2;
    cout << "\tResult is " << result << endl;
}

void factorial()
{
    int n;
    int result = 1;
    cout << "\tThe factorial of a positive integer n is the product of all the positive integers less than or equal to n."
         << "\n\n\tPlease choose the number n : " << endl;
    cin >>
        n;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    cout << "\tResult is " << result << endl;
}

void expo()
{
    double base;
    int exponent; // make double
    double result = 1;

    cout << "\tPlease choose the base number:";
    cin >> base;
    cout << "\tPlease choose the exponent:";
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
    cout << "\tResult is " << result << endl;
}

void root()
{
    cout << "\tWIP" << endl;
    double result;
}

// area functions start

void areaTrig()
{
    // only for calculating the area of a triangle
    // TODO implement radians
    cout << "\n\tIn order to calculate the area of a triangle, you must type in 3 distinct values."
            "\n\n\t 1) 3 edges\n\t 2) 2 edges - 1 angle\n\t 3) 1 side - 2 angles\n\n\tChoose: ";
    int functionId;
    cin >> functionId;

startOver:
    system("CLS");

    switch (functionId)
    {

    case 1:
    {
        // 3 edges

        cout << "\tEnter the values." << endl;
        cout << "\n\tLength of the first edge: ";
        double edge1;
        cin >> edge1;

        cout << "\tLength of the second edge: ";
        double edge2;
        cin >> edge2;

        cout << "\tLength of the third edge: ";
        double edge3;
        cin >> edge3;

        double s = (edge1 + edge2 + edge3) / 2;

        double area = sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)); // using s formula

        cout << "\n\tThe area of the triangle: " << area << endl;
    }
    break;
    case 2:
    {
        // 2edges-1angle

        cout << "\tEnter the values." << endl;
        cout << "\n\tLength of the first edge: ";
        double edge1;
        cin >> edge1;

        cout << "\tLength of the second edge: ";
        double edge2;
        cin >> edge2;

        cout << "\tThe angle between the two edges(in degrees): ";
    invalidAngle:
        double angleDeg;
        cin >> angleDeg;

        double angleRad = angleDeg * 3.141592 / 180;

        if (angleDeg > 0 && angleDeg < 180)
        {
            double area = (edge1 * edge2 * sin(angleRad) / 2); // sin area formula
            cout << "\n\tThe area of the triangle: " << area << endl;
        }
        else
        {
            system("CLS");
            cout << "\t" << angleDeg << " degrees, huh? Are you sure about that?" // TODO after a certain amount of times, redirect to https://en.wikipedia.org/wiki/Triangle
                 << "\n\n\tThe angle between the two edges(in degrees): ";
            goto invalidAngle;
        }
    }
    break;
    case 3:
    {
        // 1side-2angle

        cout << "\tEnter the values." << endl;
    invalidAngle1:
        cout << "\n\tThe first angle(in degrees): ";
        double angleDeg1;
        cin >> angleDeg1;

        double angleRad1 = angleDeg1 * 3.141592 / 180;

        if (angleDeg1 > 0 && angleDeg1 < 180)
        {
            cout << "\tThe second angle(in degrees): ";
            double angleDeg2;
            cin >> angleDeg2;
            double angleRad2 = angleDeg2 * 3.141592 / 180;
            double angleSum = angleDeg1 + angleDeg2;

            if (angleSum > 0 && angleSum < 180)
            {
                cout << "\tLength of the edge between those two angles: ";
                double edge1;
                cin >> edge1;

                // case3 area calculations

                double angleDeg3 = 180 - angleSum;
                double angleRad3 = angleDeg3 * 3.141592 / 180;
                double edge2 = (sin(angleRad1) * edge1) / sin(angleRad3); // law of sines
                double area = (edge1 * edge2 * sin(angleRad2)) / 2;       // sin area formula

                cout << "\n\tThe area of the triangle: " << area << endl;
            }
            else
            {
                system("CLS");
                cout << "\tAre you sure about those angles? Because they add up to " << angleSum << " degrees.\n"
                     << endl;
                goto invalidAngle1;
            }
        }
        else
        {
            system("CLS");
            cout << "\t" << angleDeg1 << " degrees, huh? Are you sure about that?" << endl;
            goto invalidAngle1;
        }
    }

    break;
    }

    cout << "\n\tType [M] to go back to menu or [S] to start over: ";
    string restartInput;
    cin >> restartInput;
    if (restartInput == "m" || restartInput == "M")
    {
        system("CLS");
    }
    else if (restartInput == "s" || restartInput == "S")
    {
        goto startOver;
    }
}

// area functions end

void area()
{
    cout << "\n\tCalculate the area of a polygon with n edges.\n\n\tChoose n: ";
    int polygonEdgeCount;
    cin >> polygonEdgeCount;

    if (polygonEdgeCount < 3)
    {
        cout << "\n\tI'm afraid a polygon with less than 3 edges is not possible." << endl;
    }

    switch (polygonEdgeCount)
    {
    case 3:
        system("CLS");
        printLogo();
        areaTrig();
        break;
    }
}

int main()
{
    printLogo();

    cout << "\tChoose function: \n\n\t1) [reserved for Calculator] \n\t2) Gauss sum "
         << "\n\t3) Factorial \n\t4) Exponentiation \n\t5) [reserved for nth Root]"
         << "\n\t6) Area (Only for triangles)" << endl;
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
    case 6:
        area();
        restart();
        break;
    default:
        restart();
        break;
    }
}

void restart()
{
    cout << "\n\tType [M] to go back to menu: " << endl; // todo press [ESC] for menu
    string restartInput;
    cin >> restartInput;

    if (restartInput == "m" || restartInput == "M") // todo restart the function on "c"
    {
        system("CLS"); // apparently this only works in windows or so I've been told
        main();
    }
}
