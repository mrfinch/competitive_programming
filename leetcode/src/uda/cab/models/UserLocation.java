package uda.cab.models;

public class UserLocation extends Location {

  private String userId;

  public UserLocation(String userId, int xCoord, int yCoord, long timeStamp) {
    super(xCoord, yCoord, timeStamp);
    this.userId = userId;
  }

  public String getUserId() {
    return userId;
  }
}
