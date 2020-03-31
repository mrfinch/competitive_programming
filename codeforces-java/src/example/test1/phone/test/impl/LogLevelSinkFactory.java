package example.test1.phone.test.impl;

import example.test1.phone.test.api.LogSink;
import example.test1.phone.test.api.LoggerLevel;

import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class LogLevelSinkFactory {

  private Map<LoggerLevel, String> levelLogSinkMap = new HashMap<>();
  private Properties properties;

  public LogLevelSinkFactory(Properties properties) {
    this.properties = properties;
  }

  public void register(LoggerLevel loggerLevel, String logSink) {
    levelLogSinkMap.put(loggerLevel, logSink);
  }

  public LogSink get(LoggerLevel loggerLevel) {
    return LogSinkFactory.getLogSink(levelLogSinkMap.get(loggerLevel), properties);
  }

}
