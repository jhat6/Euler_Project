# -*- coding: utf-8 -*-
"""
Created on Sun Feb 14 13:01:28 2021

Project Euler

Problem 34

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.


@author: jeffa
"""


from math import factorial as fac
from time import time

start = time()

sumOfAll = 0
m = 5
for n in range(3, 10**m):
    if n % 10**(m-1) < 1:
        print(10*n/10**(m-1),'% , ', time()-start)        
    nStr = str(n)
    facSum = 0
    for digit in range(len(nStr)):
        # compute the sum of the factorial of the digits in n
        facSum += fac(int(nStr[digit]))
        # print if factorial sum of n equals n
        
        if facSum == n:
            sumOfAll += n
            print(n, ',', sumOfAll)
            

print(time()-start)