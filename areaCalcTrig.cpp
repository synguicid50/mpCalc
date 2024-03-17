#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// only for calculating the area of a triangle
string startMessage = "\n\tIn order to calculate the area of a triangle, you must type in 3 distinct values."
                      "\n\n\t 1) 3 edges\n\t 2) 2 edges - 1 angle\n\t 3) 1 side - 2 angles\n\n\tChoose: ";

int main()
{
    cout << startMessage;
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

        double area = sqrt(s * (s - edge1) * (s - edge2) * (s - edge3));

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

        cout << "\tThe angle between the two edges(in degrees): "; // implement radians
    invalidAngle:
        double angleDeg;
        cin >> angleDeg;

        double angleRad = angleDeg * 3.141592 / 180;

        if (angleDeg > 0 && angleDeg < 180)
        {
            double area = (edge1 * edge2 * sin(angleRad) / 2);
            cout << "\n\tThe area of the triangle: " << area << endl;
        }
        else
        {
            system("CLS");
            cout << "\t" << angleDeg << " degrees, huh? Are you sure about that?" // after a certain amount of times, redirect to https://en.wikipedia.org/wiki/Triangle
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
        cout << "\n\tThe first angle(in degrees): "; // implement radians
        double angleDeg1;
        cin >> angleDeg1;

        double angleRad1 = angleDeg1 * 3.141592 / 180;

        if (angleDeg1 > 0 && angleDeg1 < 180)
        {
            cout << "\tThe second angle(in degrees): "; // implement radians
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
        main();
    }
    else if (restartInput == "s" || restartInput == "S")
    {
        goto startOver;
    }
}