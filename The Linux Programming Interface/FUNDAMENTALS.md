
# The Fundamental Concepts of Linux programming interface 

## These are some of the fundamental concepts :

- **The Core Operating System : Kernel**
- **The Shell**
- **Users and Groups**
- **Programs**
- **Processes**
- **Memory Mapping**
- **Inter Process Communication , (IPC)**
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
	non-negative integer value that is available for inspection by the parent process using the wait() system call . In the case of a call to
	exit() , the process explicitly specifies it's own termination status . If a process is killed by a signal , the termination status is set 
	accordingly to the type of signal that caused the death of the process .

	- Sometimes we'll refer to the argument passed to exit() as the exit status of the process , as distinct from the termination status , which is 
	either the value passed to exit() , or an indication of the signal that killed the process . 

	- The termination status of 0 indicates that the process succeeded , and a nonzero status indicates that some error occured  .
	
```

- **Process User and Group Identifiers**

```

	Each process has a number of associates user ID's (UID's) and group ID's (GID's).

	- Real User ID : The user to which the process belongs , A new process inherits this ID from it's parent .
	- Read Group ID : The group to which the process belongs , A new process inherits this ID from it's parent .
	
	note : a login shell takes it Real IDs from the corresponding fields in the system password file . 

	- Effective user ID and Effective group ID : These two ID's are used in determining the permissions that a process has 
	when accessing protected resources such as files and Inter process Communication (IPC) objects . 
	Typically , the processes Effective IDs have the same value as the corresponding real IDs . Changing the effective IDs is
	a mechanism that allows a process to assume the privileges of another user or group , as described in a moment . 

	- Supplementary group IDs : These IDs identify additional groups to which a process belongs . A new process inherits its
	supplementary group IDs from its parent . A login shell gets its supplementary group IDs from the system group file 

```

- **Privileged Processes**

```
	Traditionally , on UNIX systems , a privileged process is the one whose EFFECTIVE USER ID is 0 (SUPERUSER) . such a process bypasses 
	the permission restrictions normally applied by the KERNEL . By contrast , the term unprivileged or nonprivileged is applied to processes
	run by other users . Such processes have a nonzero effective user ID and must abide by the permission rules enforces by the KERNEL .

	A process may be privileged because it was created by another privileged process . for example by a login shell started by root (SUPERUSER) .
	Another way a process may become privileged is by the set-user-id mechanism . which allows a process to assume an effective usr ID that is the 
	same as the usr ID of the program file that is executing .  

```

- **The init Process**

```
	When booting the system , the KERNEL creates a special process called init , "the parent of ALL PROCESSES", which is derived from the the 
	program file /sbin/init . All processes on the system are created using fork() , either by init or by one of its decendants . 
	The init process always has the process ID 1 and runs with superuser privilege . The init process cant be killed (no even by the superuser) .

	init terminates only when the system is shutdown . The main task of init is to create and monitor a range of processes required by a running system .

```

- **Daemon Processes**

```
	A daemon is a special purpose process that is created and handled by the system in the same way as other processes, but which is distinguished by 
	the following characteristics :

	- It is Long-Lived : A Daemon Process is often started at system boot and remains in existence until the system is shutdown . 
	- It runs in the background : It has no controlling terminal from which it can read input or which it can write output . 


	Examples of Daemon Processes include syslog , which records messages in the system log , and httpd , which served web-pages via 
	The Hyper Text Transfer Protocol (HTTP) .

```

- **Environment List**

```
	Each Process has an environment list , which is a set of environment variables that are maintained within the user-space memory of the process 
	Each element of this list consists of a name and an associated value . when a process is created vie fork() , it inherits a copy of its parents 
	environment . The environment provides a mechanism for a parent process to communicate information to a child process . 
	 When a process replaces the program that it is running using exec(), the new
	program either inherits the environment used by the old program or receives a
	new environment specified as part of the exec() call.

	C programs can access the environment using an external variable (char **environ),
	and various library functions allow a process to retrieve and modify values in its
	environment.


	Environment variables are used for various purposes . for example , the shell defines and uses a range of variables that can be accessed by scripts 
	and programs executed from the shell . 

```

- **Resource Limit**

```
	Each process consumes resources , such as open files , memory and CPU time . using setrlimit() system call , a process can establish upper limits on 
	its consumption of various resources . Each resource limit has two values : a soft limit , which limits the amount of the resource that the process may 
	consume , and a hard limit , which is ceiling of the value to which the soft limits may be adjusted . An unprivileged process may change its soft limit 
	for a particular resource to any value in the range from zero up to the corresponding hard limit , but can only lower its hard limit . 

	when a new process is created with fork() , it inherits copies of its parents resource limit settings . 


```

<br />

- **Memmory Mappings**

```
	The mmap() system call creates a new memory mapping in the calling processes virtual address space .

	Mappings fall into two categories :

	- A "File Mapping" maps a region of a file into the calling processes virtual memory . Once mapped , the files contents can be accessed 
	by operations on the bytes in the corresponding memory regions . The pages of the mapping are automatically loaded from the file as required 


	- By contrast, an "Anonymous Mapping" does not have a corresponding file . Instead , the pages of the mapping are initialized to 0 .

	The memory in one processes mapping may be shared with mappings in other processes . This can occur either because two processes map
	the same region of a file or because a child process created by fork() inherits a mapping from its parent .

	when two or more processes share the same pages , each process may see the changes made by other processes to the contents of the page ,
	depending on whether the mapping is created as private or shared . when a mapping is private , modifications to the contents of the mapping 
	are not visible to other processes and are not carried through to the underlying file . 
	when a mapping is shared , modifications to the contents of the mapping are visible to other processes sharing the same mapping and are 
	carried through to the underlying file . 

	Memory Mappings serve a variety of purposes , including initialization of a process's text segment from the corresponding segment of an 
	executable file , allocation of new (zero-filled) memory , file I/O (memory-mapped I/O) , and Inter Process Communication (IPC) via a shared mapping .

```

- **Inter Process Communication and Synchronization**

```
	A running Linux system consists of numerous processes , many of which operate independently of each other . Some processes, however, 
	cooperate to achieve their intended purposes , and these processes need methods of communicating with one another and synchronizing 
	their actions . 
	One way for processes to communicate is by reading and writing information in disk files . However , for many applications , this is 
	too slow and inflexible . 

	Therefor, Linux, like all modern UNIX implementations , provides a rich set of mechanisms for Inter Process Communication (IPC) , including 
	the following :

	- signals : which are used to indicate that an event has occurred .
	- pipes : (familiar to shell users as | operator) and FIFOs, which can be used to transfer data between processes . 
	- sockets : which can be used to transfer data from one process to another , either on the same host computer 
	or on different hosts connected by a network .
	
	- file locking : which allows a process to lock regions of a file in order to prevent other processes from reading and updating  
	the file contents .
	- message queues : which are used to exchange messages (packets of data) between processes .
	- semaphores : which are used to synchronize the actions of processes .
	- shared memory : which allows two or more processes to share a piece of memory , when one process changes the content of the shared memory 
	all of the other processes can immediately see the changes .  


```

- **Signals**

```

	Signal is one of the IPC (Inter Process Communication) methods . 
	Signals are often described as "Software Interrupts" . The arrival of a signal informs a process that some event or exceptional condition has occured 
	There are various Types of Signals , Each of which identifies a different event or condition . Each signal type is identified by a different integer 
	Signals are Defined by a symbolic name of the form SIGxxxx . 

	Signals are sent to a process by the KERNEL , by another process (with suitable permissions), or by the process itself 
	(for example a process can terminate itself) . 

	We said that the KERNEL might sent a signal to a process . so these are some of the situations that KERNEL may send a signal to a process : 
	- The user typed the interrupt character (usually Ctrl+C) .
	- One of the process's children has terminated .
	- A timer (alarm clock) set by the process has expired .
	- The process has attempted to access an invalid memory address .
 

	Within the SHELL , the 'kill' command can be used to send a signal to a process , kill command used to be a murderer before (it could only kill a process) , but now 
	it can send many other signals . 
	The kill() system call provides the same facility within the programs . 

	When a process recieves a signal , it takes one of the following actions , depending of the signal :

	- It ignores the signal 
	- It is killed by the signal 
	- It is suspended until later being resumed by receipt of a special-purpose signal 

	For most signal types , instead of accepting the default signal action , a program can choose to ignore the signal (useful if the default action for the signal 
	is something other than being ignored ) , or to establish a "signal handler" . 
	A 'signal handler' is a programmer-defined function that is automatically invoked when the signal is delivered to the process . This functions permorms some action 
	appropriate to the condition that generated the signal . In the interval between the time it is generated and the time it is delivered , a signal is said to be 
	'pending' for a process . Normally , a pending signal is delivered as soon as the receiving process is next scheduled to run , or immediately if the process is 
	already running . However , it is also possible to "block" a signal by adding it to the process's 'signal mask' . if a process is generated while it is blocked ,
	it remains pending until it is later unblocked (i.e., removed from the 'signal mask').  

```
<br />

- **Threads**

```

	In modern UNIX implementations , each process can have multiple threads of execution , One way of envisaging threads is as a set of processes that share 
	the same virtual memory , as well as a range of other attributes , Each 'thread' is executing the same program code and shares the same data area and hip .
	However, each 'thread' has its own stack containing local variables and function call linkage information . Threads can communicate with each other via
	the global variables that they share .
	The threading API provides 'condition variables' and 'Mutexes', which are primitives that enable the threads of a process to communicate and synchronize 
	their actions , in particular , their use of shared variables .
	Threads can also communicate with one another using the IPC (Inter Process communication) and synchronization mechanisms described above .

	The primary advantages of using threads are that they make it easy to share data (via global variables) between cooperating threads and that some 
	algorithms transpose more naturally to a multithreaded implementation than to a multiprocess implementation . Furthermore , a multithreaded application 
	can transparently take advantage of possiblities for parallel processing on multiprocessero hardware .  

```
<br />

- **Realtime**

```
	'Realtime applications' are those that need to respond in a timely fashion to input . Frequently , such input comes from an external sensor or a specialized 
	input device , and output takes the form of controlling some external hardware . Examples of applications with 'realtime' resonse requirements include automated 
	assembly line , Bank ATMs , and Aircraft Navigation Systems . Although many realtime applications require rapid responses to input , the defining factor is 
	that the response guaranteed to be delivered within a certain deadline time after the triggering event . 

	The provision of realtime responsiveness , specially where short response times are demanded , requires support from 'the underlying operating system' .
	Most operating systems do not natively provide such support because the requirements of realtime responsiveness can conflict with the requirements of 
	multiuser time sharing operating systems . Traditional UNIX implementations are not realtime operating systems (RTOS) , although realtime variants have been devised .

	Realtime variants of Linux have also been created , and recent Linux KERNELs are moving toward full native support for realtime applications . 

	POSIX.1b defined a number of extensions to POSIX.1 for the support of realtime applications. These include asynchronous I/O, shared memory, memory-mapped files, 
	memory locking, realtime clocks and timers, alternative scheduling policies, realtime signals, message queues, and semaphores.

```
