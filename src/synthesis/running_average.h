/*
  ==============================================================================

    running_average.h
    Created: 29 Sep 2019 10:10:34pm
    Author:  Trenton

  ==============================================================================
*/

#pragma once

#include <list>
#include "../JuceLibraryCode/JuceHeader.h"

class RunningAverage
{
public:
	float getRunningAverage(AudioBuffer<float>& audioBuffer);
private:
	std::list<float> m_lastFewVolumes;
	float getPositiveAverage(AudioBuffer<float> audioBuffer);
};