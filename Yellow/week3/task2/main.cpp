#include <iostream>
#include <phone_number.h>

int main()
{
    PhoneNumber number("+868687574");
    cout << number.GetInternationalNumber() << endl;
    cout << number.GetCountryCode() << endl;
    cout << number.GetCityCode()<< endl;
    cout << number.GetLocalNumber()<< endl;
    return 0;
}
