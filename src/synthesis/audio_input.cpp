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

	// could try inlining this, assigning output buffer pointer to input buffer, and making sure this only runs once, not for each copied
	// AudioInput. Not sure why it would run for each copy though, since that might mean that each synth voice runs for unplayed notes which
	// would be dumb. Also could check if its performance or something else making it sound bad. I actually think it might not be performance
	// since it has a pitch shifted metallic sound which usually means something happining in each buffer. Maybe you could try out that
	// guy's audio buffer debugger tool
	void AudioInput::process() {
		const float* source = input_buffer_.getReadPointer(0);
		mopo_float* dest = output()->buffer;
		for (int i = 0; i < 256; ++i) {
		  //output()->buffer[i] = mopo_float((i % 100) / (mopo_float)200);
		  output()->buffer[i] = (mopo_float)source[i];
		}
    }

	/*
	void AudioInput::copyInput(AudioSampleBuffer* buffer) {
		//buffer->makeCopyOf(temp_buffer_);
		//temp_buffer_->makeCopyOf(*buffer);
		temp_buffer_ = buffer;
	}
	*/
}
