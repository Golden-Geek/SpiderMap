/*
  ==============================================================================

    Object.h
    Created: 26 Sep 2020 10:02:32am
    Author:  bkupe

  ==============================================================================
*/

#pragma once

class ScreenRenderer;

class Screen :
    public BaseItem
{
public:
    Screen(var params = var());
    virtual ~Screen();

    String objectType;
    var objectData;
    
    EnablingControllableContainer positionCC;
    IntParameter* screenX;
    IntParameter* screenY;
    IntParameter* screenWidth;
    IntParameter* screenHeight;

    enum OutputType { DISPLAY, SHARED_TEXTURE, NDI };
    EnumParameter* outputType;
    IntParameter* screenID;

    BoolParameter* showTestPattern;
    FloatParameter* snapDistance;

    SurfaceManager surfaces;

    std::unique_ptr<ScreenRenderer> renderer;
    SharedTextureSender* sharedTextureSender;

    void clearItem() override;

    void onContainerParameterChangedInternal(Parameter* p) override;
    void onContainerNiceNameChanged() override;

    void setupOutput();
    
    Point2DParameter* getClosestHandle(Point<float> pos, float maxDistance = INT32_MAX, Array<Point2DParameter*> excludeHandles = {});
    Point2DParameter* getSnapHandle(Point<float> pos, Point2DParameter* handle);
    Array<Point2DParameter*> getOverlapHandles(Point2DParameter* handle);
    Surface* getSurfaceAt(Point<float> pos);

    String getTypeString() const override { return objectType; }
    static Screen* create(var params) { return new Screen(params); }

};


