#pragma once

#include<memory>

namespace pgm{
    class Node;
    class ProbabilityDistribution;


    typedef std::shared_ptr<Node>                    node_ptr;
    typedef std::shared_ptr<ProbabilityDistribution> pDist_ptr;

    enum class ProbabilityDistributionType{
        MARGINAL,
        CONDITIONAL
    };
}
