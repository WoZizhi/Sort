class Shell:
    def shell1(self, list_exam):
        n = len(list_exam)
        gap = n // 2
        while gap >= 1:
            for i in range(gap, n):
                for j in range(i, gap-1, -gap):
                    exchange = False
                # 注意上下边界的确定
                # for j in range(i-gap, -1, -gap):
                    # if list_exam[j+gap] > list_exam[j]:
                    if list_exam[j-gap] > list_exam[j]:
                        list_exam[j-gap], list_exam[j] = list_exam[j], list_exam[j-gap]
                        exchange = True
                    if not exchange:
                        break
            gap //= 2
        return list_exam
            
    def shell2(self, list_exam):
        n = len(list_exam)
        gap = n // 2
        while gap > 0:
            for i in range(gap, n):
                pre_index, tmp = i - gap, list_exam[i]
                while list_exam[pre_index] > tmp and pre_index >= 0:
                    pre_index -= gap
                for j in range(i-gap, pre_index+gap-1, -gap):
                    list_exam[j + gap] = list_exam[j]
                list_exam[pre_index+gap] = tmp
            gap //= 2
        return list_exam