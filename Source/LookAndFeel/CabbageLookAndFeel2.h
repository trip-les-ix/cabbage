/*
  ==============================================================================

    CabbageLookAndFeel2.h
    Created: 10 Nov 2016 5:36:11pm
    Author:  rory

  ==============================================================================
*/

#ifndef CABBAGELOOKANDFEEL2_H_INCLUDED
#define CABBAGELOOKANDFEEL2_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../CabbageCommonHeaders.h"

class CabbageLookAndFeel2	: public LookAndFeel_V3
{
public:
    CabbageLookAndFeel2();
    ~CabbageLookAndFeel2() {};

    void drawToggleButton (Graphics &g, ToggleButton &button, bool isMouseOverButton, bool isButtonDown);

    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &slider);

    void drawLinearSlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider);

    void drawLinearSliderBackground (Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos,	float maxSliderPos,	const Slider::SliderStyle style, Slider &slider);

    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider);
    Slider::SliderLayout getSliderLayout (Slider& slider) override;

    static Image drawToggleImage (float width, float height, bool isToggleOn, const Colour colour, const bool isRect, const float corners);

    void drawGroupComponentOutline (Graphics &g, int w, int h, const String &text, const Justification &position, GroupComponent &group);

    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown);

    void drawComboBox(Graphics& g, int width, int height, bool /*isButtonDown*/, int /*buttonX*/, int /*buttonY*/, int /*buttonW*/, int /*buttonH*/, ComboBox& box);

    void drawPopupMenuBackground(Graphics &g, int width, int height);

    void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, const bool isHighlighted, const bool isTicked,
                           const bool hasSubMenu, const String& text, const String& shortcutKeyText, const Drawable* icon, const Colour* const textColourToUse);

	void drawAlertBox (Graphics& g, AlertWindow& alert, const Rectangle<int>& textArea, TextLayout& textLayout);
    Image drawCheckMark();

    static void drawFromSVG(Graphics &g, File svgFile, int x, int y, int newWidth, int newHeight, AffineTransform affine);
    void drawSphericalThumb (Graphics& g, const float x, const float y, const float w, const float h, const Colour& colour,	const float outlineThickness);
    void drawTwoValueThumb (Graphics& g, float x, float y, float diameter, const Colour& colour, float outlineThickness, int direction);

private:




};

#endif  // CABBAGELOOKANDFEEL2_H_INCLUDED
