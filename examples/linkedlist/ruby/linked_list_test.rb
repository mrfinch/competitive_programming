#!/usr/bin/env ruby

require './linked_list'

linked_list = LinkedList.new
linked_list.add_node(2)
linked_list.add_node(25)

puts linked_list.head.value

# this should be true
puts linked_list.remove_node(2)
# this should be false
puts linked_list.remove_node(40)
# head should be 25
puts linked_list.head.value
