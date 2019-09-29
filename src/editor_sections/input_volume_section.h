/*
  ==============================================================================

    input_volume_section.h
    Created: 28 Sep 2019 5:13:11pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "modulation_button.h"
#include "synth_section.h"
#include "modulation_look_and_feel.h"


class InputVolumeSection : public SynthSection {
public:
	InputVolumeSection(String name);
	void resized() override;

private:
	ScopedPointer<ModulationButton> modulation_button_;
};
