#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int parent(int pid1, int pid2){
    wait(NULL);
    char fileName1[20];
    sprintf(fileName1,"%d.txt",pid1);
    char fileName2[20];
    sprintf(fileName2,"%d.txt",pid2);
    char fileName3[20];
    sprintf(fileName3,"%d.txt",getpid());
    FILE *fp1, *fp2, *fp3;
    fp1 =fopen(fileName1, "r");
    fp2 =fopen(fileName2, "r");
    int left,right;
    fscanf(fp1, "%d", &left);
    fscanf(fp2, "%d", &right);
    fclose(fp1);
    fclose(fp2);
    fp3 = fopen(fileName3, "w");
    fprintf(fp3, "%d", left + right);
    fclose(fp3);
}


void leafNode(){
    char fileName[20];
    sprintf(fileName,"%d.txt",getpid());
    FILE *fp =fopen(fileName,"w");
    srand(getpid());
    fprintf(fp,"%d",(rand()%100));
    fclose(fp);
}
void makeTree(int height){
    if(height == 0){ 
        leafNode();
        return;
        
    }
    int pid1 = fork(); //create child
    if(pid1 > 0){ // parent
        int pid2 = fork();
        if(pid2>0){
            wait(NULL);
            printf("parent : %d, child1 : %d, child2 : %d", getpid(), pid1, pid2);
            fflush(stdout);
            parent(pid1,pid2); 
        }
        else if (pid2 == 0){
            //left child
            makeTree(--height);
        }
    }
    else if(pid1 == 0){
        //right child
        makeTree(--height);
    }
    
}


int main(){
    makeTree(3);
}