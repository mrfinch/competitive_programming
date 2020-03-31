package uda.cab.models;

public class Driver extends User {

  private String licenseNumber;
  private String address;
  private String cabId;

  public Driver(String phoneNumber, String licenseNumber, String address) {
    super(phoneNumber);
    this.licenseNumber = licenseNumber;
    this.address = address;
  }

  public String getLicenseNumber() {
    return licenseNumber;
  }

  public void setLicenseNumber(String licenseNumber) {
    this.licenseNumber = licenseNumber;
  }

  public String getAddress() {
    return address;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public String getCabId() {
    return cabId;
  }

  public void setCabId(String cabId) {
    this.cabId = cabId;
  }
}
