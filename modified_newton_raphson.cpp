#include<bits/stdc++.h>
#define nl endl
#define ll long long
using namespace std;
double f(double x){
    return x*x*x - 5*x*x+7*x - 3;
}
double df(double x){
    return 3*x*x - 10*x+7;
}
double ddf(double x){
    return  6*x - 10;
}

double modified_newton_raphson(double a,int itr,double ep){
    int cnt = 1;
    double oroot = a;
    cout<<"-------------------------------------------------------\n";
    cout<<"iteration  |  old root     |  new root   |  error \n";
    cout<<"-------------------------------------------------------\n";


    while(cnt<itr){

        if(((df(oroot)*df(oroot))-f(oroot)*ddf(oroot)) == 0){
            return INT_MIN;
        }
        double nroot = (f(oroot) * df(oroot))/(pow(df(oroot),2) - (f(oroot)*ddf(oroot)));
        cnt++;
        double err = abs(abs(abs(oroot) - abs(nroot))/nroot);
        if(err <= ep) return oroot;
        oroot = nroot;
        printf("    %2d     | %10.5lf   |  %10.5lf%%  |   %10.5lf%% \n",cnt,oroot ,nroot,err*100);
        cout<<"-------------------------------------------------------\n";
    }
    return oroot;
}
int main(){
    cout<<nl<<"         Table for every iteration   "<<nl;
    double ans  = modified_newton_raphson(0,100000,0.0001);
    if(ans != INT_MIN)
        cout<<"        Approximate Root is "<<setprecision(5)<<ans<<nl<<nl<<nl;
    return 0;
}