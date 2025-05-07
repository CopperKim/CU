package data_structure.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<String> stack = new LinkedListStack<>();
        stack.push("Apple");
        stack.push("Banana");
        stack.push("Carrot");

        System.out.println(stack);
        System.out.println(stack.top());
        stack.push("Dangen");
        System.out.println(stack);
        System.out.println(stack.pop());
        System.out.println(stack);
    }
}
