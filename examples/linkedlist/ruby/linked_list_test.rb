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

puts linked_list.is_present?(25)
puts linked_list.is_present?(2)

linked_list.print

linked_list.add_node(10)
linked_list.add_node(12)
puts 'linkedin content'
linked_list.print

# reverse
linked_list.reverse!
puts 'reverse'
linked_list.print

puts 'add in front'
linked_list.insert_in_front 4
linked_list.print

