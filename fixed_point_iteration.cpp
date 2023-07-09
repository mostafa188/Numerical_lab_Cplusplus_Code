#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

double g(double x) {
  return (cos(x)+1) / 3;
}
double fixed_point_iteration(double a,int itr,int ep){
    double oroot = a;
    int cnt=1;
    cout<<"--------------------------------------------------------\n";
    cout<<"iteration  |  old root    |new root =g(old_root)|  error \n";
    cout<<"--------------------------------------------------------\n";
    while(cnt<itr){
        double nroot = g(oroot);
        if(abs(oroot-nroot) <= ep){
            break;
        }
        double error = abs(nroot - oroot);
        ++cnt;
        printf("    %2d     | %10.5lf   |  %10.5lf%%  |  %10.5lf%%    \n",cnt,oroot ,nroot,error*100);
        cout<<"--------------------------------------------------------\n";
        
        oroot = nroot;
    }
    return oroot;

}
int main() {
    cout<<nl<<"         Table of every iteration   "<<nl;
    double ans  = fixed_point_iteration(100,10,0.00001);
    cout<<"        Approximate Root is "<<setprecision(5)<<ans<<nl<<nl<<nl;
  return 0;
}