class Node:
    def __init__(self, d: int):
        self.data = d
        self.next = None

    def getData(self) -> int:
        return(self.data)

    def getNext(self):
        return(self.next)

    def setData(self, d: int):
        self.data = d

    def setNext(self, n):
        self.next = n

class LinkedList:
    def __init__(self):
        self.head = None

    def Print(self):
        temp = self.head
        while(temp != None):
            print(temp.getData(), end=" ")
            temp = temp.getNext()
        print()

    def AddToEnd(self, v: int):
        n = Node(v)
        
        if(self.head == None):
            self.head = n
        
        else:
            temp = self.head
            while(temp.getNext() != None):
                temp = temp.getNext()
            temp.setNext(n)
    
    def AddToBeginning(self, v: int):
        temp = self.head
        n = Node(v)
        n.setNext(temp)
        self.head = n

    def Search(self, v: int) -> int:
        if(self.head == None):
            return(-1)  # Not Found.
        temp = self.head
        while(temp != None):
            if(temp.getData() == v):
                return(0)  # Found.
            temp = temp.getNext()
        return(-1)  # Not Found.

    def Remove(self, v: int):
        if(self.Search(v) == 0):
            temp = self.head
            n = None
            
            if(temp.getData() == v):
                self.head = self.head.getNext()
            
            else:
                while(temp.getData() != v):
                    n = temp
                    temp = temp.getNext()
                
                n.setNext(temp.getNext())
                temp.setNext(None)
        
        else:
            print("Value not in Linked List")

    
if __name__ == "__main__":
    l = LinkedList()

    for i in range(1, 31):
        l.AddToEnd(i)
    for i in range(-1, -31, -1):
        l.AddToBeginning(i)
    
    l.Print()

    print(l.Search(13))
    print(l.Search(0))

    l.Remove(13)
    print(l.Search(13))
    l.Print()
    l.Remove(0)
