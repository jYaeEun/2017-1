
a = {}
io.write("a value\n")
math.randomseed(os.time())

for i = 1,500 do 
  a[i] = math.random(0,2000)
  io.write(a[i].." ")  
end

b = {}
print()
io.write("\nb value\n")
math.randomseed(os.time())

for j = 1,500 do
  b[j] = math.random(0,500)
  io.write(b[j].." ")
end

a_sort2 = a
b_sort2 = b
print()

start_time = os.time()

for k,v in ipairs(b) do
    table.insert(a,v)
end

for o = 1, #a do
   for s = 1, #a-o do
      if a[s] > a[s+1] then 
          a[s],a[s+1] = a[s+1],a[s] end
   end
end
end_time = os.time()

print()
print("This is the time it takes to rearrange the numbers in the list combined by bubble sort.".." "..end_time-start_time)
start = os.time()

for k,v in ipairs(b_sort2) do
    table.insert(a_sort2,v)
end
table.sort(a_sort2)
end_t= os.time()

print()
print("measured time when using sort function.".." "..end_t-start)
print()

print("sort value")
for i = 1,#a do 
  io.write(a[i].." ")  
end
print()
print("overlap")
n = 1
for j = 1,#a do
    if a[j] == a[j+1] then n=n+1 
    else if n>=2 then 
            io.write(a[j].." "..n.."¹ø ") 
            n=1
         end
    end
end                 




