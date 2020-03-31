package example.test1.phone.test;

import example.test1.phone.test.api.LoggerLevel;
import example.test1.phone.test.api.SampleLogger;
import example.test1.phone.test.impl.SampleLoggerImpl;

import java.io.IOException;

/**
 * // TODO Comment
 */
public class Solution {
  public static void main(String[] args) {
    SampleLogger sampleLogger;

    {
      try {
        
        sampleLogger = new SampleLoggerImpl("/home/saurabh/personal/competitive_programming/codeforces-java/src/example/test1/phone/test/impl/logger.properties");
        sampleLogger.write(LoggerLevel.INFO, "hello");
        sampleLogger.write(LoggerLevel.WARN, "hello2");
        sampleLogger.write(LoggerLevel.ERROR, "hello3");

      } catch (IOException e) {
        e.printStackTrace();  // TODO impl
      }


    }

  }


}
