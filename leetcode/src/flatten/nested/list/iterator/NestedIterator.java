package flatten.nested.list.iterator;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;


public class NestedIterator implements Iterator<Integer> {

  List<Integer> resp = new ArrayList<>();
  int index = 0;

  public NestedIterator(List<NestedInteger> nestedList) {
    flattenList(nestedList);
  }

  private void flattenList(List<NestedInteger> nestedIntegers) {
    for (NestedInteger n: nestedIntegers) {
      if (n.isInteger()) {
        resp.add(n.getInteger());
      } else {
        flattenList(n.getList());
      }
    }
  }

  @Override
  public Integer next() {
    return resp.get(index++);
  }

  @Override
  public boolean hasNext() {
    return index < resp.size();
  }
}
