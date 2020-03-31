package uda.cab.models;

public class CabLocation extends Location {

  private String cabId;
  private boolean isAvailable;

  public CabLocation(String cabId, int xCoord, int yCoord, long timeStamp) {
    super(xCoord, yCoord, timeStamp);
    this.cabId = cabId;
  }

  public String getCabId() {
    return cabId;
  }

  public void setCabId(String cabId) {
    this.cabId = cabId;
  }

  public boolean isAvailable() {
    return isAvailable;
  }

  public void setAvailable(boolean available) {
    isAvailable = available;
  }
}
