# Alfheim
This is my training of algorithm like data structure, search, sort, and so on.
Languages are C and C++.


--- Compare "insertion sort" "bubble sort" "selection sort" ---

1. Calculation speed of "insertion sort" depends on data's alignment but of others don't.
2. All of three sorts, alculation order is O(N**2).
3. "insertion sort" and "bubble sort" is stable, but "selection sort" is not.
   (Stable means that if the array has same numbers, they cannot be exchanged by sort.)

"shell sort":
This is updated selection sort. If data's alignment is almost orderd, this algorithm is faster than others, of course selection sort. In this algorithm, 'g' is data's distance. It is selected by number sequence "p_n+1 = 3*p_n + 1".
