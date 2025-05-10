package data_structure.List.ArrayList;

import java.util.Iterator;
import java.util.NoSuchElementException;

import data_structure.APIs.List;

public class DynamicArrayList<E> implements List<E>, Iterable<E> {
    
    private static int CAPACITY = 16;
    private E[] array;
    private int size=0;

    public DynamicArrayList() { array = (E[]) new Object[CAPACITY]; }

    protected void checkIndex(int i, int n) throws IndexOutOfBoundsException {
        if (i < 0 || i >= n) throw new IndexOutOfBoundsException("illegal index : " + i);
    }

    public int size() { return size; }

    public boolean isEmpty() { return size == 0; } 

    public void resize(int cap) {
        E[] newArr = (E[]) new Object[cap];
        for(int i=0;i<size;i++) newArr[i] = array[i];
        array = newArr;
    } 

    public E get(int i) throws IndexOutOfBoundsException { 
        checkIndex(i, size); 
        return array[i]; 
    }

    public E set(int i, E e) throws IndexOutOfBoundsException { 
        checkIndex(i, size);
        E res = array[i];
        array[i] = e;
        return res;
    }

    public void add(int i, E e) throws IndexOutOfBoundsException, IllegalStateException {
        checkIndex(i, size+1);
        if (size == CAPACITY) {
            resize(CAPACITY = 2*CAPACITY);
        }
        for(int k = size++;k>i;k--) {
            array[k] = array[k-1];
        }
        array[i] = e;
        return;
    }

    public E remove(int i) throws IndexOutOfBoundsException {
        checkIndex(i, size);
        E res = array[i];
        for(;i<size;i++) {
            array[i] = array[i+1];
        }
        size--;
        if (size == CAPACITY/4) resize(CAPACITY = CAPACITY/2);
        return res;
    }

    public Iterator<E> iterator() { return new ArrayListIterator(); }

    private class ArrayListIterator implements Iterator<E> {

        private int j = 0;

        public boolean hasNext() { return j < size; }

        public E next() {
            if (!hasNext()) throw new NoSuchElementException(); 
            return array[j++]; 
        }
    }

    public String toString() {
        String res = "";
        for(int i=0;i<size;i++) {
            res += array[i].toString() + " ";
        }
        res += ", size : " + size + ", capacity : " + CAPACITY;
        return res;
    }
}