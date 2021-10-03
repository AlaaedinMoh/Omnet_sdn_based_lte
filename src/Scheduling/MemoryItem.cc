/*
 * MemoryItem.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: alaaedin-moh
 */

#include "MemoryItem.h"

MemoryItem::MemoryItem(MacNodeId id) : _id(id), _dir(UNKNOWN_DIRECTION) {}

void
MemoryItem::putBand(Band band, bool reassigned) {
  _assignedBands.push_back(band);
  _reassigned.push_back(reassigned);
}

std::size_t
MemoryItem::getNumberOfAssignedBands() const {
    return _assignedBands.size();
}

const
std::vector<Band>& MemoryItem::getBands() const {
    return _assignedBands;
}

const
std::vector<bool>& MemoryItem::getReassignments() const {
    return _reassigned;
}

void
MemoryItem::setDir(Direction dir) {
    _dir = dir;
}

const Direction&
MemoryItem::getDir() const {
    return _dir;
}


const MacNodeId&
MemoryItem::getId() const {
    return _id;
}

