package data_structure.Tree;

public class BinarySearchTree<E extends Comparable<E>>  {

    private Node<E> root;

    private static class Node<E extends Comparable<E>> {

        private E element;
        private Node<E> left, right; 
        private int n; // numbers of node in subtree
        
        public Node(E e, int n) { element = e; this.n = n; }
    }  

    public boolean search(Comparable e) {

        Node<E> current = root; 

        while(root != null) {
            int comp = e.compareTo(root.element);
            if (comp > 0) current = current.right; 
            else if (comp < 0) current = current.left; 
            else return true; 
        }
        
        return false; 
    }

    public void insert(E e) {
        
        root = insert(root, e); 
    }

    private Node insert(Node<E> x, E e) {
        
        if (x == null) return new Node(e, 1);
        
        int comp = e.compareTo(x.element); 

        if (comp < 0) x.left = insert(x.left, e);
        else if (comp > 0) x.right = insert(x.right, e);  
        else x.element = e; 

        x.n = 1 + x.left.n + x.right.n; 

        return x; 
    }

    
}
