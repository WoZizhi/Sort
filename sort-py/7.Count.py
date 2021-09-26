class Count:
    '''
    当存在负数时，需要再弄一个 min，同时序号为 list_exam[i]-min
    当不存在负数时，为了节省空间，也可以弄一个 min，总共长度为 max-min
    '''
    def max_num(self, list_exam):
        '''
        闲的没事写的 max, 直接调用内置函数就行了...
        '''
        max_number = 0
        for i in range(len(list_exam)):
            if list_exam[i] > list_exam[max_number]:
                max_number = i
        return list_exam[max_number]
        
    def count_sort1(self, list_exam):
        # 原数组元素取值的范围
        k = self.max_num(list_exam)+1
        final, count = [], [0]*k
        for element in list_exam: 
            count[element] += 1
        for i in range(len(count)):
            for _ in range(count[i]):
                final.append(i)
        return final
        
    def count_sort2(self, list_exam):
        # 原数组元素取值的范围
        k = self.max_num(list_exam)+1
        # 原数组元素的长度
        n = len(list_exam)
        final, count = [0]*n, [0]*k
        for element in list_exam: 
            count[element] += 1
        # 后续更好的排序，代表其在新数组中的序号
        for i in range(1, k):
            count[i] += count[i-1]
        # 之所以倒序是为了保证稳定性
        for i in range(n-1, -1, -1):
            count[list_exam[i]] -= 1
            final[count[list_exam[i]]] = list_exam[i]
        return final