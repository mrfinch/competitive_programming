#!/usr/bin/env ruby
require "minitest/autorun"
require './bst'
require 'pry'
# run using `ruby bst_test.rb`

class BstTest < Minitest::Test

  def setup
    @binary_tree = Bst.new
  end

  def test_node_is_added
    @binary_tree.add_node(value: 10)
    @binary_tree.add_node(value: 20, current_head: @binary_tree.head)

    assert_equal @binary_tree.head.value, 10
  end

  def test_inorder_traversal_is_correct
    @binary_tree.add_node(value: 15)
    @binary_tree.add_node(value: 20, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 25, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 10, current_head: @binary_tree.head)

    @binary_tree.output = []
    @binary_tree.inorder(node: @binary_tree.head, push_to_array: true)

    assert_equal [10, 15, 20, 25], @binary_tree.output
  end

  def test_preorder_traversal_is_correct
    @binary_tree.add_node(value: 15)
    @binary_tree.add_node(value: 20, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 25, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 10, current_head: @binary_tree.head)

    @binary_tree.output = []
    @binary_tree.preorder(node: @binary_tree.head, push_to_array: true)

    assert_equal [15, 10, 20, 25], @binary_tree.output
  end

  def test_postorder_traversal_is_correct
    @binary_tree.add_node(value: 15)
    @binary_tree.add_node(value: 20, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 25, current_head: @binary_tree.head)
    @binary_tree.add_node(value: 10, current_head: @binary_tree.head)

    @binary_tree.output = []
    @binary_tree.postorder(node: @binary_tree.head, push_to_array: true)

    assert_equal [10, 25, 20, 15], @binary_tree.output
  end

end
