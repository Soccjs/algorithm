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
