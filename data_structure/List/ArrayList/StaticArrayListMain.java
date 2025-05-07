package data_structure.List.ArrayList;

import data_structure.List.ArrayList.StaticArrayList;

public class StaticArrayListMain {
    public static void main(String[] args) {
        StaticArrayList<Integer> list = new StaticArrayList<>(); 
        for(int i=1;i<100;i=i*2) {
            list.add(list.size(), i);
            System.out.println(list);
        }
        System.out.println(list.get(3));
        System.out.println(list.set(3, 100));
        System.out.println(list);
        System.out.println(list.remove(2));
        System.out.println(list);
    }
}
