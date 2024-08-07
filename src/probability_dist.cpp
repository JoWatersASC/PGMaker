#include<iomanip>

#include"..\include\probability_dist.h"
#include"..\include\node.h"

typedef std::map<std::vector<int>, std::vector<float>> cpd;

//______________________________________________
//Raw PD
//______________________________________________
namespace pgm{
    ProbabilityDistribution::ProbabilityDistribution() {}
    ProbabilityDistribution::ProbabilityDistribution(node_ptr n) : node(n) {}

    void ProbabilityDistribution::setNode(node_ptr n) {
        node = n;
        reset();
    }
    node_ptr ProbabilityDistribution::getNode() { return node; }
}


//______________________________________________
//Marginal PD
//______________________________________________
namespace pgm{
    MarginalProbabilityDistribution::MarginalProbabilityDistribution() {}
    MarginalProbabilityDistribution::MarginalProbabilityDistribution(node_ptr n) { n->setDefinition(shared_from_this()); }

    std::vector<float>& MarginalProbabilityDistribution::getMPD() { return MPD; }

    void MarginalProbabilityDistribution::reset(){
        MPD.clear();
        int size = node->getValues().size();
        float whole = 1.0f;
        float prob = whole / size;

        for(int i = 0; i < size - 1; i++){
            MPD.push_back(prob);
            whole -= prob;
        }

        MPD.push_back(prob);
    }

    std::ostream& MarginalProbabilityDistribution::print(std::ostream& out) {
        out << node->getName() << std::endl;

        int width = 0;
        std::vector<std::string> values = node->getValues();

        for(std::string s : values){
            if(s.length() > width) width = s.length();
        }

        for(int i = 0; i < MPD.size(); i++){
            out << std::left << std::setw(width) << values[i] << " " << std::setw(4) << MPD[i] << std::endl;
        }

        return out;
    }
}

//______________________________________________
//Conditional PD
//______________________________________________
namespace pgm {
    ConditionalProbabilityDistribution::ConditionalProbabilityDistribution() {}

    cpd& ConditionalProbabilityDistribution::getCPD() {
        return CPD;
    }
    void ConditionalProbabilityDistribution::reset(std::vector<node_ptr> dependencyList, node_ptr n) {}
    void ConditionalProbabilityDistribution::reset() {}

    std::ostream& ConditionalProbabilityDistribution::print(std::ostream& out) {
        return out;
    }
}
   