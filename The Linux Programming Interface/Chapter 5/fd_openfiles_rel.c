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
	;;:;:8@ %@:;;:;;:;;:;;:tS;..       :t;::;::;::t::t:X S@;:;;.
	.;;:8S  t.t:.t::t::t.;;t:XS         S.;t.;t.;;.t;.t:S ;8;::t
	t::X8 :t:t.;t.;;.;;.t:;; @8@@        %;.t::t::t.:t.;;X.8S;;.
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
