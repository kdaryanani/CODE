/*
 
 Created by Karan Daryanani on 2/20/2015
 COEN 171
 Pantoja
 Binary Search Tree Implementation
 
 This is an implementation of a Binary Search Tree in Scala. Scala reflects Java greatly so the conversion was very strait forward

 For the implementation, I still use the Java Scanner for reading in Integers.


 
 */

import java.util.Scanner //Take in values library


object BinaryNode {

  def main(args: Array[String]) {
    val x = new BinaryNode() //This assumes we have no Root
    val in = new Scanner(System.in)
    var NumberOne = in.nextInt() //Takes in the value while enter is being hit
    while (NumberOne != -1) {
      x.insert(NumberOne)
      NumberOne = in.nextInt()
    }
    val in2 = new Scanner(System.in)
    var Number2 = in2.nextInt()
    while (Number2 != -1) { //If the number -1 is then terminate the read in 
      println(x.member(Number2))
      Number2 = in2.nextInt()
    }
  }
}

class BinaryNode { //Creating the class and the base case of an empty tree

  var data: Int = 0

  var left: BinaryNode = null

  var right: BinaryNode = null

  def this(a: Int) { //defining this functinoality
    this()
    left = null
    right = null
    data = a
  }

  def insert(a: Int) { //Insert values into the binary search tree in the correct location recursively
    if (a < data) {
      if (left == null) left = new BinaryNode(a) else left.insert(a)
    } else if (a > data) {
      if (right == null) right = new BinaryNode(a) else right.insert(a)
    }
  }

  def member(a: Int): Boolean = { //Function to check if an element is a member. Returns true or false boolean
    var isThere = false
    if (a == data) isThere = true
    if (a < data && left != null) return left.member(a)
    if (a > data && right != null) return right.member(a)
    isThere
  }
}