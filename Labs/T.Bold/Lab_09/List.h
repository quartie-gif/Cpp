#pragma once

#include <iostream>
#include <utility>

template <typename T>
class Node
{

  public:
    Node(T data): m_data(data){};
    T m_data;
    Node *m_next;
};

template <typename T>
class List{
public:

  //constructor
  List();
  
  //deconstructor
  
  ~List();
  //copy constrctor
  List(const List &other);

  //Move constrctor
  List(List &&other);

  //Adding elements
  List<T> & add (const T &item);

  //Looking for specific element
  bool contains(const T &item) const;

  //Printing list
  void print() const;

  Node <T>* m_head;
  Node <T>* m_tail;
};

template <typename T>
std::ostream & operator <<(std::ostream & strm, const List<T> &other);

template <typename T>
List<T>::List(): m_head(nullptr), m_tail(nullptr)
{

}

template <typename T>
List<T>::~List()
{
  if(m_head)
  {
    Node<T> *temp = m_head;
    Node<T> *temp2 = nullptr;
    while(temp)
    {
      temp2 = temp;
      temp = temp->m_next;
      delete temp2;
    }
  }
}

template <typename T>
List<T>::List(const List &other)
{
  Node<T> *temp = other.m_head;
  m_head = m_tail = nullptr;
  
  while(temp->m_next != nullptr)
  {
    add(temp->m_data);
    temp = temp->m_next;
  }
  add(temp->m_data);
}

template <typename T>
List<T>::List(List &&other)
{
  Node<T> *temp = other.m_head;
  m_head = m_tail = nullptr;
  
  while(temp->m_next != nullptr)
  {
    add(temp->m_data);
    temp = temp->m_next;
  }
  add(temp->m_data);

  other.m_head = other.m_tail = nullptr;
}

template <typename T>
List<T> & List<T>::add (const T &item)
{
  Node<T> *newNode  = new Node<T>(item);
  newNode -> m_next = nullptr;
  if(m_head == nullptr)
  {
    m_head = newNode;
    m_tail = newNode;
  }
  else
  {
    m_tail->m_next = newNode;
    m_tail = m_tail->m_next;
  }
  return *this;
}

template <typename T>
bool List<T>::contains(const T &item) const
{
  Node<T> *temp = m_head;
  while(temp->m_next != nullptr)
    {
      if(temp -> m_data == item)
      {
        return true;
      }
      temp = temp->m_next;
    }
  return false;
}

template <typename T>
void List<T>::print() const
{
  if(m_head)
  {
    Node<T> *temp = m_head;
    while(temp->m_next != nullptr)
    {
      std::cout << temp->m_data << " ";
      temp = temp->m_next;
    }
    std::cout << temp->m_data; 
  }
}

template <typename T>
std::ostream & operator <<(std::ostream & strm, const List<T> &other)
{
  other.print();
  return strm;
}