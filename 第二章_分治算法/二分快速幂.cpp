//第二章_二分快速幂

#include<bits/stdc++.h>
using namespace std;

//二分快速幂
inline long long binaryPower(const long long& numm, long long pow) {

    if(pow==0) return 1;
    else if(pow==1) return numm;

    long long pow_2 = binaryPower(numm, pow>>1);    //递归求 a^(b/2)
    if(pow%2) { //若是奇次幂
        return pow_2*pow_2*numm;
    } else {
        return pow_2*pow_2;
    }

}

int main() {

    srand(time(0));

    //二分快速幂
    for(int i=0; i<5; i++) {
        long long a=rand()%4+1, b=rand()%32;
        cout << "<二分快速幂>\t " << a << "^" << b << "  \t = \t";
        cout << binaryPower(a, b) << '\n';
    }


    return 0;
}
