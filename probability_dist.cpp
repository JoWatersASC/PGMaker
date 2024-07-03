#include"probability_dist.h"

namespace pgm{
    ProbabilityDistribution::ProbabilityDistribution() {}
}
    /**
    void discPD::set(std::map<condition, std::vector<float>> conditionFunction) {
        func = conditionFunction;
    }
//     typedef std::set<std::pair<pgm::Node*, int>> condition;

    void discPD::reset(std::vector<Node*> dependencies, Node* n) {
        std::vector<condition> conditionSet;

        {
            condition c;
            auto vals = dependencies[0].getValues();

            for(int j = 0; j < vals.size(); j++){
                auto p = std::make_pair(vect[i], j);
                c.insert(p);
            }
            conditionSet.push_back(c);

            if(dependencies.size() == 1) return;
        }

        std::vector<condition> newConditionSet = {}
        for(int i = 1; i < dependencies.size(); i++){
            Node* dependency = dependencies[i];
            std::vector<condition> tempConditionSet = conditionSet;

            for(int j = 0; j < dependency->getValues.size(); j++){
                for(condition c : tempConditionSet){
                    c.emplace({dependency, j});
                }

                newConditionSet.push_back(tempConditionSet);
            }
        }
    }


    condition getConditionSet(std::set<std::pair<pgm::Node*, int> c, Node* dependency){
        condition output;


    }
    
}*/