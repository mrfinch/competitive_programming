package example.test1.phone.test.impl;

import example.test1.phone.test.api.LogSink;

public class ConsoleLogSinkImpl implements LogSink {
  @Override
  public void write(String message) {
    System.out.println(message);
  }
}
