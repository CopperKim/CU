package data_structure.APIs;

import data_structure.APIs.Collection; 

public interface Set<E> {

    public void addAll(Collection<E> coll);

    public void containsAll(Collection<E> coll); 

    public boolean equals(Set<E> set); 
}
