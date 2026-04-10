#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int power10(int a) {
  int res = 1;
  while(a--) {
    res *= 10;
  }
  return res;
}

int digits(int x) {
  int cnt = 0;
  while(x > 0) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

int64 Karatsuba(int64 a, int64 b) {

  if(a < 10 || b < 10) return a * b;

  int n = max(digits(a), digits(b));
  int m = n/2;

  int64 divisor = power10(m);

  int64 high1 = a / divisor;
  int64 low1 = a % divisor;
  int64 high2 = b / divisor;
  int64 low2 = b % divisor;

  int64 z0 = Karatsuba(low1, low2);
  int64 z2 = Karatsuba(high1, high2);
  int64 z1 = Karatsuba(low1 + high1, low2 + high2) - z2 - z0;

  return z2 * power10(2*m) + z1 * divisor + z0;
}


int main() {

  int64 a = 1234;
  int64 b = 5678;

  cout << "The Multiplication : " << Karatsuba(a,b) << endl;

  return 0;
}
