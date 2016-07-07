## Sort 

  1. [Insertion(삽입정렬)](#Insertion)
  1. [Selection(선택정렬)](#Selection)

---
  

## Insertion(삽입정렬)

Basic principle :

 * 한 번에 한 원소씩 이미 정렬된 다른 언소들과 비교하여 새 원소를 제 위치에 삽입 하는 방식.
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
**[⬆ back to top](#Sort)**

## Selection(선택정렬)

Basic principle :

 * 배열의 첫 번째 원소에서 시작하여 배열 전체를 훑으면서 가장 작은 키를 가지는 원소를 첫번째 원소와 맞바꾼다.
 * Bestcase, Avgcase, Worstcase 모두 O(n^2) : 비교횟수가 n-1, n-2, ... , 1 번 총 n(n-1)/2번 이므로.
 * 장점은 원소간 자리부꿈 횟수가 최대 n-1 번
 * stable, 제자리 정렬
 * 데이터를 비교하는 것 비용보다 원소를 더 적게 이동해야 하는 경우라면 권장
Look, a list!
```
		5 3 1 2 4
step1 : 1 3 5 2 4

step2 : 1 2 5 3 4
		
step3 : 1 2 3 5 4
		
step4 : 1 2 3 4 5
```
And here's some code! :+1:

```python
def selection( List ):
	start = 0
	for cnt in range(1, len(List)) :
		minMember = List[start]
		minPos = start
		for i in range(start+1, len(List)) :
			if(minMember > List[i]) :
				minMember = List[i]
				minPos = i
		List[start], List[minPos] = List[minPos], List[start]

		start = start + 1

	return List

unsorted = [5, 3, 1, 2, 4]
print unsorted	#[5, 3, 1, 2, 4]

sorted = selection(unsorted)
print sorted	#[1, 2, 3, 4, 5]
```
**[⬆ back to top](#Sort)**

## Merge(합병정렬)

Basic principle :

 * 배열의 전체 원소를 하나의 단위로 분할한 후, 분할된 각각의 원소에 대해 비교하여 sorting 후 병합하는 방식.
 * 분할정복 기법(divide and conquer) 알고리즘의 하나. 
 * Worstcase 는 O(nlogn) 
 * W(n) = 2 * W(n/2) + (n-1)
 *   ...
 * W(n) = 2^k * W(n/2^k) + kn - (2^k - 1), n=2^k 일 때,
 * W(1) = 1
 * W(n) = log n + nlog n - (log n - 1) = nlog n
 * stable O, 제자리 정렬 X
 * 데이터의 양이 많을수록 효과적 
 
 Look, a list!
```
					[5, 4, 1, 8, 7, 2, 6, 3]
step1 (divide):   [5, 4, 1, 8]	  [7, 2, 6, 3] 
				 [5, 4]  [1, 8]	 [7, 2]  [6, 3]
				[5] [4] [1] [8] [7] [2]	[6] [3]
step2 (conquer): [4, 5]  [1, 8]  [2, 7]  [3, 6]
				  [1, 4, 5, 8]    [2, 3, 6, 7]
				  	[1, 2, 3, 4, 5, 6, 7, 8]
		
```
And here's some code! :+1:

```python
def mergesort( List ) :
	lenList = len( List )
	if(lenList <= 1) : 
		return List
	
	ListA = mergesort( List[0:lenList/2] )
	ListB = mergesort( List[lenList/2:lenList] )

	ListC = []
	i = 0
	j = 0
	k = 0

	while i<len(ListA) and j<len(ListB) :
		if ListA[i]>ListB[j] : 
			ListC.append(ListB[j])
			j += 1
		else :
			ListC.append(ListA[i])
			i += 1
	ListC += (ListA[i:] + ListB[j:])
	
	return ListC


unsorted = [5, 4, 1, 8, 7, 2, 6, 3]
print unsorted	#[5, 4, 1, 8, 7, 2, 6, 3]

sorted = mergesort(unsorted)
print sorted #[1, 2, 3, 4, 5, 6, 7, 8]
```
**[⬆ back to top](#Sort)**
