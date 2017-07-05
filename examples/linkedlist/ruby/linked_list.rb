require './node'

class LinkedList

  attr_accessor :head

  def add_node value
    if @head
      new_node = Node.new(value, nil)
      current_node = @head
      last_node = nil

      while current_node
        last_node = current_node
        current_node = current_node.next
      end

      last_node.next = new_node
    else
      new_node = Node.new(value, nil)
      @head = new_node
    end
  end

  def remove_node value
    current_node = @head
    node_to_be_deleted = nil
    prev_node = nil

    while current_node
      if current_node.value == value
        node_to_be_deleted = current_node
        break
      end

      prev_node = current_node
      current_node = current_node.next
    end

    if node_to_be_deleted
      if prev_node.nil?
        @head = node_to_be_deleted.next
      else
        prev_node.next = node_to_be_deleted.next
      end
    else
      false
    end
  end

  def is_present? value
    current_node = @head

    is_present = false
    while current_node
      if current_node.value == value
        is_present = true
        break
      end
      current_node = current_node.next
    end
    is_present
  end

  def reverse!
    current_node = @head
    previous_node = nil

    while current_node
      temp = current_node.next
      current_node.next = previous_node
      previous_node = current_node
      current_node = temp
    end

    @head = previous_node
  end

  def print
    current_node = @head

    while current_node
      puts current_node.value
      current_node = current_node.next
    end
  end

  def insert_in_front value
    if is_present? value
      return false
    end

    new_node = Node.new(value, @head)
    @head = new_node
  end

end
