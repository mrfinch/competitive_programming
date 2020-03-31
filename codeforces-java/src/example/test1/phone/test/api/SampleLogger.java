package example.test1.phone.test.api;

public interface SampleLogger {

  // identifier can be moved to instance variable too if needed depending on design
  void write(LoggerLevel loggerLevel, String message);

}
