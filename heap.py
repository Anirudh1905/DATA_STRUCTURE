class MinHeap:
    
    def __init__(self):
        self.h=[]
    
    def insert(self,x):
        i=len(self.h)
        self.h.append(x)
        while i>0 and self.h[i] < self.h[(i-1)//2]:
            self.h[i], self.h[(i-1)//2] = self.h[(i-1)//2], self.h[i]
            i = (i-1)//2
    
    def delete(self):
        i=0
        self.h[0]=self.h[-1]
        self.h.pop()
        self.heapify()
    
    def heapify(self):
        i=0
        while True:
            l = 2*i + 1
            r = 2*i + 2
            smallest=i
            if l < len(self.h) and self.h[l] < self.h[smallest]:
                smallest=l
            if r < len(self.h) and self.h[r] < self.h[smallest]:
                smallest = r
            if smallest!=i:
                self.h[i], self.h[smallest] = self.h[smallest], self.h[i]
                i=smallest
            else:
                break
    
    def get_min(self):
        return self.a[0] if self.a else None
    
    def print_heap(self):
        print(self.h)
    
h = MinHeap()
h.insert(10)
h.insert(2)
h.insert(3)
h.insert(4)
h.insert(1)
h.print_heap()
h.delete()
h.print_heap()
h.delete()
h.print_heap()
h.delete()
h.print_heap()
