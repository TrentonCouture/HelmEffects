/*
  ==============================================================================

    input_volume_section.cpp
    Created: 28 Sep 2019 5:13:11pm
    Author:  Trenton

  ==============================================================================
*/

#include "input_volume_section.h"

#include "colors.h"
#include "fonts.h"

InputVolumeSection::InputVolumeSection(String name) : SynthSection(name) {
  addModulationButton(modulation_button_ = new ModulationButton("input_volume"));
  modulation_button_->setLookAndFeel(ModulationLookAndFeel::instance());

  addSlider(volume_sensitivity_ = new SynthSlider("input_volume_sensitivity"));
  volume_sensitivity_->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
  volume_sensitivity_->setBipolar();
}

InputVolumeSection::~InputVolumeSection() {
  volume_sensitivity_ = nullptr;
}

void InputVolumeSection::paintBackground(Graphics& g) {
  SynthSection::paintBackground(g);

  g.setColour(Colors::control_label_text);
  g.setFont(Fonts::instance()->proportional_regular().withPointHeight(size_ratio_ * 10.0f));
  
  drawTextForComponent(g, TRANS("SENSITIVITY"), volume_sensitivity_);
}

void InputVolumeSection::resized() {
  int mod_button_width = getModButtonWidth();
  int knob_width = getStandardKnobSize();

  float space = (getWidth() - (mod_button_width + knob_width)) / 3.0f;

  int title_width = getTitleWidth();
  int mod_button_y = (getHeight() - mod_button_width + title_width) / 2.0f;

  modulation_button_->setBounds(space, mod_button_y, mod_button_width, mod_button_width);

  //int slider_y = (getHeight() - knob_width + title_width) / 2.0f;
  int slider_y = size_ratio_ * 38;

  volume_sensitivity_->setBounds(2 * space + mod_button_width, slider_y, knob_width, knob_width);

  SynthSection::resized();
}
