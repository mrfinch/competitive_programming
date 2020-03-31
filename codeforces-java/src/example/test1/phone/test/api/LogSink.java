package example.test1.phone.test.api;

public interface LogSink {

  // cant have third party ppl create sink then since we tie level to sync at initialize time, could pass sink as parameter if we want to allow this
  void write(String message);

}
