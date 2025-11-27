#include <iostream>
#include <cmath>
n = int(input("enter n: "))
a=1
b=1
p=1
for k in range(2, n + 1):
    an=math.sqrt(b+a)/5
    bn=2*b+5*a**2
    a,b=an,bn
    p*=a*b
print("P =", p)