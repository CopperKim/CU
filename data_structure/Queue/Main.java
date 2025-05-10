package data_structure.Queue;

import data_structure.APIs.Queue;
import data_structure.Queue.LinkedListQueue;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> Q = new LinkedListQueue<>();
        for(int i=1;i<100;i=i*2) {
            Q.enqueue(i);
            System.out.println(Q);
        }
        System.out.println(Q.dequeue());
        System.out.println(Q.dequeue());
        System.out.println(Q.dequeue());
        System.out.println(Q);
        System.out.println(Q.first());
        System.out.println(Q.size());

        for(int i : Q) System.out.println(i);
    }
}
