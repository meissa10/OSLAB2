#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h> 

#define   MAX_COUNT  10

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     int  pid;
     int i;
     
 for (i = 0 ; i<2 ; i++){
   
     pid = fork();
     srand(time(0));
   
     if (pid == 0) {
       ChildProcess();
       
     }
          
     /*else if (pid >0){
          int status = wait(&status);
          printf("Child Pid: %d has completed", status);
     }*/
          
  
     else if (pid < 0){
       printf("Error in Fork\n");
     }
   
          
  }
  for (i = 0; i<2 ; i++){
    int status = wait(&status);
    printf("Child Pid: %d has completed\n\n", status);
  }
  
}

void  ChildProcess(void)
{
     int   i;
     
     int randomNum = (rand() % 30 + 1);

     for (i = 1; i <= randomNum; i++){
       int randomTime = (rand() % 10 + 1);
       pid_t child = getpid();
       pid_t parent = getppid();
       
       printf("Child Pid: %d is going to sleep!\n", child);
       sleep(randomTime);
       printf(" Child Pid: %d is awake!\n Where is my Parent: %d?\n", child, parent);
     }
  
     exit(0);
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent %d, value = %d\n",getpid(), i);
     printf("*** Parent is done ***\n");
}