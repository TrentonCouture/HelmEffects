/*
  ==============================================================================

    running_average.cpp
    Created: 29 Sep 2019 10:10:34pm
    Author:  Trenton

  ==============================================================================
*/

#include "running_average.h"

float RunningAverage::getRunningAverage(AudioBuffer<float>& audioBuffer)
{
	if (m_lastFewVolumes.size() < 100)
	{
		m_lastFewVolumes.push_back(getPositiveAverage(audioBuffer));
		return 0;
	}
	else
	{
		m_lastFewVolumes.pop_front();
		m_lastFewVolumes.push_back(getPositiveAverage(audioBuffer));

		StatisticsAccumulator<float> accumulator;
		for (auto& volume : m_lastFewVolumes)
		{
			accumulator.addValue(volume);
		}
		return accumulator.getAverage();
	}
}

float RunningAverage::getPositiveAverage(AudioBuffer<float> audioBuffer)
{
	StatisticsAccumulator<float> accumulator;
	for (int channel = 0; channel < audioBuffer.getNumChannels(); channel++)
	{
		for (int sample = 0; sample < audioBuffer.getNumSamples(); sample++)
		{
			accumulator.addValue(abs(audioBuffer.getWritePointer(channel)[sample]));
		}
	}

	return accumulator.getAverage();
}

