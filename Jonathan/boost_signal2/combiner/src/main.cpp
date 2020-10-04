#include "main.hpp"

double mean(double num1, double num2, double num3){
    return (num1+num2+num3)/3;
}

double max(double num1, double num2, double num3){
    return std::max(std::max(num1,num2),num3);
}

double min(double num1, double num2, double num3){
    return std::min(std::min(num1,num2),num3);
}

double sum(double num1, double num2, double num3){
    return num1+num2+num3;
}

int main()
{
    // create signal
    boost::signals2::signal<double (double, double, double), findMedian<double>> sig;
    //std::cout << "Median: " << findMedian(52.2,6300.42,2100.231) << std::endl;
    
    sig.connect(&mean);
    sig.connect(&max);
    sig.connect(&min);
    sig.connect(&sum);

    std::cout << "Median: " << sig(90.32,232.321,42.321) << std::endl;

    return 0;
}