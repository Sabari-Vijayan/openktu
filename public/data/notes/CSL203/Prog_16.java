class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class DoublyLinkedList {
    private Node head;

    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } 
        else {
            Node ptr = head;
            while (ptr.right != null) {
                ptr = ptr.right;
            }
            ptr.right = newNode;
            newNode.left = ptr;
        }
    }

    public void delete(int data) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node ptr = head;

        while (ptr != null && ptr.data != data) {
            ptr = ptr.right;
        }

        if (ptr == null) {
            System.out.println("Element not found in the list.");
            return;
        }
        if (ptr == head) {
            head = ptr.right;
            if (head != null) {
                head.left = null;
            }
        } else {
            if (ptr.right != null) {
                ptr.right.left = ptr.left;
            }
            ptr.left.right = ptr.right;
        }
        System.out.println("Deleted element: " + data);
    }

    public void display() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node ptr = head;
        System.out.print("List contents: ");
        while (ptr != null) {
            System.out.print(ptr.data + " ");
            ptr = ptr.right;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        
        dll.add(10);
        dll.add(20);
        dll.add(30);
        dll.add(40);
        dll.add(50);
    
        System.out.println("Initial list:");
        dll.display();

        dll.delete(30);
        dll.delete(10);
        dll.delete(50);

        System.out.println("List after deletion:");
        dll.display();
    }
}

