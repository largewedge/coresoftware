#ifndef MBD_MBDRECO_H
#define MBD_MBDRECO_H

#include <fun4all/SubsysReco.h>

#include <array>
#include <memory>
#include <string>

class PHCompositeNode;
class MbdEvent;
class MbdPmtContainer;
class MbdVertexMap;
class MbdOut;
class MbdGeom;
class Event;
class CaloPacket;
class CaloPacketContainer;
class Gl1Packet;
class EventHeader;
class TF1;
class TH1;

class MbdReco : public SubsysReco
{
 public:
  MbdReco(const std::string &name = "MbdReco");

  ~MbdReco() override = default;

  int Init(PHCompositeNode * /*topNode*/) override;
  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  int End(PHCompositeNode *topNode) override;

  void SetCalPass(const int calpass) { _calpass = calpass; }
  void SetProcChargeCh(const bool s) { _always_process_charge = s; }
  void SetMbdTrigOnly(const int m) { _mbdonly = m; }

 private:
  int  createNodes(PHCompositeNode *topNode);
  int  getNodes(PHCompositeNode *topNode);
  int  _simflag{0};
  int  _calpass{0};
  bool _always_process_charge{0};
  int  _mbdonly{0};  // only use mbd triggers

  float m_tres = 0.05;
  std::unique_ptr<TF1> m_gaussian = nullptr;

  std::unique_ptr<MbdEvent> m_mbdevent{nullptr};
  Event *m_event{nullptr};
  std::array<CaloPacket *,2>m_mbdpacket{nullptr};
  CaloPacketContainer *m_mbdraw{nullptr};
  Gl1Packet *m_gl1raw{nullptr};
  MbdOut *m_mbdout{nullptr};
  MbdPmtContainer *m_mbdpmts{nullptr};
  MbdGeom *m_mbdgeom{nullptr};
  MbdVertexMap *m_mbdvtxmap{nullptr};
  EventHeader *m_evtheader{nullptr};
};

#endif  // MBD_MBDRECO_H
