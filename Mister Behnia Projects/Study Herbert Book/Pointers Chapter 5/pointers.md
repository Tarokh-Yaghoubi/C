<h1 color="blue"> Pointers in C programming , Herbert Shieldt Book </h1>
<h3> Tarokh Yaghoubi , Jacob </h3>


```

	The correct understanding and use of pointers is crucial to successful C programming. There are 
	several reasons for this: First, pointers provide the means by which functions can modify their 
	calling arguments. Second, pointers support dynamic allocation. Third, pointers can improve the 
	efficiency of certain routines.

```

- **Pointers provide support for dynamic data structures, such as binary trees and linked lists**
- **Pointers are one of the strongest but also one of the most dangerous features in C.**
- **A pointer containing an invalid value can cause your program to crash.**
- **It is easy to use pointers incorrectly, causing bugs that are very difficult to find.**

```

	A pointer is a variable that holds a memory address . This address is the location of another object (typically another variable) 
	in memory . if one variable is meant to keep the address of another variable , the first variable is said to point to the second 


	A pointer variable is defined like : { data_type *name } - the type can be any data type ( int , float , char , double ..... )
	The name of the pointer variable is specified by name .

```

```

	The base type of the pointer defines the type of object to which the pointer will point. Technically, 
	any type of pointer can point anywhere in memory. However, all pointer operations are done relative 
	to the pointer's base type. For example, when you declare a pointer to be of type int *, the compiler 
	assumes that any address that it holds points to an integer— whether it actually does or not. (That is, 
	an int * pointer always ''thinks" that it points to an int object, no matter what that piece of memory 
	actually contains.) Therefore, when you declare a pointer, you must make sure that its type is 
	compatible with the type of object to which you want to point .

```

<h2 color="blue">The Pointer Operators</h2>

```

	There are two pointer operators : * and & . The & is a unary operator that returns the memory address of its operand.
	m = &count; -> keeps the internal address of variable count (it has nothing to do with its value) in pointer variable 'm';
	you can think of & as return 'the address of' . therefor , we can say m = &count; as " m recieves the address of count "
	
	To understand the above assignment better, assume that the variable count uses memory location 
	2000 to store its value. Also assume that count has a value of 100. Then, after the preceding 
	assignment, m will have the value 2000 .
	
	The second pointer operator, *, is the complement of &. It is a unary operator that returns the value 
	located at the address that follows. For example, if m contains the memory address of the variable 
	count ->	q = *m;	-> this will place the value of count in 'q' . q will have the value 100 . because 100
	is stores in value 2000 which the memory address that was stored in 'm' . 

	You can think of * as "at address" , so you can read q = *m; as "q recieves the value at address m ";

```

- **Pointer Expressions** : ***In general, expressions involving pointers conform to the same rules as other expressions. This section examines a few special aspects of pointer expressions, such as assignments, conversions, and arithmetic***

<h2 color="red">Pointer Assignments</h2>
<p>You can use a pointer on the right-hand side of an assignment statement to assign its value to another pointer. When both pointers are the same type, the situation is straightforward.</p>

<h2 color="blue"> Pointer Conversion </h2>

```

	In C, it is permissible to assign a void * pointer to any other type of pointer. It is also permissible to 
	assign any other type of pointer to a void * pointer. A void * pointer is called a generic pointer. The 
	void * pointer is used to specify a pointer whose base type is unknown. The void * type allows a 
	function to specify a parameter that is capable of receiving any type of pointer argument without 
	reporting a type mismatch.

```
```

	The preceding example reinforces the rule stated earlier: Pointer operations are performed relative to 
	the base type of the pointer. While it is technically permissible for a pointer to point to some other 
	type of object, the pointer will still ''think" that it is pointing to an object of its base type. Thus, 
	pointer operations are governed by the type of the pointer, not the type of the object being pointed 
	to.

	One other pointer conversion is allowed: You can convert an integer into a pointer or a pointer into 
	an integer. However, you must use an explicit cast, and the result of such a conversion is 
	implementation defined and may result in undefined behavior. (A cast is not needed when 
	converting zero, which is the null pointer.)
```


<h2 color="blue">Pointers and Arrays in C programming</h2>

<span color="red">There is a close relationship between pointers and arrays</span>
<br />

```

	char str[80], *p1;
	p1 = str;

	here p1 has been set to the address of the first array element in str .	To access the fifth element in str , you could write :
	str[4] ;	or	   *(p1 + 4) , you add 4 to p1 because p1 points to the first element of the array by default . so +4 means go
	4 steps and now p1 is pointing at fifth index of the array (we say fifth because array indexes start from 0)

```
<span color="red">note : You can use pointers in arrays instead of array indexes , Although the standard array-indexing notation is 
sometimes easier to understand, pointer arithmetic can be faster. Since speed is often a consideration 
in programming, C programmers often use pointers to access array elements. </span>

```
	These two versions of putstr( )— one with array indexing and one with pointers— illustrate how you 
	can use pointers in place of array indexing. The putstr( ) function writes a string to the standard 
	output device one character at a time.

	/* Index s as an array. */

	void putstr(char *s)
	{
		register int t;
		for(t=0; s[t]; ++t) putchar(s[t]);
	}
		
	/* Access s as a pointer. */
		
	void putstr(char *s)
	{
		while(*s) putchar(*s++);
	}

	Most professional C programmers would find the second version easier to read and understand. 
	Depending upon the compiler, it might also be more efficient. In fact, the pointer version is the way 
	routines of this sort are commonly written in C

```

<br />
```
	

```

## Arrays of Pointers , in C programming 

<span color="red">Pointers can be arrayed like any other data type </span> 
<br />

```
	The decleration for an int pointer array of size 10 would be like : int *x[10];
	
	to assign the address of an integer called 'myvar' to the third element of the array

	write -> x[2] = &myvar; and to file the value of myvar , write printf("myvar value : [%d] \n", *x[2]);

```
<br />
<hr>

```
	If you want to pass an array of pointers into a function, you can use the same method that you use to 
	pass other arrays: Simply call the function with the array name without any subscripts. For example, 
	a function that can receive array x looks like this:

	void display_array(int *q[])
	{
	 	int t;
		for(t=0; t<10; t++)
		printf(''%d ", *q[t]);
	}

    
	Remember, q is not a pointer to integers, but rather a pointer to an array of pointers to integers. 
	Therefore you need to declare the parameter q as an array of integer pointers, as just shown. You 
	cannot declare q simply as an integer pointer because that is not what it is.

	note : As a point of interest, note that the command line argument argv is an array of character pointers .
```

