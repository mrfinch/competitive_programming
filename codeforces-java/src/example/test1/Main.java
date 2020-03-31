package example.test1;

import java.util.ArrayList;

/**
 * // TODO Comment
 */
public class Main {

  public static void main(String[] args) {
    Employee employee = new Employee(1, "sp");
    Company company = new Company(new ArrayList<Employee>() {{add(employee);}});

    System.out.println(company.getEmployeeList().size());
    
  }
}
