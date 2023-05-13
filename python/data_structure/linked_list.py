class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

node = head

while node:
    if node.next is None:
        node.next = Node(4)
        break
    print(node.data, end = " ")
    node = node.next
    
print()
    
node = Node(0)
node.next = head
head = node

while node:
    print(node.data, end = " ")
    node = node.next
    
#메모리 할당 안 해줘도 된다는게 너무...........편하다 나 자꾸 alloc이 아른거린다