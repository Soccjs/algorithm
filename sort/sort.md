**[Insertion](#insertion)**  

---

# Sort 

## Insertion

Basic principle :

 * 배열의 첫 번째 원소에서 시작하여 배열 전체를 훑으면서 가장 작은 키를 가지는 원소를 첫번째 원소와 맞바꾼다.
 * Best case : 리스트가 정렬되어 있을 때, O(n)
 > 정렬된 리스트에 새 원소를 추가할 때에는 삽입 정렬이 효율적.
 * Worst calse : 무작위로 정렬되어 있을 경우, O(n^2)
 * stable(안정적) , 제자리 정렬
 * 소량의 데이터에 적합
 	
Look, a list!
```
		5 3 1 2 4
step1 : 3 5 1 2 4

step2 : 3 1 5 2 4
		1 3 5 2 4

step3 : 1 3 2 5 4
		1 2 3 5 4
        
step4 : 1 2 3 4 5
```
And here's some code! :+1:

```python
def insertion( List ):
	for i in range(1, len(List) ) :
		for j in range(i, 0, -1) :
			if(List[j] < List[j-1]) :
				List[j], List[j-1] = List[j-1], List[j]

	return List

unsorted = [5, 3, 1, 2, 4]
print unsorted	#[5, 3, 1, 2, 4]

sorted = insertion(unsorted)
print sorted	#[1, 2, 3, 4, 5]
```

