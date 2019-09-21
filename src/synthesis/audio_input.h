/*
  ==============================================================================

    audio_input.h
    Created: 2 Sep 2019 2:17:10pm
    Author:  Trenton

  ==============================================================================
*/

#include "processor.h"
#include "JuceHeader.h"

#pragma once

namespace mopo {

  class AudioInput : public Processor {
  public:

	AudioInput();
    AudioInput(AudioSampleBuffer* buffer);
    virtual ~AudioInput() { }

	virtual void destroy() override;

	/*
	AudioInput(const AudioInput& obj) {
		temp_buffer_ = obj.temp_buffer_;
	}
	*/

    virtual Processor* clone() const override {
		//AudioInput* tempInput = new AudioInput();
		//tempInput->temp_buffer_ = temp_buffer_;
		return new AudioInput(*this);
    }

	//void copyInput(AudioSampleBuffer* buffer);

    void process() override;

	AudioSampleBuffer* temp_buffer_;

  private:
  };
}
