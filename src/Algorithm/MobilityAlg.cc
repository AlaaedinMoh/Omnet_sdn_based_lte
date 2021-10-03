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

#include "MobilityAlg.h"

MobilityAlg::MobilityAlg(int barrierCount) {
    // TODO Auto-generated constructor stub
    _barrierCount = barrierCount;
}

MobilityAlg::MobilityAlg(int barrierCount, double rsrpThresh, double distRef)
{
    _barrierCount = barrierCount;
    _rsrpThresh = rsrpThresh;
    _distRef = distRef;
}

void
MobilityAlg::Calculate(Device ueTx, Device ueRx, double distance)
{
    double q = CalculateQ();
    if(CheckRsrp(ueTx) && CheckDistance(distance) && CheckSinr(ueTx, q))
    {
        std::vector<Device> devices = {ueTx, ueRx};
        Startd2dSession(devices);
        return;
    }
    //TODO: Controller Check if RB available
}

void
MobilityAlg::Startd2dSession(std::vector<Device> devices)
{

}

double
MobilityAlg::CalculateQ()
{
//TODO: Calculate Q from barrier
    return 0;
}

bool
MobilityAlg::CheckRsrp(Device ue)
{
    return ue.Rsrp > _rsrpThresh;
}

bool
MobilityAlg::CheckSinr(Device ue, double q)
{
    return ue.Sinr > q;
}

bool
MobilityAlg::CheckDistance(double distance)
{
    return distance > _distRef;
}

