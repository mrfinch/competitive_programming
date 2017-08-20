require './node'

class Bst

  attr_accessor :head, :parent, :output

  def add_node(value:, current_head: nil)
    if current_head.nil?
      node = Node.new(value: value, parent: parent)
      if @head.nil?
        @head = node
      end
      return node
    end

    parent = current_head

    if value > current_head.value
      current_head.right = add_node(value: value, current_head: current_head.right)
    else
      current_head.left = add_node(value: value, current_head: current_head.left)
    end
    current_head
  end

  def inorder(node: nil, push_to_array: false)
    return if blank_node?(node)

    inorder(node: node.left, push_to_array: push_to_array)
    print_or_push_to_array(push_to_array, node.value)
    inorder(node: node.right, push_to_array: push_to_array)
  end

  def preorder(node: nil, push_to_array: false)
    return if blank_node?(node)

    print_or_push_to_array(push_to_array, node.value)
    preorder(node: node.left, push_to_array: push_to_array)
    preorder(node: node.right, push_to_array: push_to_array)
  end

  def postorder(node: nil, push_to_array: false)
    return if blank_node?(node)

    postorder(node: node.left, push_to_array: push_to_array)
    postorder(node: node.right, push_to_array: push_to_array)
    print_or_push_to_array(push_to_array, node.value)
  end

  def print_or_push_to_array push_to_array, value
    if push_to_array
      @output << value
    else
      puts value
    end
  end

  def blank_node?(node)
    node.nil?
  end

end
