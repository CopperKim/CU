package data_structure.Map.HashMap;

// import data_structure.APIs.MAP; 
import data_structure.Map.HashMap.SeparateChainingHashTable; 

public class SeparateChainingHashTableMain {
    public static void main(String[] args) {
        SeparateChainingHashTable<String, Integer> map = new SeparateChainingHashTable<>(); 

        map.put("seoul", 1); 
        map.put("apple", 5); 
        map.put("banana", 10); 

        System.out.println(map); 
        System.out.println(map.hash("banana"));
        System.out.println(map.get("banana"));
        System.out.println(map.get("carrot"));  
    }
 
}