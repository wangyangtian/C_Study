#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int main() {
    char c1[2],c2[2];
    int x[5],y[5],z[5];
    FILE *fp;
    fp=fopen("xy.txt","r");
    if(fp==NULL){
        printf("打开文件错误！");
        return 1;
    }
        
    else{
        fscanf(fp,"%s%s",c1,c2);
        for(int i=0;i<5;i++){
            fscanf(fp,"%d%d",&x[i],&y[i]);
            z[i]=x[i]+y[i];
        }
    }
    fclose(fp);
    fp=fopen("xy.txt","w");
    if(fp==NULL){
        printf("打开文件错误！");
    }
    else{
        fprintf(fp,"%c\t%c\t%c\n",'x','y','z');
        for(int i=0;i<5;i++){
            fprintf(fp,"%d\t%d\t%d\n",x[i],y[i],z[i]);
        }
    }
    fclose(fp);
    return 0;
}