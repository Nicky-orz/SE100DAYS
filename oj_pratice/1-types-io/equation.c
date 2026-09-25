#include<stdio.h>
#include<math.h>

double safe_pow(double x,double y){
    if(x<0)
        return -pow(-x,y);
    else
        return pow(x,y);
}

int main(){
    double p,q;
    scanf("%lf%lf",&p,&q);
    double ans;
    ans = safe_pow(-(q/2)+sqrt(pow(q/2,2)+pow(p/3,3)),1.00/3)+safe_pow(-(q/2)-sqrt(pow(q/2,2)+pow(p/3,3)),1.00/3);
    printf("%.3lf",ans);
    return 0;
}