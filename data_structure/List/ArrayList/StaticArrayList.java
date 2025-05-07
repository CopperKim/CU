package data_structure.List.ArrayList;

import data_structure.List.List;

public class StaticArrayList<E> implements List<E> {
    
    private static final int CAPACITY = 16;
    private E[] data;
    private int size=0;

    public StaticArrayList() { data = (E[]) new Object[CAPACITY]; }

    public int size() { return size; }

    public boolean isEmpty() { return size == 0; } 

    public E get(int i) { return data[i]; }

    public E set(int i, E e) { 
        E res = data[i];
        data[i] = e;
        return res;
    }

    public void add(int i, E e) {
        for(int k = size++;k>i;k--) {
            data[k] = data[k-1];
        }
        data[i] = e;
        return;
    }

    public E remove(int i) {
        E res = data[i];
        for(;i<size;i++) {
            data[i] = data[i+1];
        }
        size--;
        return res;
    }

    public String toString() {
        String res = "";
        for(int i=0;i<size;i++) {
            res += data[i].toString() + " ";
        }
        return res;
    }
}