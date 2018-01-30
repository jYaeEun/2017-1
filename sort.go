package main
import "fmt"
import "math/rand"
import "time"
import "sort"

func main(){

var a [200]int
var b [200]int
var a_sort2 [200]int
var b_sort2 [200]int

println("a value")

for  i:= 0;i<200;i++ { 
  a[i] = rand.Intn(2000)
        fmt.Print(a[i]," ")  
        }

println("\nb value")
for j:= 0;j<200;j++{
  b[j] = rand.Intn(2000)
        fmt.Print(b[j]," ")
	}

a_sort2=a
b_sort2=b

fmt.Println()
startTime:=time.Now()

var c []int
var c_sort2 []int
c_sort2=c

for index, _ := range a{
                 c= append(c,a[index])
         }

for index, _ := range b {
                 c = append(c, b[index])
         }

for o := 0;o<len(c)-1;o++{
   for s := 0;s<len(c)-1-o;s++{
      if c[s] > c[s+1] { 
          c[s],c[s+1] = c[s+1],c[s] }
   }
}

elapsedTime := time.Since(startTime)
fmt.Printf("This is the time it takes to rearrange the numbers in the list combined by bubble sort: %s\n", elapsedTime)

startTime2 := time.Now()
for index, _ := range a_sort2{
                 c_sort2= append(c_sort2,a_sort2[index])
         }

for index, _ := range b_sort2 {
                 c_sort2 = append(c_sort2, b_sort2[index])
         }
sort.Ints(c_sort2)
elapsedTime2 := time.Since(startTime2)
fmt.Printf("measured time when using sort function: %s\n", elapsedTime2)

print("\noverlap\n")
n := 1
for j := 0;j < len(c)-1; j++{
    if c[j] == c[j+1] 
	{n=n+1}
    else {
	if n>=2 { 
            fmt.Print(c[j]," ",n," ") 
            n=1}}      
    }
         






