package data_structure.List.ArrayList;

import data_structure.List.List;

public class DynamicArrayList<E> implements List<E> {
    
    private int CAPACITY = 16;
    private E[] array; 
    private int size=0;

    public DynamicArrayList() { array = (E[]) new Object[CAPACITY]; }

    public void checkSize() {}
}
