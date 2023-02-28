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

<h2 style="text-align: center;">H3 that is center aligned</h2>