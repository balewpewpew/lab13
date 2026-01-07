#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool x[][M]){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if(i!=0&&i!=N+1){
                if(j==0 || j==M+1) cout << "|";
            }
            if(i==0 || i==N+1) cout << "-";
            if(i>0&&i<N+1&&j>0&&j<M+1){
                if(x[i-1][j-1]) cout << "*";
                else cout << " ";
            }
        }
        cout << "\n";
    }
}

void updateImage(bool im[][M],int size,int x,int y){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if((sqrt(pow((i-x),2)+(pow((j-y),2))))<=size-1){
                if(i<N&&j<M){
                    im[i][j] = true;
                }
            }
        }
    }     
}