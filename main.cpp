#include".\include\network.h"

void p(pgm::ProbabilityDistribution& p){
    std::cout << p;
}

int main(int argc, char* argv[]){
    pgm::Node n;
    pgm::MarginalProbabilityDistribution m;

    p(m);

    return 0;
}