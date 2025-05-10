package data_structure.Stack;

import data_structure.APIs.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<String> S = new LinkedListStack<>();
        S.push("Apple");
        S.push("Banana");
        S.push("Carrot");

        System.out.println(S);
        System.out.println(S.top());
        S.push("Dangen");
        System.out.println(S);
        System.out.println(S.pop());
        System.out.println(S);

        for(String s : S) System.out.println(s);
    }
}
