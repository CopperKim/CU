package data_structure.List.ArrayList;

import data_structure.List.List;

public class StaticArrayList<E> implements List<E> {
    
    private static final int CAPACITY = 16;
    private E[] array;
    private int size=0;

    public StaticArrayList() { array = (E[]) new Object[CAPACITY]; }

    public int size() { return size; }

    public boolean isEmpty() { return size == 0; } 

    public E get(int i) { return array[i]; }

    public E set(int i, E e) { 
        E res = array[i];
        array[i] = e;
        return res;
    }

    public void add(int i, E e) {
        for(int k = size++;k>i;k--) {
            array[k] = array[k-1];
        }
        array[i] = e;
        return;
    }

    public E remove(int i) {
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