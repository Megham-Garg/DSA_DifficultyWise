#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (pow(10,9)+7)

class Triplet{
public:
    int x,y,gcd;
};

Triplet extended_euclid(int a, int b){
    if(!b){
        Triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
    }
    Triplet smallAns = extended_euclid(b, a%b);
    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = smallAns.x - (a/b)*smallAns.y;
    return Triplet;
}

int GCD(int a, int b){
    if(a<b) return GCD(b,a);
    if(!b) return a;
    return GCD(b, a%b);
}

int main()
{
    cout << gcd(30, 15);
    return 0;
}
// O(log(max(a,b)))
// a%b = a - b*(a/b)
// ax + by = GCD(a,b)
// GCD(a,b) = GCD(b, a%b) for a>b
// therefore bx1 + (a%b)y1 = ax + by
// x = y1
// y = x1 - (a/b)y1