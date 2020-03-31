package pub.sub.uber.impl;

import pub.sub.uber.api.Channel;
import pub.sub.uber.api.Message;
import pub.sub.uber.api.Publisher;
import pub.sub.uber.pubsubimpl.MessageStore;

public class PublisherImpl implements Publisher {

  private Channel channel;
  private MessageStore messageStore;

  public PublisherImpl(Channel channel) {
    this.channel = channel;
    this.messageStore = new MessageStore();
  }

  @Override
  public boolean publish(Message message) {
    messageStore.storeMessage(this.channel, message);
    return false;  // TODO impl
  }
}
