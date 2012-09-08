#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#define MODE_NUM 5

using namespace ci;
using namespace ci::app;
using namespace std;

class HelloShape02App : public AppBasic {
  public:
	void setup();
    void mouseMove( MouseEvent event );
    void mouseUp  ( MouseEvent event );
	void mouseDown( MouseEvent event );
	void mouseDrag( MouseEvent event );
    void keyDown  ( KeyEvent event );
	void update();
	void draw();
    
    int mSegment;
    int mSize;
    float mModeDomainY;
    
    bool mDraw;
    bool mRight;
    
    float mOpacity;
};

void HelloShape02App::setup()
{
    mModeDomainY = (float)getWindowHeight() / MODE_NUM;
    mOpacity = 0.1;
    
    gl::enableAlphaBlending();
    gl::clear( Color( 255, 255, 255 ) );
    
    mRight = false;
    gl::color(1, 0.69f, 0.2f, mOpacity);
    glLineWidth(2.5f);
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
    
    int xpos = event.getX();
    if(xpos > getWindowWidth()/2) {
        mRight = true;
    } else mRight = false;
    //glLineWidth(1.0f);
}


void HelloShape02App::mouseDown( MouseEvent event )
{
    mDraw =true;
    
}

void HelloShape02App::mouseUp ( MouseEvent event )
{
    mDraw = false;
}

void HelloShape02App::mouseDrag( MouseEvent event )
{
    mouseMove(event);
    //mouseDown(event);
}

void HelloShape02App::keyDown( KeyEvent event )
{
    if(event.getChar() == '1') {
        gl::color(1, 0.69f, 0.2f, mOpacity);
    } else if(event.getChar() == '2') {
        gl::color(0.28, 0.71, 0.14, mOpacity);
    } else if(event.getChar() == '3') {
        gl::color(0.09f, 0.48, 0.48, mOpacity);
    } else if(event.getChar() == '4') {
        gl::color(0, 0, 0, mOpacity);
    } else if(event.getChar() == '5') {
        gl::clear(Color(1,1,1));
    }
}

void HelloShape02App::update()
{
 //   printf("mSegment: %i \n", mSize/200);
}

void HelloShape02App::draw()
{
	// clear out the window with black
	// gl::clear( Color( 0, 0, 0 ) );
    if(mDraw) {
        gl::pushMatrices();
        
        gl::translate(getWindowCenter());
        if(mRight) gl::rotate(45);
        else gl::rotate(315);
        
        gl::drawStrokedCircle(Vec2f::zero(), sqrt(mSize), mSegment);
        gl::popMatrices();
    }
    
    
    
}

CINDER_APP_BASIC( HelloShape02App, RendererGl )
