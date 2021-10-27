/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


int x = 0;

void begin(int a){
  x++;
  printf("running %d seconds\n", x);
	alarm(1);
}

void end(int a){
  printf("%d seconds\n", x);
  exit(0);
}


int main(int argc, char * argv[]){ 
	
	signal(SIGALRM, begin);
	signal(SIGINT, end);
	
	
	alarm(1);
	while(1);
	
  
  return 0; //never reached
}