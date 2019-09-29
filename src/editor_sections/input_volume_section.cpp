/*
  ==============================================================================

    input_volume_section.cpp
    Created: 28 Sep 2019 5:13:11pm
    Author:  Trenton

  ==============================================================================
*/

#include "input_volume_section.h"

InputVolumeSection::InputVolumeSection(String name) : SynthSection(name) {
  addModulationButton(modulation_button_ = new ModulationButton("input_volume"));
  modulation_button_->setLookAndFeel(ModulationLookAndFeel::instance());
}

void InputVolumeSection::resized() {
  int mod_button_x = size_ratio_ * 10.0f;
  int mod_button_width = getModButtonWidth();
  int title_width = getTitleWidth();
  float mod_button_y = (getHeight() - mod_button_width + title_width) / 2.0f;

  modulation_button_->setBounds(mod_button_x, mod_button_y, mod_button_width, mod_button_width);
}
