class Heap:
    
    def __init__(self,heap):
        self.heap = heap
        self.length = len(heap)

    def copy(self,arr):
        self.heap = arr 
        return self.heap

    def heapify(self,i): 
        if len(self.heap) == 0:
            print("Heap does not exist")
        leftchild = 2*i + 1
        rightchild = 2*i + 2
        min_ = i 
        if(len(self.heap) > leftchild and self.heap[leftchild] < self.heap[min_] ):
            min_ = leftchild 
        if(len(self.heap) > rightchild and self.heap[rightchild] < self.heap[min_] ):
            min_ = rightchild
        if(min_ != i):
            temp = self.heap[i]
            self.heap[i]=self.heap[min_]
            self.heap[min_] = temp
            self.heapify(min_)
        return self.heap
        
    
    def insert(self,data):
        if len(self.heap) == 0:
            print("Heap does not exist")
            return 0
        self.heap.append(data)
        return self.heap 


    def delete(self,k):
        if k not in self.heap:
            print("Integer not found")
            return 0
        if len(self.heap) == 0:
            print("Heap does not exist")
        index_ = self.heap.index(k)

        self.heap[index_] = self.heap[-1]
        self.heap = self.heap[:-1]
        return self.heap
        

    def deleteMin(self):
        if len(self.heap) == 0:
            print("Heap does not exist")
        
        index_ = self.heap.index(min(self.heap))
        self.heap[index_] = self.heap[-1]
        self.heap = self.heap[:-1]
        return self.heap


    def HeapSort(self):
        if len(self.heap) == 0:
            print("Heap does not exist")
        count = len(self.heap)
        while count >0:
            temp = self.heap[0]
            self.heap[0] = self.heap[count-1]
            self.heap[count-1] = temp                                      
            count -= 1
            x = count//2
            for i in range(x-1,-1,-1):
                self.heap = self.heapify(i)
        self.heap.sort()
        return self.heap[::-1]

    
# -------------------------------------------------------------------  TESTING -----------------------------------------------------------------


heap = []
hp = Heap(heap)
while(1):
    arr = [int(i) for i in input().split()]
    if arr[0] == 1:
        heap = hp.copy(arr[2:])
        for i in range(len(heap)//2-1,-1,-1):
            heap = hp.heapify(i)
        for i in heap:
            print(i,end=" ")
        print(end = '\n')
    if arr[0] == 2:
        element = arr[1]
        heap = hp.insert(element)
        if heap == 0:
            continue
        else:
            for i in range(len(heap)//2-1,-1,-1):
                heap = hp.heapify(i)
            for i in heap:
                print(i,end=" ")
            print(end = '\n')
    if arr[0] == 3:
        heap = hp.deleteMin()
        for i in range(len(heap)//2-1,-1,-1):
            heap = hp.heapify(i)
        for i in heap:
            print(i,end=" ")
        print(end = '\n')
    if arr[0] == 4:
        element = arr[1]
        heap = hp.delete(element)
        if heap == 0:
            continue
        else:
            for i in range(len(heap)//2-1,-1,-1):
                heap = hp.heapify(i)
            for i in heap:
                print(i,end=" ")
            print(end = '\n')
    if arr[0] == 5:
        heap = hp.HeapSort()
        for i in heap:
            print(i,end=" ")
        print(end = '\n')
    if arr[0] == -1:
        break