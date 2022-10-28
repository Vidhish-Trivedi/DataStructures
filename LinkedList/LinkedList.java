public class LinkedList{
    private Node head;


    public LinkedList(){
        this.head = null;
    }

    public void Print(){
        Node temp = this.head;
        while(temp != null){
            System.out.print(temp.getData() + " ");
            temp = temp.getNext();
        }
        System.out.println();
        return;
    }

    public void AddToEnd(long d){
        Node n = new Node(d);
        if(this.head == null){
            this.head = n;
            return;
        }

        Node temp = this.head;
        while(temp.getNext() != null){
            temp = temp.getNext();
        }
        temp.setNext(n);
        return;
    }

    public void AddToBeginning(long d){
        Node temp = this.head;
        Node n = new Node(d);
        n.setNext(temp);
        this.head = n;
        return;
    }

    public int Search(long d){
        if(this.head == null){
            return(-1);  // Not Found.
        }

        Node temp = this.head;
        while(temp != null){
            if(temp.getData() == d){
                return(0);  // Found.
            }
            temp = temp.getNext();
        }
        return(-1);  // Not Found.
    }

    public void Remove(long d){
        if(this.Search(d) == 0){
            Node temp = this.head;
            Node n = null;
            if(temp.getData() == d){
                this.head = this.head.getNext();
                return;
            }
            while(temp.getData() != d){
                n = temp;
                temp = temp.getNext();
            }
            n.setNext(temp.getNext());
            temp.setNext(null);
            return;
        }
        else{
            System.out.println("Value not in Linked List.");
            return;
        }
    }

    // Main().
    public static void main(String[] args) {
        LinkedList l = new LinkedList();

        // Simple Test.
        for(int i = 1; i <= 30; i++){
            l.AddToEnd(i);
        }

        l.Print();

        for(int i = -1; i >= -30; i--){
            l.AddToBeginning(i);
        }

        l.Print();

        System.out.println(l.Search(13));
        System.out.println(l.Search(0));

        l.Remove(13);
        System.out.println(l.Search(13));
        l.Print();
        l.Remove(0);
    }
}

class Node{
    private long data;
    private Node next;

    
    public Node(long d){
        this.data = d;
        this.next = null;
    }

    public long getData(){
        return(this.data);
    }

    public Node getNext(){
        return(this.next);
    }

    public void setData(long d){
        this.data = d;
        return;
    }

    public void setNext(Node n){
        this.next = n;
        return;
    }
}