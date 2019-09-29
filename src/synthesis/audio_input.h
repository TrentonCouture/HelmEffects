/*
  ==============================================================================

    audio_input.h
    Created: 2 Sep 2019 2:17:10pm
    Author:  Trenton

  ==============================================================================
*/

#include "input_processor.h"
#include "JuceHeader.h"

#pragma once

namespace mopo {

  class AudioInput : public InputProcessor {
  public:

	AudioInput();
    AudioInput(AudioSampleBuffer* buffer);
    virtual ~AudioInput() { }

	virtual void destroy() override;

    virtual Processor* clone() const override {
		return new AudioInput(*this);
    }

    void process() override;

	AudioSampleBuffer* temp_buffer_;

  private:
  };
}
