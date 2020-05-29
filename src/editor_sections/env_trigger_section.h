/*
  ==============================================================================

    enveloper_runner.h
    Created: 25 May 2020 5:50:43pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "synth_section.h"
//#include "env_trigger_button.h"


class EnvTriggerSection : public SynthSection {
public:
	EnvTriggerSection(String name);
	//~EnvTriggerSection();

	//void resized() override;
	//void paintBackground(Graphics& g) override;

private:
	//ScopedPointer<EnvTriggerButton> env_trigger_button_;
	//ScopedPointer<Label> label_;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvTriggerSection)
};
