package uda.cab;

import uda.cab.apis.BookingController;
import uda.cab.apis.CabController;
import uda.cab.apis.DriverController;
import uda.cab.apis.DriverCreateRequest;
import uda.cab.apis.LocationController;
import uda.cab.apis.RiderController;
import uda.cab.apis.RiderCreateRequest;

public class Solution {


  public static void main(String[] args) {
    RiderController riderController = new RiderController();
    DriverController driverController = new DriverController();
    LocationController locationController = new LocationController();
    BookingController bookingController = new BookingController();
    CabController cabController = new CabController();

    String riderPhone =  "ph123";
    String driverPhone = "ph234";
    riderController.create(
        new RiderCreateRequest(riderPhone, "s@gm.com", "Saurabh", 100)
    );
    driverController.create(
        new DriverCreateRequest(
          "lic123",
          "add234",
          driverPhone,
          "sa@ga.co",
          "SP"
        )
    );
    cabController.create("veh123", driverPhone);
    locationController.updateCabLocation(
        driverPhone,
        2,
        2
    );
    locationController.updateUserLocation(
        riderPhone,
        1,
        1
    );
    locationController.updateAvailibility(driverPhone, true);
    //locationController.updateAvailibility(driverPhone, false);

    //System.out.println(bookingController.bookCab(riderPhone));

    locationController.updateUserLocation(riderPhone, 100, 100);
    //String bookingID = bookingController.bookCab(riderPhone);
    //System.out.println("bid " + bookingID);
    //bookingController.endTrip(bookingID, riderPhone);
    System.out.println(bookingController.bookCab(riderPhone));


  }
}
