
/**
 * @file LinkedListExercises.h
 * University of Illinois CS 400, MOOC 2, Week 1: Linked List
 * Spring 2019
 *                        STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
**/

/********************************************************************
  Week 1: Linked List and Merge Sort Exercises

  There are two exercises in this file. Please read the code comments
  below and see the provided instructions PDF before you begin. The
  other provided code files in the starter zip also contain important
  comments and hints about how to approach this.

  This is the only file you can edit for the sake of grading! You can
  edit the other provided starter files for testing purposes, but the
  autograder will assume that this is the only file that has been edited
  by you, and the others will be replaced with the original intended
  versions at grading time.
 ********************************************************************/

// Prevent the header from being included more than once per cpp file
#pragma once

// It's good to put system headers first, so that if your own libraries
// cause conflicts, the compiler will most likely identify the problem
// as being in your own source code files, where it arises later.
#include <iostream>
#include <string>

#include "LinkedList.h"
#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);


template <typename T>
void LinkedList<T>::insertOrdered(const T& newData) {

  Node *new_node = new Node(newData);


  if( 0 == size_ )
  {
    
 
    head_ = new_node;
    tail_ = new_node;
    
   
  }
  else if( newData <= head_->data )
  {

    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
  
  }
  else
  {
  
    Node *current = head_;
    Node *prev = head_;
        
    while( nullptr != current )
    {
      
      if( current->data <= newData )
      {
        
      
        if( nullptr != current->next  )
        {
    
          prev = current;
          current = current->next;
        }
        else
        {
      
          current->next=new_node;
          new_node->prev = current;
          
        
          tail_ = new_node;
          
          break;
        }
      
      }
      else
      {
  
  
        prev->next = new_node;
        new_node->prev = prev;
        
         new_node->next = current;
        current->prev = new_node;
        
        break;
      }
    
    }

  }

  size_ += 1;
  
  return;

}
template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other) const {

  LinkedList<T> left = *this;
  LinkedList<T> right = other;

  LinkedList<T> merged;

    while( false == left.empty() && false == right.empty() )
  {
    T left_front = left.front();
    T right_front = right.front();
    
    if( left_front <= right_front )
    {
      merged.pushBack( left_front );
      left.popFront();
    }
    else
    {
      merged.pushBack( right_front );
      right.popFront();
    }
    
  }

  if( left.empty() )
  {
    while( false == right.empty() )
    {
    
      merged.pushBack( right.front() );
      right.popFront();
    }
  }

  if( right.empty() )
  {
    while( false == left.empty() )
    {
 
      merged.pushBack( left.front() );
      left.popFront();
    }
  }
  
  return merged;
}
