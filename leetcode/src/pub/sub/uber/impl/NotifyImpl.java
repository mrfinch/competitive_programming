package pub.sub.uber.impl;

import pub.sub.uber.api.Message;
import pub.sub.uber.api.Notify;

public class NotifyImpl implements Notify {
  @Override
  public void run(Message message) {
    new Thread(new Runnable() {
      @Override
      public void run() {
        System.out.println("Received: " + message.getText());
      }
    }).start();
  }
}
