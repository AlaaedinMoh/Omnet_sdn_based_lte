/*
 * MemoryItem.h
 *
 *  Created on: Sep 25, 2021
 *      Author: alaaedin-moh
 */

#ifndef MEMORYITEM_H_
#define MEMORYITEM_H_

#include "Direction.h"
#include "../Common/Types.h"
#include <vector>

/**
     * A memory item holds the assigned bands per node id
     * as well as the transmission direction this node wants to transmit in.
     */
class MemoryItem {
public:
    MemoryItem(MacNodeId id);
    void putBand(Band band, bool reassigned);
    std::size_t getNumberOfAssignedBands() const;
    const std::vector<Band>& getBands() const;
    const std::vector<bool>& getReassignments() const;
    void setDir(Direction dir);
    const Direction& getDir() const;
    const MacNodeId& getId() const ;

private:
    MacNodeId _id;
    std::vector<Band> _assignedBands;
    std::vector<bool> _reassigned;
    Direction _dir;
};

#endif /* MEMORYITEM_H_ */
