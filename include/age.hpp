#include "genetic.hpp"

#ifndef AGE_H
#define AGE_H

class AGE : public GeneticAlg {
private:
   Population Replace(const Population& originalP, Population& toReplaceP) override;
   Population Select(const Population& originalP) override;

public:
   AGE(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pMutate, int maxEvals)
   : GeneticAlg(distances, frequencies, populationSize, 1, pMutate, maxEvals){}
};

class AGE_OX : public AGE {
protected:
   Population Cross(const Population& originalP) override { return CrossOX(originalP, this->crossProb);}

public:
   AGE_OX(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pMutate, int maxEvals)
   : AGE(distances, frequencies, populationSize, pMutate, maxEvals){}
};

class AGE_PMX : public AGE {
protected:
   Population Cross(const Population& originalP) override { return CrossPMX(originalP, this->crossProb);}

public:
   AGE_PMX(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pMutate, int maxEvals)
   : AGE(distances, frequencies, populationSize, pMutate, maxEvals){}
};

#endif