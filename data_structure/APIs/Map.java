package data_structure.APIs;

public interface Map<Key, Value> {
    
    public int size();

    public boolean isEmpty();

    public Value get(Key k); 

    public void put(Key k, Value v);

    public Value remove(Key k);

    public List<Key> keySet(); 

    public List<Value> values(); 

    public List<Pair<Key, Value>> entrySet(); 
}
