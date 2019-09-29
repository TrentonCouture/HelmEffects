/*
  ==============================================================================

    input_processor.cpp
    Created: 29 Sep 2019 1:02:00pm
    Author:  Trenton

  ==============================================================================
*/

#include "input_processor.h"

namespace mopo {
  InputProcessor::InputProcessor(int num_inputs, int num_outputs) : Processor(num_inputs, num_outputs) {}

  void InputProcessor::copyBuffer(AudioSampleBuffer& buffer) {
    for (int channel = 0; channel < buffer.getNumChannels(); channel++) {
      auto inputBuff = input_buffer_.getWritePointer(channel);
      auto buff = buffer.getReadPointer(channel);
      for (int i = 0; i < buffer.getNumSamples(); i++) {
        inputBuff[i] = buff[i];
      }
    }
  }

  AudioSampleBuffer InputProcessor::input_buffer_(2, 256);
}

