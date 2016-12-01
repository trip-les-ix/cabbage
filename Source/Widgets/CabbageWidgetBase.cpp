/*
  Copyright (C) 2016 Rory Walsh

  Cabbage is free software; you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Cabbage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
  02111-1307 USA
*/

#include "CabbageWidgetBase.h"
#include "../CabbageCommonHeaders.h"
#include "../Audio/Plugins/CabbagePluginEditor.h"


void CabbageWidgetBase::handleCommonUpdates(Component* child, ValueTree data, bool calledFromConstructor)
{
	if(calledFromConstructor == false)
	{
		if(getPluginEditor(child)->isEditModeEnabled() == false)
			child->setBounds(CabbageWidgetData::getBounds(data));

		else if(CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::allowboundsupdate)==1)
		{
			child->setBounds(CabbageWidgetData::getBounds(data));
			getPluginEditor(child)->updateLayoutEditorFrames();
		}
	}
    if(rotate!=CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::rotate))
    {
        rotate = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::rotate);
        child->setTransform(AffineTransform::rotation(rotate, child->getX()+CabbageWidgetData::getNumProp(data,
                            CabbageIdentifierIds::pivotx),
                            child->getY()+CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::pivoty)));
    }

    if(visible != CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::visible))
    {
        visible = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::visible);
        child->setVisible(visible==1 ? true : false);
        child->setEnabled(visible==1 ? true : false);
    }

    if(active != CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::active))
    {
        active = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::active);
        child->setEnabled(active==1 ? true : false);
    }

    if(alpha != CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::alpha))
    {
        alpha = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::alpha);
        child->setAlpha(alpha);
    }

    if(alpha != CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::alpha))
    {
        alpha = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::alpha);
    }

}


String CabbageWidgetBase::getCurrentText(ValueTree data)
{
    if(text!=CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::text))
    {
        text = CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::text);
        return text;
    }

    return text;
}

String CabbageWidgetBase::getCurrentPopupText(ValueTree data)
{
    if(tooltipText!=CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::popuptext))
    {
        tooltipText = CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::popuptext);
        return tooltipText;
    }

    return tooltipText;
}

void CabbageWidgetBase::setChannel(ValueTree data)
{
    if(channel != CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::channel))
    {
        channel = CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::channel);
        CabbageWidgetData::setProperty(data, CabbageIdentifierIds::channel, channel);
    }
}

float CabbageWidgetBase::getCurrentValue(ValueTree data)
{
    if(currentValue!=CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::value))
    {
        currentValue = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::value);
        return currentValue;
    }

    return currentValue;
}

void CabbageWidgetBase::initialiseCommonAttributes(Component* child, ValueTree data)
{
    rotate = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::rotate);
    pivotx = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::pivotx);
    pivoty = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::pivoty);
    visible = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::visible);
    active = CabbageWidgetData::getNumProp(data, CabbageIdentifierIds::active);
    tooltipText = CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::popuptext);
    child->setBounds(CabbageWidgetData::getBounds(data));
    child->setName(CabbageWidgetData::getStringProp(data, CabbageIdentifierIds::name));
	//now initialise everything that can be updated using ident channels
	handleCommonUpdates(child, data, true);

}


int CabbageWidgetBase::getSVGWidth(File svgFile)
{
    ScopedPointer<XmlElement> svg (XmlDocument::parse(svgFile.loadFileAsString()));
    for(int i=0; i<svg->getNumAttributes(); i++)
    {
        if(svg->getAttributeName(i)=="width")
            return svg->getAttributeValue(i).getIntValue();
    }
    return 0;
}

int CabbageWidgetBase::getSVGHeight(File svgFile)
{
    ScopedPointer<XmlElement> svg (XmlDocument::parse(svgFile.loadFileAsString()));
    for(int i=0; i<svg->getNumAttributes(); i++)
    {
        if(svg->getAttributeName(i)=="height")
            return svg->getAttributeValue(i).getIntValue();
    }
    return 0;
}