package example.test1.phone.test.impl;

import example.test1.phone.test.api.LogSink;
import example.test1.phone.test.api.LoggerLevel;
import example.test1.phone.test.api.SampleLogger;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.InvalidPropertiesFormatException;
import java.util.Properties;

public class SampleLoggerImpl implements SampleLogger {

  private String namespace;
  private String timeFormat;
  private LogLevelSinkFactory logLevelSinkFactory;

  public SampleLoggerImpl(String filePath) throws IOException {
    FileReader fileReader = new FileReader(filePath);
    Properties p = new Properties();
    p.load(fileReader);

    namespace = p.getProperty("namespace");
    timeFormat = p.getProperty("timeFormat");

    // throw error if any of above field is absent from config
    if (namespace == null) {
      throw new InvalidPropertiesFormatException("Namespace is null");
    }

    // also need to check for valid formats, maybe we can have set of formats allowed
    if (timeFormat == null) {
      throw new InvalidPropertiesFormatException("Timeformat is not valid");
    }
    
    logLevelSinkFactory = new LogLevelSinkFactory(p);
    for (LoggerLevel loggerLevel: LoggerLevel.values()) {
      logLevelSinkFactory.register(loggerLevel, p.getProperty(loggerLevel.toString()));

      if (logLevelSinkFactory.get(loggerLevel) == null) {
        throw new InvalidPropertiesFormatException("Invalid sink for level: " + loggerLevel);
      }
    }
    
  }

  @Override
  public void write(LoggerLevel loggerLevel, String message) {
    LogSink logSink = logLevelSinkFactory.get(loggerLevel);

    String finalMessage = getTimeAccordingToFormat() + " " + namespace + " [" +
        loggerLevel.toString() +
        "] " +
        message;
    logSink.write(finalMessage);
  }

  private String getTimeAccordingToFormat() {
    DateFormat dateFormat = new SimpleDateFormat(timeFormat);
    return dateFormat.format(new Date());
  }
}
