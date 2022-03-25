#include <iostream>
using namespace std;
class Average
{
public:
    float Average;
    int num1, num2, num3;

    float CalculateAverage()
    {
        Average = (num1 + num2 + num3) / 3;
        return Average;
    }
};
class Derived : public Average
{

public:
    void GetNumbers()
    {
        cout << "Enter three numbers : ";
        cin >> num1 >> num2 >> num3;
    }
    float CalculateAverage();
    void Display()
    {
        cout << "The average of the given numbers is : " << Average << endl;
    }
};
int main()
{
    Derived Obj1;
    Obj1.GetNumbers();
    Obj1.Display();

    return 0;
}