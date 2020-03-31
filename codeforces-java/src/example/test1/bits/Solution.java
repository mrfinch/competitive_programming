package example.test1.bits;

public class Solution {

  public static int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
      if ((n & 1) == 1) {
        count++;
      }
      n >>= 1;
    }

    return count;
  }

  public static int countSetBits2(int n) {
    int count = 0;
    while (n > 0) {
      n = n & (n - 1);
      count++;
    }
    return count;
  }

  // swap ith and jth bit
  public static int swapBits(int n, int i, int j) {
    int ith = (n >> i) & 1;
    int jth = (n >> j) & 1;

    if (ith != jth) {
      int xorNum = (1 << i) | (1 << j);
      n = n ^ xorNum;
    }
    return n;
  }

  public static void main(String[] args) {
    System.out.println("count set bits");
    System.out.println(countSetBits(3));
    System.out.println(countSetBits(8));
    System.out.println(countSetBits(5));
    System.out.println(countSetBits(21));
    System.out.println(countSetBits(79));
    System.out.println("count set bits2");
    System.out.println(countSetBits2(3));
    System.out.println(countSetBits2(8));
    System.out.println(countSetBits2(5));
    System.out.println(countSetBits2(21));
    System.out.println(countSetBits2(79));


    System.out.println("swap bits");
    System.out.println(swapBits(18, 1, 0));
    System.out.println(swapBits(18, 2, 1));
    System.out.println(swapBits(18, 3, 2));

  }


}
