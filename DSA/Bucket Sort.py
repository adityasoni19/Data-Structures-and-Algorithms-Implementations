class sorting:
    def __init__(self,inp,buckets):
        self.array = inp 
        self.buckets = buckets
        self.temp = []

    def insertionSort(self,b):
        for i in range(1, len(b)):
            up = b[i]
            j = i - 1
            while j >= 0 and b[j] < up:
                b[j + 1] = b[j]
                j -= 1
            b[j + 1] = up	
        return b	
    
    def reverseArray(self,a):
    	return a[::-1]
    	
    def printing1D(self,a):
    	for i in a:
    		print(i,end=' ')
    	print(end='\n')
    
    def printing2D(self,a):
    	for i in a:
        	if(len(i)!=0):
        		self.printing1D(i)
        	else:
        		continue
        	
    def eachBucketSort(self,a):
    	for i in range(self.buckets):
    		a[i] = self.insertionSort(a[i])
    	return a
    	
    	
    def bucketSort(self):
        
        
        
        for i in range(self.buckets):
            self.temp.append([])
            
        for j in self.array:
            index_b = int(self.buckets * j)
            self.temp[index_b].append(j)
        
        self.temp = self.reverseArray(self.temp)
        self.printing2D(self.temp)
        self.temp = self.eachBucketSort(self.temp)
        self.printing2D(self.temp)
        
        k = 0
        for i in range(self.buckets):
            for j in range(len(self.temp[i])):
                self.array[k] = self.temp[i][j]
                k += 1

        self.printing1D(self.array)
        
        return self.array


def takeInput():
    inputlist = [float(i) for i in input().split()]
    length = int(inputlist[0])
    buckets = int(inputlist[1])
    inputlist = inputlist[2:]
    sort = sorting(inputlist,buckets)
    x = sort.bucketSort()
def main():
    return takeInput()
main()

