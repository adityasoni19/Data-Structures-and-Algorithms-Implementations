class Queue:
    def __init__(self,queue_capacity):
        self.front = -1
        self.back = 0
        self.queue_capacity = queue_capacity
        self.queue = [0 for i in range(self.queue_capacity)]
   
    def numcount(self):
        count= 0
        for i in self.queue: 
            if i!=0:
                count+=1  
            else:
                continue
        return count

    def emptyspacescount(self):
        count= 0
        for i in self.queue:
            if i==0:
                count+=1 
            else:
                continue
        return count

    def enqueue(self,data):
        if (self.front-self.back)%self.queue_capacity==-1:
            print("overflow")
            return self.queue
        else:
            self.queue[self.back] = data
            self.back = (self.back+1)%self.queue_capacity
            return self.queue 

    def dequeue(self):
        if (self.front-self.back)%self.queue_capacity==-1:
            print("underflow")
            return self.queue
        elif(qu.emptyspacescount() == queue_capacity):
            self.front-=1 
            self.back-=1
        else:
            self.front = (self.front+ 1)%self.queue_capacity
            self.queue[self.front] = 0
            return self.queue

    def display(self):
        count = 0
        for i in self.queue:
            if i==0:
                continue
            else:
                count+=1

        print(f'{self.queue[self.front+1]} {self.queue.index(self.queue[self.front+1])}')
        
        print(f'{self.queue[self.back-1]} {self.queue.index(self.queue[self.back-1])}')
        
        print(count)
         
        for i in self.queue:
            print(i,end=' ')
        print(end='\n')


# ----------------------- test case testing ---------------------------

queue_capacity = int(input())
qu = Queue(queue_capacity)
queue_res= []
while(True):
    x = [int(i) for i in input().split()]  
    if x[0]==-1:
        break 
    if x[0]==1:
        if(qu.emptyspacescount()>=x[1]):
            for i in range(x[1]):
                queue_res = qu.enqueue(x[i+2])
            for i in queue_res:
                print(i,end=' ')
            print(end='\n')
        else:
            print('overflow')
            
    if x[0]==2:
        if(qu.numcount()>x[1]):
            for i in range(x[1]):
                queue_res=qu.dequeue()
            for i in queue_res: 
                print(i,end=' ')
            print(end='\n')
        elif(qu.numcount()==x[1]):
            for i in range(x[1]):
                queue_res=qu.dequeue()
            for i in queue_res:
                print(i,end=' ')
            print(end='\n')
            qu.dequeue()
        else:
            print('underflow')
             
    if x[0]==3:
        if(qu.emptyspacescount() == queue_capacity):
            print('underflow')
        else:
            qu.display()