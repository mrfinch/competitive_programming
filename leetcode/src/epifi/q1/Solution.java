package epifi.q1;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Solution {

  public static List<Integer> circuitsOutput(List<String> circuitsExpression) {
    // Write your code here
    List<Integer> res = new ArrayList<>();
    for (String s: circuitsExpression) {
      if (s.length() <= 1) {
        res.add(1);
        continue;
      }

      Deque<Character> stack = new LinkedList<>();
      stack.addLast(s.charAt(1));

      int i = 2;
      while (!stack.isEmpty() && i < s.length()) {
        Character c = s.charAt(i);
        if (canIgnore(c)) {
          i++;
          continue;
        }

        if (isNumber(c)) {
          Character last = stack.getLast();
          if (last == '!') {
            Character temp = c == '0' ? '1' : '0';
            stack.removeLast();
            stack.addLast(temp);
          } else {
            if (isNumber(last)) {
              Character temp1 = stack.removeLast();

              Character out = evaluate(c, last, temp1);
              stack.addLast(out);
              //if (isNumber(temp1) && stack.size() > 0) {
              //  Character temp2 = stack.removeLast();
              //  Character out = evaluate(last, temp1, temp2);
              //  stack.addLast(out);
              //} else {
              //  stack.addLast(temp1);
              //  stack.addLast(c);
              //}
            } else {
              stack.addLast(c);
            }
          }
        } else {
          stack.addLast(c);
        }

        System.out.println("put " + stack.getLast() + " sz " + stack.size());


        i++;
      }

      for (int j =0; i< stack.size(); i++){
        System.out.println("outttt " + stack.getLast());

      }
      if (stack.size() == 1) {
        Integer x = stack.removeLast() == '1' ? 1 : 0;
        res.add(x);
      }

      if (stack.size() == 2) {
        Character num = stack.getLast();
        Integer x = (num == '0' ? 1 : 0);
        res.add(x);
      }

      if (stack.size() == 3) {
        Character n1 = stack.getLast();
        Character n2 = stack.getLast();
        Character r = evaluate(n1, n2, stack.getLast());
        Integer x = (r == '0' ? 1 : 0);
        res.add(x);
      }
         
      System.out.println("here " + res.size());
    }

    return res;
  }

  private static boolean canIgnore(Character c) {
    return c == '[' || c == ']' || c == ' ';
  }

  private static boolean isNumber(Character c) {
    return c == '1' || c == '0';
  }

  private static Character evaluate(Character a, Character b, Character operator) {
    boolean a1 = (a == '1');
    boolean a2 = (b == '1');

    if (operator == '&') {
      return (a1 & a2) ? '0' : '1';
    } else {
      return (a1 & a2) ? '0' : '1';
    }
  }

}
