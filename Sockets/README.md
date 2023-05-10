# What is Socket Programming ?
<hr />

```
	Socket programming is a way of connecting two nodes on a network to 
	communicate with each other .


	One socket (node) listens on a particular port at an IP , while the other
	socket reaches out to the other to form a connection .


```

## Socket Creation 

```
	int sockfd = socket(domain, type, protocol);

```

```
	* sockfd = socket file descriptor , an integer (Like a file-handle)
	* domain = integer , specifies communication domain . we use AF_LOCAL
	as defined in the POSIX standard for communication between processes on 
	the same host . for communication between processes on different hosts 
	connected by IPV4 we use AF_INET, and AF_INET6 for IPV6 .

	* type : Communication type :
		
		SOCK_STREAM : TCP, (reliable , connection-oriented)
		SOCK_DGRAM : UDP, (unreliable, connectionless)

	* protocol : Protocol value for internet protocol (IP), which is 0 . 

```

## Setsockopt

```
	int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen)

```

```
	This function helps in manipulating options for the socket referred by the
	file descriptor sockfd . 
	This is completely optional , but it helps in reuse of address and port .
	Prevents errors such as : "address in use" .
```

## Bind

```
	int bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

```

```
	After the creation of the socket , the bind functions binds the socket to the 
	address and port number specified in addr(custom data structure) . 
	when you want to bind the server to localhost , you use INADDR_ANY to the specify
	the ip address .

```

## Listen

```
	int listen(int sockfd, int backlog);

```

```
	It puts the server socket in a passive mode , where it waits for the client 
	to approach the server , the backlog defines the length to which the queue
	of pending connections for sockfd may grow .
	if a connection request arrives when the queue is full it may recieve an error
	with an indication of ECONNREFUSED .

```

## Accept

```
	int new_socket = accept(int sockfd, struct sockaddr *addr, socklen_t * addrlen);

```

```
	it extracts the first connections request on the queue of pending connections 
	for the listening socket , sockfd creates a new connected socket, and returns a new 
	file descriptor referring to that socket . at this point , the connections is 
	established between client and server, and they are ready to transfer data . 

```



# Stages for Client 

```
	* Socket Connection : Exactly same as that of servers socket creation 
	* Connect : The connect() system call connects the socket referred to by 
	the file descriptor sockfd to the address specified by addr . Servers address and 
	port is specified in addr . 


	int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

```
