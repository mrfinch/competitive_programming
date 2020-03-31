package example.test1.phone.test.impl;

import example.test1.phone.test.api.LogSink;

import java.util.Properties;

public class LogSinkFactory {

  public static LogSink getLogSink(String sinkName, Properties properties) {
    if ("CONSOLE".equalsIgnoreCase(sinkName)) {
      return new ConsoleLogSinkImpl();
    } else if ("FILE".equalsIgnoreCase(sinkName)) {
      return new FileLogSinkImpl(properties.getProperty("fileLocation"));
    } else {
      return null;
    }
  }
}
