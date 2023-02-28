# Pointers in C programming , Herbert Shieldt Book
## Tarokh Yaghoubi , Jacob


```

	The correct understanding and use of pointers is crucial to successful C programming. There are 
	several reasons for this: First, pointers provide the means by which functions can modify their 
	calling arguments. Second, pointers support dynamic allocation. Third, pointers can improve the 
	efficiency of certain routines.

```
- **pointers provide support for dynamic data structures, such as binary trees and linked lists**
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

<h2>The Pointer Operators</h2>

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

<h2>Pointer Assignments</h2>
<p>You can use a pointer on the right-hand side of an assignment statement to assign its value to another pointer. When both pointers are the same type, the situation is straightforward.</p>