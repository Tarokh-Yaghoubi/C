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

	A pointer is a variable that holds a memory address . This address is the location of another object 
	(typically another variable) 
	in memory . if one variable is meant to keep the address of another variable , the first variable is 
	said to point to the second 


	A pointer variable is defined like : { data_type *name } - the type can be any data type 
	( int , float , char , double ..... )
	The name of the pointer variable is specified by name .

```

```

	The base type of the pointer defines the type of object to which the pointer will point. Technically, 
	any type of pointer can point anywhere in memory. However, all pointer operations are done relative 
	to the pointer's base type. For example, when you declare a pointer to be of type int *, the compiler 
	assumes that any address that it holds points to an integer whether it actually does or not. (That is, 
	an int * pointer always ''thinks" that it points to an int object, no matter what that piece of memory 
	actually contains.) Therefore, when you declare a pointer, you must make sure that its type is 
	compatible with the type of object to which you want to point .

```

<h1 color="blue">The Pointer Operators</h1>

```

	There are two pointer operators : * and & . The & is a unary operator that returns the memory address of 
	its operand. m = &count; -> keeps the internal address of variable count (it has nothing to do with its value)
	in pointer variable 'm'; you can think of & as return 'the address of' . therefor , we can say m = &count; as 
	" m recieves the address of count "

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

<h1 color="blue"> Pointer Conversion </h1>

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


<h1 color="blue">Pointers and Arrays in C programming</h1>

<span color="red">There is a close relationship between pointers and arrays</span>
<br />

```

	char str[80], *p1;
	p1 = str;

	here p1 has been set to the address of the first array element in str .	To access the fifth element in str , 
	you could write :
	str[4] ;	or	   *(p1 + 4) , you add 4 to p1 because p1 points to the first element of the array by default .
	so +4 means go 4 steps and now p1 is pointing at fifth index of the array 
	(we say fifth because array indexes start from 0)

```
<span color="red">note : You can use pointers in arrays instead of array indexes , Although the standard array-indexing notation is 
sometimes easier to understand, pointer arithmetic can be faster. Since speed is often a consideration 
in programming, C programmers often use pointers to access array elements. </span>

```
	These two versions of putstr() - one with array indexing and one with pointers illustrate how you 
	can use pointers in place of array indexing. The putstr() function writes a string to the standard 
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


<h1> Arrays of Pointers , in C programming </h1> 

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
<br />
<br />

<h1 color="blue">Multiple Indirection - Pointer to Pointer </h1>

```
	You can have a pointer to point to another pointer that points to the target value 
	this situation is called multiple indirection or pointers to pointers . Pointers to Pointers 
	can be confusing . As you can see, the value of a normal pointer is the
	address of the object that contains the desired value. In the case of a pointer to a pointer, the first
	pointer contains the address of the second pointer, which points to the object that contains the
	desired value.
```
```
	A variable that is a pointer to a pointer must be declared as such. You do this by placing an
	additional asterisk in front of the variable name. For example, the following declaration tells the
	compiler that newbalance is a pointer to a pointer of type float:
	
	float **newbalance;		
```
<h3 color="red"><b> You should understand that newbalance is not a pointer to a floating-point number but rather a pointer to a float pointer. </b></h3>

<h3 color="blue"> Single indirection (Pointer) : address -> value | Multiple Indirection (Pointer to pointer) : address -> address -> value </h3>
<hr />
<h3 color="red">Note : To access the target value indirectly pointed to by a pointer to a pointer, you must apply the asterisk operator twice, as in this example : </h3>

```
	include < stdio.h >
	int main(void)
	{
		int x, *p, **q;
		x = 10;
		p = &x;
		q = &p;
		printf("%d", **q); /* print the value of x */
		return 0;
	}
```

<h1 color="gray">Initializing Pointers</h1>

```
	After a nonstatic, local pointer is declared but before it has been assigned a value, it contains an
	unknown value. (Global and static local pointers are automatically initialized to null.) Should you
	try to use the pointer before giving it a valid value, you will probably crash your program and
	possibly your computer's operating system as well a very nasty type of error!


	There is an important convention that most C programmers follow when working with pointers: A
	pointer that does not currently point to a valid memory location is given the value null (which is
	zero). Null is used because C guarantees that no object will exist at the null address. Thus, any
	pointer that is null implies that it points to nothing and should not be used.

	One way to give pointer a null value is to assign zero to it , for example the following initializes p to null : 

	char *p = 0;

	also some headers like <stdio.h> provide statements such as NULL , which is a null pointer constant  , therefor you often
	see	a pointer assigned null using a statement such as this :	char *p = NULL;
```

```
	Because a null pointer is assumed to be unused, you can use the null pointer to make many of your
	pointer routines easier to code and more efficient. For example, you can use a null pointer to mark
	the end of a pointer array.
```

```
	
	A routine that accesses that array knows that it has reached the end when
	it encounters the null value. The search() function shown in the following program illustrates this
	type of approach. Given a list of names, search() determines whether a specified name is in that
	list .
```
```

	#include <stdio.h>
	#include <string.h>

	int search(char *p[], char *name);

	char *names[] = {
	
		"Herb",
		"Rex",
		"Dennis",
		"John ",
		NULL};		/* null pointer constant ends the list */

	int main(void)
	{

		if(search(names, "Dennis") != -1)
			printf("Dennis is in list.\n");

		if(search(names, "Bill") == -1)
			printf("Bill not found.\n");

	return 0;

	}

	/* Look up a name. */

	int search(char *p[], char *name)
	{

		register int t;

		for(t=0; p[t]; ++t)

		if(!strcmp(p[t], name)) return t;

		return -1;		/* not found */

	}

```
<h1 color="blue">What does (PC) Program Counter mean ? </h1>

```
	A program counter (PC) is a CPU register in the computer processor which has the address
	of the next instruction to be executed from memory. It is a digital counter needed for faster
	execution of tasks as well as for tracking the current execution poin

	All instructions as well as data in memory have a specific address. As each instruction is processed,
	the software application responsible updates the program counter with the upcoming instructions' address
	which needs to be fetched. 
	The program counter in turn passes this information to the memory address register as part of 
	the execution cycle/standard fetch.
	The program counter increases the stored value by one as the next instruction is fetched. 
	If the computer is reset or restarts, the program counter usually reverts to the value of zero.

```

<p color="red"><b> What's Heap Memory ?  In certain programming languages including C and Pascal , a heap is an area of pre-reserved computer main storage ( memory ) that a program process can use to store data in some variable amount that won't be known until the program is running </b></p>

```
	char *p = "Hello C programmers !";

	As you can see, p is a pointer, not an array. This raises a question: Where is the string constant
	"hello world" being held? Since p is not an array, it can't be stored in p. Yet,
	the string is obviously being stored somewhere. The answer to the question is found in the way C
	compilers handle string constants. The C compiler creates what is called a string table, which stores
	the string constants used by the program. Therefore, the preceding declaration statement places the
	address of "hello world", as stored in the string table, into the pointer p. Throughout a program, p
	can be used like any other string .

	for example the following program is perfectly valid : 

```
<br />

```

	#include "stdio.h"
	#include "string.h"

	char *p = "Hello C programmers";

	int main(void) {

		register int t;

		/* print the string forward and backwards */

		printf("%s\n", p);
		for (t=strlen(p) - 1; t > -1; t--) printf("%c ", p[t]);

		return 0;

	}

```

<h1 color="blue">Pointers to Functions</h1>

```
	A particularly confusing yet powerful feature of C is the function pointer. A function has a physical
	location in memory that can be assigned to a pointer. This address is the entry point of the function
	and it is the address used when the function is called. Once a pointer points to a function, 
	the function can be called through that pointer. Function pointers also allow functions to be
	passed as arguments to other functions.
	
	You obtain the address of a function by using the functions name without '()' Parantheses 
	(This is similar to the way an array's address is obtained when only the array name without indexes is used)


	take a look at this program , this program compares two strings together and it will print if they are 
	equal or not :


```
```
	#include "stdio.h"
	#include "string.h"

	/* a program that compares two strings together */

	void check(char* a, char* b, int (*cmp)(const char*, const char*));


	int main(void)
	{
		// Write your code here

		char s1[80], s2[80];
		int (*p)(const char*, const char*);		/* Function Pointer	*/

		p = strcmp;		/* assign the address of strcmp to p (p is pointer pointing to the address of strcmp)*/

		printf("Enter two strings : \n");
		gets(s1);
		gets(s2);

		check(s1, s2, p);

		return 0;
	}

	void check(char* a, char* b, int (*cmp)(const char*, const char*))
	{
		printf("testing for equality \n");
		if (!(*cmp)(a, b)) printf("Equal \n");
		else printf("Not Equal \n");
	}

```
<br />

<p color="red">Let's take a closer look at the program</p>

<h4> int (*p)(const char *, const char *); <br><br> This declaration tells the compiler that 'p' is a pointer to a function that has two const char * parameters
and return an int result <br> The parentheses around p are necessary in order for the
compiler to properly interpret this declaration. You must use a similar form <br> when declaring other
function pointers, although the return type and parameters of the function may differ .</h4>

<h4>Next, examine the check() function. It declares three parameters: two character pointers, a and b,
and one function pointer, cmp. Notice that the function pointer is declared using the same format as
was p inside main(). Thus, cmp is able to receive a pointer to a function that takes two 
const char * arguments and returns an int result. Like the declaration for p, 
the parentheses around the *cmp are necessary for the compiler to interpret this statement correctly.</h4>
<h4>When the program begins, it assigns p the address of strcmp(), the standard string comparison
function. Next, it prompts the user for two strings, and then it passes pointers to those strings along with p to check(),
which compares the strings for equality. Inside check(), the expression :</h4>
<p color="red">(*cmp)(a, b)</p>
<h4>This calls the function strcmp() , which is pointed to by 'cmp' , with the arguments {a , b} . The parentheses around
*cmp are necessary. This is one way to call a function through a pointer. A second, simpler syntax,
as shown here, can also be used : </h4>
<p color="red">cmp(a , b);</p>
<h4>The reason that you will frequently see the first style is that it tips off anyone reading your code that

a function is being called through a pointer (that is, that cmp is a function pointer, not the name of a
function). Also, the first style was the form originally specified by C.
</h4>
<p color="red">Note : You can call check by using strcmp() directly , as shown here : </p>
<p color="blue">check (s1, s2, strcmp) <br>This eliminates the need for an additional pointer variable, in this case.</p>
<h4>You may wonder why anyone would write a program like the one just shown. Obviously, nothing is
gained, and significant confusion is introduced. However, at times it is advantageous to pass
functions as parameters or to create an array of functions. For example, when an interpreter is
written, the parser (the part that processes expressions) often calls various support functions, such as
those that compute mathematical operations (sine, cosine, tangent, etc.), perform I/O, or access
system resources. Instead of having a large switch statement with all of these functions listed in it,
an array of function pointers can be created. In this approach, the proper function is selected by its
index.</h4>

<p color="red">Look at this example : </p>

```

	#include stdio.h
	#include ctype.h
	#include stdlib.h
	#include string.h
	
	void check(char *a, char *b,
	int (*cmp)(const char *, const char *));
	int compvalues(const char *a, const char *b);

	int main(void)
	{
		char s1[80], s2[80];
		printf ("Enter two values or two strings.\n");
		
		gets (s1);
		gets(s2);
		
		if(isdigit(*sl)) {

			printf(''Testing values for equality.\n");
			check(s1, s2, compvalues);
		}	
		
		else {
			printf("Testing strings for equality.\n");
			check(s1, s2, strcmp);
		}

	return 0;
	
	}

	void check(char *a, char *b,
	int (*cmp)(const char *, const char *))
	{
		if(!(*cmp)(a, b)) printf("Equal");
		else printf("Not Equal");
	
	}
	
	int compvalues(const char *a, const char *b)
	{
		if(atoi(a)==atoi(b)) return 0;
		else return 1;
	}

```
<h4>In this program, if you enter a string that begins with a digit, compvalues() is passed to check().
Otherwise, strcmp() is used. Since check() calls the function that it is passed, it can use a different
comparison function in different cases. Two sample program runs are shown here : </h4>

<p color="blue">Enter two values or two strings.<br>Test<br>Test<br>Testing strings for equality.</p>

<br>

<h1>Dynamic Memory Allocation in C</h1>
<h2 color="red">malloc() , calloc() , free() , realloc()</h2>
<p color="red">Since C is a structured language, it has some fixed rules for programming. One of them includes changing the size of an array. An array is a collection of items stored at contiguous memory locations.</p>
<h4>int nums[9]; <br>As it can be seen the length (size) of the array above is 9 But what if there is a requirement to change this length (size). For Example :</h4>

- **If there is a situation where only 5 elements are needed to be entered in this array. In this case, the remaining 4 indices are just wasting memory in this array. So there is a requirement to lessen the length (size) of the array from 9 to 5.**
- **Take another situation. In this, there is an array of 9 elements with all 9 indices filled. But there is a need to enter 3 more elements in this array. In this case, 3 indices more are required. So the length (size) of the array needs to be changed from 9 to 12.**
<br>
<p color="red">This procedure is referred to as <b>Dynamic Memory Allocation in C</b></p>
<h4>Therefor , C <b><i>Dynamic Memory Allocation</i></b> can be defined as a procedure in which the size of a data structure (like array) <br>
is changed during the runtime .</h4>
<h4>C provides some functions to achieve these tasks. There are 4 library functions provided by C defined under <b>"stdlib.h"</b> header file to facilitate dynamic memory allocation in C programming. They are: </h4>

- **malloc()**
- **calloc()**
- **free()**
- **realloc()**

<p color="red">Let's look at each one of them in detail :</p>

<h1 color="blue">C malloc() Method , Memory Allocation using malloc()</h1>
<h2 color="red">Malloc or Memory Allocation</h2>
<h4>The "malloc" or "memory allocation" method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially .</h4>

<p color="red"><b>Syntax :</b><br>ptr = (cast-type*)malloc(byte-size)<br><b>For Example:</b><br>ptr = (int*) malloc(100 * sizeof(int));</p>
<p>Since the size of int is 4 bytes , this statement will <b>allocate 400 bytes of memory</b> . And , the pointer <b>ptr</b> hold the address of the first byte in the allocated memory</p>
<p color="red"><b>Example :</b></p>

```
	#include 'stdio.h'
	#include 'stdlib.h'
  
	int main()
	{
  
		// This pointer will hold the
		// base address of the block created
		
		int* ptr;
		int n, i;
  
		// Get the number of elements for the array
		
		printf("Enter number of elements:");
		
		scanf("%d",&n);
		printf("Entered number of elements: %d\n", n);
  
		// Dynamically allocate memory using malloc()
		
		ptr = (int*)malloc(n * sizeof(int));
  
		// Check if the memory has been successfully
		// allocated by malloc or not
		
		if (ptr == NULL) {
			printf("Memory not allocated.\n");
			exit(0);
		}
		else {
  
			// Memory has been successfully allocated
			printf("Memory successfully allocated using malloc.\n");
  
			// Get the elements of the array
			for (i = 0; i < n; ++i) {
				ptr[i] = i + 1;
			}
  
			// Print the elements of the array
			printf("The elements of the array are: ");
			
			for (i = 0; i < n; ++i) {
				printf("%d, ", ptr[i]);
			}
		}
  
    return 0;
}

```

<p color="red"><b>OutPut :</b></p>

```
	Enter number of elements: 5
	Memory successfully allocated using malloc.
	The elements of the array are: 1, 2, 3, 4, 5,

```

<h1 color="red">Memory Allocation usign calloc</h1>

<p color="red">"calloc" or "contiguous allocation" method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar to malloc() but has two different points and these are: </p>

- **It initializes each block with a default value "0"**
- **It has two parameters or arguements as compared to malloc()**

<p color="blue"><b>Synax and Example : </b></p>

```
	ptr = (cast-type*)calloc(n, element-size);
	here, n is the no. of elements and element-size is the size of each element.

	Example :

	ptr = (float*) calloc(25, sizeof(float));
	This statement allocates contiguous space in memory for 25 elements each with the size of the float.

```

<p color="red"><b>An Example by calloc :</b></p>

```
	
	/* Dynamic Memory Allocation in C programming */
	// Tarokh Yaghoubi , Jacob 

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>

	int main()
	{
		int* ptr;
		int i, n;

		printf("Enter the number of elements : \n");

		scanf("%d", &n);

		printf("The number of elements is : %d \n", n);
	
		ptr = (int*)calloc(n, sizeof(int));

		if (ptr == NULL)
		{
			printf("Memory Not Allocated using calloc \n");
			exit(0);
		}
		else
		{

			printf("Memory is successfully allocated using calloc \n");

			for (i = 0; i < n; i++)
			{
				ptr[i] = i + 1;
			}

			printf("The elements of the array are : \n");

			for (i = 0; i < n; ++i)
				printf("%d ", ptr[i]);
		}

	return 0;

}

```

<p color="blue"><b>OutPut :</b>Enter number of elements: 5 <br>Memory successfully allocated using calloc.<br> The elements of the array are: 1, 2, 3, 4, 5,</p>

<h1 color="red">C free() method</h1>
<p color="red">free() is used to de-allocate memory</p>
<h4>The memory allocated using the functions malloc and calloc are not <b>de-allocated</b>on their own . Hence , free() is used whenever dynamc memory allocation takes place , it helps to reduce wastage of memory by freeing it .</h4>

<p color="blue"><b>Syntax :</b></p>

```
	free(ptr);
```

<p color="blue"><b>free() Example :</b></p>

```

	// How free() is used to reduce the wastage of memory after dynamic memory allocation
	// free the memory after allocation in C programming 

	// Tarokh Yaghoubi , Jacob 

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>

	int main()
	{

		int* ptr, * ptr1;

		int n, i;

		printf("Enter the number of elements : \n");
		scanf("%d", &n);
		printf("The number of elements is : %d \n", n);

		ptr = (int*)malloc(n * sizeof(int));
		ptr1 = (int*)calloc(n, sizeof(int));

		if (ptr == NULL || ptr1 == NULL)
		{
			printf("Memory not allocated \n");
			exit(0);
		}
		else
		{
			printf("Memory successfully allocated using calloc and malloc \n");

			for (i = 0; i < n; i++)
			{
				ptr[i] = i + 1;
				ptr1[i] = i + 1;
			}

			printf("The elements of the array allocated using malloc are : \n");
			for (i = 0; i < n; i++)
				printf("%d ", ptr[i]);

			printf("\n ------------ \n");

			printf("The elements of the array allocated using calloc are : \n");
			for (i = 0; i < n; i++)
				printf("%d ", ptr1[i]);

			printf(" \n ------------ \n");

			printf("free the memory allocated by malloc \n");
			free(ptr);
			printf("malloc memory is free \n");
			printf("free the memory allocated by calloc \n");
			free(ptr1);
			printf("calloc memory is free \n");

		}

	return 0;
	
	}	

```

<p color="blue"><b>Enter the number of elements : <br> 6 <br> The number of elements is : 6 <br> Memory successfully allocated using calloc and malloc <br>The elements of the array allocated using malloc are : 1 2 3 4 5 6 <br> ------------ <br> The elements of the array allocated using calloc are : 1 2 3 4 5 6 <br> ------------ <br> free the memory allocated by malloc <br> malloc memory is free <br> free the memory allocated by calloc <br> calloc memory is free</b></p>


<h1 color="red">Reallocate - realloc()</h1>
<p color="red"><b>"realloc" or "re-allocation" method in C is used to dynamically change the memory allocation of a previously allocated memory</b></p>

<h4>If the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically <b>re-allocate</b> memory. re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value</h4>

<p color="blue"><b>Syntax :</b></p>

```
	ptr = realloc(ptr, newSize);

	where ptr is reallocated with new size 'newSize'.

```

<p color="blue"><b>realloc() Example :</b></p>

```

	/* re-allocation in C programming , 

	Dynamically change the memory allocation of a previously allocated memory using malloc or calloc */

	// Tarokh Yaghoubi , Jacob 

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>

	int main()
	{
		// this pointer will hold the base address of the block created 

		int* ptr;
		int n, i;

		// Get the number of the elements for the array 

		n = 5;
		printf("Entered number of elements : %d \n", n);
	
		ptr = (int*)calloc(n, sizeof(int));
	
		if (ptr == NULL)
		{
			printf("Memory not allocated , \n");
			exit(0);
		}
		else
		{
			printf("Memory Successfully allocated using calloc \n");

			for (i = 0; i < n; i++)
			{
				ptr[i] = i + 1;
			}

			printf("The elements of the array are : \n");
			for (i = 0; i < n; i++)
				printf("%d ", ptr[i]);


			// Get the new size of the array for re-allocation 


			n = 10;

			ptr = realloc(ptr, n * sizeof(int));

			printf("\n Memory was successfully re-allocated \n");

			for (i = 5; i < n; i++)
				ptr[i] = i + 1;

			printf("The elements of the array are : \n");
			for (i = 0; i < n; i++)
				printf("%d ", ptr[i]);


			free(ptr);
		}


		return 0;

	}

```

- **Some Other Notes on Dynamic Memory Allocation**

<p color="red">If there is not enough memory to satisfy the <b>malloc()</b>request , an allocation failure occurs and malloc() return a <b>NULL</b></p>
<p color="blue">The code fragment shown here allocates 1000 bytes of contigous memory :</p>

```
	
	#include <stdlib.h>

	char* p;
	p = malloc(1000);	/* get 1000 bytes */

```

<p color="red">After assignment p points to the first 1000 bytes of free memory</p>
<p color="red">The Next Example allocates space for 50 integers  , Notice the use of <b>sizeof()</b> to ensure portability</p>

