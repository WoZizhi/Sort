class Heap:
    def heap_build(self, array, n):
        # 建立大顶堆
        if n < 2:
            return 
        i = (n-2)//2
        for j in range(i, -1, -1):
            self.heap_adjust(array, j, n)
        
    def heap_adjust(self, array, root, num):
        # 调整大顶堆
        left_node = 2*root + 1
        right_node = 2*root + 2
        largest = root
        if left_node < num and array[left_node] > array[largest]:
            largest = left_node
        if right_node < num and array[right_node] > array[largest]:
            largest = right_node
        if largest != root:
            array[largest], array[root] = array[root], array[largest]
            # 调整完第一次后，如果继续往上调整，下来的还要和之前的叶子节点比较
            self.heap_adjust(array, largest, num)
        
    def heap_sort(self, array):
        n = len(array)
        self.heap_build(array, n)
        for i in range(n, 1, -1):
            # 自顶向下调整大顶堆
            array[0], array[i-1] = array[i-1], array[0]
            self.heap_adjust(array, 0, i-1)
        return array