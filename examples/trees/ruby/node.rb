class Node

  attr_accessor :left, :right, :parent, :value

  def initialize(value: , left: nil, right: nil, parent: nil)
    @value = value
    @left = left
    @right = right
    @parent = parent
  end

end
