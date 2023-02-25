
# Indexing Pointers , C programming , Herbert Shieldt 
## Tarokh Yaghoubi - Jacob , Chapter 4

/*
		
		Herbert Shieldt , C programming , Indexing Pointers (Arrays , Chapter 4)

		Tarokh Yaghoubi , Jacob

*/

/*

		Pointers and arrays are closely related.
		As you know, an array name without an index is a pointer to
		the first element in the array

		char p[100];

		p == &p[0] -> these two are equals 

		An array name without an index , generates a pointer ! 

		int *p, number[10];
		p = numbers;

		p[5] = 12;		// assign using index  
		*(p + 5) = 12;	// asign using pointer arithmetic 


		This same concept also applies to arrays of two or more dimensions. For example, assuming that a is
		a 10-by-10 integer array, these two statements are equivalent:

		a == &a[0][0]
	
*/
