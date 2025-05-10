package data_structure.Map.HashMap;

// import data_structure.APIs.Set;
import data_structure.APIs.Map;
// import data_structure.APIs.Pair;

public class SeparateChainingHashTable<Key, Value> { // implements Map<Key, Value> {
    
    private int n = 0 , m = 31; // n : key-value pairs, m : hash table size 
    private Node[] table; 

    private static class Node {
        private Object key; 
        private Object value; 
        private Node next;
        
        public Node(Object key, Object value, Node next) {
            this.key = key;
            this.value = value; 
            this.next = next; 
        }
    }

    public int hash(Key key) {
        return (key.hashCode() & 0x7fffffff) % m;
    }

    public SeparateChainingHashTable() { this(127); }

    public SeparateChainingHashTable(int m) { 
        this.m = m;
        table = new Node[m];
    }

    public int size() { return n; }

    public boolean isEmpty() { return n == 0; }

    public Value get(Key k) { 
        Node cur = table[hash(k)];
        while(cur != null) {
            if (cur.key.equals(k)) return (Value) cur.value; 
            cur = cur.next;
        }
        return null; 
    }

    public void put(Key k, Value v) {
        int h = hash(k); 
        Node newNode = new Node(k, v, table[h]);
        table[h] = newNode;
        n++; 
    }

    // public Value remove(Key k) {

    // }

    // public Set<Key> keySet() {

    // }

    // public Set<Value> values() {

    // }

    // public Set<Pair<Key, Value>> entrySet() {

    // }

    public String toString() {
        String res = "" ;
        for(Node node : table) {
            Node cur = node; 
            while(cur != null) {
                res += "(k : " + cur.key.toString() + ", v : " + cur.value.toString() + " ), "; 
                cur = cur.next; 
            }
        }
        res += (n + " elements");
        return res; 
    }
}
