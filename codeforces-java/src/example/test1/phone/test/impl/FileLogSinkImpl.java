package example.test1.phone.test.impl;

import example.test1.phone.test.api.LogSink;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class FileLogSinkImpl implements LogSink {
  private BufferedWriter bufferedWriter;
  private String threadModel;
  private String writeMode;


  public FileLogSinkImpl(String filePath) {
    try {
      bufferedWriter = new BufferedWriter(new FileWriter(filePath, true));
    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }
  }


  @Override
  public void write(String message) {
    try {

      bufferedWriter.append("\n").append(message);
      bufferedWriter.close();
    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }
  }
}