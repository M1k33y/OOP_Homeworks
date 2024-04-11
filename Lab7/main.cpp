#include <iostream>
float operator"" _Kelvin(long double Celsius)
{
    return static_cast<float>(Celsius - 273.15);
}
float operator"" _Fahrenheit(long double Celsius)
{
    return static_cast<float>((Celsius - 32) / 1.8);
}

using namespace std;
int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    cout << a << " " << b;
    return 0;
}