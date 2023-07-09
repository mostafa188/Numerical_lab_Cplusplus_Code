#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

double f(double x) {
  return 3*x - cos(x)-1;
}
double g(double x){
    return 3 + sin(x);
}
double fixed_point_iteration(double a,double b,int itr,int ep){
    double oroot = b,nroot;
    if(f(a)*f(b)>0){
        cout<<"Root doesn't exist in this interval !!";
        return INT_MIN;
    }
    int cnt=1;
    cout<<"------------------------------------------------------------------------------\n";
    cout<<"iteration | old root     |     f(x)    |    f'(x)   |  new root  |  error \n";
    cout<<"------------------------------------------------------------------------------\n";
    while(cnt<itr){
        double droot = g(oroot);
        double mroot = f(oroot);

        if(droot == 0){
            cout<<"Mathmatical error !!\n";
            return INT_MIN;
        }
        nroot = oroot - (mroot/droot);
        if(abs(oroot-nroot) <= ep){
            break;
        }
        double error = abs(abs(nroot - oroot)/nroot);
        ++cnt;
        printf("  %2d      |  %10.5lf  | %10.5lf  | %9.5lf  |  %9.5lf | %9.5lf%%  \n",cnt,oroot,mroot,droot,nroot,error*100);
        cout<<"------------------------------------------------------------------------------\n";
        
        oroot = nroot;
    }

    return oroot;
}
int main() {
    printf("\n%25cTable for every iteration\n",' ');
    double ans  = fixed_point_iteration(0,1000,10,0.0001);
    if(ans != INT_MIN)
        cout<<"        Approximate Root is "<<setprecision(5)<<ans<<nl<<nl<<nl;
  return 0;
}
