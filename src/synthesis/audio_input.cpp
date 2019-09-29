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
	AudioInput::AudioInput(AudioSampleBuffer* buffer) : InputProcessor(1, 1) { 
	  temp_buffer_ = buffer;
	}

	void AudioInput::destroy() {
	  Processor::destroy();
	}

	void AudioInput::process() {
		const float* source = input_buffer_.getReadPointer(0);
		mopo_float* dest = output()->buffer;
		for (int i = 0; i < 256; ++i) {
		  output()->buffer[i] = (mopo_float)source[i];
		}
    }
}
