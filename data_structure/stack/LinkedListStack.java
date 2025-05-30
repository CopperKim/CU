package data_structure.Stack;

import java.util.Iterator;

import data_structure.APIs.Stack;
import data_structure.List.SinglyLinkedList.SinglyLinkedList;

public class LinkedListStack<E> implements Stack<E>, Iterable<E> {
    
    private SinglyLinkedList<E> list = new SinglyLinkedList<>();
    
    public int size() { return list.size(); }

    public boolean isEmpty() { return list.isEmpty(); }

    public void push(E e) { list.addFirst(e); }

    public E top() { return list.first(); }

    public E pop() { return list.removeFirst(); }

    public Iterator<E> iterator() { return list.iterator(); }
    
    public String toString() { return list.toString(); }
}
