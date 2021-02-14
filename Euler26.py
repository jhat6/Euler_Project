# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 19:01:11 2020

@author: jeffa
"""
import time
from decimal import *
getcontext().prec = 100



max_count = 0
for d in range(17, 18):
    count = 0
    if d > 10: 
        start = 2
    elif d > 100:
        start = 3
    else: 
        start = 1
    for k in range(start, 100):
        num = int(10**k/d)
        remainder = (10**k)%d
        if k == start:
            init_remainder = remainder
            count += 1
        else:
            print(k, num, remainder)
            if (num >0) & ((remainder == init_remainder) | (remainder ==0)):
                break
            count += 1
        
    if count > max_count:
        max_count = count
        max_num = d
    print("\n")
print("\n", max_count, max_num)
