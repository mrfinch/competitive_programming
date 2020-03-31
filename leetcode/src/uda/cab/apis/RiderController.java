package uda.cab.apis;

import uda.cab.models.Rider;

import java.util.ArrayList;
import java.util.List;

public class RiderController {

  private static List<Rider> riders = new ArrayList<>();

  public boolean create(RiderCreateRequest riderCreateRequest) {
    // validations

    Rider rider = new Rider(riderCreateRequest.getPhoneNumber());
    rider.setCredits(riderCreateRequest.getCredits());
    rider.setEmail(riderCreateRequest.getEmail());
    rider.setName(riderCreateRequest.getName());

    riders.add(rider);

    return true;
  }

  public Rider getRider(String phone) {
    Rider rider = null;
    for (Rider r: riders) {
      if (r.getPhoneNumber().equalsIgnoreCase(phone)) {
        rider = r;
        break;
      }
    }
    return rider;
  }

}
