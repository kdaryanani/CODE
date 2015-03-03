/*
 
 Created by Karan Daryanani on 2/1/2015
 
 This is the conversion from the teachers C++ Binary Search Tree translated to Java. The most interesting thing I found about Java is that there are no pointers.
 
 */

import java.util.Scanner; //Take in values library
import java.io.*;

public class BinaryNode
{
    int data;
    BinaryNode left;
    BinaryNode right; //Weird that this isnt a pointer
    
    public BinaryNode(){ //This assumes we have no Root
        left = null;
        right = null;
        data = 0;
    }
    public BinaryNode(int a) { //This assumes we are given a as the root of our tree
        left = null;
        right = null;
        data = a;
    }
    public void insert(int a){ //Function to insert a piece of data in the balanced position
        if (a < data)//Left side
        {
            if(left == null)
                left = new BinaryNode(a);
            else
                left.insert(a);//Keep checking recurusively until the correct position is found.
        }
        else if (a > data)//Right side
        {
            if(right == null)
                right = new BinaryNode(a);
            else
                right.insert(a); //Keep checking recurusively until the correct position is found.
        }
    }
    
    public boolean member (int a){
        boolean isThere = false;
        if (a == data)
            isThere = true;
        if (a < data && left != null)
            return left.member(a); //Recursively call....
        if (a > data && right != null)
            return right.member(a); //Recursively call until the value is found if possible
        return isThere;
    }
    
    
    public static void main(String[] args){
        BinaryNode x = new BinaryNode(); //Creates a new node
        Scanner in = new Scanner(System.in); //Uses built in functinality to take in values
        int NumberOne = in.nextInt();
        
        while (NumberOne != -1) {
            x.insert(NumberOne);
            NumberOne = in.nextInt();
        }
        
        Scanner in2 = new Scanner(System.in);
        int Number2 = in2.nextInt();
        
        while (Number2 != -1) {
            System.out.println(x.member(Number2));
            Number2 = in2.nextInt();
        }
    }
}