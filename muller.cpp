#include<bits/stdc++.h>
using namespace std;

const int MAX_ITERATIONS = 10000;
float f(float x)
{
	return (1*pow(x, 3) + 2*x*x + 10*x - 20);
}

void Muller(float a, float b, float c,int itr,double ep)
{
	float res;
    int cnt=0;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"itr |    a   |    b    |    c  |   f(a)  |  f(b)  |   f(c) |   h1   |   h2   |    d1   |    d2   |    na  |   nb  |   nc  |  error \n";
    cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";

	while(itr>cnt)
	{
		float f1 = f(a);
		float f2 = f(b);
		float f3 = f(c);

		float d1 = f1 - f3;
		float d2 = f2 - f3;

		float h1 = a - c;
		float h2 = b - c;

		float a = f3;
		float b = (((d2*pow(h1, 2)) - (d1*pow(h2, 2)))/ ((h1*h2) * (h1-h2)));
		float c = (((d1*h2) - (d2*h1))/((h1*h2) * (h1-h2)));

		float x = ((-2*a) / (b + abs(sqrt(b*b-4*a*c))));
		float y = ((-2*a) / (b-abs(sqrt(b*b-4*a*c))));

		if (x >= y)
			res = x + c;
		else
			res = y + c;

        cnt++;
		double err = abs((res-c)/res);
        printf("%2d  | %5.3lf | %5.3lf  | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf | %5.3lf |   %5.3lf%% \n",cnt,a,b,c,f1,f2,f3,h1,h2,d1,d2,b,c,res,err*100);
        cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
        if(err*10000 <= 1){
            break;
        }
		a = b;
		b = c;
		c = res;
	}
	cout<<res<<" ";
}

// Driver main function
int main()
{
    freopen("mostafa","w",stdout);
	float a = 0, b = 19, c = 20;
	Muller(a, b, c,10,0.0001);
	return 0;
}
