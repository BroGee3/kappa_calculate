#include<iostream>
#include <Eigen/Dense>
#include <vector>
using namespace std;
using namespace Eigen;

float PJcurvature(Eigen::Vector3f &x,Eigen::Vector3f y)
{
    float kappa;
    float t_a = hypotf(x(1)-x(0),y(1)-y(0));
    float t_b = hypotf(x(2)-x(1),y(2)-y(1));

    Eigen::Matrix3f M ;
    M <<    1, -t_a ,t_a*t_a,
            1,  0,   0,
            1 ,t_b,  t_b*t_b;
    Eigen::Vector3f a = M.inverse() * x;
    Eigen::Vector3f b = M.inverse() * y;

    kappa  = 2*(a(2)*b(1)-b(2)*a(1)) / pow(a(1)*a(1)+b(1)*b(1),1.5);

    return kappa;

}


int main(int argc, char *argv[])
{
    Eigen::Vector3f x ;
    Eigen::Vector3f y;
    float r = 3;
//    x << r*cos(-2.0),r*cos(-2.3),r*cos(-2.7);
//    y << r*sin(-2.0),r*sin(-2.3),r*sin(-2.7);
    x << -84.52,-84.511,-84.497;
    y << 61.067,61.071,61.078;
    std::cout << 1.0/PJcurvature(x,y) <<std::endl;

}
