package data_structure.singly_linked_list;

import data_structure.singly_linked_list.SinglyLinkedList;

public class Main {
    public static void main(String[] args) {
        SinglyLinkedList<Integer> list = new SinglyLinkedList<>();
        
        System.out.println(list);
        
        for(int i=1;i<100;i=i*2) {
            list.addFirst(i);
            System.out.println(list);
        }

        list.removeFirst();
        System.out.println(list);

        list.addLast(100);
        System.out.println(list);

    }
}
