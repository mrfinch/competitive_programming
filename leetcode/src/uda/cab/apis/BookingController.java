package uda.cab.apis;

import uda.cab.models.BookingStatus;
import uda.cab.models.Cab;
import uda.cab.models.CabLocation;
import uda.cab.models.Driver;
import uda.cab.models.UserCabBooking;
import uda.cab.models.UserLocation;
import uda.cab.models.Rider;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BookingController {

  private static Map<String, List<UserCabBooking>> userBookings = new HashMap<>();

  public static int MAX_ALLOWED_DISTANCE = 10;

  public String bookCab(String phoneNumber) {
    Rider rider = getRider(phoneNumber);
    Cab cab = getAvailableCab(rider);

    System.out.println("r " + rider + " c " + cab);
    if (rider == null || cab == null) {
      System.out.println("Can't book ride");
      return "";
    }

    UserCabBooking userCabBooking = new UserCabBooking(
        rider.getUuid(),
        cab.getCabId(),
        cab.getDriverId(),
        System.currentTimeMillis(),
        null,
        BookingStatus.BOOKED
    );

    if (userBookings.containsKey(rider.getUuid())) {
      userBookings.get(rider.getUuid()).add(userCabBooking);
    } else {
      List<UserCabBooking> userCabBookings = new ArrayList<UserCabBooking>() {{ add(userCabBooking); }};
      userBookings.put(rider.getUuid(), userCabBookings);
    }

    System.out.println("BOOKED " + userCabBooking.getBookingId());
    return userCabBooking.getBookingId();
  }

  public void endTrip(String bookingId, String phoneNumber) {
    RiderController riderController = new RiderController();
    Rider r = riderController.getRider(phoneNumber);

    List<UserCabBooking> userCabBookings = userBookings.get(r.getUuid());

    for (UserCabBooking u: userCabBookings) {
      if (u.getBookingId().equalsIgnoreCase(bookingId)) {
        u.setBookingStatus(BookingStatus.ENDED);
        LocationController locationController = new LocationController();
        DriverController driverController = new DriverController();
        Driver driver = driverController.getDriver(null, u.getDriverId());
        System.out.println("end driver " + driver.getUuid() + " cab " + driver.getCabId());
        locationController.updateAvailibility(driver.getPhoneNumber(), true);

        break;
      }
    }

  }

  public List<UserCabBooking> getAllBookings(String phoneNumber) {
    return userBookings.get(phoneNumber);
  }

  private Cab getAvailableCab(Rider r) {
    if (r == null) {
      System.out.println("No rider");
      return null;
    }

    LocationController locationController = new LocationController();
    List<CabLocation> cabs = locationController.getAvailableCabsLocation();
    UserLocation userLocation = locationController.getRiderLastLocation(r.getUuid());

    String cabId = getCabWithinDistance(cabs, userLocation);
    if (cabId == null) {
      System.out.println("No cab available");
      return null;
    }

    System.out.println("cabId " + cabId);
    CabController cabController = new CabController();
    return cabController.getCab(cabId);
  }

  private Rider getRider(String phone) {
    RiderController riderController = new RiderController();
    return riderController.getRider(phone);
  }

  private String getCabWithinDistance(List<CabLocation> cabLocations, UserLocation userLocation) {
    String cabId = null;

    for (CabLocation cabLocation: cabLocations) {
      if (isWithInDistance(cabLocation, userLocation)) {
        cabId = cabLocation.getCabId();
        break;
      }
    }
    return cabId;
  }

  private boolean isWithInDistance(CabLocation cabLocation, UserLocation userLocation) {
    double distance = Math.pow((cabLocation.getxCoord() - userLocation.getxCoord()), 2) +
        Math.pow((cabLocation.getyCoord() - userLocation.getyCoord()), 2);

    return distance < MAX_ALLOWED_DISTANCE;
  }

}
