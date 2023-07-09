#include<iostream>
#define nl endl
#define ll long long
using namespace std;

double f(double x){
    return (x*3 - cos(x)-1);
}

double bisection(double a,double b,int itr,double ep){
    if(f(a)*f(b)>=0){
        cerr<<"Root doesn't exist in the given interval !!\n";
    }
    int cnt = 0;

    double nroot=0,oroot=0;

    cout<<"-------------------------------------------------------\n";
    cout<<" iteration   | old root    |    new root  |   error \n";
    cout<<"-------------------------------------------------------\n";
    while(itr>cnt){
        nroot = ((a+b)*1.00)/2;
        if(f(nroot) == 0) break;

        if(f(nroot)*f(a*1.00) < 0){
            b = nroot;
        }else{
            a = nroot;
        }
        double error = (abs(oroot - nroot)/nroot);
        oroot = nroot;
        if(error<=ep) break;
        printf("     %2d      |  %.5lf    | %10.5lf   |   %.5lf%%  \n",++cnt,oroot,nroot ,error*100);
        cout<<"-------------------------------------------------------\n";
    }
    return oroot;
}

int main(){
    cout<<nl<<"         Table of every iteration   "<<nl;
    double ans  = bisection(0,1,10,0.00001);
    cout<<"        Approximate Root is "<<ans<<nl<<nl<<nl;
    return 0;
}
