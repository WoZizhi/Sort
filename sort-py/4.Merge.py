class Merge:
    '''
    这里用了 append, 每次都需要重新开辟一段内存空间
    额外开辟的数组空间使用完毕就被释放，因此空间复杂度为 n(n+logn) 而非 nlogn
    def merge(left, right):
        l = r = 0
        new_list = []
        while(l<len(left) and r<len(right)):
            if left[l] <= right[r]:
                new_list.append(left[l])
                l += 1
            else:
                new_list.append(right[r])
                r += 1
        new_list += left[l:]
        new_list += right[r:]
        return new_list
    '''
    def merge(self, left, right):
        l = r = index = 0
        nl, nr = len(left), len(right)
        new_list = [0]*(nl+nr)
        while l < nl and r < nr:
            if left[l] <= right[r]:
                new_list[index] = left[l]
                l += 1
            else:
                new_list[index] = right[r]
                r += 1
            index += 1
        if l == nl:
            for i in range(r, nr):
                new_list[i+nl] = right[i]
        else:
            for i in range(l, nl):
                new_list[i+nr] = left[i]
        return new_list
    
    def merge_recursion(self, list_exam):
        n = len(list_exam)//2
        if n < 1:
            return list_exam
        else:
            left = self.merge_recursion(list_exam[:n])
            right = self.merge_recursion(list_exam[n:])
            return self.merge(left, right)
        
    def merge_non_recursion(self, list_exam):
        i, n = 1, len(list_exam)
        while i < n:
            l, m, h = 0, i, 2*i
            while h <= n:
                list_exam[l:h] = self.merge(list_exam[l:m], list_exam[m:h])
                # 一截一截排序
                l, m, h = h, h+i, h+2*i
            # 完整的左侧 + 不完整的右侧
            # if m < n 意思是右侧的个数为 (m-l)+(n-m), 即大于间隔的一半
            # 此时需要合并，是为了保证这部分的有序性，防止后续合并时出错
            # 如果右侧部分小于等于间隔的一半，则不需要此次迭代中合并，因为已经有序
            # 为什么已经有序呢？可以用倒推法，假设当前时刻前中段为 A，中后段为 B，左侧部分为 A+B，右侧部分为 C
            # 如果 C 小于左侧间隔一半，即小于 A 和 B，那么总会在前第 N 个时刻大于等于左侧一半。故总会有序
            if m < n:
                list_exam[l:n] = self.merge(list_exam[l:m], list_exam[m:n])
            i *= 2
        return list_exam