#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
string fixedfloat(float x, int p)
{
    ostringstream strout ;
    strout << fixed << setprecision(p) << x ;
    string str = strout.str() ;
    size_t end = str.find_last_not_of( '0' ) + 1 ;
    str.erase( end ) ;
    if (str.back() == '.'){
        str.pop_back();
    }
    return str;
}

int main(){
    int tests_amount, i;
    double temp0_celsius, temp0_fahrenheit, temp1_fahrenheit, sum_fahrenheit, sum_celsius;
    queue<double> sums;
    
    scanf("%d", &tests_amount);
    for (i = 0; i < tests_amount; i++){
        scanf("%lf %lf", &temp0_celsius, &temp1_fahrenheit);
        temp0_fahrenheit = 9.0/5 * temp0_celsius + 32;
        sum_fahrenheit = temp0_fahrenheit + temp1_fahrenheit;
        sum_celsius = 5.0/9*(sum_fahrenheit - 32);
        sums.push(sum_celsius);
    }

    double output;
    for (i = 0; i < tests_amount; i++){
        cout << fixedfloat(sums.front(), 2) << endl;
        sums.pop();
    }
}