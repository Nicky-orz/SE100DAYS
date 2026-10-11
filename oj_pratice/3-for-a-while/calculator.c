#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char s[105];
    while(fgets(s,sizeof(s),stdin)){
        int a,b;
        char op[5];
        sscanf(s,"%d %3s %d",&a,op,&b);
        if(strcmp(op,"+") == 0)
            printf("%d\n",a+b);
        if(strcmp(op,"-") == 0)
            printf("%d\n",a-b);
        if(strcmp(op,"*") == 0)
            printf("%d\n",a*b);
        if(strcmp(op,"/") == 0)
            printf("%d\n",a/b);
        if(strcmp(op,"/*") == 0)
            printf("%.3f\n",(double)a/(double)b);
        if(strcmp(op,"**") == 0)
            printf("%d\n",(int)pow((double)a,(double)b));
        if(strcmp(op,"%") == 0)
            printf("%d\n",a%b);
    }

    return 0;
}