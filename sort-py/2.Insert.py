class Insert:    
    def insert1(self, list_exam):
        n = len(list_exam)
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if list_exam[j+1] < list_exam[j]:
                    list_exam[j+1], list_exam[j] = list_exam[j], list_exam[j+1]
                else:
                    break
        return list_exam
                    
    def insert2(self, list_exam):
        n = len(list_exam)
        for i in range(1,n):
            pre_index, tmp = i-1, list_exam[i]
            while list_exam[pre_index] > tmp and pre_index >= 0:
                pre_index -= 1
            for j in range(i-1,pre_index,-1):
                list_exam[j+1] = list_exam[j]
            list_exam[pre_index+1] = tmp
        return list_exam
                    
    def insert_optimization(self, list_exam):
        # 折半插入
        n = len(list_exam)
        for i in range(n-1):
            for j in range(i+1, n):
                if list_exam[j] < list_exam[j-1]:
                    l, h, tmp = 0, j, list_exam[j]
                    while l < h:
                        mid = (l+h)//2
                        if tmp < list_exam[mid]:
                            h = mid
                        elif tmp > list_exam[mid]:
                            l = mid+1
                        else:
                            l = mid+1  # 这里设置 mid + 1 是为了保证算法稳定性
                            break
                    # 二分后，tmp 应该被插入到 l(low) 处
                    for k in range(j, l, -1):
                        list_exam[k] = list_exam[k-1]
                    list_exam[l] = tmp
        return list_exam