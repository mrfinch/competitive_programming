package uda.cab.models;

import uda.cab.helpers.RandomIdGenerator;

public class UserCabBooking {

  private String bookingId;
  private String userId;
  private String cabId;
  private String driverId;
  private Long startTime;
  private Long endTime;
  private BookingStatus bookingStatus;
  private boolean isCancelled;


  public UserCabBooking(String userId, String cabId, String driverId, Long startTime, Long endTime, BookingStatus bookingStatus) {
    this.userId = userId;
    this.cabId = cabId;
    this.driverId = driverId;
    this.startTime = startTime;
    this.endTime = endTime;
    this.bookingStatus = bookingStatus;
    this.bookingId = RandomIdGenerator.getId("booking");
  }

  public String getUserId() {
    return userId;
  }

  public void setUserId(String userId) {
    this.userId = userId;
  }

  public String getCabId() {
    return cabId;
  }

  public void setCabId(String cabId) {
    this.cabId = cabId;
  }

  public String getDriverId() {
    return driverId;
  }

  public void setDriverId(String driverId) {
    this.driverId = driverId;
  }

  public Long getStartTime() {
    return startTime;
  }

  public void setStartTime(Long startTime) {
    this.startTime = startTime;
  }

  public Long getEndTime() {
    return endTime;
  }

  public void setEndTime(Long endTime) {
    this.endTime = endTime;
  }

  public BookingStatus getBookingStatus() {
    return bookingStatus;
  }

  public void setBookingStatus(BookingStatus bookingStatus) {
    this.bookingStatus = bookingStatus;
  }

  public String getBookingId() {
    return bookingId;
  }

  public boolean isCancelled() {
    return isCancelled;
  }

  public void setCancelled(boolean cancelled) {
    isCancelled = cancelled;
  }
}
