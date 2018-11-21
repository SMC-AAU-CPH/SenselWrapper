/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize(800, 600);

    // specify the number of input and output channels that we want to open
    setAudioChannels(2, 2);
    startTimer(1000.0 / 150.0);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

void MainComponent::hiResTimerCallback()
{
    for (auto sensel : sensels)
    {
        sensel->check();
        
        unsigned int fingerCount = sensel->contactAmount;
        
        for (int f = 0; f < fingerCount; f++)
            if (sensel->fingers[f].state)
                cout << "Sensel[" << sensel->senselIndex << "] Finger ID: " << sensel->fingers[f].fingerID << "\n";
            //cout << "Sensel[" << sensel->senselIndex << "] delta x: " << sensel->fingers[0].delta_x << "\n";
            //cout << "Sensel[" << sensel->senselIndex << "] delta y: " << sensel->fingers[0].delta_y << "\n";
        
    }
}
//==============================================================================
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()

    for (int i = 0; i < amountOfSensels; i++)
        sensels.add(new Sensel(i)); // chooses the device in the sensel device list
    
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{

    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint(Graphics &g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
