package pub.sub.uber;

import pub.sub.uber.api.Channel;
import pub.sub.uber.api.Message;
import pub.sub.uber.api.Notify;
import pub.sub.uber.api.Publisher;
import pub.sub.uber.api.Subscriber;
import pub.sub.uber.impl.NotifyImpl;
import pub.sub.uber.impl.PublisherImpl;
import pub.sub.uber.impl.SubscriberImpl;

public class Solution {


  public static void main(String[] args) {
    Channel channel = new Channel("123", "Ch 123");

    Message message = new Message("msg 1");
    Publisher publisher = new PublisherImpl(channel);

    Subscriber subscriber = new SubscriberImpl(channel);
    Notify notify = new NotifyImpl();
    Subscriber subscriber1 = new SubscriberImpl(channel);
    Subscriber subscriber2 = new SubscriberImpl(channel);
    subscriber.subscribe(notify);
    subscriber1.subscribe(notify);
    subscriber2.subscribe(notify);

    publisher.publish(message);

    Message message1 = new Message("m2");
    Message message2 = new Message("m3");
    Message message3 = new Message("m4");
    publisher.publish(message1);
    publisher.publish(message2);
  }
}
