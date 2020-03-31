package uda.cab.apis;

import uda.cab.models.CabLocation;
import uda.cab.models.Driver;
import uda.cab.models.UserLocation;
import uda.cab.models.Rider;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LocationController {

  private static Map<String, List<UserLocation>> userLocationMap = new HashMap<>();
  private static Map<String, List<CabLocation>> cabLocationMap = new HashMap<>();

  public boolean updateUserLocation(String phoneNumber, int x, int y) {
    RiderController riderController = new RiderController();
    Rider rider = riderController.getRider(phoneNumber);

    UserLocation userLocation = new UserLocation(rider.getUuid(), x, y, System.currentTimeMillis());
    if (userLocationMap.containsKey(rider.getUuid())) {
      userLocationMap.get(rider.getUuid()).add(userLocation);
    } else {
      userLocationMap.put(rider.getUuid(), new ArrayList<UserLocation>() {{add(userLocation);}});
    }

    return true;
  }


  public boolean updateCabLocation(String phoneNumber, int x, int y) {
    DriverController driverController = new DriverController();
    Driver driver = driverController.getDriver(phoneNumber, null);
    CabController cabController = new CabController();
    String cabId = cabController.getCabFromDriver(driver.getUuid()).getCabId();

    CabLocation cabLocation = new CabLocation(cabId, x, y, System.currentTimeMillis());
    if (cabLocationMap.containsKey(driver.getUuid())) {
      cabLocationMap.get(driver.getUuid()).add(cabLocation);
    } else {
      cabLocationMap.put(driver.getUuid(), new ArrayList<CabLocation>() {{add(cabLocation);}});
    }

    return true;
  }

  public boolean updateAvailibility(String phoneNumber, boolean isAvailable) {
    DriverController driverController = new DriverController();
    Driver driver = driverController.getDriver(phoneNumber, null);

    if (cabLocationMap.containsKey(driver.getUuid())) {
      List<CabLocation> cabLocations = cabLocationMap.get(driver.getUuid());
      CabLocation last = cabLocations.get(cabLocations.size() - 1);
      if (last == null) { // shouldn't happen ideally
        last = new CabLocation(driver.getUuid(), -1, -1, System.currentTimeMillis());
        last.setAvailable(isAvailable);
        cabLocations.add(last);
      } else {
        last.setAvailable(isAvailable);
      }
    }

    return true;
  }

  public List<CabLocation> getAvailableCabsLocation() {
    List<CabLocation> availableCabsLocation = new ArrayList<>();
    for (Map.Entry<String, List<CabLocation>> entry: cabLocationMap.entrySet()) {
      CabLocation lastLocation = entry.getValue().get(entry.getValue().size() - 1);

      if (lastLocation.isAvailable()) {
        availableCabsLocation.add(lastLocation);
      }
    }
    return availableCabsLocation;
  }

  public UserLocation getRiderLastLocation(String id) {
    List<UserLocation> userLocations = userLocationMap.get(id);

    return userLocations.get(userLocations.size() - 1);
  }

}
