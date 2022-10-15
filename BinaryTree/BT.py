class Node:
    def __init__(self, v: int):
        self.val = v
        self.left = None
        self.right = None

class BT:
    def __init__(self):
        self.root = None

    def SetRoot(self, n: Node):
        self.root = n

    def PrintInorder(self, n: Node):
        if(n == None):
            return
        self.PrintInorder(n.left)
        print(n.val, end=" ")
        self.PrintInorder(n.right)

    def PrintPreorder(self, n: Node):
        if(n == None):
            return
        print(n.val, end=" ")
        self.PrintPreorder(n.left)
        self.PrintPreorder(n.right)

    def PrintPostorder(self, n: Node):
        if(n == None):
            return
        self.PrintPostorder(n.left)
        self.PrintPostorder(n.right)
        print(n.val, end=" ")

if __name__ == "__main__":
    myTree = BT()
    myTreeRoot = Node(10)
    myTree.SetRoot(myTreeRoot)

    myTree.root.left = Node(11)
    myTree.root.left.right = Node(20)
    myTree.root.left.left = Node(211)
    myTree.root.right = Node(5)
    myTree.root.right.left = Node(-321)

    myTree.PrintInorder(myTree.root)
    print()
    myTree.PrintPostorder(myTree.root)
    print()
    myTree.PrintPreorder(myTree.root)
    print()
