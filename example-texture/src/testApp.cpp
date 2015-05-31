#include "testApp.h"

#include "ofxAlembic.h"

ofEasyCam cam;

ofxAlembic::Reader abc;

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0);
	
	string path = "test.abc";
	
	// load allembic file
	abc.open(path);
	
	// show all drawable names
	abc.dumpNames();
	abc.setTime(0);

	//texture loading
	ofDisableArbTex();
	image.loadImage("Tex/0.jpg");
	face.loadImage("Tex/1.jpg");
	pro.loadImage("Tex/2.jpg");
	ofEnableArbTex();

}

void testApp::exit()
{
	abc.close();
}

//--------------------------------------------------------------
void testApp::update()
{
	float t = fmodf(ofGetElapsedTimef(), abc.getMaxTime());
	abc.setTime(t);
}

//--------------------------------------------------------------
void testApp::draw()
{
	cam.begin();
	
	ofMesh m_plane, m_face, m_propeller;
	
	abc.get(1, m_plane);
	abc.get(3, m_face);
	abc.get(5, m_propeller);
	
	ofEnableDepthTest();
	texDraw(image, m_plane);
	texDraw(pro, m_propeller);
	texDraw(face, m_face);
	ofDisableDepthTest();
	
	cam.end();
	
	ofSetColor(255);
	
	ofDrawBitmapString(ofToString(abc.getTime()) + "/" + ofToString(abc.getMaxTime()), 10, 20);
	
}

void testApp::texDraw(ofImage &img, ofMesh &mesh){
	img.getTextureReference().bind();
	mesh.draw();
	img.getTextureReference().unbind();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}