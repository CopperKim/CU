package data_structure.APIs;

public interface Stack<E> extends Iterable<E> {
    
    int size();
    
    boolean isEmpty();

    void push(E e);

    E top();

    E pop();
}