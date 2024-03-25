#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double maps(double x) {
    double y = 3.0/4*x-7.0/4;
    return y;
}

int main()
{
    ifstream inFile("data.csv");
    if (inFile.fail())
    {
        std::cerr << "File does not exist" << std::endl;
    }
    else
    {
        std::cout << "We create it in a previous execution" << std::endl;
    };

    ofstream outFile("result.csv");
    double x;
    double mean=0.0;
    int contatore=0;
    outFile << "# N mean " << scientific << setprecision(16) << endl ;
    while (inFile >> x)
    {
        mean=(mean*contatore+maps(x))/(contatore+1);
        contatore++;
        outFile << contatore << " " << mean << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}
