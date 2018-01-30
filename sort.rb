a = [*1..1000].sample(200)
b = [*1..1000].sample(150)

a_sort2 = a
b_sort2 = b

puts"a\n"
puts a

puts"\nb\n"
puts b

start = Time.now

c= a.concat(b)
for k in 0..c.size-1 
   for l in 0..c.size-2-k
        if (c[l]>c[l+1]) then
	c[l],c[l+1] = c[l+1],c[l] 
	           
      end   
   end
end
finish = Time.now

puts"\nc\n"
puts c
puts("This is the time it takes to rearrange the numbers in the list combined by bubble sort. ")
puts(finish-start)

puts"\nc_sort2\n"
start = Time.now

c_sort2 = a_sort2.concat(b_sort2)
puts c_sort2.sort

finish = Time.now

puts("measured time when using sort function.")
puts(finish-start)

puts "\noverlap\n"
n = 1
for j in 0..c.size-1 do
    if c[j] == c[j+1] then 
	n=n+1 
    else 
	if n>=2 then 
            puts c[j]
	    puts" "
	    puts n
	    puts" " 
            n=1
         end
    end
end                                     


 