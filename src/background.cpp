#include "background.h"
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

Background::Background() {
    hillX  = skyscrapperX = smallHillX = cloudFarX = cloudNearX = 0.0;
    sunScale = 1;
}

// ─── Gradient Night Sky ───────────────────────────────────────────────────────
void Background::drawSky() {
    glBegin(GL_QUADS);
        // Top - deep midnight purple
        glColor3f(0.04f, 0.01f, 0.12f);
        glVertex3f(-20.0f, 10.0f, -6.0f);
        glVertex3f( 20.0f, 10.0f, -6.0f);
        // Bottom - dark navy blue
        glColor3f(0.08f, 0.04f, 0.22f);
        glVertex3f( 20.0f, -2.0f, -6.0f);
        glVertex3f(-20.0f, -2.0f, -6.0f);
    glEnd();
}

// ─── Stars ────────────────────────────────────────────────────────────────────
void Background::stars() {
    static float sx[] = {-9.5f,-7.2f,-5.8f,-3.1f,-1.4f, 0.6f, 2.9f, 4.4f, 6.7f, 8.3f,
                         -8.8f,-6.5f,-4.3f,-2.7f,-0.9f, 1.2f, 3.6f, 5.1f, 7.8f, 9.2f,
                         -9.1f,-7.6f,-5.0f,-2.2f,-0.3f, 0.9f, 2.1f, 4.8f, 6.2f, 8.9f,
                          -8.0f,-6.0f,-4.7f,-1.8f, 1.8f, 3.3f, 5.7f, 7.1f, 9.5f,-9.3f};
    static float sy[] = { 5.2f, 6.8f, 5.5f, 7.1f, 6.0f, 5.3f, 6.9f, 5.7f, 7.3f, 6.1f,
                          6.5f, 5.9f, 7.4f, 6.3f, 5.6f, 7.0f, 6.4f, 5.1f, 6.7f, 7.5f,
                          5.8f, 7.2f, 6.6f, 5.4f, 7.6f, 6.2f, 5.0f, 7.8f, 6.0f, 5.3f,
                          7.9f, 6.5f, 5.2f, 7.3f, 6.1f, 5.7f, 7.0f, 6.8f, 5.5f, 7.7f};
    int count = 40;

    // Bright large stars
    glPointSize(3.0f);
    glColor3f(1.0f, 1.0f, 0.85f);
    glBegin(GL_POINTS);
    for(int i = 0; i < count/2; i++)
        glVertex3f(sx[i], sy[i], -5.5f);
    glEnd();

    // Small dim stars
    glPointSize(1.5f);
    glColor3f(0.75f, 0.75f, 0.9f);
    glBegin(GL_POINTS);
    for(int i = count/2; i < count; i++)
        glVertex3f(sx[i], sy[i], -5.5f);
    glEnd();

    glPointSize(1.0f);
}

// ─── Moon (replaces sun) ──────────────────────────────────────────────────────
void Background::sun(){
    Color color;

    // Outer glow ring
    color.setColor("FFF9E0");
    glPushMatrix();
        glScalef(2.2f, 2.2f, 1);
        glTranslatef(-0.05f, -0.05f, 0);
        Shapes::circle(color);
    glPopMatrix();

    // Mid glow
    color.setColor("FFE87C");
    glPushMatrix();
        glScalef(1.6f, 1.6f, 1);
        glTranslatef(-0.07f, -0.07f, 0);
        Shapes::circle(color);
    glPopMatrix();

    // Moon face
    color.setColor("FFD700");
    glPushMatrix();
        Shapes::circle(color);
    glPopMatrix();

    // Moon crater shadow (dark circle offset)
    color.setColor("E8C000");
    glPushMatrix();
        glScalef(0.35f, 0.35f, 1);
        glTranslatef(0.6f, 0.6f, 0);
        Shapes::circle(color);
    glPopMatrix();
}

// ─── Night Clouds ─────────────────────────────────────────────────────────────
void Background::cloud(){
    Color color;
    // Dark blue-gray night clouds with slight highlight
    color.setColor("2C3E6A");

    glPushMatrix();
        glTranslatef(.7f, 0, 0);
        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(.2f, 0, 0);
        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.5f, .5f, 1);
        glTranslatef(-0.7f, 0, 0);
        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.5f, .5f, 1);
        glTranslatef(2.5f, 0, 0);
        Shapes::octagon(color);
    glPopMatrix();
}

// ─── Road ─────────────────────────────────────────────────────────────────────
void Background::road() {
    Color color;

    // Asphalt base
    color.setColor("1A1A1A");
    glPushMatrix();
        glScalef(50, 3, 1);
        Shapes::rect(color);
    glPopMatrix();

    // Road edge lines (white)
    color.setColor("F0F0F0");
    glPushMatrix();
        glScalef(50, .12f, 1);
        glTranslatef(0, 6.5f, 0);
        Shapes::rect(color);
    glPopMatrix();
    glPushMatrix();
        glScalef(50, .12f, 1);
        glTranslatef(0, -0.5f, 0);
        Shapes::rect(color);
    glPopMatrix();

    // Dashed center line (yellow)
    color.setColor("FFD700");
    for(int i = 0; i < 20; i++) {
        glPushMatrix();
            glScalef(1.2f, .08f, 1);
            glTranslatef(i * 2.4f - 12, 16.0f, 0);
            Shapes::rect(color);
        glPopMatrix();
    }
}

// ─── Hills ────────────────────────────────────────────────────────────────────
void Background::hills(){
    Color color;

    color.setColor("1B4332");
    glPushMatrix();
        glScalef(4, 8, 1);
        glTranslatef(1, -12, 0);
        Shapes::circle(color);
    glPopMatrix();

    color.setColor("2D6A4F");
    glPushMatrix();
        glScalef(4, 4, 1);
        glTranslatef(-2, 0, 0);
        Shapes::circle(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(4, 6, 1);
        glTranslatef(2, -1, 0);
        Shapes::circle(color);
    glPopMatrix();
}

// ─── Small Hills ─────────────────────────────────────────────────────────────
void Background::smallHills(){
    Color color;

    color.setColor("1B4332");
    glPushMatrix();
        glScalef(4, 8, 1);
        glTranslatef(1, 0, 0);
        Shapes::triangle(color);
    glPopMatrix();

    color.setColor("2D6A4F");
    glPushMatrix();
        glScalef(4, 4, 1);
        Shapes::triangle(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(4, 6, 1);
        glTranslatef(2, 0, 0);
        Shapes::triangle(color);
    glPopMatrix();
}

// ─── Skyscrapers ─────────────────────────────────────────────────────────────
void Background::drawSkyscrapper(){
    int heights[] = {3,1,3,2,1};
    float x = 0;
    for(int i = 0; i < 5; i++){
        glPushMatrix();
            glTranslatef(x, 0, 0);
            skyscrapper(heights[i]);
        glPopMatrix();
        x += 1.9f;
    }
}

void Background::skyscrapper(int till){
    float y = -4.9f;
    for(int i = 1; i <= till; i++){
        glPushMatrix();
            glTranslatef(0, y, 0);
            skyscrapperHelper();
        glPopMatrix();
        y += 2;
    }
}

void Background::skyscrapperHelper(){
    Color color;

    // Dark building body
    color.setColor("0D1117");
    glPushMatrix();
        glScalef(1.8f, 2, 1);
        glTranslatef(-.07f, -.06f, 0);
        Shapes::rect(color);
    glPopMatrix();

    // Building outline (slight blue tint)
    color.setColor("1C2A3A");
    glPushMatrix();
        glScalef(1.82f, 2.02f, 1);
        glTranslatef(-.075f, -.065f, 0);
        Shapes::rect(color);
    glPopMatrix();

    // Lit windows — warm yellow
    float x = 0, y = 0;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            // Random-ish window glow: alternate lit/unlit
            if((i + j) % 3 != 0) {
                color.setColor("FFD700");
            } else {
                color.setColor("334455");
            }
            glPushMatrix();
                glScalef(.22f, .22f, 1);
                glTranslatef(x, y, 0);
                x += 1.3f;
                Shapes::rect(color);
            glPopMatrix();
        }
        y += 1.5f;
        x = 0;
    }
}

// ─── Main Render ─────────────────────────────────────────────────────────────
void Background::render(){

    // 1. Gradient sky — drawn first, behind everything
    drawSky();

    // 2. Stars
    stars();

    // 3. Moon
    glPushMatrix();
        glTranslatef(-9, 4, 0);
        glScalef(sunScale, sunScale, 1);
        sun();
    glPopMatrix();

    // 4. Far clouds
    glPushMatrix();
        glTranslatef(cloudFarX, 4.5f, 0);
        glScalef(.8f, .8f, 1);
        cloud();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloudFarX+5, 5, 0);
        glScalef(.8f, .8f, 1);
        cloud();
    glPopMatrix();

    // 5. Hills
    glPushMatrix();
        glTranslatef(hillX, -3, 0);
        hills();
    glPopMatrix();

    // 6. Near cloud
    glPushMatrix();
        glTranslatef(cloudNearX+5, 2, 0);
        glScalef(1.2f, 1.2f, 1);
        cloud();
    glPopMatrix();

    // 7. Small hills
    glPushMatrix();
        glScalef(.6f, .6f, 1);
        glTranslatef(smallHillX-5, -6, 0);
        smallHills();
    glPopMatrix();

    // 8. Skyscrapers
    glPushMatrix();
        glTranslatef(skyscrapperX, 2, 0);
        drawSkyscrapper();
    glPopMatrix();

    // 9. Road
    glPushMatrix();
        glTranslatef(-15, -6, 0);
        road();
    glPopMatrix();
}

// ─── Animation ───────────────────────────────────────────────────────────────
void Background::animate(float sunScaleChanger){
    glClearColor(0.04f, 0.01f, 0.12f, 1.0f);  // deep night purple
    skyscrapperX -= (0.004f + overAllSpeed) * 30.0f;
    hillX        -= (0.001f + overAllSpeed) * 30.0f;
    smallHillX   -= (0.003f + overAllSpeed) * 30.0f;
    cloudFarX    -= (.0005f) * 30.0f;
    cloudNearX   -= (.002f) * 30.0f;

    if(sunScale > 1.3f)      sunScaleChanger *= -1;
    else if(sunScale < 1.0f) sunScaleChanger *= -1;
    sunScale += sunScaleChanger * 30.0f;

    if(skyscrapperX < -21)  skyscrapperX = 10;
    if(hillX < -23.2f)      hillX = 16;
    if(smallHillX < -22.2f) smallHillX = 20;
    if(cloudFarX < -23)     cloudFarX = 10;
    if(cloudNearX < -23)    cloudNearX = 10;
}

Background::~Background()
{
    //dtor
}
