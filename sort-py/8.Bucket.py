class Bucket:
    ''' 
    桶排序是计数排序的扩展版本，计数排序可以看成每个桶只存储相同元素，
    而桶排序每个桶存储一定范围的元素，通过映射函数，将待排序数组中的元素映射到各个对应的桶中，
    对每个桶中的元素进行排序，最后将非空桶中的元素逐个放入原序列中。
    '''
    def heap_build(self, array):
        # 建立大顶堆
        num = len(array)
        if num < 2:
            return 
        i = (num-2)//2
        while i >= 0:
            self.heap_adjust(array, i, num)
            i -= 1
        
    def heap_adjust(self, array, root, num):
        # 调整大顶堆
        left_node = 2*root + 1
        right_node = 2*root + 2
        largest = root
        if left_node < num:
            if array[left_node] > array[largest]:
                largest = left_node
        if right_node < num:
            if array[right_node] > array[largest]:
                largest = right_node
        if largest != root:
            array[largest], array[root] = array[root], array[largest]
            self.heap_adjust(array, largest, num)
        
    def heap_sort(self, array):
        num = len(array)
        self.heap_build(array)
        while num > 0:
            # 自顶向下调整大顶堆
            array[0], array[num-1] = array[num-1], array[0]
            num -= 1
            self.heap_adjust(array, 0, num)
        return array
        
    def bucket_sort(self, arr):
        max_num, min_num = max(arr), min(arr)
        # set the map rule and apply for space
        bucketArr = [[] for _ in range(max_num // 10 - min_num // 10 + 1)]  
        for i in arr: 
            index = i // 10 - min_num // 10
            bucketArr[index].append(i)
        arr.clear()
        for i in bucketArr:
            # 对每一个桶内的元素都进行堆排序(方法随意，冒泡等等都无所谓)
            arr.extend(self.heap_sort(i))
        return arr