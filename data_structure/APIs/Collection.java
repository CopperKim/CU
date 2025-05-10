package data_structure.APIs;

public interface Collection<E> {
    
    public void add(E element); 

    public E remove(E element); 

    public int size(); 

    public boolean contains(E element); 

    public boolean isEmpty(); 
}