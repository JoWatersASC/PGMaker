#ifndef PROBDIST_H
#define PROBDIST_H

#include<iostream>
#include<map>
#include<vector>

#include"forward_dec.h"
namespace pgm{

    class ProbabilityDistribution {
        public:
            virtual ~ProbabilityDistribution() = default;

            virtual std::ostream& print(std::ostream &out) = 0;
            friend std::ostream& operator<<(std::ostream& out, ProbabilityDistribution& pDist){
                return pDist.print(out);
            }
        
        protected:
            node_ptr node;
    };

    class MarginalProbabilityDistribution : public ProbabilityDistribution{
        private:
            std::vector<float> MPD;
            node_ptr node;

        public:
            MarginalProbabilityDistribution();
            MarginalProbabilityDistribution(node_ptr n);

            std::vector<float>& getMPD();
            void reset(node_ptr n);
            void reset();
            
            std::ostream& print(std::ostream &out) override;
            const static ProbabilityDistributionType pdType = ProbabilityDistributionType::MARGINAL;
    };




    class ConditionalProbabilityDistribution : public ProbabilityDistribution {
        private:
            std::map<std::vector<int>, std::vector<float>> CPD;
            std::vector<node_ptr> dependencies;

        public:
            ConditionalProbabilityDistribution();
            
            std::map<std::vector<int>, std::vector<float>>& getCPD();
            void reset(std::vector<node_ptr> dependencyList, node_ptr n);

            std::ostream& print(std::ostream &out) override;
            const static ProbabilityDistributionType pdType = ProbabilityDistributionType::CONDITIONAL;
    };
}

#endif