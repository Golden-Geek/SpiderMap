/*
  ==============================================================================

    MediaNDI.h
    Created: 26 Sep 2020 1:51:42pm
    Author:  Mediaupe

  ==============================================================================
*/

#pragma once


class MediaNDI :
    public Media,
    public NDIInputDevice::NDIInputListener
{
public:
    MediaNDI(var params = var());
    ~MediaNDI();

    NDIDeviceParameter* ndiParam;
    NDIInputDevice* ndiDevice = nullptr;
    ColorParameter* color;

    void clearItem() override;
    void onContainerParameterChangedInternal(Parameter* p) override;
    
    DECLARE_TYPE("NDI")

    void updateDevice();

    //virtual MediaUI* createUI() {return new MediaNDI(); };
};