package data_structure.List.ArrayList;

import data_structure.List.ArrayList.DynamicArrayList;

public class DynamicArrayListMain {
    public static void main(String[] args) {
        DynamicArrayList<Integer> list = new DynamicArrayList<>(); 
        for(int i=1;i<100;i=i+5) {
            list.add(list.size(), i);
            System.out.println(list);
        }
        System.out.println(list.get(3));
        System.out.println(list.set(3, 100));
        System.out.println(list);
        System.out.println(list.remove(2));
        System.out.println(list);

        for(int i : list) {
            System.out.println(i);
        }
        // for(int i=1;i<=20;i++) {
        //     list.remove(0);
        //     System.out.println(list);
        // }
    }
}
