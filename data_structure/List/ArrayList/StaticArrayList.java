package data_structure.List.ArrayList;

import data_structure.APIs.List;

public class StaticArrayList<E> implements List<E> {
    
    private static final int CAPACITY = 16;
    private E[] array;
    private int size=0;

    public StaticArrayList() { array = (E[]) new Object[CAPACITY]; }

    protected void checkIndex(int i, int n) throws IndexOutOfBoundsException {
        if (i < 0 || i >= n) throw new IndexOutOfBoundsException("illegal index : " + i);
    }

    public int size() { return size; }

    public boolean isEmpty() { return size == 0; } 

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
        if (size == CAPACITY) throw new IllegalStateException("Array Full!"); 
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
        return res;
    }

    public String toString() {
        String res = "";
        for(int i=0;i<size;i++) {
            res += array[i].toString() + " ";
        }
        return res;
    }
}