//
// Generated file, do not edit! Created by nedtool 5.6 from Messages/PacketMessage.msg.
//

#ifndef __PACKETMESSAGE_M_H
#define __PACKETMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Messages/PacketMessage.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet PacketMessage
 * {
 *     int PacketId;
 *     int SrcId;
 *     int DestId;
 *     int Size;
 *     char arrayField2[10];
 * }
 * </pre>
 */
class PacketMessage : public ::omnetpp::cPacket
{
  protected:
    int PacketId;
    int SrcId;
    int DestId;
    int Size;
    char arrayField2[10];

  private:
    void copy(const PacketMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketMessage&);

  public:
    PacketMessage(const char *name=nullptr, short kind=0);
    PacketMessage(const PacketMessage& other);
    virtual ~PacketMessage();
    PacketMessage& operator=(const PacketMessage& other);
    virtual PacketMessage *dup() const override {return new PacketMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getPacketId() const;
    virtual void setPacketId(int PacketId);
    virtual int getSrcId() const;
    virtual void setSrcId(int SrcId);
    virtual int getDestId() const;
    virtual void setDestId(int DestId);
    virtual int getSize() const;
    virtual void setSize(int Size);
    virtual unsigned int getArrayField2ArraySize() const;
    virtual char getArrayField2(unsigned int k) const;
    virtual void setArrayField2(unsigned int k, char arrayField2);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PacketMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PacketMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PACKETMESSAGE_M_H
