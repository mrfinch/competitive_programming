import java.util.Scanner;

/**
 * // TODO Comment
 */
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    int[] a = new int[n];

    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    int sum = 0;

    for (int j:a) {
      sum += j;
    }

    int currentSum = 0;
    int halfSum = (int) Math.ceil(sum / 2.0);
    int out = 0;
    for (int j:a) {
      out++;
      currentSum += j;
      if(currentSum >= halfSum) {
        break;
      }
    }

    System.out.println(out);
  }

}
