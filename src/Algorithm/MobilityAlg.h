//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef ALGORITHM_MOBILITYALG_H_
#define ALGORITHM_MOBILITYALG_H_

#include "Device.h"
#include <vector>

class MobilityAlg {
public:
    MobilityAlg(int barrierCount);
    MobilityAlg(int barrierCount, double rsrpThresh, double distRef);
    void Calculate(Device ueTx, Device ueRx, double distance);

    void Startd2dSession(std::vector<Device> devices);

private:
    int _barrierCount;
    double _rsrpThresh;
    double _distRef;

    double CalculateQ();
    bool CheckRsrp(Device ue);
    bool CheckSinr(Device ue, double q);
    bool CheckDistance(double distance);
};

#endif /* ALGORITHM_MOBILITYALG_H_ */
