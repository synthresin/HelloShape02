#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#define MODE_NUM 10

using namespace ci;
using namespace ci::app;
using namespace std;

class HelloShape02App : public AppBasic {
  public:
	void setup();
    void mouseMove( MouseEvent event );
	void mouseDown( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
    
    int mSegment;
    float mSize;
    float mModeDomainY;
};

void HelloShape02App::setup()
{
    mModeDomainY = (float)getWindowHeight() / MODE_NUM;
    gl::clear( Color( 255, 255, 255 ) );
}

void HelloShape02App::mouseMove( MouseEvent event )
{
    Vec2i distVec = event.getPos() - getWindowCenter();
    mSize = distVec.lengthSquared();
    
    int ypos = event.getY();

    for (int i = 0; i < MODE_NUM; i++) {
        if (ypos >= i * mModeDomainY && ypos < ( i + 1 ) * mModeDomainY ) {
            mSegment = i + 3;
        }
    }
}

void HelloShape02App::mouseDown( MouseEvent event )
{
    
    gl::color(255, 0, 0);
    gl::drawStrokedCircle(getWindowCenter(), 50, mSegment);
}

void HelloShape02App::mouseDrag( MouseEvent event )
{
    mouseMove(event);
    mouseDown(event);
}

void HelloShape02App::update()
{
    printf("mSegment: %i \n", mSize);
}

void HelloShape02App::draw()
{
	// clear out the window with black
	// gl::clear( Color( 0, 0, 0 ) );
    
    
    
}

CINDER_APP_BASIC( HelloShape02App, RendererGl )
