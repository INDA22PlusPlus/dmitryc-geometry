#include <iostream>
#include <cmath>
using namespace std;int main(){int N;cin>>N;double s=0;for(int i=0;i<N;i++){int a,b,c;cin>>a>>b>>c;double m=sqrt((2*(a*a+b*b)-c*c)/4.0);double angle=acos((c*c/4.0+m*m-b*b)/(m*c));s+=sin(min(M_PI-angle,angle))*c;}cout<<s;return 0;}