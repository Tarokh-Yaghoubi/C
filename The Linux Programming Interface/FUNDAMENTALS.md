
# The Fundamental Concepts of Linux programming interface 

## These are some of the fundamental concepts :

- **The Core Operating System : Kernel**
- **The Shell**
- **Users and Groups**
- **Programs**
- **Processes**
- **Memory Mapping**
- **Interprocess Communication , (IPC)**
- **Signals**
- **Threads**
- **Realtime**

<br />

- ***Kernel***
```
	Kernel is the central software that manages and allocates computer resources such as : CPU, RAM and devices .
	note that it is possible to run programs on a computer without the presence of a kernel . 
	The Linux Kernel executable typically resides at the path /boot/vmlinuz 

	The Kernel Performs the following tasks : 

	- Process scheduling
	- Memory management
	- Provision of a file system
	- Creation and termination of processes
	- Access to devices
	- Networking
	- Provision of a system call application programming interface 

```
<br />

- ***The Shell***
```
	A shell is a special-purpose program designed to read commands typed by a user
	and execute appropriate programs in response to those commands. Such a pro-
	gram is sometimes known as a command interpreter.
	The term login shell is used to denote the process that is created to run a shell
	when the user first logs in.

	A number of important shells that have appeared over time : 
	
	- Bourn Shell (sh)
	- C Shell (csh)
	- Korn Shell (ksh)
	- Bourn Again Shell (Bash)
 
```
<br />

- ***Users and Groups***
```
	Each user on a system is uniquely identified, and users may belong to groups .

	Evey user of the system has a unique login name (username) and a corresponding numeric 
	user ID (UID) , for each user , these are defined by a line in the system password file . 
	/etc/passwd . this file includes the following additional information : 
	- Group ID 
	- Home Directory 
	- Login Shell : the name of the program to be executed to inrepret user commands . 

	the password of the user may also be included in the file in the hash format , btw the 
	password of the user may be stored in a seperated file due to security reasons . 
	the name of that file is : /etc/shadow, they call it ' shadow file ' .
	shadow file is readable only to the users that have the root privilege 

```
<br />

```
	For administrative purposes , for controlling access to files and other system resources 
	it is a good idea to organize users into groups . 

	Each groups is identified by a single line in the system group file , /etc/group 
	which includes the following information .

	- Group name 
	- Group ID 
	- User list


```

- **SUPER USER**

```
	SUPER USER has special privileges within the system . The superuser account has user ID 0 . 
	the SUPER USER normally has the login name ' root ' .
	on typical UNIX systems , the root user , or so called SUPERUSER can bypass all permission checks 
	in the system . 

```
<br />

- ***Programs***

```

	Programs usually exist in two forms , the first form is the source code . source-code 
	is the human-readable source that contains some sort of statements that are written in 
	a programming language such as C . to be executed  , the source code must be converted 
	to the second form : Binary Machine-language instructions that the machine can understand . 

	This contrasts with a script,  which is a text file containing commands to be directly 
	processes by a program such as shell or other commands interpreters . 

```
<br />

- ***Processes***

```

	A process is an instance of an executing program . When a program is executed , the kernel loads the 
	code of the program in the virtual memory , allocates space for program variables , and sets up kernel 
	book keeping data structures to record various information (such as process ID , Termination status, user ID's, and group ID's)
	about the process .
	From a KERNEL point of view , processes are the entities among which the kernel must share the various resources of the computer .
	For resources that are limited , such as memory , the KERNEL initially allocates some amount of the resource to the process 
	and adjusts this allocation over the lifetime of the process in response to the demands of the process and the overall system demand 
	for that resource . when the process terminates , all such resources are released for reuse by other processes . Other resources 
	such as the CPU and Network bandwidth , are renewable , but must be shared equitably among all processes .   

```

- **Process Memory Layout**

```
	A Process is logically divided into the following parts ,known as segments :
	
	- Text : The Instructions of the program .
	- Data : The static variables used by a program .
	- Heap : An area from which programs can dynamically allocate extra memory .
	- Stack : A Piece of memory that grows and shrinks as functions are called and return and that is used
	to allocate storage for local variables and function call linkage information 	A Process is logically divided into the following parts ,known as segments :
	
	- Text : The Instructions of the program .
	- Data : The static variables used by a program .
	- Heap : An area from which programs can dynamically allocate extra memory .
	- Stack : A Piece of memory that grows and shrinks as functions are called and return and that is used
	to allocate storage for local variables and function call linkage information . 

```

- **Process Creation and Program Execution**

```

	A process can ' create ' a new process using the fork() system call . The process that calls fork() is referred to as the parent process ,
	and the new process is referred to as the child process . The KERNEL creates the child process by making a duplicate of the parent process.
	The child inherits copies of the parents Data, Stack and Heap segments , which it may then modify independently of the parent's copies . 
	{ The program text , which is placed in memory marked as read-only , is shared by the two processes }


	The child process goes on either to execute a different set of functions in the same code as the parent , or , frequently , to use the 
	execve() system call to load and execute an entirely new program . An execve() call destroys the existing text, data, stack and heap segments 
	, replacing them with new segments based on the code of the new program . 

	Several related C library functions are layered on top of execve() , each providing a slightly different interface to the same funcionality ,
	all of these functions have names starting with the string 'exec' , and where the differences dont matter , we will use the notation exec to 
	refer generally to these functions . Be aware that there is not actual function with the name exec() . 
 

```

- **Process ID and Parent Process ID**

```

	Each process has a unique integer process identifier (PID) . Each process also has a parent process identifier (PPID) attribute .
	which identifies the process that requested kernel to create this process .

```

- **Process termination and Termination status**

```

	A Process can terminate in one of the two ways : by requesting its own termination using the exit() system call , or the related exit()
	library function  . Or being killed by the delivery of a signal . In either case , the process yields a " Termination Status ", A small
	non-negative integer value that is available 

```

