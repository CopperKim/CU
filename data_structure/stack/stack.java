package data_structure.Stack;

public interface Stack<E> {
    
    int size();
    
    boolean isEmpty();

    void push(E e);

    E top();

    E pop();
}