# -*- coding: utf-8 -*-
"""
Created on Sun May 17 12:45:27 2020

@author: jeffa

Project Euler Problem 25
https://projecteuler.net/problem=25

"""
import time
from math import log10

start = time.time()

Fn2 = int(1)
Fn1 = int(1)
index = int(2)
expo = 0
while expo < 999:
    F = Fn1 + Fn2
    expo = int(log10(F))
    index += 1
    if index%1E5 < 1:        
        print("{:2E}".format(index), expo)
    Fn2 = Fn1
    Fn1 = F
    
print(time.time() - start)
print("{:2E}".format(index), expo)