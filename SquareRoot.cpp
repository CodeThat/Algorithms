#include <iostream>
#include <math.h>

using namespace std;

int Q_floor(float number){
    int number2 = (int)(number * 10.0f);
    int deci = number2 % 10;
    float deci2 = deci/10.0f;
    int num3 = (int)(number - deci2);
    return num3;
}

float Q_rsqrt( float number )
{
        long i;
        float x2, y;
        const float threehalfs = 1.5F;
 
        x2 = number * 0.5F;
        y  = number;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // wtf?
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
 
        return y;
}

void compute_sqrt(int n) {
    cout << Q_floor(n * Q_rsqrt(n));
}
