# -*- coding: utf-8 -*-
"""
Created on Sat Nov  7 11:44:47 2020

@author: AhrensJH

Euler Problem 30

Surprisingly there are only three numbers that can be written as the sum of 
fourth powers of their digits:
                1634 = 14 + 64 + 34 + 44
                8208 = 84 + 24 + 04 + 84
                9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers 
of their digits.

From <https://projecteuler.net/problem=30> 

"""
from time import time
import numpy as np

start = time()

m = 5
digSumSum = 0
maxDigit = int(1E7)
maxOrder = int(np.log10(maxDigit))
for k in range(2, maxDigit+1):    
    digSum = 0
    orderRes = np.log10(k)%int(np.log10(k))
    if orderRes < np.finfo(np.float32).eps:
        print("k = ", k)
    for n in range(1, maxOrder):
        dig=int(k%(10**n)/(10**(n-1)))
        digSum += dig**m
    
    if k==digSum:
        print("Digit Sum = ", k)
        digSumSum += k 
    
print(digSumSum)
print(time()-start)