/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/** \file
 * \ingroup GHOST
 * Declaration of GHOST_EventTouch class.
 */

#ifndef __GHOST_EVENTTOUCH_H__
#define __GHOST_EVENTTOUCH_H__

#include "GHOST_Event.h"

/**
 * Touch event.
 */
class GHOST_EventTouch : public GHOST_Event {
 public:
  /**
   * Constructor.
   * \param msec      The time this event was generated.
   * \param type      The type of this event.
   * \param id        The id associated with the touch pointer.
   * \param x         The x-coordinate of the location the touch was at at the time of the event.
   * \param y         The y-coordinate of the location the touch was at at the time of the event.
   * \param phase     The phase the touch event is in: down, move, or up.
   */
  GHOST_EventTouch(GHOST_TUns64 msec,
                   GHOST_TEventType type,
                   GHOST_IWindow *window,
                   GHOST_TInt32 id,
                   GHOST_TInt32 x,
                   GHOST_TInt32 y,
                   GHOST_TTouchPhase phase)
      : GHOST_Event(msec, type, window)
  {
    m_touchEventData.id = id;
    m_touchEventData.x = x;
    m_touchEventData.y = y;
    m_touchEventData.phase = phase;

    m_data = &m_touchEventData;
  }

 protected:
  /** The id, x,y-coordinates, and phase of the touch event. */
  GHOST_TEventTouchData m_touchEventData;
};

#endif  // __GHOST_EVENTTOUCH_H__
