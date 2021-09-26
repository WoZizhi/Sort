class Select:
    def select(self, list_exam):
        n = len(list_exam)
        for i in range(n):
            min_num = i
            for j in range(i+1,n):
                if list_exam[j] < list_exam[min_num]:
                    min_num = j
            if min_num != i:
                list_exam[i], list_exam[min_num] = list_exam[min_num], list_exam[i]
        return list_exam