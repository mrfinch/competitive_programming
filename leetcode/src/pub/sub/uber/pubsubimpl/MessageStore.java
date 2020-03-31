package pub.sub.uber.pubsubimpl;

import pub.sub.uber.api.Channel;
import pub.sub.uber.api.Message;
import pub.sub.uber.api.Notify;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class MessageStore {

  private static Map<Channel, List<Message>> channelMessageMap;
  private static Map<Channel, List<Notify>> channelNotifyMap;
  private static Map<Notify, Integer> notifyOffsetMap;

  public MessageStore() {
    channelMessageMap = new ConcurrentHashMap<>();
    channelNotifyMap = new ConcurrentHashMap<>();
    notifyOffsetMap = new ConcurrentHashMap<>();
  }

  public void registerSubscriber(Channel channel, Notify notify) {
    if (channelNotifyMap.containsKey(channel)) {
      channelNotifyMap.get(channel).add(notify);
    } else {
      List<Notify> notifyList = new ArrayList<>();
      notifyList = Collections.synchronizedList(notifyList);

      notifyList.add(notify);
      channelNotifyMap.put(channel, notifyList);
    }
  }

  public void registerSubscriber(Channel channel, Notify notify, Integer offset) {
    if (notifyOffsetMap.containsKey(notify)) {
      notifyOffsetMap.put(notify, offset);
    } else {
      notifyOffsetMap.put(notify, Integer.MAX_VALUE);
    }
    registerSubscriber(channel, notify);
  }

  public void storeMessage(Channel channel, Message message) {
    System.out.println("store " + message.getText());
    if (channelMessageMap.containsKey(channel)) {
      System.out.println("loop 1");
      channelMessageMap.get(channel).add(message);
    } else {
      System.out.println("loop 2");
      List<Message> messageList = new ArrayList<>();
      messageList = Collections.synchronizedList(messageList);

      messageList.add(message);
      channelMessageMap.put(channel, messageList);
    }
    notifyMessage(channel, message);

  }

  private void notifyMessages(Notify notify, Channel channel) {
    List<Message> messageList = channelMessageMap.get(channel);
    int startIndex = notifyOffsetMap.get(notify);

    for (int i = startIndex + 1; i < messageList.size(); i++) {
      if (i < notifyOffsetMap.get(notify)) {
        i = notifyOffsetMap.get(notify);
      }
      notify.run(messageList.get(i));
      notifyOffsetMap.put(notify, i);
    }
    notifyOffsetMap.put(notify, Integer.MAX_VALUE);
  }

  private void updateOffset(Notify notify, Channel c, int offset) {
    notifyOffsetMap.put(notify, offset);
    notifyMessages(notify, c);
  }

  private void notifyMessage(Channel channel, Message message) {
    List<Notify> notifyList = channelNotifyMap.get(channel);
    List<Message> messageList = channelMessageMap.get(channel);
    System.out.println(messageList);
    int channelMessageSize = messageList != null && !messageList.isEmpty() ? messageList.size() : 0;
    for (Notify n: notifyList) {
      System.out.println(notifyOffsetMap + " " + channelMessageSize);
      if (notifyOffsetMap.get(n) != null && notifyOffsetMap.get(n) < channelMessageSize) {
        continue;
      }
      n.run(message);
    }
  }
}
