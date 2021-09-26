class Radix:
    # Least significant digital
    def lsd_sort(self, array):
        # max_len 获取最大位数
        max_len, n, gap = len(str(max(array))), len(array), 1
        for _ in range(max_len):
            # 创建桶
            bucket_list = [[0]*n for _ in range(10)]
            # 记录桶中存入的元素个数
            bucket_notes = [0]*n
            for element in array:
                index = (element // gap) % 10
                bucket_list[index][bucket_notes[index]] = element
                bucket_notes[index] += 1
            array, k = [None]*n, 0
            for i in range(n):
                if bucket_notes[i] != 0:
                    for j in range(bucket_notes[i]):
                        array[k] = bucket_list[i][j]
                        k += 1
            gap *= 10
        return array

    # Most significant digital
    def msd_sort(self, array, d):   # d = len(str(max(brray))), 即最大位数
        # 这里 j 需要在最开始定义，而 k 却在递归后，这是因为 array 由 bucket_list 排序而组成
        n, j = len(array), 0
        if d < 1 or n <= 1:
            return 
        # 创建桶
        bucket_list = [[] for _ in range(10)]
        for i in range(n):
            # 获取桶下标
            index = (array[i] // 10**(d-1)) % 10
            # 入桶
            bucket_list[index].append(array[i])
        for i in range(10):
            # 递归，细分小桶
            self.msd_sort(bucket_list[i], d-1)
            k, num = 0, len(bucket_list[i])
            while k < num:
                # 更新桶
                array[j] = bucket_list[i][k]
                j += 1
                k += 1
        return array