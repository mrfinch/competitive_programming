package uda.cab.models;

import uda.cab.helpers.RandomIdGenerator;

public class User {

  private String uuid;
  private String email;
  private String phoneNumber;
  private String name;

  public User(String phoneNumber) {
    this.phoneNumber = phoneNumber;
    this.uuid = RandomIdGenerator.getId("user");
  }

  public void setUuid(String uuid) {
    this.uuid = uuid;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public void setPhoneNumber(String phoneNumber) {
    this.phoneNumber = phoneNumber;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getUuid() {
    return uuid;
  }

  public String getEmail() {
    return email;
  }

  public String getPhoneNumber() {
    return phoneNumber;
  }

  public String getName() {
    return name;
  }
}
