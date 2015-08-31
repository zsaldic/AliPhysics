#ifndef ALIANALYSISTASKEMCALCLUSTERSREF_H
#define ALIANALYSISTASKEMCALCLUSTERSREF_H
/* Copyright(c) 1998-2015, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

#include "AliAnalysisTaskSE.h"

class AliAnalysisUtils;

class TArrayD;
class TString;

namespace EMCalTriggerPtAnalysis {

class AliEMCalHistoContainer;

class AliAnalysisTaskEmcalClustersRef : public AliAnalysisTaskSE {
public:
  AliAnalysisTaskEmcalClustersRef();
  AliAnalysisTaskEmcalClustersRef(const char *name);
  virtual ~AliAnalysisTaskEmcalClustersRef();

  void UserCreateOutputObjects();
  void UserExec(Option_t *);
  void Terminate(Option_t *) {}

  void SetClusterContainer(TString clustercontname) { fClusterContainer = clustercontname; }
  void SetCreateTriggerStringFromPatches(Bool_t doUsePatches) { fTriggerStringFromPatches = doUsePatches; }

protected:

  void CreateEnergyBinning(TArrayD& binning) const;
  void FillClusterHistograms(TString triggerclass, double energy, double eta, double phi);
  TString GetFiredTriggerClassesFromPatches(const TClonesArray* triggerpatches) const;

  AliAnalysisUtils                    *fAnalysisUtil;
  AliEMCalHistoContainer              *fHistos;
  TString                             fClusterContainer;

  Bool_t                              fTriggerStringFromPatches;

private:
  AliAnalysisTaskEmcalClustersRef(const AliAnalysisTaskEmcalClustersRef &);
  AliAnalysisTaskEmcalClustersRef &operator=(const AliAnalysisTaskEmcalClustersRef &);

  ClassDef(AliAnalysisTaskEmcalClustersRef, 1);
};

} /* namespace EMCalTriggerPtAnalysis */

#endif /* ALIANALYSISTASKEMCALCLUSTERSREF_H */
