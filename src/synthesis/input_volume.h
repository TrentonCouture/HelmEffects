/*
  ==============================================================================

    input_volume.h
    Created: 29 Sep 2019 10:08:44pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once
#include "input_processor.h"
#include "running_average.h"

namespace mopo {
  class InputVolume : public InputProcessor {
  public:
	InputVolume();
	virtual ~InputVolume() {}

	virtual void destroy() override;

    virtual Processor* clone() const override {
		return new InputVolume(*this);
    }

    void process() override;
  private:
	  RunningAverage volumeChecker;
  };
}
