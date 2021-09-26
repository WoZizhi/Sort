class Bubble:
    def bubble(self, list_exam):
        n = len(list_exam)
        for i in range(n-1):
            for j in range(n-i-1):
                if list_exam[j] > list_exam[j+1]:
                    list_exam[j], list_exam[j+1] = list_exam[j+1], list_exam[j]
        return list_exam
                    
    def bubble_optimization(self, list_exam):
        # 据说有网友美团面试挂在了冒泡优化上
        # 引入检测机制，当一轮冒泡下来发现没有任何数据交换时，直接输出最终结果
        n = len(list_exam)
        for i in range(n-1):
            exchange = False
            for j in range(n-i-1):
                if list_exam[j] > list_exam[j+1]:
                    list_exam[j], list_exam[j+1] = list_exam[j+1], list_exam[j]
                    exchange = True
            if not exchange:
                return
        return list_exam