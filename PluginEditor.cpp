/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KompresorAudioProcessorEditor::KompresorAudioProcessorEditor (KompresorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 600);
    addAndMakeVisible(inputSlider);
    inputSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    inputSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "input", inputSlider));
    addAndMakeVisible(threshSlider);
    threshSlider.setSliderStyle(juce::Slider::Rotary);
    threshSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "thresh", threshSlider));
    addAndMakeVisible(ratioSlider);
    ratioSlider.setSliderStyle(juce::Slider::Rotary);
    ratioSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "ratio", ratioSlider));
    addAndMakeVisible(attackSlider);
    attackSlider.setSliderStyle(juce::Slider::Rotary);
    attackSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "attack", attackSlider));
    addAndMakeVisible(releaseSlider);
    releaseSlider.setSliderStyle(juce::Slider::Rotary);
    releaseSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "release", releaseSlider));
    addAndMakeVisible(outputSlider);
    outputSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    outputSliderAttachmentptr.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, "output", outputSlider));
}

KompresorAudioProcessorEditor::~KompresorAudioProcessorEditor()
{
}

//==============================================================================
void KompresorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::darkblue);

    g.setColour(juce::Colours::white);
    g.setFont(14);
    g.drawFittedText("Input (dB)", inputSlider.getBounds(), juce::Justification::centredBottom, 1);
    g.drawFittedText("Threshold (dB)", threshSlider.getBounds(), juce::Justification::centredBottom, 1);
    g.drawFittedText("Ratio", ratioSlider.getBounds(), juce::Justification::centredBottom, 1);
    g.drawFittedText("Attack (ms)", attackSlider.getBounds(), juce::Justification::centredBottom, 1);
    g.drawFittedText("Release (ms)", releaseSlider.getBounds(), juce::Justification::centredBottom, 1);
    g.drawFittedText("Output (dB)", outputSlider.getBounds(), juce::Justification::centredBottom, 1);

    juce::Line<float> line(juce::Point<float>(0, 100), juce::Point<float>(200, 100));
    g.drawLine(line, 1.0f);
    juce::Line<float> line1(juce::Point<float>(0, 200), juce::Point<float>(200, 200));
    g.drawLine(line1, 1.0f);
    juce::Line<float> line2(juce::Point<float>(0, 300), juce::Point<float>(200, 300));
    g.drawLine(line2, 1.0f);
    juce::Line<float> line3(juce::Point<float>(0, 400), juce::Point<float>(200, 400));
    g.drawLine(line3, 1.0f);
    juce::Line<float> line4(juce::Point<float>(0, 500), juce::Point<float>(200, 500));
    g.drawLine(line4, 1.0f);
    juce::Line<float> line5(juce::Point<float>(0, 600), juce::Point<float>(200, 600));
    g.drawLine(line5, 1.0f);
}

void KompresorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto bounds = getLocalBounds();
    inputSlider.setBounds(bounds.removeFromTop(bounds.getHeight() * 0.166));
    threshSlider.setBounds(bounds.removeFromTop(bounds.getHeight() * 0.2));
    ratioSlider.setBounds(bounds.removeFromTop(bounds.getHeight() * 0.25));
    attackSlider.setBounds(bounds.removeFromTop(bounds.getHeight() * 0.333));
    releaseSlider.setBounds(bounds.removeFromTop(bounds.getHeight() * 0.5));
    outputSlider.setBounds(bounds.removeFromTop(bounds.getHeight()));
}
