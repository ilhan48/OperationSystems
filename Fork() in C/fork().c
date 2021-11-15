#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    int pid;
    pid = fork(); // fork-> parent has created child
    if (pid>0)
    {
        //parent   
        wait(NULL);
        printf("Parent: %d Parent pid: %d\n",pid,getpid());
    }
    if (pid == 0)
    {
        //child 
        printf("Child: %d Child pid: %d\n",pid,getpid()); 
    }
    if (pid<0)
    {
        //error
    }
    
    
    
}
