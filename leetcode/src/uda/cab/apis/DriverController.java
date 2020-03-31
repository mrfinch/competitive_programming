package uda.cab.apis;

import uda.cab.models.Driver;

import java.util.ArrayList;
import java.util.List;

public class DriverController {

  private static List<Driver> drivers = new ArrayList<>();

  public boolean create(DriverCreateRequest driverCreateRequest) {
    // validations

    Driver driver = new Driver(
      driverCreateRequest.getPhoneNumber(),
      driverCreateRequest.getLicense(),
      driverCreateRequest.getAddress()
    );

    driver.setEmail(driverCreateRequest.getEmail());
    driver.setName(driverCreateRequest.getName());

    drivers.add(driver);

    return true;
  }

  public Driver getDriver(String phoneNumber, String uuid) {
    Driver d = null;
    for (Driver dr: drivers) {
      if (dr.getPhoneNumber().equalsIgnoreCase(phoneNumber)) {
        d = dr;
        break;
      } else if (dr.getUuid().equalsIgnoreCase(uuid)) {
        d = dr;
        break;
      }
    }
    return d;
  }
}
