#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double x[],int y,double z[]){
    double sum = 0, power = 0, multi=1, frac=0, max=x[0], min = x[0];
    for(int i=0;i<y;i++){
        sum += x[i];
        power += pow(x[i],2);
        multi *= x[i];
        frac += 1/x[i];
        if(x[i]>max) max = x[i];
        if(x[i]<min) min = x[i]; 
    }
    z[0] = sum/y;
    z[1] = sqrt((power/y)-pow(z[0],2));
    z[2] = pow(multi,pow(y,-1));
    z[3] = y/frac;
    z[4] = max;
    z[5] = min;
}