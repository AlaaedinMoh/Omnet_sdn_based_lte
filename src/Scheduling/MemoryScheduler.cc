#include "MemoryScheduler.h"
#include <iostream>

MemoryScheduler::MemoryScheduler() {
    // TODO Auto-generated constructor stub

}

//MemoryScheduler::MemoryScheduler(const MemoryScheduler& other)
//{
//    _MemoryItems(other._MemoryItems);
//}

void
MemoryScheduler::putItem(const MacNodeId id, const Band band, const bool isReassigned){
    try
    {
        MemoryItem &item = getMemoryItem(id);
        item.putBand(band, isReassigned);
        // If not, create it.
    }catch (const std::exception& e) {
        _MemoryItems.push_back(MemoryItem(id));
        MemoryItem &item = _MemoryItems.at(_MemoryItems.size() - 1);
        item.putBand(band, isReassigned);
    }
}

const MemoryItem&
MemoryScheduler::getMemoryItem(const MacNodeId &id) const{
    return const_cast<MemoryItem&>(static_cast<const MemoryScheduler&>(*this).getMemoryItem(id));
}

MemoryItem&
MemoryScheduler::getMemoryItem(const MacNodeId& id){
    for (size_t i = 0; i < _MemoryItems.size(); i++)
    {
        if (_MemoryItems.at(i).getId() == id)
            return _MemoryItems.at(i);
    }
    throw std::invalid_argument("MemoryScheduler::getMemoryItem(invalid 'id') was called with id=" + std::to_string(id));
}

void
MemoryScheduler::putDirection(const MacNodeId id, const Direction dir){
    try {
        MemoryItem &item = getMemoryItem(id);
        item.setDir(dir);
        // If not, create it.
    } catch (const std::exception& e) {
        _MemoryItems.push_back(MemoryItem(id));
        MemoryItem &item = _MemoryItems.at(_MemoryItems.size() - 1);
        item.setDir(dir);
    }
}

std::size_t
MemoryScheduler::getNumberAssignedBands(const MacNodeId& id) const{
    return getMemoryItem(id).getNumberOfAssignedBands();
}

const std::vector<Band>&
MemoryScheduler::getBandsVec(const MacNodeId& id) const{
    return getMemoryItem(id).getBands();
}

const std::vector<bool>&
MemoryScheduler::getReassignmentsVec (const MacNodeId& id) const{
    return getMemoryItem(id).getReassignments();
}

const Direction&
MemoryScheduler::getDirection(const MacNodeId& id) const{
    return getMemoryItem(id).getDir();
}

