package uda.cab.apis;

import com.sun.istack.internal.NotNull;

public class RiderCreateRequest {

  @NotNull
  private String phoneNumber;

  private String email;
  private String name;
  private int credits;

  public RiderCreateRequest(String phoneNumber, String email, String name, int credits) {
    this.phoneNumber = phoneNumber;
    this.email = email;
    this.name = name;
    this.credits = credits;
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

  public int getCredits() {
    return credits;
  }
}
