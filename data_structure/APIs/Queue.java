package data_structure.APIs;

public interface Queue<E> extends Iterable<E> {

    void enqueue(E e) ;

    E dequeue();

    E first();

    boolean isEmpty();

    int size();
}