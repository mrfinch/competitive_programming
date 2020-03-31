package uda.cab.models;

public class Location {

  private int xCoord;
  private int yCoord;
  private long timeStamp;

  public Location(int xCoord, int yCoord, long timeStamp) {
    this.xCoord = xCoord;
    this.yCoord = yCoord;
    this.timeStamp = timeStamp;
  }

  public int getxCoord() {
    return xCoord;
  }

  public void setxCoord(int xCoord) {
    this.xCoord = xCoord;
  }

  public int getyCoord() {
    return yCoord;
  }

  public void setyCoord(int yCoord) {
    this.yCoord = yCoord;
  }

  public long getTimeStamp() {
    return timeStamp;
  }

  public void setTimeStamp(long timeStamp) {
    this.timeStamp = timeStamp;
  }
}
