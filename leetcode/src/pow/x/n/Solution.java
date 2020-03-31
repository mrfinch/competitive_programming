package pow.x.n;

public class Solution {

  public double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }

    if (n < 0) {
      int n1;

      if (n == Integer.MIN_VALUE) {
        if (x > 1) {
          return 0;
        }
        n1 = Integer.MIN_VALUE / 2;
        double t =  myPow(x, n1);
        return 1.0 / (t * t);
      } else {
        n1 = Math.abs(n);
        return 1.0 / myPow(x, n1);
      }
    }

    if (n % 2 == 1) {
      return x * myPow(x, n - 1);
    } else {
      double t = myPow(x, n / 2);
      return t * t;
    }
  }
  
}
