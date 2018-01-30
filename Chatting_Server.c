
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

void error_handling(char *message);
void display();

#define MAXCLIENT (16)
int c_tcpSocket[MAXCLIENT];	// max 16 clients


int main(int argc, char **argv) {
	
  int tcpServ_sock;
  int c_s_num;//The socket number of the client making the connection request
  int a;
  int d_d = 0;//Number of connected clients
  struct sockaddr_in tcpServer_addr;
  struct sockaddr_in tcpClient_addr;

  // initialize the client socket descriptors
	int o = 0;  
	while(o < MAXCLIENT) {
  	c_tcpSocket[o] = -1;;	// max 128 clients
    o++;
  }

  
  
  socklen_t clint_len;
    
  fd_set reads, temps;
  int fd_max;

  char str[BUFSIZE];
  int option = 2;

  char *tcpport = NULL;

  if(argc != 2) {
    printf("Usage : %s <tcpport> \n", argv[0]);
    exit(1);
  }

  tcpport = argv[1];

  display();
	
  tcpServ_sock = socket(PF_INET, SOCK_STREAM, 0);
  
  if(tcpServ_sock == -1)
	  error_handling("socket() error");
  
  memset(&tcpServer_addr, 0 , sizeof(tcpServer_addr));
  tcpServer_addr.sin_family = AF_INET;
  tcpServer_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  tcpServer_addr.sin_port = htons(atoi(tcpport));

  clint_len = sizeof(tcpClient_addr);
  setsockopt(tcpServ_sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&option, sizeof(int));
  if( bind(tcpServ_sock, (struct sockaddr *) &tcpServer_addr, sizeof(tcpServer_addr)) == -1 )
	  error_handling("bind() error");
			
  if(listen(tcpServ_sock, 5)==-1)
    error_handling("listen() error");
  
  FD_ZERO(&reads);
  FD_SET(tcpServ_sock, &reads);
  fd_max = tcpServ_sock;
  clint_len = sizeof(tcpClient_addr);

  while(1) {
	int k =0;
	while(k<d_d){
    	if(fd_max< c_tcpSocket[k]) fd_max = c_tcpSocket[k];
  			k++; 
  }	
	int nfound = 0;
    temps = reads;
	    int t;
	for(t = 0; t<d_d; t++)	
		FD_SET(c_tcpSocket[t],&temps);
    	nfound = select(fd_max+1, &temps, 0, 0, NULL);
		
	if(FD_ISSET(tcpServ_sock, &temps)) {
		// Input from the client for new connection
		// This request will arrive after UDP sent
				
		c_s_num = accept(tcpServ_sock, (struct sockaddr *)&tcpClient_addr, &clint_len);
		c_tcpSocket[d_d++] = c_s_num;		
		printf("connection from host %s, port %d, socket %d slot %d\n",inet_ntoa(tcpClient_addr.sin_addr),ntohs(tcpClient_addr.sin_port), c_s_num,d_d-1);
		
		FD_CLR(tcpServ_sock, &temps);
		

	} else {
		int i;
		for(i = 0; i < MAXCLIENT; i++) {
		  if (FD_ISSET(c_tcpSocket[i], &temps)) {
			  /* process the data */
			  // forward the message to all the other sockets
		   a = recv(c_tcpSocket[i],str,BUFSIZE,0);
				
         if(a==0){
            printf("Connection closed %d\n", c_tcpSocket[i]);
			 close(c_tcpSocket[i]);			 
			if(i!=d_d-1){
					c_tcpSocket[i] = c_tcpSocket[d_d-1];}
			d_d--;			
			continue;}
      
			str[a] = '\0';	  
			int w;		
			for(w=0; w< d_d;w++){
                              if(i==w) 
								  continue;
                              send(c_tcpSocket[w], str, a, 0);
                        }	
			printf("%s",str);
		
         			
		}
	}
}
  }//while End
close(tcpServ_sock);

}//main End

void display() {
	
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  perror("error");
  exit(1);
}

