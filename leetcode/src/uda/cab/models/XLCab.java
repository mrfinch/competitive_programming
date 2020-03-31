package uda.cab.models;

public class XLCab extends Cab {

  private CabType cabType;

  public XLCab(String vehicleNumber, String driverId) {
    super(vehicleNumber, driverId);
  }

  public CabType getCabType() {
    return cabType;
  }

  public void setCabType(CabType cabType) {
    this.cabType = cabType;
  }
}
