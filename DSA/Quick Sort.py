class sorting:
    def __init__(self,arr):
        self.arr = arr

    def partitioning(self,start,end):
        pivot_element = self.arr[end]
        i = start
        j = start
        while i<end:
            if self.arr[i]<pivot_element:
                self.arr[i], self.arr[j]= self.arr[j], self.arr[i]
                j+= 1
            i+=1
        
        self.arr[j], self.arr[end]= self.arr[end], self.arr[j]
        
        return j

    def insertionSorting(self, start, n):
        i = start+1
        
        while i<n+1:
            val = self.arr[i]
            j = i
            while j>start and self.arr[j-1]>val:
                self.arr[j]= self.arr[j-1]
                j-= 1
            self.arr[j]= val
            i+=1



    def quickSorting(self,start,end,threshold):
        while start<end:
            if end-start + 1<threshold:
                self.insertionSorting(start,end)
                break
    
            else:
                pivot_element = self.partitioning(start, end)
                if pivot_element-start<end-pivot_element:
                    self.quickSorting(start, pivot_element-1,threshold)
                    start = pivot_element + 1
                else:
                    self.quickSorting(pivot_element + 1, end,threshold)
                    end = pivot_element - 1
        for i in self.arr:
            print(i,end= " ")
        print(end = '\n')


def solve():
    arr = [int(i) for i in input().split()]
    threshold = arr[1]
    arr = arr[2:]

    SortedArray = sorting(arr)

    SortedArray.quickSorting(0,len(arr)-1,threshold)


solve()