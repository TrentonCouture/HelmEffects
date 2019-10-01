/*
  ==============================================================================

    input_volume.cpp
    Created: 29 Sep 2019 10:08:44pm
    Author:  Trenton

  ==============================================================================
*/

#include "input_volume.h"

namespace mopo {

  InputVolume::InputVolume() : InputProcessor(1, 1) { }

  void InputVolume::destroy() {
  	Processor::destroy();
  }

	void InputVolume::process() {
		//output()->buffer[0] = 10 * (mopo_float)volumeChecker.getRunningAverage(input_buffer_);
		output()->buffer[0] = input(kSensitivity)->source->buffer[0] * (mopo_float)volumeChecker.getRunningAverage(input_buffer_);
    }
}
   

