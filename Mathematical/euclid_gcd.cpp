#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (pow(10,9)+7)
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
