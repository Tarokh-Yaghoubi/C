
# Indexing Pointers , C programming , Herbert Shieldt 
### Tarokh Yaghoubi - Jacob , Chapter 4

```	

					Herbert Shieldt , C programming , Indexing Pointers (Arrays , Chapter 4)

					Tarokh Yaghoubi , Jacob

```
```


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


```
```

		This same concept also applies to arrays of two or more dimensions. For example, assuming that a is
		a 10-by-10 integer array, these two statements are equivalent:

		a == &a[0][0]

		Furthermore, the 0,4 element of a may be referenced two ways: either by array indexing, a[0][4] , or
		by the pointer, *((int *)a+4). Similarly, element 1,2 is either a[1][2] or *((int *)a+12). In general,
		for any Two-Dimensional array:
		a[j][k] is equivalent to *((base type *)a+(j *row length)
		+k)

		The cast of the pointer to the array into a pointer of its base type is necessary in order for the pointer
		arithmetic to operate properly. Pointers are sometimes used to access arrays because pointer
		arithmetic is often faster than array indexing.


		
		{ char str[9] = "I like C"; } is the same as { char str[9] = {'I', ' ', 'l', 'i', 'k', 'e',' ', 'C', '\0'};	}

```
```

		Because strings end with a null, you must make sure that the array you declare is long enough to
		include the null. This is why str is nine characters long even though "I like C" is only eight. When
		you use the string constant, the compiler automatically supplies the null terminator

```
```

		int sqrs[10] [2] = {
		
			1, 1,
			2, 4,
			3, 9,
			4, 16,
			5, 25,
			6, 36,
			7, 49,
			8, 64,
			9, 81,
			10, 100
		
		}

		When initializing a multidimensional array, you may add braces around the initializers for each
		dimension. This is called subaggregate grouping. For example, here is another way to write the
		preceding declaration :

		int sqrs[10] [2] = {
			
			{1, 1},
			{2, 4},
			{3, 9},
			{4, 16},
			{5, 25},
			{6, 36},
			{7, 49},
			{8, 64},
			{9, 81},
			{10, 100}

		}

```