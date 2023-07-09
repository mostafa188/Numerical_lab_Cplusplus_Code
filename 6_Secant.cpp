#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

double f(double x) {
  return 3*x - cos(x)-1;
}

double secant_method(double a,double b,int itr,int ep){
    if(f(a)*f(b)>0){
        cout<<"No root exist in the interval !!\n";
        return INT_MIN;
    }
    
    double oroot1 = a,oroot2=b,nroot=0,error;
    int cnt = 0;
    cout<<"----------------------------------------------------------------------------------\n";
    cout<<" iteration   |     guess1    |     guess2      |    new root     |    error \n";
    cout<<"----------------------------------------------------------------------------------\n";
    while(itr>cnt){
        nroot = (f(oroot1)*oroot2 - f(oroot2)*oroot1)/(f(oroot1)-f(oroot2));
        cnt++;
        error = abs(abs(oroot2-nroot)/nroot);
        printf("     %2d      |  %10.5lf   |   %10.5lf    |   %10.5lf    |  %10.6lf  \n",cnt,oroot1,oroot2,nroot,error);
        cout<<"----------------------------------------------------------------------------------\n";

        if((int)(error*100000)<=(int)(ep*100000)) break;
        oroot1 = oroot2;
        oroot2 = nroot;
    }
    return oroot2;
}
int main() {
    printf("\n%30cTable for every iteration\n",' ');
    double ans  = secant_method(0,1000,10,0.00001);
    if(ans != INT_MIN)
        cout<<"        Approximate Root is "<<setprecision(5)<<ans<<nl<<nl<<nl;
  return 0;
}
