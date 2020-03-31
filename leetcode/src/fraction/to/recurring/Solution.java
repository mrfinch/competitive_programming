package fraction.to.recurring;

import java.util.HashSet;
import java.util.Set;

public class Solution {

  public String fractionToDecimal(int numerator, int denominator) {
    if (denominator < 0) {
      if (numerator > 0) {
        denominator = Math.abs(denominator);
        numerator = -1 * numerator;
      } else {
        // TODO fix for Integer.MIN_VALUE
        numerator = Math.abs(numerator);
        denominator = Math.abs(denominator);
      }
    }
    int res = numerator / denominator;
    int rem = numerator % denominator;

    if (rem == 0) {
      return String.valueOf(res);
    }

    String out = (res == 0 && numerator < 0 ? "-" : "") + String.valueOf(res) + ".";

    Set<Integer> vis = new HashSet<>();
    boolean recur = false;
    String r = "";

    rem = Math.abs(rem);
    rem *= 10;
    String temp = "";
    while (rem < denominator) {
      temp += "0";
      rem *= 10;
    }
    while (rem != 0) {
      if (!vis.add(rem)) {
        String rep = String.valueOf(rem / denominator);
        int index = r.indexOf(rep);
        r = r.substring(0, index) + "(" + r.substring(index) + ")";
        recur = true;
        break;
      }
      if (rem < denominator) {
        r += "0";
        rem *= 10;
      } else {

        r += (rem / denominator);
        rem = rem % denominator;
        rem *= 10;
      }
    }

    //if (recur) {
    //  r = "(" + r + ")";
    //}

    return out + temp + r;
  }
  
}
