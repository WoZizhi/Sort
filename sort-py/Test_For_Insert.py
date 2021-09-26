from time import time, sleep
from functools import wraps

def logger(msg=None):
    '''
    该装饰器用于测试优化方法前后耗时
    '''
    def timer(func):
        @wraps(func)
        def wrapper(*args):
            start = time()
            func(*args)
            end = time()
            cost_time = end - start
            print("[{0:^25}] func run time:{1:>10.5f}s".format(msg, cost_time))
        return wrapper
    return timer

@logger('insert1')
def insert1(list_exam):
    n = len(list_exam)
    for i in range(1,n):
        for j in range(i-1,-1,-1):
            if list_exam[j+1] < list_exam[j]:
                list_exam[j+1], list_exam[j] = list_exam[j], list_exam[j+1]
            else:
                break
                
@logger('insert2')
def insert2(list_exam):
    n = len(list_exam)
    for i in range(1,n):
        pre_index, tmp = i-1, list_exam[i]
        while list_exam[pre_index] > tmp and pre_index >= 0:
            pre_index -= 1
        for j in range(i-1,pre_index,-1):
            list_exam[j+1] = list_exam[j]
        list_exam[pre_index+1] = tmp
        
@logger('insert_optimization')
def insert_optimization(list_exam):
    # 折半插入
    n = len(list_exam)
    for i in range(1,n):
        l, h = 0, i
        # 左闭右开
        while l < h:
            mid, tmp = (l+h)//2, list_exam[i]
            if tmp < list_exam[mid]:
                h = mid
            elif tmp > list_exam[mid]:
                l = mid+1
            else:
                l = mid
                break
        # 二分后，tmp 应该被插入到 l(low) 处
        for j in range(i-1,l-1,-1):
            list_exam[j+1] = list_exam[j]
        list_exam[l] = tmp
            
insert1(list(range(3000,-1,-1)))
insert2(list(range(3000,-1,-1)))
insert_optimization(list(range(3000,-1,-1)))