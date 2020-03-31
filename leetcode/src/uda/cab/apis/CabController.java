package uda.cab.apis;

import uda.cab.models.Cab;

import java.util.ArrayList;
import java.util.List;

public class CabController {

  private static List<Cab> cabs = new ArrayList<>();

  public boolean create(String vehicleNumber, String driverPhone) {
    DriverController driverController = new DriverController();
    String driverId = driverController.getDriver(driverPhone, null).getUuid();
    Cab cab = new Cab(vehicleNumber, driverId);
    cab.setModelType("I20");
    cabs.add(cab);
    return true;
  }

  public Cab getCab(String cabId) {
    Cab c = null;
    System.out.println("cab contr " + cabs.size());
    for (Cab cab: cabs) {
      System.out.println(cab.getCabId() + " " + cab.getDriverId());
      if (cab.getCabId().equalsIgnoreCase(cabId)) {
        c = cab;
        break;
      }
    }
    return c;
  }

  public Cab getCabFromDriver(String driverId) {
    Cab c = null;
    System.out.println("cab contr " + cabs.size());
    for (Cab cab: cabs) {
      System.out.println("from driver " + cab.getCabId() + " " + cab.getDriverId());
      if (cab.getDriverId().equalsIgnoreCase(driverId)) {
        c = cab;
        break;
      }
    }
    return c;
  }


}
