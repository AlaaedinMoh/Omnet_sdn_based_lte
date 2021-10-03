#ifndef MEMORYSCHEDULER_H_
#define MEMORYSCHEDULER_H_

#include <vector>
#include "MemoryItem.h"
#include "Direction.h"
#include "../Common/Types.h"

class MemoryScheduler {
public:
    MemoryScheduler();
    //MemoryScheduler(const MemoryScheduler& other);
        /**
         * Notify a 'band' being assigned to 'id'.
         * @param id
         * @param band
         * @param isReassigned
         */
        void putItem(const MacNodeId id, const Band band, const bool isReassigned);

        /**
         * Notify that 'id' transmits in 'dir' direction.
         * @param id
         * @param dir
         */
        void putDirection(const MacNodeId id, const Direction dir);

        /**
         * @param id
         * @return The number of bands currently assigned to 'id'.
         */
        std::size_t getNumberAssignedBands(const MacNodeId& id) const;

        const std::vector<Band>& getBandsVec(const MacNodeId& id) const;
        const std::vector<bool>& getReassignmentsVec (const MacNodeId& id) const;

        const Direction& getDirection(const MacNodeId& id) const;
//protected:
//        std::vector<MemoryItem> _MemoryItems;

private:
        const MemoryItem& getMemoryItem(const MacNodeId& id) const;
        MemoryItem& getMemoryItem(const MacNodeId& id);

        std::vector<MemoryItem> _MemoryItems;
};

#endif /* MEMORYSCHEDULER_H_ */
