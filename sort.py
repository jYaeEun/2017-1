
import time
import random
a=[]
b=[]
c=[]

a_sort2 = []
b_sort2 = []
c_sort2 = []

n = int(input())

a = [random.randint(1,2000) for i in range(n)]
b = [random.randint(1,2000) for j in range(n*10)]
a_sort2 = a
b_sort2 = b

print("a")
print(a)
print("b")
print(b)

start = time.time()

c=a+b
for d in range(0,len(c)-1):
    for u in range(0,len(c)-1-d):
        if c[u]>c[u+1]:
            c[u],c[u+1] = c[u+1],c[u]

end = time.time()

print("This is the time it takes to rearrange the numbers in the list combined by bubble sort.")
print(end-start)
print(c)
start = time.time()
c_sort2 = a_sort2+b_sort2
c_sort2.sort()
end = time.time()
print("measured time when using sort function.")
print(end-start)
print(c_sort2)


print("overlap count,print")
n = 1
for ci in range(0,len(c)-1):
    if c[ci] == c[ci+1]:
        n = n+1
    else:
        if n>=2:
            print(c[ci],n)
            n=1


