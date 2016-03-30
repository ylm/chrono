// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// Base class for a cosimulation node.
//
// =============================================================================

#ifndef CH_COSIM_NODE_H
#define CH_COSIM_NODE_H

#include "mpi.h"

#include "chrono_vehicle/ChApiVehicle.h"
#include "chrono/physics/ChSystem.h"

namespace chrono {
namespace vehicle {

/// @addtogroup vehicle_wheeled_cosim
/// @{

class CH_VEHICLE_API ChCosimNode {
  public:
    ChCosimNode(int rank, ChSystem* system) : m_rank(rank), m_system(system) {}

    virtual void SetStepsize(double stepsize) { m_stepsize = stepsize; }
    double GetStepsize() const { return m_stepsize; }

  protected:
    int m_rank;
    ChSystem* m_system;
    double m_stepsize;
};

/// @} vehicle_wheeled_cosim

}  // end namespace vehicle
}  // end namespace chrono

#endif
