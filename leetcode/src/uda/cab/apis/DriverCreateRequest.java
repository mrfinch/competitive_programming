package uda.cab.apis;

import com.sun.istack.internal.NotNull;

public class DriverCreateRequest {

  @NotNull
  private String license;

  @NotNull
  private String address;

  @NotNull
  private String phoneNumber;

  private String email;
  private String name;

  public DriverCreateRequest(String license, String address, String phoneNumber, String email, String name) {
    this.license = license;
    this.address = address;
    this.phoneNumber = phoneNumber;
    this.email = email;
    this.name = name;
  }

  public String getLicense() {
    return license;
  }

  public String getAddress() {
    return address;
  }

  public String getPhoneNumber() {
    return phoneNumber;
  }

  public String getEmail() {
    return email;
  }

  public String getName() {
    return name;
  }
}
