package data_structure.Queue;

import java.util.Iterator;

import data_structure.APIs.Queue;
import data_structure.List.SinglyLinkedList.SinglyLinkedList;

public class LinkedListQueue<E> implements Queue<E>, Iterable<E> {
    
    private SinglyLinkedList<E> list = new SinglyLinkedList<>();

    public LinkedListQueue() {}

    public int size() { return list.size(); }

    public boolean isEmpty() { return list.isEmpty(); }

    public void enqueue(E e) { list.addLast(e); }

    public E dequeue() { return list.removeFirst(); }

    public E first() { return list.first(); }

    public Iterator<E> iterator() { return list.iterator(); }

    public String toString() { return list.toString(); }
}
