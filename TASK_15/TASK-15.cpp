#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <map> 
 
double calculateMean(const std::vector<int>& data) {                         // mean calculating here
    double sum = 0.0; 
    for (int num : data) { 
        sum += num; 
    } 
    return sum / data.size(); 
} 
                                                                               // Median calculating
double calculateMedian(std::vector<int> data) { 
    std::sort(data.begin(), data.end()); 
    size_t size = data.size(); 
    if (size % 2 == 0) { 
        return (data[size / 2 - 1] + data[size / 2]) / 2.0; 
    } else { 
        return data[size / 2]; 
    } 
} 
                                                                                     //Variance calculating

double calculateVariance(const std::vector<int>& data, double mean) { 
    double variance = 0.0; 
    for (int num : data) { 
        variance += (num - mean) * (num - mean); 
    } 
    return variance / data.size(); 
} 
 
double calculateStandardDeviation(double variance) { 
    return std::sqrt(variance);                                                          // SD calculating
} 
 
int main() { 
    std::vector<int> data = {16, 24, 22, 3, 43, 14, 43, 5,22}; 
 
    double mean = calculateMean(data); 
    double median = calculateMedian(data); 
   
    double variance = calculateVariance(data, mean); 
    double standardDeviation = calculateStandardDeviation(variance); 
 
    std::cout << "Mean: " << mean << std::endl; 
    std::cout << "Median: " << median << std::endl; 
  
    std::cout << "Variance: " << variance << std::endl; 
    std::cout << "Standard Deviation: " << standardDeviation << std::endl; 
 
    return 0; 
} 