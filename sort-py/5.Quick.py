class Quick:
    def quick_sort1(self, list_exam):       
        if len(list_exam) >= 2:         
            mid = list_exam[len(list_exam)//2]
            list_exam.remove(mid)
            left = [i for i in list_exam if i <= mid]        
            right = [i for i in list_exam if i > mid]
            list_exam = self.quick_sort(left) + [mid] + self.quick_sort(right)       
        return list_exam
        
    # 基准值取最左侧
    def quick_sort2(self, list_exam, low, high):
        if low >= high:
            return
        n = len(list_exam)
        # 这里 i = low + 1 是为了让其取不到基准所在位置
        pivot, i, j = list_exam[low], low+1, high       
        while True:
            while list_exam[i] < pivot:
                i += 1
                if i == high:
                    break
            while list_exam[j] > pivot:
                j -= 1
                if j == low:
                    break
            if i >= j:
                break
            list_exam[i], list_exam[j] = list_exam[j], list_exam[i]
        list_exam[low] = list_exam[j]
        list_exam[j] = pivot
        self.quick_sort2(list_exam, low, j-1)
        self.quick_sort2(list_exam, j+1, high)
        return list_exam
        
    # 基准值取中间
    def quick_sort3(self, list_exam, low, high):
        if low >= high:
            return
        mid = (low+high)//2
        pivot, i, j = list_exam[mid], low+1, high
        # 再把基准值与第一个互换
        # 不交换，则位于中间的基准值比较难处理
        list_exam[low], list_exam[mid] = list_exam[mid], list_exam[low]
        while True:
            while list_exam[i] < pivot:
                i += 1
                if i == high:
                    break
            while list_exam[j] > pivot:
                j -= 1
                if j == low:
                    break
            if i >= j:
                break
            list_exam[i], list_exam[j] = list_exam[j], list_exam[i]
        list_exam[low] = list_exam[j]
        list_exam[j] = pivot
        self.quick_sort3(list_exam, low, j-1)
        self.quick_sort3(list_exam, j+1, high)
        return list_exam