package uda.cab.helpers;

import java.util.Random;

public class RandomIdGenerator {

  private static Random random = null;

  public static String getId(String identifier) {
    if (random == null) {
      random = new Random();
    }

    return identifier + random.nextInt(10000);
  }
}
