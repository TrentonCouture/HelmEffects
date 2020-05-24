/*
  ==============================================================================

    audio_input.cpp
    Created: 2 Sep 2019 2:17:16pm
    Author:  Trenton

  ==============================================================================
*/

#include "audio_input.h"

namespace mopo {

	AudioInput::AudioInput() : InputProcessor(1, 1) {}

	void AudioInput::destroy() {
	  Processor::destroy();
	}

	void AudioInput::process() {
		const float* source = input_buffer_.getReadPointer(0);
		for (int i = 0; i < input_buffer_.getNumSamples(); ++i) {
		  output()->buffer[i] = (mopo_float)source[i];
		}
    }
}
