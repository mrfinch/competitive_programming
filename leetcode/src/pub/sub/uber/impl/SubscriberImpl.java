package pub.sub.uber.impl;

import pub.sub.uber.api.Channel;
import pub.sub.uber.api.Notify;
import pub.sub.uber.api.Subscriber;
import pub.sub.uber.pubsubimpl.MessageStore;

public class SubscriberImpl implements Subscriber {

  private Channel channel;
  private MessageStore messageStore;

  public SubscriberImpl(Channel channel) {
    this.channel = channel;
    this.messageStore = new MessageStore(); // can be singleton
  }

  @Override
  public void subscribe(Notify notify) {
    messageStore.registerSubscriber(this.channel, notify);
  }
}
