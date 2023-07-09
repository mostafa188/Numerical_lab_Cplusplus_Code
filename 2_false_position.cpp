#include<bits/stdc++.h>
#define nl endl
#define ll long long
using namespace std;
#define mostafa always lazy 1e-10000000007-10
double f(double x){
    return (x*3 - cos(x)-1);
}

double falsi_position(double a,double b,int itr,double ep){
    if(f(a)*f(b)>=0){
        cerr<<"Root doesn't exist in the given interval !!\n";
    }
    int cnt = 0;
    double nroot=0,oroot=0;

    cout<<"--------------------------------------------------------------\n";
    cout<<" iteration   |   old root     |    new root      |   error \n";
    cout<<"--------------------------------------------------------------\n";
    while(itr>cnt){
        nroot = (a*f(b) -b*f(a))/(f(b)-f(a));

        if(f(nroot) == 0) break;
        if(f(nroot)*f(a*1.00) < 0){
            b = nroot;
        }else{
            a = nroot;
        }
        double error = (abs(oroot - nroot)/nroot);
        oroot = nroot;
        printf("     %2d      |  %10.5lf    |   %10.5lf     | %10.5lf%%  \n",++cnt,oroot,nroot,error*100);
        cout<<"--------------------------------------------------------------\n";
        if(error<=ep) break;
    }
    return oroot;
}

int main(){
    freopen("mostafa","w",stdout);
    cout<<"                  Table of every iteration   "<<nl;
    double ans  = falsi_position(0,1,10,0.00001);
    cout<<"Approximate Root is "<<setprecision(2)<<ans;
    return 0;
}
