/*
	.;t.;;.t;.t::t::t.;t.;t.;;.t;.t::t::t.;t.;t.;;.t;.t::t::t.;t
	;::;::t::;:;;:;;:;;.t::;:S8Xt.tt%8X;:;;.t::;::t::;:;;:;;:;;.
	:;;:;;:;;:;::;::;:;8.8:8:.         :8:@:@;;:;;:;;:;::;::;:;;
	:;;:;;:;::;;:;;t: 8  ;t % S888 .8%:tS:X  8 ;%;:;::;;:;;:;::;
	t::t::t.;t.;;8%;:;.t8:;:::t.@  XX.;;:t;S: 8 ; 8::t.;;:;;.t;.
	.;;.;;.t;.ttt .::;;t.;;.;;.@..   t::t.:t..tS X % .t::t::t.;t
	t::t::t.:X; . 8;:;;.t::t::S8.    %;;:;;.t::; %8t.S@;;.;;:;;.
	:;;:;;:t@.  @.:;;:;;:;;:;;S      .@:;:;;:;;:;;:;8::@t;:;;::;
	:;::;:@@ X::;;::;::;:;::;        .@S;:;;:;:;:;:;:8S 88;:;:;;
	;;:;:8@ %@:;;:;;:;;:;;:tS          :t;::;::;::t::t:X S@;:;;.
	.;;:8S  t.t:.t::t::t.;;t:           S.;t.;t.;;.t;.t:S ;8;::t
	t::X8 :t:t.;t.;;.;;.t:;;            %;.t::t::t.:t.;;X.8S;;.
	:;; .@S;;:;::;::t::;:; .    88.      .%;:;;:;;:;;:;;:;.  :;;
	;:S..::;:;;;:;;;:;;;:%.               t8;:;:;:;:;:;:;;X;.t;:
	;;. t%;::;::;:;;:;:: ..              ..8@;:;::;:;;:;;::8 t%:
	.X. %;.t;.t;.t::t.;t:.                  @%t.;;:;;.t:.t:X .8t
	t. .%:t.:t.;t.;;.t8S.                    :;t::t::t.;t.;;@ :.
	:8 @;;:;;:;::;::tX8         S: X            ;;:;;:;::;:: .8t
	;@ 8::;:;;:;;:;;S8        :%t;::8t        .8:;::;:;;;:;:@ %:
	;8 8:;;::;:;;:;%X        .t::;:;;%t         S:;:;;::;:;; .8:
	.. .%;.t;.t::t;:           t;.t::t8.        . :;;.t::t:.t tt
	t@..;:t.:t.;;. .         :t.:t.;t.;%     :X@::t.:t.;;.;X: 8:
	::t .;:;;:;;:%.          X.t;:;::t; .    . 88:@X;:;;:t:t X;;
	;;.. @;:;;:;8             ;::;:;;:::         . @:;:;;:%@ .;:
	;:;: @t::;:X        .8 8 @;:;;:;:;;t% :;.    .  .@:;::@ ;t:;
	:;;XX S;;:;     ::8;t:;:;;:;;:;;:;:::.;;8t 8.    8S::  t8:;;
	t::tX;.8;..  8@t:t;.t::t::t.:t.;;.;;.t;.t: t8%::  tX.:;X.t:.
	.;;.;X;..:t8@t::t::t.;;.;;.t;.t::t::t::t.;;.;t:%. %S:tX:t::t
	;;:;::88 88;;:;;:;;:;;:;:;;::;:;;:;;:;;:;;:;::;::t :88:;:;;:
	;:;;;;;% .:Xt:;:;:;:;:;;:;:;;;:;:;:;:;:;:;:;;;:;.8: %:;:;:;:
	:;;::;:::S8 @%t:;::;:;;:;;:;::;::;::;::;:;;:;;;S 8:::;::;::t
	t:.t::t::t.:8 S@8;;.t::t::t.;t.;t.;t.t;.t::@X8 8;%.;;.;;.t;.
	.;t.;;.t;.t::: ..88t:;;.;;.t;.t::t::t.:t8Xt .::t;.t::t::t.:t
	;;:;::t::;:;;:;X; ;.;% %t8X::;:;;;8%:@:t.:;SX;;::;:;;:;;:;;:
	:;:;;;:;:;;::;:;;::@S t;.  .;@S;;.  %@ ;@;t:;:;;;:;:;:;:;:;;
	:;;:;::;;:;;:;::;::;::;:%8S: .:.:t8t;:.;:;;:;;:;::;;:;:;;::;
	t::;::t::t.;;:;;.t;.t::t::t::t:;;.;;.t;.t::t::;::t.;;:;;.t;.
*/

/*/////////////////////////////////////////////////////////////
**    Tarokh Yaghoubi (Jacob)                                 **
**    RelationShip BetWeen FileDescriptors and OpenFiles      **
**    C Programming Language, 				      **
**    The Linux Programming Interface			      **
*//////////////////////////////////////////////////////////////

/*
** You might think that there is a one-to-one correspondence between a file descriptor 
** and an open file , However ; this is not the case , It is possible and useful to have 
** multiple file descriptors referring to the same open file . These file descriptors 
** may be open in the same process or in different processes . 
*/

/*
** To understand what is going on , we need to examine three data structures maintained by the KERNEL :
**    - The per-process file descriptor table 
**    - The system-wide table of open file descriptors 
**    - The File system i-node table .
*/

/*
**      For each process, the KERNEL maintains a table of open file descriptors . Each entry in this table 
**      records information about a single file descriptor, including :
**              - A set of flags controlling the operation of the file descriptor (there is only one such 
**		flag, the close-on-exec flag) .
**		- A reference to the open file description 
**
*/

/* The KERNEL maintains a system-wide table of all open file descriptions. This table is sometimes referred
   to as the open file table . and its entries are sometimes called open file handles .
   An open file description stores all information relating to an open file , Including :
       - The current file offset (as updated by read() and write() or explicitly modified using lseek());
       - Status flags specified when opening the file (i.e, the flags argument to open());
       - The file access mode , (read-only, write-only or read-write, as specified in open());
       - Settings relating to signal-driven I/O .
       - A reference to the i-node object for this file .
*/

/*
** Each file system has a table of i-nodes for all files residing in the file system. The i-node for each 
** file includes the following information :
**
**        - File Type (e.g, Regular File, Socket, or FIFO) and permissions;
**        - A pointer to a list of locks held on this file;
**        - Various properties of the file, including its size and timestamps relating to different types of 
**          file operations .
*/

/*
** Here we are overlooking the distinction between on-disk and in-memory representations of an i-node .
** The on-disk i-node records the persistent attributes of a file such as its type, permissions , and timestamps .
** When a file is accessed , and in-memory copy of the i-node is created, and this version of the i-node records 
** a count of the open file descriptions referring to the i-node and the major and minor ID's of the device from 
** which the i-node was copied . The in-memory i-node also records various ephermal attributes that are associated 
** with a file while it is open, such as <file locks> .
*/

// NOTE
/*
    (1)
    Two different file descriptors that refer to the same open file description share a file offset value 
    Therefor , if the file offset is changed via one file descriptor (as a consequence of calls to read(), write()
    or lseek()), this change is visible through the other file descriptor . This applies both when the two file 
    descriptors belong to the same process and when they belong to a different process . 

    (2)
    Similar scope rules apply when retrieving and changing the open file status flags (e.g, O_APPEND, O_ASYNC, ...)
    using fcntl() F_GETFL and F_SETFL operations .

    (3)
    By contrast, the file descriptor flags (the close-on-exec flag) are private to the process and file descriptor .
    Modifying these flags does not affect other file descriptors in the same process or a different process .

*/


