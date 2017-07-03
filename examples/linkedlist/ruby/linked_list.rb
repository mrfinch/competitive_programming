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

end
