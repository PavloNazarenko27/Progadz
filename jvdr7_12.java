import java.io.File;
import java.util.Scanner;

public class Main {
    static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
        }
    }

    static Node insertSorted(Node head, int val) {
        Node n = new Node(val);
        if (head == null || val <= head.val) {
            n.next = head;
            return n;
        }
        Node cur = head;
        while (cur.next != null && cur.next.val < val) {
            cur = cur.next;
        }
        n.next = cur.next;
        cur.next = n;
        return head;
    }

    static Node mergeLists(Node h1, Node h2) {
        Node dummy = new Node(0);
        Node tail = dummy;
        while (h1 != null && h2 != null) {
            if (h1.val <= h2.val) {
                tail.next = h1;
                h1 = h1.next;
            } else {
                tail.next = h2;
                h2 = h2.next;
            }
            tail = tail.next;
        }
        tail.next = (h1 != null) ? h1 : h2;
        return dummy.next;
    }

    static void printList(Node head) {
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.val + (cur.next != null ? " " : ""));
            cur = cur.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("input.txt"));
            Node c1 = null;
            Node c2 = null;
            boolean sec = false;
            while (sc.hasNextInt()) {
                int v = sc.nextInt();
                if (v < 0) {
                    sec = true;
                    continue;
                }
                if (!sec) {
                    c1 = insertSorted(c1, v);
                } else {
                    c2 = insertSorted(c2, v);
                }
            }
            sc.close();
            printList(c1);
            printList(c2);
            Node merged = mergeLists(c1, c2);
            printList(merged);
        } catch (Exception e) {
        }
    }
}