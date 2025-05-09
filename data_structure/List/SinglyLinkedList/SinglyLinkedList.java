package data_structure.List.SinglyLinkedList;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class SinglyLinkedList <E> implements Iterable<E> {
    
    private static class Node <E> {

        private E element;

        private Node<E> next; 

        public Node(E e, Node<E> n) {
            element = e;
            next = n;
        }

        // public E getElement() { return element; }

        // public Node<E> getNext() { return next; }

        // public void setNext(Node<E> n) { next = n; }
    }

    private Node<E> head = null;

    private Node<E> tail = null;

    private int size = 0;

    public SinglyLinkedList() {}

    public E first() { return head.element; }

    public void addFirst(E data) {
        head = new Node<>(data, head); 
        if (size == 0) tail = head; 
        size++;
    }

    public void addLast(E data) {
        Node<E> newNode = new Node<>(data, null);
        if (isEmpty()) head = newNode; 
        else tail.next = newNode;
        tail = newNode;
        size++;
    }

    public E removeFirst() {
        if (isEmpty()) { return null; }

        E removedElement = head.element;
        head = head.next;
        size --;
        if (size == 0) tail = null; 
        return removedElement;
    }

    public boolean isEmpty() { return size==0 ; }

    public int size() { return size; }

    public Iterator<E> iterator() { return new SLLiterator(); }

    private class SLLiterator implements Iterator<E> {

        private Node<E> cur = head; 

        public boolean hasNext() { 
            if (cur == null) return false;
            else return true;
        } 

        public E next() { 
            if (!hasNext()) throw new NoSuchElementException(); 
            E data = cur.element;
            cur = cur.next;
            return data;
        }
    }

    public String toString() {
        String res = "";
        Node<E> cur = head;
        while(cur != null) {
            res += cur.element.toString() + ' ';
            cur = cur.next;
        }
        return res;
    }

}