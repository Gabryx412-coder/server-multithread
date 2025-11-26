#include<bits/stdc++.h>
// #include<studio.h>

#include<sys/types.h>
#include<sys/socket.h>
#include <unistd.h>
#include <stdarg.h>

#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include <sys/ioctl.h>
#include <sys/time.h>


#include<signal.h>
// #include<studio.h>
#include<stdlib.h>
#include<netdb.h>

#define SERVER_PORT 80 

#define MAX_LENGHT 4096 

#define SA struct sockaddr

using namespace std ; 


void error_and_kill(const char *fmt , ...) ;


void error_and_kill(const char *ch , ...){
    int error_save ;
    va_list ap;
    

    error_save = errno ; 
    
    va_start(ap , ch) ;
    vfprintf(stdout , ch , ap);
    fprintf(stdout , "\n");
    fflush(stdout);

    if ( error_save != 0  ){
        fprintf(stdout , "  ( error = %d ) : %s\n" , error_save , 
        strerror(error_save)) ;

        fprintf(stdout , "\n") ; 
        fflush(stdout) ; 
    }

    va_end(ap) ; 

    exit(1) ; 

}




int main(int identity , char ** argc){
    int  sockfd , n ; 
    int  sendbytes ; 
    struct sockaddr_in server_address ; 
    char   sendline[MAX_LENGHT] ; 
    char   receiveline[MAX_LENGHT] ; 



    if(identity != 2){
        error_and_kill("usage : %s < server_address>" , argc[0]) ; 
    }

    if(( sockfd  = socket(AF_INET , SOCK_STREAM , 0)   ) < 0){
        error_and_kill("Error while creating socket");
    }

    bzero( &server_address , sizeof(server_address)  ) ; 
    server_address.sin_family = AF_INET ; 
    server_address.sin_port = htons(SERVER_PORT) ; 

    if(inet_pton( AF_INET , argc[1] , &server_address.sin_addr ) <=0){
         error_and_kill("inet_pton error %s" , argc[1]);
    }



    if(connect(     sockfd , (SA *) &server_address , sizeof(server_address) ) < 0){
         error_and_kill("falied to connect server") ;
    }


    sprintf ( sendline , "GET / HTTP /1.1\r\n\r\n" ) ;
    sendbytes = strlen(sendline) ; 
    



     if( write(sockfd , sendline , sendbytes ) != sendbytes ){
         error_and_kill("write error");
     }
    memset(receiveline , 0 , MAX_LENGHT) ; 



    while ( ( n = read(sockfd , receiveline , MAX_LENGHT-1 ) ) > 0)
    {
        cout<<"serever sends following response"<<endl;
        printf("%s" ,receiveline );
    }

    if(n < 0){
        error_and_kill("read error") ; 
    }

    exit(0) ; 
    
}


