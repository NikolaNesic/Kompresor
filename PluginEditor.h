/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class KompresorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KompresorAudioProcessorEditor (KompresorAudioProcessor&);
    ~KompresorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KompresorAudioProcessor& audioProcessor;
    juce::Slider inputSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inputSliderAttachmentptr;
    juce::Slider threshSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> threshSliderAttachmentptr;
    juce::Slider ratioSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ratioSliderAttachmentptr;
    juce::Slider attackSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachmentptr;
    juce::Slider releaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachmentptr;
    juce::Slider outputSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outputSliderAttachmentptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KompresorAudioProcessorEditor)
};
