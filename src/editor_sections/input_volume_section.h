/*
  ==============================================================================

    input_volume_section.h
    Created: 28 Sep 2019 5:13:11pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "modulation_button.h"
#include "synth_section.h"
#include "modulation_look_and_feel.h"
#include "synth_slider.h"


class InputVolumeSection : public SynthSection {
public:
	InputVolumeSection(String name);
	~InputVolumeSection();

	void resized() override;
	void paintBackground(Graphics& g) override;

private:
	ScopedPointer<ModulationButton> modulation_button_;
	ScopedPointer<SynthSlider> volume_sensitivity_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InputVolumeSection)
};
