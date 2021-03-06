//
// Copyright (c) 2015-2019, RTE (http://www.rte-france.com)
// See AUTHORS.txt
// All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, you can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//
// This file is part of Dynawo, an hybrid C++/Modelica open source time domain
// simulation tool for power systems.
//

/**
 * @file  TLEventCmp.cpp
 *
 * @brief Dynawo timeline event comparator : implementation file
 *
 */

#include "DYNCommon.h"
#include "TLEventCmp.h"
#include "TLEvent.h"

using boost::shared_ptr;

namespace timeline {

bool
EventCmp::operator()(const shared_ptr<Event>& E1, const shared_ptr<Event>& E2) const {
  if (DYN::doubleEquals(E1->getTime(), E2->getTime())) {
    if (E1->getModelName() < E2->getModelName()) {
      return true;
    }
    return (E1->getModelName() == E2->getModelName() && E1->getMessage() < E2->getMessage());
  }
  return (E1->getTime() < E2->getTime());
}

}  // namespace timeline
