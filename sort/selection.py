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