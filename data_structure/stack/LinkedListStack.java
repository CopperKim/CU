package data_structure.Stack;

import data_structure.List.SinglyLinkedList.SinglyLinkedList;
import data_structure.Stack.Stack;

public class LinkedListStack<E> implements Stack<E> {
    
    private SinglyLinkedList<E> list = new SinglyLinkedList<>();
    
    public int size() { return list.size(); }

    public boolean isEmpty() { return list.isEmpty(); }

    public void push(E e) { list.addFirst(e); }

    public E top() { return list.First(); }

    public E pop() { return list.removeFirst(); }

    public String toString() { return list.toString(); }
}
