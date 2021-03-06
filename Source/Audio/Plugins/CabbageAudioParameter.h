/*
  Copyright (C) 2016 Rory Walsh

  Cabbage is free software; you can redistribute it
  and/or modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Cabbage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
  02111-1307 USA
*/

#ifndef AUDIOPRAMATERS_H_INCLUDED
#define AUDIOPRAMATERS_H_INCLUDED

#include "../../CabbageCommonHeaders.h"
#include "CabbagePluginProcessor.h"

class CabbageAudioParameter : public AudioParameterFloat
{

public:
    CabbageAudioParameter (ValueTree wData, Csound& csound, String channel, String name, float minValue, float maxValue, float def, float incr, float skew)
        : AudioParameterFloat (channel, channel, NormalisableRange<float> (minValue, maxValue, incr, skew), def), widgetData (wData), currentValue (def), widgetName (name), channel (channel), csound (csound)
    {
        widgetType = CabbageWidgetData::getStringProp (widgetData, CabbageIdentifierIds::type);
    }
    ~CabbageAudioParameter() {}

    float getValue() const override
    {
        return range.convertTo0to1 (currentValue);
    }

    void setValue (float newValue) override
    {
        csound.SetChannel (channel.toUTF8(), range.convertFrom0to1 (newValue));
        currentValue = range.convertFrom0to1 (newValue);
    }

    const String getWidgetName() {   return widgetName;  }

    String channel;
    String widgetName;
    ValueTree widgetData;
    String widgetType;
    float currentValue;

    Csound csound;
};

#endif  // AUDIOPRAMATERS_H_INCLUDED
