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