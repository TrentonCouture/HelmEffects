/*
  ==============================================================================

    input_processor.h
    Created: 29 Sep 2019 1:02:00pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "processor.h"

namespace mopo {
	class InputProcessor : public Processor {
	public:
		InputProcessor(int num_inputs, int num_outputs);
		void copyBuffer(AudioSampleBuffer& buffer, int num_channels, int offset);
	protected:
		static AudioSampleBuffer input_buffer_;
	};
}
