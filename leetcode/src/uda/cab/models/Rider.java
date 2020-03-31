package uda.cab.models;

public class Rider extends User {

  private int credits;

  public Rider(String phoneNumber) {
    super(phoneNumber);
  }

  public int getCredits() {
    return credits;
  }

  public void setCredits(int credits) {
    this.credits = credits;
  }
}
