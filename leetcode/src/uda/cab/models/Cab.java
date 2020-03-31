package uda.cab.models;

import uda.cab.helpers.RandomIdGenerator;

public class Cab {

  private String vehicleNumber;
  private String modelType; // can be enum too like I20, DZIRE
  private String color;
  private String cabId; // uuid
  private String driverId;

  public Cab(String vehicleNumber, String driverId) {
    this.vehicleNumber = vehicleNumber;
    this.driverId = driverId;
    this.cabId = RandomIdGenerator.getId("cab");
  }

  public String getVehicleNumber() {
    return vehicleNumber;
  }

  public void setVehicleNumber(String vehicleNumber) {
    this.vehicleNumber = vehicleNumber;
  }

  public String getModelType() {
    return modelType;
  }

  public void setModelType(String modelType) {
    this.modelType = modelType;
  }

  public String getColor() {
    return color;
  }

  public void setColor(String color) {
    this.color = color;
  }

  public String getCabId() {
    return cabId;
  }

  public String getDriverId() {
    return driverId;
  }
}
