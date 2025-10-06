#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <mmsystem.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>


void sound()

{


    PlaySound("bgm.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}




// Variable to track the current scene (1, 2, or 3)
int currentScene = 1;


int lightState = 0;     // 0 = Red, 1 = Yellow, 2 = Greenint timerCount = 0;
int timerCount=0;
void renderBitmapString(float x, float y, float z, void *font, char *string){
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
GLfloat position = 0.0f;
GLfloat speed = 10.0f;
GLfloat position1 = 0.0f;
GLfloat speed1 = 2.0f;
GLfloat position2 = 0.0f;
GLfloat speed2 = 2.0f;
GLfloat position3=0.0f;
GLfloat speed3 = 4.0f;
void update(int value){
    if(position <-1000)
    position = -2000.0f;

    position -= speed;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
void update1(int value1){
    if(position1 >=50)
        position1 = 1000.0f;
    position1 += speed1;
    glutPostRedisplay();
    glutTimerFunc(100, update1, 0);
}
void update2(int value2){
    if(position2 >=190)
        position2 = 1000.0f;
    position2 += speed2;
    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}
void update3(int value2){
    if(position3 >=1300)
        position3= 0.0f;
    position3 += speed3;
    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}
void chotojanala(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.427f, 0.419f, 0.404f);
    glVertex2f(787.8198813147462, 502.7508454868938);
    glVertex2f(808.8495982778238, 502.7508454868938);
    glVertex2f(798.0254792527104, 529.9657733285167);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.427f, 0.419f, 0.404f);
    glVertex2f(788.9479596646152, 476.7025703056669);
    glVertex2f(806.5671288653665, 477.1662326531753);
    glVertex2f(806.5671288653665, 502.7508454868938);
    glVertex2f(788.9479596646152, 502.7508454868938);
    glEnd();
}
void drawCircle(float cx, float cy, float r, float red, float green, float blue){
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float theta = 2.0f * 3.1415926f * i / 100;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
void drawRectangle(float x, float y, float w, float h, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}
void drawTriangle(float x, float y, float w, float h, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w / 2, y + h);
    glEnd();
}
void drawRealisticStudent(float x, float y, float scale){
    // Head
    drawCircle(x, y + 35 * scale, 10 * scale, 0.0f, 0.0f, 0.0f); // black head
    // Body
    drawRectangle(x - 8 * scale, y + 10 * scale, 16 * scale, 20 * scale, 0.0f, 0.3f, 1.0f); // blue shirt
    // Arms
    drawRectangle(x - 13 * scale, y + 10 * scale, 5 * scale, 15 * scale, 1.0f, 0.85f, 0.7f); // left arm
    drawRectangle(x + 8 * scale, y + 10 * scale, 5 * scale, 15 * scale, 1.0f, 0.85f, 0.7f);  // right arm
    // Pants
    drawRectangle(x - 8 * scale, y - 10 * scale, 16 * scale, 20 * scale, 0.0f, 0.0f, 0.5f); // navy pants
    // Legs
    drawRectangle(x - 6 * scale, y - 30 * scale, 5 * scale, 20 * scale, 1.0f, 0.85f, 0.7f); // left leg
    drawRectangle(x + 1 * scale, y - 30 * scale, 5 * scale, 20 * scale, 1.0f, 0.85f, 0.7f); // right leg
    // Shoes
    drawRectangle(x - 7 * scale, y - 35 * scale, 7 * scale, 5 * scale, 0.0f, 0.0f, 0.0f); // left shoe
    drawRectangle(x + 1 * scale, y - 35 * scale, 7 * scale, 5 * scale, 0.0f, 0.0f, 0.0f); // right shoe
    // School bag
    drawRectangle(x - 9 * scale, y + 15 * scale, 18 * scale, 20 * scale, 0.5f, 0.25f, 0.0f); // brown bag
}
void drawArchedWindow(float x, float y, float width, float height, float r, float g, float b){
    drawRectangle(x, y, width, height * 0.6f, r, g, b);
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i += 5){
        float theta = i * 3.1415926f / 180.0f;
        float cx = x + width / 2;
        float cy = y + height * 0.6f;
        float rx = width / 2;
        float ry = height * 0.4f;
        glVertex2f(cx + rx * cosf(theta), cy + ry * sinf(theta));
    }
    glEnd();
    glPushMatrix();
    glTranslatef(0,10,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y + height * 0.3f);
    glVertex2f(x + width, y + height * 0.3f);
    glEnd();
    glPopMatrix();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);

    for(int i=0;i<width;i+=2){
    glVertex2f(x+i,y);
    glVertex2f(x+i, y+height*.6f);
    }
    glEnd();

}
void drawCloud(float x, float y){
    drawCircle(x, y, 20, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 20, y + 10, 25, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 40, y, 20, 1.0f, 1.0f, 1.0f);
}
void drawCloud2(float x, float y){
    drawCircle(x, y, 30,1.0f, 1.0f, 1.0f);
    drawCircle(x + 30, y + 30, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 70, y + 30,35,  1.0f, 1.0f, 1.0f);
    drawCircle(x + 115, y + 20, 35,  1.0f, 1.0f, 1.0f);

    drawCircle(x -5, y - 35, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +35, y - 50, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +80, y - 45, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +125, y - 45, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +145, y - 10, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +30, y - 15, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +70, y - 15, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +110, y - 15, 35,   1.0f, 1.0f, 1.0f);
}
void drawEllipse(float cx, float cy, float rx, float ry, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(100);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
void treeHead(float x, float y){
    drawCircle(x, y, 30, 0.350f, 0.75f, 0.310f);
    drawCircle(x + 30, y + 30, 30, 0.350f, 0.75f, 0.310f);
    drawCircle(x + 70, y + 30, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x + 115, y + 20, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x -5, y - 35, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x +35, y - 50, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x +80, y - 45, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x +125, y - 45, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x +145, y - 10, 30,  0.350f, 0.75f, 0.310f);
    drawCircle(x +30, y - 15, 30, 0.580f, 0.810f, 0.330f);
    drawCircle(x +70, y - 15, 30, 0.580f, 0.810f, 0.330f);
    drawCircle(x +110, y - 15, 30, 0.580f, 0.810f, 0.330f);
}
void tree(){
    glPushMatrix();
    glScalef(1.70f,1.30f,1.0f);
    glTranslatef(-180,-110,0);
    treeHead(224, 300);
    glPopMatrix();
    //lower body
    glBegin(GL_POLYGON);
    glColor3f(0.31, 0.14, 0.027);
    glVertex2f(155.7301236202257, 72.0421515010932);
    glVertex2f(149.7579089946561, 38.9621624402731);
    glVertex2f(112.6960693987372, 23.6473526898933);
    glVertex2f(109.9394036436688, 17.5214287897415);
    glVertex2f(138.7312459743827, 22.7284641048706);
    glVertex2f(160, 20);
    glVertex2f(161.7034605999523, 10.4766163045668);
    glVertex2f(170.5860502551726, 11.7018010845972);
    glVertex2f(177.3843278361614, 19.1407737645242);
    glVertex2f(193.314960066708, 29.9674170280025);
    glVertex2f(205.533600321205, 31.0500813543503);
    glVertex2f(216.2055772523479, 28.1114210399776);
    glVertex2f(226.6382539415623, 18.4403173747642);
    glVertex2f(236.746028376813, 17.2151325947339);
    glVertex2f(243.48454466698, 16.2962440097111);
    glVertex2f(249.3041723721244, 18.1340211797566);
    glVertex2f(276.8347795278264, 18.8314410998534);
    glVertex2f(285.9600931356152, 19.450106429195);
    glVertex2f(294.0027424170563, 19.6047727615304);
    glVertex2f(296.3599253008474, 21.5550384412671);
    glVertex2f(294.9307404110687, 24.0900963992571);
    glVertex2f(275.2881162044724, 30.4314160250087);
    glVertex2f(258.8934849769195, 35.6900713244124);
    glVertex2f(242.9628527463729, 46.6713809202262);
    glVertex2f(232.1362094828945, 59.6633528364001);
    glVertex2f(224.5575591984597, 76.3673167286238);
    glVertex2f(220.1004480864475, 102.6001679539584);
    glVertex2f(218.8124236827546, 133.11359853248);
    glVertex2f(227.6746429812014, 146.8553798637673);
    glVertex2f(244.9322358476004, 158.1963839259493);
    glVertex2f(280.2181474456824, 166.6553353364484);
    glVertex2f(271.517511709169, 175.3559710729617);
    glVertex2f(221.9722248762456, 155.7795406658067);
    glVertex2f(245.7863004155707, 189.0981758349485);
    glVertex2f(232.1465729448739, 187.7063669093672);
    glVertex2f(211.3302902420866, 166.4291688786665);
    glVertex2f(217.933372660573, 174.1546222496312);
    glVertex2f(216.3155210583334, 195.6444969983423);
    glVertex2f(193.8149076410676, 202.764944282287);
    glVertex2f(187.2640961398383, 172.0046120156455);
    glVertex2f(175.3017447028109, 196.2141327810578);
    glVertex2f(166.1875721793615, 192.7963180847643);
    glVertex2f(177.2954699423155, 168.0171615366365);
    glVertex2f(177.2954699423155, 168.0171615366365);
    glVertex2f(148.5288629151782, 180.2643308650215);
    glVertex2f(137.705783043582, 173.4287014724345);
    glVertex2f(177.2954699423155, 142.0987334230774);
    glVertex2f(180, 100);
    glVertex2f(172.7301236202257, 72.0421515010932);
    glVertex2f(149.7579089946561, 38.9621624402731);
    glEnd();

    //tree right part
    glBegin(GL_POLYGON);
    glColor3f(0.31, 0.14, 0.027);
    glVertex2f(224.5575591984597, 76.3673167286238);
    glVertex2f(263.6274868719692, 104.7738362350868);
    glVertex2f(230.6512297416402, 111.5561168760047);
    glVertex2f(220.1004480864475, 102.6001679539584);

    glEnd();
    drawEllipse(247.0f, 109.0f, 18.0f, 8.0f, 0.55f, 0.38f, 0.20f); // bark
    drawEllipse(247.0f, 109.0f, 13.5f, 6.0f, 0.76f, 0.60f, 0.42f); // sapwood
    drawEllipse(247.0f, 109.0f, 8.0f, 3.5f, 0.65f, 0.45f, 0.25f);  // heartwood
}
void drawTrafficLight(float x, float y){
    //Pole
    drawRectangle(x + 40, y - 200, 15, 300, 0.2f, 0.2f, 0.2f);

    // Light box
    drawRectangle(x, y, 100, 250, 0.1f, 0.1f, 0.1f);

    // Lights
    if (lightState == 0){ // RED ON
        drawCircle(x + 50, y + 200, 30, 1.0f, 0.0f, 0.0f);
        drawCircle(x + 50, y + 125, 30, 0.2f, 0.2f, 0.0f);
        drawCircle(x + 50, y + 50, 30, 0.0f, 0.2f, 0.0f);
    }
    else if (lightState == 1){ // YELLOW ON
        drawCircle(x + 50, y + 200, 30, 0.2f, 0.0f, 0.0f);
        drawCircle(x + 50, y + 125, 30, 1.0f, 1.0f, 0.0f);
        drawCircle(x + 50, y + 50, 30, 0.0f, 0.2f, 0.0f);
    }
    else if (lightState == 2){ // GREEN ON
        drawCircle(x + 50, y + 200, 30, 0.2f, 0.0f, 0.0f);
        drawCircle(x + 50, y + 125, 30, 0.2f, 0.2f, 0.0f);
        drawCircle(x + 50, y + 50, 30, 0.0f, 1.0f, 0.0f);
    }
}
void drawBird(float x, float y, float scale){

    float bodyWidth  = 35 * scale;
    float bodyHeight = 28 * scale;
    float eyeRadius  = 4 * scale;

    // Body
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(20, 0, 0, 1);
    drawEllipse(0, 0, bodyWidth, bodyHeight, 0.9f, 0.6f, 0.2f);
    glPopMatrix();

    //Wing
    glPushMatrix();
    glTranslatef(x - 5 * scale, y + 5 * scale, 0);
    glRotatef(-25, 0, 0, 1);
    drawEllipse(0, 0, 22 * scale, 15 * scale, 0.7f, 0.4f, 0.1f);
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_LINES);
    for (int i = -1; i <= 2; i++){
        float offset = i * 5 * scale;
        glVertex2f(-10 * scale, offset);
        glVertex2f(15 * scale, offset - 5 * scale);
    }
    glEnd();
    glPopMatrix();

    //beak
    glPushMatrix();
    glTranslatef(x + bodyWidth - (4 * scale), y + 2* scale, 0);
    glRotatef(15, 0, 0, 1);
    drawTriangle(0, 0, 12 * scale, 8 * scale, 1.0f, 0.6f, 0.0f);
    glColor3f(0.8f, 0.4f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(12 * scale, -1 * scale);
    glEnd();
    glPopMatrix();

    //eye
    drawCircle(x + 12 * scale, y + 8 * scale, eyeRadius, 0.0f, 0.0f, 0.0f);

    // tail
    drawTriangle(x - bodyWidth - 5 * scale,  y + 4 * scale, 12 * scale, 18 * scale, 0.5f, 0.3f, 0.1f);
    drawTriangle(x - bodyWidth - 10 * scale, y,              12 * scale, 18 * scale, 0.5f, 0.3f, 0.1f);
    drawTriangle(x - bodyWidth - 5 * scale,  y - 4 * scale,  12 * scale, 18 * scale, 0.5f, 0.3f, 0.1f);
}
void timer(int value){
    timerCount++;

    // RED = 10s, YELLOW = 5s, GREEN = 30s
    if (lightState == 0 && timerCount >= 6){ // after 10s red → yellow
        lightState = 1;
        timerCount = 0;
    }
    else if (lightState == 1 && timerCount >= 3){ // after 5s yellow → green
        lightState = 2;
        timerCount = 0;
    }
    else if (lightState == 2 && timerCount >= 30){ // after 30s green → red
        lightState = 0;
        timerCount = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0);
}
void bus(){
    glPushMatrix();
    //body
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.796f, 0.157f);
    glVertex2f(350, 610);
     glVertex2f(860, 610);
    glVertex2f(860, 710);
    glVertex2f(390, 710);
    glVertex2f(350, 660);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(343,672);
    glVertex2f(350,660);
    glEnd();
    glLineWidth(1.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(343,684);
    glVertex2f(343,672);
    glEnd();
    glLineWidth(1.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(343,684);
    glVertex2f(352,684);
    glVertex2f(352,672);
    glVertex2f(343,672);
    glEnd();

    glColor3f(0.6f, 0.8f, 0.95f);
    glBegin(GL_QUADS);
    glVertex2f(344,683);
    glVertex2f(351,683);
    glVertex2f(351,673);
    glVertex2f(344,673);
    glEnd();

    //janala
    glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.8f, 0.95f);
        glVertex2f(360, 663);
        glVertex2f(395, 703);
        glVertex2f(440, 703);
        glVertex2f(440, 663);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(360, 663);
        glVertex2f(395, 703);
        glVertex2f(440, 703);
        glVertex2f(440, 663);
        glEnd();

    for (float x = 465; x <= 800; x += 105){
        glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.8f, 0.95f);
        glVertex2f(x, 663);
        glVertex2f(x, 703);
        glVertex2f(x+65, 703);
        glVertex2f(x+65, 663);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 663);
        glVertex2f(x, 703);
        glVertex2f(x+65, 703);
        glVertex2f(x+65, 663);
        glEnd();
    }

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(350, 660);
    glVertex2f(860, 660);
    glEnd();
    glLineWidth(1.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(350, 630);
    glVertex2f(860, 630);
    glEnd();
    glLineWidth(1.0f);

    //wheels
    drawCircle(460, 610, 28, 0.0f, 0.0f, 0.0f);
    drawCircle(460, 610, 20, 0.7f, 0.7f, 0.7f);
    drawCircle(760, 610, 28, 0.0f, 0.0f, 0.0f);
    drawCircle(760, 610, 20, 0.7f, 0.7f, 0.7f);

    const char* label = "STUDENT BUS";
    glColor3f(0.0f, 0.0f, 0.0f);
    for (float dx = -1; dx <= 1; dx += 1){
        for (float dy = -1; dy <= 1; dy += 1){
            glRasterPos2f(518 + dx, 636 + dy);
            for (const char* c = label; *c != '\0'; c++){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
            }
        }
    }

    // stop
    float cx = 820;
    float cy = 645.5f;
    float r  = 15;

    glColor3f(0.86f, 0.08f, 0.24f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 8; i++){
        float angle = M_PI/8 + i * M_PI/4;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 8; i++){
        float angle = M_PI/8 + i * M_PI/4;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(cx - 12.5, cy - 4);
    const char* stopText = "STOP";
    for (const char* c = stopText; *c != '\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }

    drawCircle(350,648,8,0,0,0);
    drawCircle(350,648,6,1,1,1);
    glPopMatrix();
}
void drawChristmasTree(float x, float y, float w, float h){

    float trunkH   = h * 0.18f;
    float trunkW   = w * 0.18f;
    float foliageH = h - trunkH;
    int   layers   = 5;
    float layerH   = foliageH / (layers + 0.5f);
    float overlap  = layerH * 0.3f;

    glColor3f(0.45f, 0.25f, 0.10f);
    glBegin(GL_QUADS);
    glVertex2f(x - trunkW * 0.5f, y);
    glVertex2f(x + trunkW * 0.5f, y);
    glVertex2f(x + trunkW * 0.5f, y + trunkH);
    glVertex2f(x - trunkW * 0.5f, y + trunkH);
    glEnd();

    for (int i = 0; i < layers; ++i)
    {

        float baseY = y + trunkH + i * (layerH - overlap);
        float topY  = baseY + layerH;
        float halfW = (w * 0.5f) * (1.0f - 0.15f * i);

        // Base
        glColor3f(0.0f, 0.45f + 0.1f * (layers - i), 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x - halfW, baseY);
        glVertex2f(x,         topY);
        glVertex2f(x + halfW, baseY);
        glEnd();

        float shadowW = halfW * 0.6f;
        float shadowH = layerH * 0.6f;
        float shadowOffsetX = -halfW * 0.15f;
        float shadowBaseY = baseY + (layerH - shadowH) * 0.5f;

        float shadowTopY  = shadowBaseY + shadowH;

        glColor3f(0.0f, 0.3f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x - shadowW + shadowOffsetX, shadowBaseY);
        glVertex2f(x + shadowOffsetX,           shadowTopY);
        glVertex2f(x + shadowW + shadowOffsetX, shadowBaseY);
        glEnd();

        // Highlight side
        float insetW = halfW * 0.6f;
        float insetH = layerH * 0.6f;
        float highlightOffsetX = halfW * 0.15f;
        float insetBaseY = baseY + (layerH - insetH) * 0.5f;
        float insetTopY  = insetBaseY + insetH;

        glColor3f(0.4f, 0.85f, 0.4f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x - insetW + highlightOffsetX, insetBaseY);
        glVertex2f(x + highlightOffsetX,          insetTopY);
        glVertex2f(x + insetW + highlightOffsetX, insetBaseY);
        glEnd();
    }
}
void Grass(int x, int y){
    glPushMatrix();

    // First leaf
    glBegin(GL_POLYGON);
    glColor3f(0.49f, 0.82f, 0.0509f);
    glVertex2i(x + 20, y + 0);
    glVertex2i(x + 9, y + 24);
    glVertex2i(x + 29, y + 0);
    glEnd();

    // Second leaf
    glBegin(GL_POLYGON);
    glColor3f(0.121f, 0.32f, 0.027f);
    glVertex2i(x + 20, y + 0);
    glVertex2i(x + 16, y + 40);
    glVertex2i(x + 29, y + 0);
    glEnd();

    // Third leaf
    glBegin(GL_POLYGON);
    glColor3f(0.49f, 0.82f, 0.0509f);
    glVertex2i(x + 20, y + 0);
    glVertex2i(x + 29, y + 40);
    glVertex2i(x + 29, y + 0);
    glEnd();

    // Fourth leaf
    glBegin(GL_POLYGON);
    glColor3f(0.121f, 0.32f, 0.027f);
    glVertex2i(x + 20, y + 0);
    glVertex2i(x + 40, y + 32);
    glVertex2i(x + 29, y + 0);
    glEnd();

    glPopMatrix();
}

static void polygonCentroid(const int verts[][2], int count, float* cx, float* cy) {
    double A = 0.0, Cx = 0.0, Cy = 0.0;
    for (int i = 0; i < count; i++) {
        int j = (i + 1) % count;
        double cross = (double)verts[i][0] * verts[j][1] - (double)verts[j][0] * verts[i][1];
        A += cross;
        Cx += (verts[i][0] + verts[j][0]) * cross;
        Cy += (verts[i][1] + verts[j][1]) * cross;
    }
    A *= 0.5;
    if (A == 0) { *cx = verts[0][0]; *cy = verts[0][1]; return; }
    *cx = (float)(Cx / (6.0 * A));
    *cy = (float)(Cy / (6.0 * A));
}

static int pointInPolygon(float x, float y, const int verts[][2], int count) {
    int wn = 0;
    for (int i = 0; i < count; i++) {
        int j = (i + 1) % count;
        float yi = (float)verts[i][1], yj = (float)verts[j][1];
        float xi = (float)verts[i][0], xj = (float)verts[j][0];
        int intersect = ((yi <= y && y < yj) || (yj <= y && y < yi));
        if (intersect) {
            float xint = xi + (y - yi) * (xj - xi) / (yj - yi);
            if (x < xint) wn = !wn;
        }
    }
    return wn;
}
static void drawMountainFillWithGradient(const int verts[][2], int count) {
    float cx, cy;
    polygonCentroid(verts, count, &cx, &cy);

    float minY = (float)verts[0][1], maxY = (float)verts[0][1];
    for (int i = 1; i < count; i++) {
        if (verts[i][1] < minY) minY = (float)verts[i][1];
        if (verts[i][1] > maxY) maxY = (float)verts[i][1];
    }

    glBegin(GL_TRIANGLE_FAN);
        float tC = (cy - minY) / (maxY - minY);
        float rC = (1.0f - tC) * 0.2f + tC * 1.0f;
        glColor3f(rC, rC, rC);
        glVertex2f(cx, cy);

        for (int i = 0; i < count; i++) {
            float y = (float)verts[i][1];
            float t = (y - minY) / (maxY - minY);
            float r = (1.0f - t) * 0.2f + t * 1.0f;
            glColor3f(r, r, r);
            glVertex2i(verts[i][0], verts[i][1]);
        }

        float y0 = (float)verts[0][1];
        float t0 = (y0 - minY) / (maxY - minY);
        float r0 = (1.0f - t0) * 0.2f + t0 * 1.0f;
        glColor3f(r0, r0, r0);
        glVertex2i(verts[0][0], verts[0][1]);
    glEnd();
}
static void drawMountainOutline(const int verts[][2], int count) {
    glLineWidth(2.0f);
    glColor3f(0.05f, 0.05f, 0.05f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < count; i++) {
        glVertex2i(verts[i][0], verts[i][1]);
    }
    glEnd();
}
static void drawMountainStriations(const int verts[][2], int count, float minX, float maxX, float minY, float maxY) {
    float spacing = 70.0f;
    float slope   = 0.25f;
    float lenPad  = 30.0f;

    glLineWidth(1.0f);
    glColor3f(0.25f, 0.25f, 0.25f);

    for (float baseX = minX - 100.0f; baseX <= maxX + 100.0f; baseX += spacing) {
        float yStart = minY - lenPad;
        float yEnd   = maxY + lenPad;

        glBegin(GL_LINE_STRIP);
        int drawing = 0;
        for (float y = yStart; y <= yEnd; y += 10.0f) {
            float x = baseX + slope * (y - yStart);
            float wave = 15.0f * sinf(y * 0.02f + baseX * 0.05f); // waviness
            x += wave;

            int inside = pointInPolygon(x, y, verts, count);
            if (inside) {
                if (!drawing) {
                    glEnd();
                    glBegin(GL_LINE_STRIP);
                    drawing = 1;
                }
                glVertex2f(x, y);
            } else {
                if (drawing) {
                    glEnd();
                    glBegin(GL_LINE_STRIP);
                    drawing = 0;
                }
            }
        }
        glEnd();
    }
}
static void drawRockType1(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + w * 0.6f, y + h * 0.5f);
        glVertex2f(x + w,        y + h * 0.1f);
        glVertex2f(x + w * 0.78f, y - h * 0.55f);
        glVertex2f(x + w * 0.28f, y - h * 0.45f);
    glEnd();
}
static void drawRockType2(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + w * 0.45f, y + h * 0.75f);
        glVertex2f(x + w * 0.95f, y + h * 0.25f);
        glVertex2f(x + w * 0.88f, y - h * 0.35f);
        glVertex2f(x + w * 0.42f, y - h * 0.55f);
        glVertex2f(x + w * 0.12f, y - h * 0.25f);
    glEnd();
}
static void drawRockType3(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x + w * 0.10f, y);
        glVertex2f(x + w * 0.55f, y + h * 0.65f);
        glVertex2f(x + w * 1.00f, y + h * 0.20f);
        glVertex2f(x + w * 0.90f, y - h * 0.20f);
        glVertex2f(x + w * 0.50f, y - h * 0.60f);
        glVertex2f(x + w * 0.15f, y - h * 0.30f);
    glEnd();
}
static void drawRock(int type, float x, float y, float w, float h, float r, float g, float b) {
    switch (type % 3) {
        case 0: drawRockType1(x, y, w, h, r, g, b); break;
        case 1: drawRockType2(x, y, w, h, r, g, b); break;
        default: drawRockType3(x, y, w, h, r, g, b); break;
    }
}
static void sprinkleRocks(const int verts[][2], int count, float minX, float maxX, float minY, float maxY) {
    float stepX = 140.0f;
    float stepY = 110.0f;
    int index = 0;

    for (float y = minY; y <= maxY; y += stepY) {
        for (float x = minX; x <= maxX; x += stepX) {
            if (pointInPolygon(x, y, verts, count)) {
                int type = index % 3;
                float w, h;
                if (index % 3 == 0) { w = 30; h = 18; }
                else if (index % 3 == 1) { w = 45; h = 28; }
                else { w = 60; h = 36; }
                float shade;
                if (index % 3 == 0) shade = 0.12f;
                else if (index % 3 == 1) shade = 0.16f;
                else shade = 0.08f;

                drawRock(type, x, y, w, h, shade, shade, shade);
                index++;
            }
        }
    }
}
void drawMountain() {
    int verts[][2] = {
        {0, 267}, {1300, 267}, {1300, 450}, {1300, 500},
        {1188, 570}, {1136, 543}, {1033, 630}, {880, 567},
        {827, 596}, {557, 790}, {357, 650}, {327, 658},
        {167, 540}, {102, 584}, {0, 526}
    };
    int count = (int)(sizeof(verts) / sizeof(verts[0]));

    // Bounds
    float minX = (float)verts[0][0], maxX = (float)verts[0][0];
    float minY = (float)verts[0][1], maxY = (float)verts[0][1];
    for (int i = 1; i < count; i++) {
        if (verts[i][0] < minX) minX = (float)verts[i][0];
        if (verts[i][0] > maxX) maxX = (float)verts[i][0];
        if (verts[i][1] < minY) minY = (float)verts[i][1];
        if (verts[i][1] > maxY) maxY = (float)verts[i][1];
    }
    drawMountainFillWithGradient(verts, count);
    drawMountainOutline(verts, count);
    drawMountainStriations(verts, count, minX, maxX, minY, maxY);
    sprinkleRocks(verts, count, minX, maxX, minY, maxY);
}






float raindropX[2000];
float raindropY[2000];
float raindropSpeed[2000];


bool isRaining = false;


void initRain() {
    srand(time(NULL));

    for (int i = 0; i < 2000; i++) {
        raindropX[i] = rand() % 1300;
        raindropY[i] = rand() % 800;
        raindropSpeed[i] = (rand() % 3 + 2) * 0.5f;
    }
}


void updateRain() {
    for (int i = 0; i <2000; i++) {
        raindropY[i] -= raindropSpeed[i];
        if (raindropY[i] < 0) {
            raindropY[i] = 800;
            raindropX[i] = rand() % 1300;
        }
    }
}


void drawRain() {
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 2000; i++) {
        glBegin(GL_LINES);
        glVertex2f(raindropX[i], raindropY[i]);
        glVertex2f(raindropX[i], raindropY[i] -10);
        glEnd();
    }
}


void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isRaining) {
            isRaining = false;
        } else {
            isRaining = true;
            initRain();
        }
    }
}


void display1_view() {
   glClearColor(0.5290f, 0.808f, 0.922f, 0.0f);
         if (isRaining) {

glClearColor(0.5843f, 0.6471f, 0.7098f, 0.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);
    glBegin(GL_LINE);

    //cloud
    glPushMatrix();
    glTranslatef(position3,0,0);
    drawCloud(1050, 650);
    drawCloud(450, 720);
    glPopMatrix();
    glPushMatrix();
    glScalef(0.5f, 0.4f, 0.0f);
    glTranslatef(position3, 1200.0f, 0.0f);
    drawCloud2(100, 690);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f, 0.6f, 0.0f);
    glTranslatef(position3, 520.0f, 0.0f);
    drawCloud2(100, 690);
    glPopMatrix();

    drawMountain();

    drawCloud(1050, 650);
    glPushMatrix();
    glScalef(0.6f, 0.5f, 0.0f);
    glTranslatef(0.0f, 750.0f, 0.0f);
    drawCloud2(100, 690);
    glPopMatrix();

// left grass down
    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(209.16, 75.5);
    glVertex2i(0, 75.58);
    glEnd();

    // right grass down
    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2i(514.9756, 0);
    glVertex2i(1300, 0);
    glVertex2i(1298.5649, 78.9036);
    glVertex2i(583.4593, 78.9036);
    glEnd();

// right left street road
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex2i(0, 184.7055);
    glVertex2i(1300, 184.7055);
    glVertex2i(1300, 200);
    glVertex2i(0, 200);
    glEnd();

    // right left street road par
    glBegin(GL_QUADS);
    glColor3f(0.72f, 0.36f, 0.188f);
    glVertex2i(0,175.3604);
    glVertex2i(1300, 176.1698);
    glVertex2i(1300, 184.7055);
    glVertex2i(0, 184.7055);
    glEnd();

    // school street entry
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex2i(453.2250,200);
    glVertex2i(611.0527, 200);
    glVertex2i(695.4265, 269.3066);
    glVertex2i(595.5435, 267.9173);
    glEnd();

    //road big
    glBegin(GL_QUADS);
    glColor3f(0.4156f, 0.502f, 0.5f);
    glVertex2i(0, 74.5831);
    glVertex2i(1298.5649, 75.1807);
    glVertex2i(1300, 177.1698);
    glVertex2i(0, 177.1698);
    glEnd();

    //road small
    glBegin(GL_QUADS);
    glColor3f(0.4156f, 0.502f, 0.5f);
    glVertex2i(100, 0);
    glVertex2i(514.9756, 0);
    glVertex2i(583.4593, 78.9036);
    glVertex2i(209.1593, 75);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White stripes
    glBegin(GL_QUADS);
    glVertex2f(236.1810, 56.6372); // Stripe 1
    glVertex2f(515, 56.6372);
    glVertex2f(535.0499, 73.0444);
    glVertex2f(264.1034, 73.0444);
    glVertex2f(266.1810, 76.6372); // Stripe 2
    glVertex2f(535.0499, 76.6372);
    glVertex2f(555, 93.0444);
    glVertex2f(294.1034, 93.0444);
    glVertex2f(296.1810, 96.6372); // Stripe 3
    glVertex2f(555, 96.6372);
    glVertex2f(574.9501, 113.0444);
    glVertex2f(324.1034, 113.0444);
    glVertex2f(326.1810, 116.6372); // Stripe 4
    glVertex2f(574.9501, 116.6372);
    glVertex2f(594.9002, 133.0444);
    glVertex2f(354.1034, 133.0444);
    glVertex2f(356.1810, 136.6372); // Stripe 5
    glVertex2f(594.9002, 136.6372);
    glVertex2f(614.8503, 153.0444);
    glVertex2f(384.1034, 153.0444);
    glVertex2f(386.1810, 156.6372); // Stripe 6
    glVertex2f(614, 156.6372);
    glVertex2f(634.8004, 173.0444);
    glVertex2f(414.1034, 173.0444);
    glEnd();

    //road divider
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 6; ++i){
        float xOffset = 120.0f - i * 120.0f;

        glBegin(GL_QUADS);
        glVertex2f(1096.6458f + xOffset, 134.0016f);
        glVertex2f(1177.7360f + xOffset, 134.0016f);
        glVertex2f(1173.4877f + xOffset, 141.8735f);
        glVertex2f(1097.4758f + xOffset, 141.8969f);
        glEnd();
    }
    for (int i = 8; i < 11; ++i){
        float xOffset = 120.0f - i * 120.0f;

        glBegin(GL_QUADS);
        glVertex2f(1096.6458f + xOffset, 134.0016f);
        glVertex2f(1177.7360f + xOffset, 134.0016f);
        glVertex2f(1173.4877f + xOffset, 141.8735f);
        glVertex2f(1097.4758f + xOffset, 141.8969f);
        glEnd();
    }
    glPopMatrix();

    //buildings
    drawRectangle(307.819016505051f, 268.1426795192467f, 58.4847553765548f, 250.0f, 0.663, 0.663, 0.663);  //L1

    glPushMatrix(); //L2
    glScalef(2.0f, 1.0f, 1.0f);
    glTranslatef(-143.0f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f,0.412, 0.412, 0.412);
    glPopMatrix();

    glPushMatrix(); //L3
    glScalef(0.5f, 1.0f, 1.0f);
    glTranslatef(635.0f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 59.4847553765548f, 236.0087315738737f,0.663f, 0.663f, 0.663f);
    glPopMatrix();

    glPushMatrix(); //L4
    glScalef(0.8f, 1.0f, 1.0f);
    glTranslatef(312.0f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 59.0f, 236.0087315738737f, 0.412, 0.412, 0.412);
    glPopMatrix();

    glPushMatrix(); //CB
    glScalef(3.0f, 1.0f, 1.0f);
    glTranslatef(-140.09f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f,0.886f, 0.847f, 0.800f);
    glPopMatrix();

    glPushMatrix(); //CS
    glScalef(2.8f, 0.8f, 1.0f);
    glTranslatef(-124.50f, 80.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 190.161281205264f, 0.412, 0.412, 0.412);
    glPopMatrix();

    glPushMatrix(); //Stair 1
    glScalef(2.8f, 0.05f, 1.0f);
    glTranslatef(-124.50f, 5100.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f, 0.502, 0.502, 0.5023);
    glPopMatrix();

    // left grass up
    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2i(0, 200);
    glVertex2i(453.2250, 201.9137);
    glVertex2i(595.5435, 267.9373);
    glVertex2i(0, 269.8934);
    glEnd();
    // right grass up

    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2i(611.0517, 200);
    glVertex2i(1300, 200);
    glVertex2i(1300, 267.9373);
    glVertex2i(659.4265, 268.7);
    glEnd();

    glPushMatrix(); //R4
    glScalef(0.8f, 1.0f, 1.0f);
    glTranslatef(590.0f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f, 0.412, 0.412, 0.412);
    glPopMatrix();

    glPushMatrix(); //R3
    glScalef(0.5f, 1.0f, 1.0f);
    glTranslatef(1232.0f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f,0.663f, 0.663f, 0.663f);
    glPopMatrix();

    glPushMatrix(); //R2
    glScalef(2.0f, 1.0f, 1.0f);
    glTranslatef(78.30f, 0.0f, 0.0f);
    drawRectangle(325.819016505051f, 268.1426795192467f, 58.4847553765548f, 236.0087315738737f, 0.412, 0.412, 0.412);
    glPopMatrix();
    drawRectangle(925.0f, 268.1426795192467f, 58.4847553765548f, 265.0f, 0.663f, 0.663f, 0.663f); //R1

    //door
    drawArchedWindow(595.5435, 280, 98, 115, 0.502, 0.0, 0.0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);

    //window 2nd mid
    glPushMatrix();
    glTranslatef(32.0f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glLineWidth(0.2);
    glPopMatrix();

    //window 1st down
    glPushMatrix();
    glTranslatef(0.0f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window second down
    glPushMatrix();
    glTranslatef(32.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window right 1st down
    glPushMatrix();
    glTranslatef(440.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window right 2nd  down
    glPushMatrix();
    glTranslatef(472.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window right 2nd  mid
    glPushMatrix();
    glTranslatef(440.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window right 2nd  mid
    glPushMatrix();
    glTranslatef(472.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window left up
    glPushMatrix();
    glTranslatef(0.0f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //2nd
    glPushMatrix();
    glTranslatef(32.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //window Right up
    glPushMatrix();
    glTranslatef(472.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(440.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //right mid quad
    glPushMatrix();
    glTranslatef(88.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(88.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(88.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(386.0f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(386.0f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(386.0f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

//window third quad
    glPushMatrix();
    glTranslatef(125.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(125.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

//window third quad
    glPushMatrix();
    glTranslatef(350.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(350.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //beside door window
    glPushMatrix();
    glTranslatef(173.00f,-30.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305.00f,-30.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

//first
    glPushMatrix();
    glTranslatef(-64.0f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

//4th quad
    glPushMatrix();
    glTranslatef(545.00f,0.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(545.00f,-54.0f,0.0f);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(545.00f,70.0f,0.0f);
    drawArchedWindow(400,335, 13, 35, 0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //roofs
    drawTriangle(295, 510, 80, 100,0.569, 0.404, 0.243);
    drawTriangle(914, 530, 80, 100,0.569, 0.404, 0.243);

    glPushMatrix();
    glScalef(2.0f, 1.0f, 1.0f);
    glTranslatef(-118.70f, -6.0f, 0.0f);
    drawTriangle(295, 510, 80, 100, 0.569, 0.404, 0.243);
    glPopMatrix();

//main chad
    glPushMatrix();
    glTranslatef(12.70f, 35.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.639f, 0.592f, 0.529f);
    glVertex2i(499.7294,469 );
    glVertex2i(913.4414, 469);
    glVertex2i(870.63,568.4223);
    glVertex2i(556.2503,568.4223);
    glVertex2i(539.0771,540.73);
    glVertex2i(443.9289,540.73);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.576f, 0.518f, 0.427f);
    glVertex2i(714.2061, 502.5198);   // B3
    glVertex2i(740, 500);              // I5
    glVertex2i(738.6379, 512.5024);   // A6
    glVertex2i(735.8564, 514.8203);   // B6
    glVertex2i(747.1256, 549.9846);   // C6
    glVertex2i(700, 550);             // C3
    glEnd();

    glPushMatrix();//attic 2
    glTranslatef(-180.0f, 29.0f, 0.0f);
    glScalef(1.8f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.502f, 0.408f, 0.337f);
    glVertex2i(486.98,520.4151);
    glVertex2i(504.1483,520.4151 );
    glVertex2i(522.408,520.4151 );
    glVertex2i(522.408,640.79 );
    glVertex2i(486.98,640.79 );
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8f, 1.0f, 1.0f);
    glTranslatef(574.70f, 155.0f, 0.0f);
    drawTriangle(289, 510, 92, 90, 0.631f, 0.580f, 0.514f);
    glPopMatrix();

    // chad er upor
    glBegin(GL_TRIANGLES);
    glColor3f(0.239f, 0.224f, 0.224f);
    glVertex2f(580, 504);
    glVertex2f(645.1852384801084, 650);
    glVertex2f(710, 504);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.886f, 0.847f, 0.800f);
    glVertex2f(587, 504);
    glVertex2f(644.3897319116145, 635);
    glVertex2f(700, 504);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.192f, 0.173f, 0.192f);
    glVertex2f(710, 504);
    glVertex2f(725, 500);
    glVertex2f(660, 620);
    glVertex2f(700, 610);
    glVertex2f(648, 640);
    glEnd();

    glPushMatrix();//attic 1
    glTranslatef(12.70f, 35.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.796f, 0.757f, 0.706f);
    glVertex2i(486.98,520.4151);
    glVertex2i(504.1483,503.9667 );
    glVertex2i(522.408,520.4151 );
    glVertex2i(522.408,579.79 );
    glVertex2i(486.98,579.79 );
    glEnd();
    glPopMatrix();

//head
    glPushMatrix();
    glScalef(0.8f, 1.0f, 1.0f);
    glTranslatef(320.70f, 104.0f, 0.0f);
    drawTriangle(295, 510, 60, 90, 0.710f, 0.667f, 0.616f);
    glPopMatrix();

//2 poly piller
    glPushMatrix();
    glTranslatef(0,40,0);
    glBegin(GL_POLYGON);
    glColor3f(0.698, 0.639, 0.565);
    glVertex2f(456.6990494364464, 414.7718183041332);
    glVertex2f(465.2, 398.3991942075681);
    glVertex2f(475.2307691606063, 414.7718183041332);
    glVertex2f(475.2307691606063, 476.9606983466956);
    glVertex2f(465.2, 505.4069592324909);
    glVertex2f(456.6990494364464, 476.9606983466956);
    glVertex2f(456.6990494364464, 414.7718183041332);
    glEnd();
    glPopMatrix();

//3
    glPushMatrix();
    glTranslatef(-205,15,0);
    glBegin(GL_POLYGON);
    glColor3f(0.698, 0.639, 0.565); //
    glVertex2f(740, 470.2199944357906); // C5
    glVertex2f(749.4895264906913, 450.6752527694243); // D5
    glVertex2f(759.0235468132777, 451.62865480193);   // E5
    glVertex2f(766, 471.1163499043267); // F5
    glVertex2f(766.3175033580762, 510.5441516444114); // G5
    glVertex2f(753.3182713831214, 565.9472784130967); // H5
    glVertex2f(740, 510); // I5
    glEnd();
    glPopMatrix();

//1
    glPushMatrix();
    glTranslatef(-18,16,0);
    glBegin(GL_POLYGON);
    glColor3f(0.698, 0.639, 0.565);
    glVertex2f(373.3086232479083, 436.4909469032707);
    glVertex2f(383.2948084928827, 420.9242463703064);
    glVertex2f(389, 420.9242463703064);
    glVertex2f(399, 436.4909469032707);
    glVertex2f(399, 490.8275431032405);
    glVertex2f(387.5816124461045, 529);
    glVertex2f(373.3086232479083, 490.8275431032405);
    glVertex2f(373.3086232479083, 436.4909469032707);
    glEnd();
    glPopMatrix();

//4
    glPushMatrix();
    glTranslatef(-14,15,0);
    glBegin(GL_POLYGON);
    glColor3f(0.698, 0.639, 0.565); // White color
    glVertex2f(740, 470.2199944357906); // C5
    glVertex2f(749.4895264906913, 450.6752527694243); // D5
    glVertex2f(759.0235468132777, 451.62865480193);   // E5
    glVertex2f(766, 471.1163499043267); // F5
    glVertex2f(766.3175033580762, 510.5441516444114); // G5
    glVertex2f(753.3182713831214, 565.9472784130967); // H5
    glVertex2f(740, 510); // I5
    glEnd();
    glPopMatrix();

// right
    glPushMatrix();
    glTranslatef(18,30,0);
    glBegin(GL_POLYGON);
    glColor3f(0.698, 0.639, 0.565);
    glVertex2f(880.3520671160301, 413.4245602719822);
    glVertex2f(890.5294748756919, 394.5236601419986);
    glVertex2f(901.1915211000994, 395.00829860687);
    glVertex2f(912.8228442539986, 413.4245602719822);
    glVertex2f(912.8228442539986, 480.5684985881956);
    glVertex2f(897.781183015392, 530);
    glVertex2f(880, 480);
    glVertex2f(880.3520671160301, 413.4245602719822);
    glEnd();
    glPopMatrix();

// choto janala
    glPushMatrix();
    glTranslatef(42,26,0);
    chotojanala();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,26,0);
    chotojanala();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,40,0);
    glBegin(GL_QUADS);
    glColor3f(0.698, 0.639, 0.565);
    glVertex2f(831.5226124223497, 557.6920255156084);
    glVertex2f(849.381972281462, 557.6920255156084);
    glVertex2f(849.381972281462, 605.2106794264612);
    glVertex2f(831.5226124223497, 605.2106794264612);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.149f, 0.173f, 0.224f);
    glVertex2f(824.8935096861904, 605);
    glVertex2f(855.0738955059555, 605);
    glVertex2f(840.2413446821495, 654.1816443464093);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,position1, 0.0);
    drawRealisticStudent(680, 200, 1.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,position1, 0.0);
    drawRealisticStudent(650, 200, 1.5f);
    glPopMatrix();

//grass right middle
    for (int x = 640; x < 900; x += 50) {Grass(x, 220);}

    //tree
    glPushMatrix();
    glScalef(0.70f,0.90f,1.0f);
    glTranslatef(1450,250,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.40f,0.50f,1.0f);
    glTranslatef(2400,400,0);
    tree();
    glPopMatrix();

    drawChristmasTree(50,265,100,200);
    drawChristmasTree(100,255,50,150);
    drawChristmasTree(200,255,50,150);
    drawChristmasTree(150,250,120,250);
    drawChristmasTree(250,265,100,200);

    //left top grass
    Grass(10,210);
    Grass(60,210);
    Grass(110,210);
    Grass(160,210);
    Grass(210,210);
    Grass(260,210);
    Grass(310,210);
    Grass(360,210);
    Grass(410,210);
    Grass(-5,240);
    Grass(35,240);
    Grass(85,240);
    Grass(145,240);
    Grass(195,240);
    Grass(245,240);
    Grass(285,240);
    Grass(345,240);
    Grass(385,240);
    Grass(445,240);
    Grass(460,220);
    Grass(490,250);
    Grass(420,250);
    //left down grass
    Grass(5,50);
    Grass(55,50);
    Grass(105,50);
    Grass(30,20);
    Grass(-10,20);
    Grass(70,20);

    //right down grass
    for (int x = 570; x < 1300; x += 50) {Grass(x, 50);}
        for (int x = 570; x < 1300; x += 50) {Grass(x, 20);}
       for (int x = 570; x < 1300; x += 50) {Grass(x, 0);}
        for (int x = 620; x < 1300; x += 50) {Grass(x, 200);}
        for (int x = 620; x < 1300; x += 50) {Grass(x, 200);}
        for (int x = 640; x < 900; x += 50) {Grass(x, 250);}

    glPushMatrix();
    glTranslatef(position2+40,position2, 0.0);
    drawRealisticStudent(330, 90, 1.5f);
    glPopMatrix();

    //piller er janala
    glPushMatrix();
    glTranslatef(165.0f,306.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala1
    glPushMatrix();
    glTranslatef(338.0f,330.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala2
    glPushMatrix();
    glTranslatef(351.0f,330.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala2
    glPushMatrix();
    glTranslatef(530.0f,330.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala2
    glPushMatrix();
    glTranslatef(542.0f,330.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala3
    glPushMatrix();
    glTranslatef(553.0f,340.0f,0.0f);
    glScalef(.8,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala4
    glPushMatrix();
    glTranslatef(515.0f,340.0f,0.0f);
    glScalef(.8,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala5
    glPushMatrix();
    glTranslatef(702.0f,300.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

//piller er janala5
    glPushMatrix();
    glTranslatef(722.0f,300.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    //piller er janala2
    glPushMatrix();
    glTranslatef(265.0f,320.0f,0.0f);
    glScalef(.5,.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

//JANALAS
    glPushMatrix();
    glTranslatef(-80.0f,-50.0f,0.0f);

    glScalef(1.7,1.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20.0f,-50.0f,0.0f);

    glScalef(1.7,1.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50.0f,-50.0f,0.0f);

    glScalef(1.7,1.5,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70.0f,130.0f,0.0f);

    glScalef(1.4,1.2,0);
    drawArchedWindow(400,335, 13, 35,0.337f, 0.278f, 0.231f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19,-30,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.133, 0.169, 0.216);
    glVertex2f(877.3687059536979, 530.7403692514115);
    glVertex2f(914.471443709989, 530.7403692514115);
    glVertex2f(895.781183015392, 600.6908724190426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-156,-58,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.133, 0.169, 0.216);
    glVertex2f(879.3687059536979, 580.7403692514115);
    glVertex2f(911.471443709989, 580.7403692514115);
    glVertex2f(894.781183015392, 640.6908724190426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-347,-58,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.133, 0.169, 0.216);
    glVertex2f(879.3687059536979, 580.7403692514115);
    glVertex2f(911.471443709989, 580.7403692514115);
    glVertex2f(894.781183015392, 640.6908724190426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-528,-72,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.133, 0.169, 0.216);
    glVertex2f(881.3687059536979, 580.7403692514115);
    glVertex2f(911.471443709989, 580.7403692514115);
    glVertex2f(896.781183015392, 640.6908724190426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-430,-72,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.133, 0.169, 0.216);
    glVertex2f(884.3687059536979, 580.7403692514115);
    glVertex2f(907.471443709989, 580.7403692514115);
    glVertex2f(896.781183015392, 640.6908724190426);
    glEnd();
    glPopMatrix();

    //likha
    glColor3f(1.0, 1.0,0.81);
    renderBitmapString(577.0f, 403.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOGWARTS");
    glColor3f(1.0,1.0,0.81);
    renderBitmapString(575.0f, 401.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOGWARTS");

    glPushMatrix();
    glScalef(0.45,0.45,1.0);
    drawTrafficLight(800, 620);
    glPopMatrix();

    //bus
    glPushMatrix();
    glTranslatef(position+280.0f, -440.0f, 0.0f);
    bus();
    glPopMatrix();
glPushMatrix();
glTranslatef(position3,0,0);
    drawBird(400, 750, 0.4f);
    drawBird(350, 710, 0.4f);
    drawBird(300, 730, 0.4f);
    drawBird(890, 750, 0.4f);
glPopMatrix();
//dorjar kaj
    glPushMatrix();
    glTranslatef(0,22,0);
    glBegin(GL_QUADS);
    glColor3f(0.337f, 0.278f, 0.231f);
    for(int i=0;i<90;i+=15) {
    glVertex2f(601.2861611125437+i, 409.7291577610771);
    glVertex2f(605.7559594658075+i, 409.7291577610771);
    glVertex2f(605.7559594658075+i, 425.3057277840623);
    glVertex2f(601.2861611125437+i, 425.3057277840623);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,25.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(.7,.7,.7);
    glVertex2f(563, 401.0513387582997);
    glVertex2f(728,401.0513387582997);
    glVertex2f(729, 407.9135235472634);
    glVertex2f(562, 407.9135235472634);
    glEnd();
    glPopMatrix();

        if (isRaining) {

       drawRain();

    }

    glFlush();

}

#include <windows.h>
#include <GL/glut.h>
#include <cmath>

GLfloat position10 = 0.0f;
GLfloat speed10= 4.0f;

void update10(int value){
    if(position10 >=1000)
        position10 = 1.0f;

    position10 += speed10;

    glutPostRedisplay();
    glutTimerFunc(100, update10, 0);
}






void drawTree(float x, float y, float trunkWidth, float trunkHeight, float foliageRadius) {
    // Draw trunk
    drawRectangle(x, y, trunkWidth, trunkHeight, 0.55f, 0.27f, 0.07f); // Brown trunk
    // Draw foliage (three overlapping circles for a fuller look)
    float foliageX = x + trunkWidth / 2;
    float foliageY = y + trunkHeight;
    drawCircle(foliageX, foliageY, foliageRadius, 0.0f, 0.6f, 0.0f); // Center foliage
    drawCircle(foliageX - foliageRadius * 0.8f, foliageY - 10, foliageRadius * 0.8f, 0.0f, 0.6f, 0.0f); // Left foliage
    drawCircle(foliageX + foliageRadius * 0.8f, foliageY - 10, foliageRadius * 0.8f, 0.0f, 0.6f, 0.0f); // Right foliage
}
void drawGlassPanes(float x, float y, float w, float h) {

    float thickness = 2.0f; // Divider thickness
    float padding = 1.5f;   // Optional inner margin from wood edge
    float paneW = (w - thickness - 2 * padding) / 2.0f;
    float paneH = (h - thickness - 2 * padding) / 2.0f;
    float glassR = 0.7f, glassG = 0.85f, glassB = 0.95f; // Light blue tint
    // Top-left pane
    drawRectangle(x + padding, y + h / 2 + thickness / 2, paneW, paneH, glassR, glassG, glassB);
    // Top-right pane
    drawRectangle(x + w / 2 + thickness / 2, y + h / 2 + thickness / 2, paneW, paneH, glassR, glassG, glassB);
    // Bottom-left pane
    drawRectangle(x + padding, y + padding, paneW, paneH, glassR, glassG, glassB);
    // Bottom-right pane
    drawRectangle(x + w / 2 + thickness / 2, y + padding, paneW, paneH, glassR, glassG, glassB);
    // Vertical divider
    drawRectangle(x + w / 2 - thickness / 2, y + padding, thickness, h - 2 * padding, 0.4f, 0.2f, 0.05f);
    // Horizontal divider
    drawRectangle(x + padding, y + h / 2 - thickness / 2, w - 2 * padding, thickness, 0.4f, 0.2f, 0.05f);
}
void drawGate(float x, float y, float w, float h) {
    int numPlanks = 5; // Number of planks per door
    float plankWidth = (w / 2.0f) / numPlanks;
    float spacing = 1.0f;
    // Left door planks
    for (int i = 0; i < numPlanks; ++i) {
        float px = x + i * (plankWidth + spacing);
        drawRectangle(px, y, plankWidth, h, 0.545f, 0.271f, 0.075f); // Wood color
    }
    // Right door planks
    for (int i = 0; i < numPlanks; ++i) {
        float px = x + w / 2.0f + i * (plankWidth + spacing);
        drawRectangle(px, y, plankWidth, h, 0.545f, 0.271f, 0.075f);
    }

    // Center divider
    drawRectangle(x + w / 2.0f - 1.0f, y, 2.0f, h, 0.4f, 0.2f, 0.05f);

    // Handles
    float handleW = 2.0f, handleH = 5.0f;
    drawRectangle(x + w / 2.0f - 6.0f, y +h / 2.0f, handleW, handleH, 0.2f, 0.2f, 0.2f); // Left
    drawRectangle(x + w / 2.0f + 4.0f, y + h / 2.0f - handleH / 2.0f, handleW, handleH, 0.2f, 0.2f, 0.2f); // Right

}

void drawTile(float cx, float cy, float rx, float ry, float spacing) {
    for (float x = cx - rx; x <= cx + rx; x += spacing) {
        for (float y = cy - ry; y <= cy + ry; y += spacing) {
            float dx = (x - cx) / rx;
            float dy = (y - cy) / ry;
            float dist = sqrtf(dx*dx + dy*dy); // normalized distance from center

            if (dist <= 1.0f) { // inside ellipse
                // Outer tiles: off-white, Inner tiles: deep blue
                if (dist > 0.6f) {
                    // Muted sandy beige instead of bright white
                    glColor4f(0.85f, 0.80f, 0.65f, 0.35f);
                } else {
                    // Deep blue for inner tiles
                    glColor4f(0.0f, 0.2f, 0.5f, 0.45f);
                }
                glBegin(GL_POLYGON);
                glVertex2f(x, y + 4.0f);  // top
                glVertex2f(x + 4.0f, y);  // right
                glVertex2f(x, y - 4.0f);  // bottom
                glVertex2f(x - 4.0f, y);  // left
                glEnd();
            }
        }
    }
}
void drawFish(float cx, float cy, float size, float r, float g, float b, float angleDeg) {
    glPushMatrix();
    glTranslatef(cx, cy, 0.0f);
    glRotatef(angleDeg, 0.0f, 0.0f, 1.0f);

    // Body

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++) {
        float theta = 2.0f * M_PI * i / 30;
        float x = size * 0.6f * cosf(theta);
        float y = size * 0.3f * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Tail
    glBegin(GL_TRIANGLES);
    glVertex2f(-size * 0.6f, 0.0f);
    glVertex2f(-size * 0.9f, size * 0.2f);
    glVertex2f(-size * 0.9f, -size * 0.2f);
    glEnd();

    // Eye (small white circle with black pupil)
    float eyeX = size * 0.35f;
    float eyeY = size * 0.1f;
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glBegin(GL_POLYGON);
    for (int i = 0; i < 12; i++) {
        float theta = 2.0f * M_PI * i / 12;
        glVertex2f(eyeX + size * 0.08f * cosf(theta),
                   eyeY + size * 0.08f * sinf(theta));
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // black pupil
    glBegin(GL_POLYGON);
    for (int i = 0; i < 12; i++) {
        float theta = 2.0f * M_PI * i / 12;
        glVertex2f(eyeX + size * 0.04f * cosf(theta),
                   eyeY + size * 0.04f * sinf(theta));
    }
    glEnd();

    glPopMatrix();
}
void drawBrickWall(float x, float y, float wallW, float wallH, float brickW, float brickH, float r, float g, float b, float mortarR, float mortarG, float mortarB, float mortarThickness){
    // Draw mortar background first
    drawRectangle(x, y, wallW, wallH, mortarR, mortarG, mortarB);

    int rows = (int)ceil(wallH / brickH);

    for (int row = 0; row < rows; row++) {
        float yPos = y + row * brickH;
        float xOffset = (row % 2 == 0) ? 0.0f : brickW / 2.0f;

        // Number of columns is enough to cover the wall even with offset
        int cols = (int)ceil((wallW + brickW) / brickW);

        for (int col = 0; col < cols; col++) {
            float xPos = x + col * brickW + xOffset;

            // Clip brick width if it overflows the wall
            float actualBrickW = brickW;
            if (xPos + brickW > x + wallW) {
                actualBrickW = (x + wallW) - xPos;
                if (actualBrickW <= 0) continue; // skip if outside
            }

            // Clip brick height if it overflows the wall
            float actualBrickH = brickH;
            if (yPos + brickH > y + wallH) {
                actualBrickH = (y + wallH) - yPos;
                if (actualBrickH <= 0) continue;
            }

            drawRectangle(
                xPos + mortarThickness,
                yPos + mortarThickness,
                actualBrickW - mortarThickness * 2,
                actualBrickH - mortarThickness * 2,
                r, g, b
            );
        }
    }
}
void drawClock(float cx, float cy, float radius) {
    //clock face
    drawCircle(cx, cy, radius, 1.0f, 1.0f, 0.6f); // RGB for yellow

    //clock outline
    glColor3f(0.6f, 0.2f, 0.2f); // brick brown
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1415926f * i / 100;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();

    // Draw hour hand (white)
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx, cy + radius * 0.5f); // pointing up
    glEnd();

    // Draw minute hand (white)
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx + radius * 0.7f, cy); // pointing right
    glEnd();
}
void drawRoofTiles(float x, float y, float w, float h, int tileCount, float r, float g, float b, float thickness) {
    // Peak coordinates
    float peakX = x + w / 2.0f;
    float peakY = y + h;

    glColor3f(r, g, b);
    glLineWidth(thickness); // make lines bold

    glBegin(GL_LINES);
    for (int i = 1; i < tileCount; i++) {
        float t = (float)i / tileCount;
        float baseX = x + t * w; // point along base
        glVertex2f(baseX, y);
        glVertex2f(peakX, peakY);
    }
    glEnd();

    glLineWidth(1.0f); // reset to default
}
void drawRoofHorizontalLines(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int lineCount, float r, float g, float b, float thickness){
    glColor3f(r, g, b);
    glLineWidth(thickness);

    glBegin(GL_LINES);
    for (int i = 1; i < lineCount; i++) {
        float t = (float)i / lineCount;

        // Interpolate between bottom and top edges for left side
        float leftX  = x1 + t * (x4 - x1);
        float leftY  = y1 + t * (y4 - y1);

        // Interpolate between bottom and top edges for right side
        float rightX = x2 + t * (x3 - x2);
        float rightY = y2 + t * (y3 - y2);

        glVertex2f(leftX, leftY);
        glVertex2f(rightX, rightY);
    }
    glEnd();

    glLineWidth(1.0f); // reset to default
}
void drawCanteen(float x, float y, float w, float h) {
    float roofHeight = h * 0.35f;   // taller roof
    float wallHeight = h - roofHeight;

    // ===== Front wall =====
    drawRectangle(x - w, y, w, wallHeight, 0.95f, 0.9f, 0.8f); // light beige

        // ===== Gabled roof =====
    drawRectangle(x - w, y + wallHeight, w, roofHeight * 0.6f, 0.85f, 0.45f, 0.35f); // lighter reddish-brown
    glColor3f(0.8f, 0.3f, 0.3f); // triangle part of roof
    glBegin(GL_TRIANGLES);
        glVertex2f(x - w, y + wallHeight + roofHeight * 0.6f);
        glVertex2f(x,     y + wallHeight + roofHeight);
        glVertex2f(x,     y + wallHeight + roofHeight * 0.6f);
    glEnd();

    // ===== Signboard (polygon) =====
    glColor3f(0.9f, 0.9f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(x - w * 0.75f, y + wallHeight + roofHeight * 0.2f);
        glVertex2f(x - w * 0.25f, y + wallHeight + roofHeight * 0.2f);
        glVertex2f(x - w * 0.30f, y + wallHeight + roofHeight * 0.52f);
        glVertex2f(x - w * 0.70f, y + wallHeight + roofHeight * 0.52f);
    glEnd();

    // ===== Roof overhang polygon =====
    glColor3f(0.75f, 0.25f, 0.25f); // slightly darker shade for contrast
    glBegin(GL_POLYGON);
        glVertex2f(x - w - 15, y + wallHeight + 20);
        glVertex2f(x + 15,     y + wallHeight + 20);
        glVertex2f(x,          y + wallHeight);
        glVertex2f(x - w,      y + wallHeight);
    glEnd();

    // ===== Serving hatch =====
    float hatchW = w * 0.5f;
    float hatchH = wallHeight * 0.4f;
    float hatchX = (x - w/2) - hatchW/2;
    float hatchY = y + wallHeight * 0.3f;
    drawRectangle(hatchX, hatchY, hatchW, hatchH, 0.7f, 0.7f, 0.7f);

    // Counter ledge
    drawRectangle(hatchX, hatchY - h * 0.05f, hatchW, h * 0.05f, 0.5f, 0.3f, 0.1f);

    // Awning polygon above hatch
    glColor3f(0.3f, 0.3f, 0.6f);
    glBegin(GL_POLYGON);
        glVertex2f(hatchX,              hatchY + hatchH + 10);
        glVertex2f(hatchX + hatchW,     hatchY + hatchH + 10);
        glVertex2f(hatchX + hatchW + 10, hatchY + hatchH - 10);
        glVertex2f(hatchX - 10,         hatchY + hatchH - 10);
    glEnd();

    // ===== Windows =====
    drawRectangle(x - w * 0.95f, y + wallHeight * 0.5f, w * 0.15f, wallHeight * 0.3f, 0.6f, 0.85f, 0.95f);
    drawRectangle(x - w * 0.20f, y + wallHeight * 0.5f, w * 0.15f, wallHeight * 0.3f, 0.6f, 0.85f, 0.95f);

    glColor3f(0.1f, 0.1f, 0.1f); // dark text
    glRasterPos2f(x - w * 0.665f, y + wallHeight + roofHeight * 0.30f);
    const char* label = "CANTEEN";
    while (*label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *label);
        label++;
    }
}
// for window
float baseX = 101.1973f;
float baseY = 293.8717f;
float w = 26.8025f;
float h = 55.4663f;
float r = 0.545f, g = 0.271f, b = 0.075f;
void drawWindowGrid(float startX, float startY, int cols, int rows, float spacingX, float spacingY) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            glPushMatrix();
            glTranslatef(startX + col * spacingX, startY + row * spacingY, 0.0f);
            drawRectangle(baseX, baseY, w, h, r, g, b);
            drawGlassPanes(baseX, baseY, w, h);
            glPopMatrix();
        }
    }
}


void drawCloud1(float x, float y){
    drawCircle(x, y, 30,1.0f, 1.0f, 1.0f);
    drawCircle(x + 30, y + 30, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 70, y + 30,35,  1.0f, 1.0f, 1.0f);
    drawCircle(x + 115, y + 20, 35,  1.0f, 1.0f, 1.0f);

    drawCircle(x -5, y - 35, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +35, y - 50, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +80, y - 45, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +125, y - 45, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(x +145, y - 10, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +30, y - 15, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +70, y - 15, 35,  1.0f, 1.0f, 1.0f);
    drawCircle(x +110, y - 15, 35,   1.0f, 1.0f, 1.0f);

}


void drawWave(float cx, float cy, float rx, float ry, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);   // outline only, no fill
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * M_PI * float(i) / float(100);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawEllipseOutline(float cx, float cy, float rx, float ry, float r, float g, float b) {
    glColor3f(r, g, b);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * M_PI * float(i) / float(100);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}










void display2_view() {
    glClearColor(0.529f, 0.808f, 0.922f,0.0f);
          if (isRaining) {

glClearColor(0.5843f, 0.6471f, 0.7098f, 0.0f);
    }
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(2);
glColor3f(0.5333f, 0.0667f, 0.0980f);
    // Brick color: warm reddish tone
    float brickR = 0.533f, brickG = 0.0667f, brickB = 0.0980f;
    // Mortar color: light gray
    float mortarR = 0.85f, mortarG = 0.85f, mortarB = 0.85f;

    // Left partition
    drawBrickWall(60.4545f, 244.6386f, 182.3157f, 299.2526f, 20.0f, 10.0f, brickR, brickG, brickB, mortarR, mortarG, mortarB, 1.0f);

    // Middle partition
    drawBrickWall(242.7702f, 244.6386f, 817.2022f, 299.2526f,
                  20.0f, 10.0f,
                  brickR, brickG, brickB,
                  mortarR, mortarG, mortarB,
                  1.0f);

    // Right partition
    drawBrickWall(1059.9724f, 244.6386f, 181.7307f, 299.2526f, 20.0f, 10.0f, brickR, brickG, brickB, mortarR, mortarG, mortarB, 1.0f);

    //cloud
    glPushMatrix();
    glTranslatef(position10,0,0);
    drawCloud(550,760);
    drawCloud(950,720);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position10,200,0);
    glScalef(0.8,.7,0);
    drawCloud1(100.0f, 700.0);
     glPopMatrix();

    glPushMatrix();
    glTranslatef(position10,280,0);
    glScalef(0.6,.6,0);
    drawCloud1(100.0f, 700.0);
     glPopMatrix();

//door
drawRectangle(585.4152f,245.0f,160.8423f,116.2132f,1.0f,0.95f,0.8f);
drawRectangle(596.0114f,253.0f,140.5157f,98.7991f,0.396f, 0.263f, 0.129f);
drawRectangle(608.6561f,264.0f,115.0508f,79.2016f,0.5f,0.5f,0.5f);
    glPushMatrix();
    glTranslatef(339.0f,170.0f,0.0f);
    glScalef(1.8f,.95f,1.0f);
    drawGate(150.0f, 100.0f, 60.0f, 80.0f); // Position and size
    glPopMatrix();

//chader uporer ongso

glBegin(GL_QUADS);
glColor3f(0.663f, 0.663f, 0.663f);
glVertex2f(240.7702f,543.8912);
glVertex2f(1241.7030f,543.8912);
glVertex2f(1160.0f,603.3884f);
glVertex2f(150.414f,603.3884f);
glEnd();
drawRoofHorizontalLines(240.7702f, 543.8912f, 1241.7030f, 543.8912f, 1160.0f,    603.3884f, 150.414f,   603.3884f, 6, 0.4f, 0.4f, 0.4f, 3.0f);

//roof left
drawTriangle(50.0f,535.8912,205.2702,85.6798,.663f, 0.663f, 0.663f);
drawRoofTiles(50.0f, 535.8912f, 205.2702f, 85.6798f, 12, 0.5f, 0.5f, 0.5f, 3.0f);

glPushMatrix();
glTranslatef(0,-112,0);
glBegin(GL_TRIANGLES);
glColor3f(0.498f,0.498f,0.498f);
glVertex2f(632.2544f,801.2978f);
glVertex2f(672.2759f,801.2978f);
glVertex2f(653.2652f,838.9115f);
glEnd();
glPopMatrix();

//stick
drawRectangle(651.5f,721.0f,3.0f,40.0f,0.498f,0.498f,0.498f);

glBegin(GL_QUADS);
glColor3f(1.0f,0.95f,0.8f);
glVertex2f(612.8791f,601.2978);
glVertex2f(692.4351f,601.2978);
glVertex2f(692.4351f,638.5759f);
glVertex2f(612.8791f,638.5759f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,0.95f,0.8f);
glVertex2f(635.2544f,601.2978);
glVertex2f(671.2759f,601.2978);
glVertex2f(671.2759f,690.3795);
glVertex2f(635.2544f,690.3795f);
glEnd();

// clock
    float clockX = (612.8791f + 692.4351f) / 2.0f; // ≈ 652.6571
    float clockY = (608.2978f + 638.5759f) / 2.0f; // ≈ 619.93685
    drawClock(clockX, clockY, 18.0f);

//grass

    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(237.37598f,0.0f);
    glVertex2f(595.4152f,244.6386f);
    glVertex2f(0.0f,244.6386f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.18f,0.5547f,0.066f);
    glVertex2f(500.2548f,0.0f);
    glVertex2f(1300.0f,0.0f);
    glVertex2f(1300.0f,244.6386f);
    glVertex2f(735.254f,244.6386f);
    glEnd();


//rasta

glBegin(GL_QUADS);
glColor3f(0.741f, 0.718f, 0.418f);
glVertex2f(237.37598f,0.0f);
glVertex2f(500.2548f,0.0f);
glVertex2f(735.254f,244.6386f);
glVertex2f(595.4152f,244.6386f);
glEnd();

//janala

    // Left 3×3 grid
    drawWindowGrid(0.0f, 0.0f, 3, 3, 49.7773f, 75.7643f);

    // Right 2×3 grid
    drawWindowGrid(1004.0f, 0.0f, 2, 3, 60.0f, 75.7643f);

    // Middle 12×3 grid
    drawWindowGrid(180.0f, 150.7643f, 13, 1, 60.0f, -75.7643f);
    drawWindowGrid(180.0f, 75.7643f, 5, 1, 60.0f, -75.7643f); //2nd row 1st 3
    drawWindowGrid(660.0f, 75.7643f, 5, 1, 60.0f, -75.7643f); //2nd row last 3
    drawWindowGrid(180.0f, 0.0f, 5, 1, 60.0f, -75.7643f);
    drawWindowGrid(660.0f, 0.0f, 5, 1, 60.0f, -75.7643f);


//school divider
glPushMatrix(); //1
glTranslatef(-187.0f, 139.0f, 0.0f);
drawRectangle(245.0f, 101.5601f, 6.0f, 296.0f, 0.50f, 0.0f, 0.13f);
glPopMatrix();

glPushMatrix(); //2
glTranslatef(6.0f, 139.0f, 0.0f);
drawRectangle(236.0f, 100.5601f, 6.0f, 297.0f, 0.55f, 0.07f, 0.07f);
glPopMatrix();

glPushMatrix(); //3
glTranslatef(820.0f, 144.0f, 0.0f);
drawRectangle(240.0f, 100.5601f, 6.0f, 299.0f, 0.55f, 0.07f, 0.07f);
glPopMatrix();

glPushMatrix(); //4
glTranslatef(996.0f, 144.0f, 0.0f);
drawRectangle(240.0f, 100.5601f, 6.0f, 299.0f, 0.55f, 0.07f, 0.07f);
glPopMatrix();

//school top border
drawRectangle(247.0f, 540.5601f, 815.0f, 4.0f, 0.55f, 0.07f, 0.07f);

    //grass
    for (int x = 0; x < 550; x += 50) {
        Grass(x, 220);
    }
    for (int x = 0; x < 500; x += 50) {Grass(x, 190);}
    for (int x = 0; x < 450; x += 50) {Grass(x, 140);}
    for (int x = 0; x < 350; x += 50) {Grass(x, 90);}
    for (int x = 0; x < 300; x += 50) {Grass(x, 50);}
    for (int x = 0; x < 250; x += 50) {Grass(x, 25);}
    for (int x = 0; x < 200; x += 50) {Grass(x, 5);}
   glPushMatrix();
    glTranslatef(1050.0f, 200.0f, 0.0f);
    glScalef(0.7f, 0.7f, 1.0f);
    tree();
    glPopMatrix();

    //potaka

    glPushMatrix();
    glTranslatef(-220.0f, 200.0f, 0.0f);
    glScalef(0.7f, 0.5f, 1.0f);
    drawRectangle(1030.0f, 53.5601f, 10.0f, 630.0f, 0.31f, 0.14f, 0.027f);
    glTranslatef(0.0f, 88.0f, 0.0f);
    drawRectangle(1040.0f, 411.0388f, 200.0f, 150.0f, 0.0f, 0.60f, 0.20f);
    glTranslatef(0.0f, -48.0f, 0.0f);
    drawCircle(1138.0f, 532.0388f, 35.0f, 1.0f, 0.0f, 0.0f);
    glPopMatrix();

    //Canteen
    drawCanteen(280.0f, 140.0f, 250.0f, 200.0f);

    //likha
    // ===== Billboard background =====
    glColor3f(1.0f, 1.0f, 0.8039f); // light yellow
    glBegin(GL_POLYGON);
        glVertex2f(560, 378);
        glVertex2f(560, 425);
        glVertex2f(750, 425);
        glVertex2f(750, 378);
    glEnd();

    // ===== Billboard border =====
    glColor3f(0.0f, 0.0f, 0.0f); // black border
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(560, 378);
        glVertex2f(560, 425);
        glVertex2f(750, 425);
        glVertex2f(750, 378);
    glEnd();
    glLineWidth(1.0f);

    // ===== Text on billboard =====
    glColor3f(0.0f, 0.0f, 0.0f); // black text
    renderBitmapString(588.0f, 395.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "PUBLIC COLLEGE");
//BASKETBALL

glPushMatrix();
glLineWidth(7);
glTranslatef(20,0,0);
glBegin(GL_LINES);
glColor3f(1,1,1);
    glVertex2f(542.232725778326, 43.2200551431998); // Coordinates from point C
    glVertex2f(668.677614293348, 186.6713062071259); // Coordinates from point D
glEnd();

glPopMatrix();

glPushMatrix();
glLineWidth(3);
glTranslatef(15,0,0);
glBegin(GL_LINES);
glColor3f(1,1,1);
glVertex2f(670.677614293348, 186.6713062071259); // Point D
glVertex2f(1149.3260595031327,186.6713062071259); // Point E
glEnd();
glPopMatrix();
glPushMatrix();
glLineWidth(7);
glTranslatef(10,0,0);
glBegin(GL_LINES);
glColor3f(1,1,1);
    glVertex2f(1153.3260595031327, 185.6350998656194); // First point
    glVertex2f(1270.1011752575419, 42.244683333855);  // Second point
glEnd();
glPopMatrix();


glPushMatrix();

glTranslatef(1,0,0);
glLineWidth(3);
glBegin(GL_LINES);
glColor3f(1,1,1);
    glVertex2f(562.2327257783261, 42.244683333855);  // First point
    glVertex2f(1282.1011752575419, 42.244683333855); // Second point
    glEnd();
    glPopMatrix();

glBegin(GL_LINE_LOOP);
glColor3f(1,1,1);
    glVertex2f(599.1950156475043, 84.9352685189481);  // Point G
    glVertex2f(716.5737773123692, 84.9352685189481);  // Point H
    glVertex2f(766.4629670300437, 158.8247767612192); // Point I
    glVertex2f(663.3954615819395, 158.8247767612192); // Point J
glEnd();

glLineWidth(7);
glBegin(GL_LINES);

glColor3f(1,1,1);
    glVertex2f(917.0271601787134, 185.6474655996199); // Point K
    glVertex2f(917.0271601787134, 41.0911108297227);  // Point L
glEnd();

glLineWidth(3);
glBegin(GL_LINE_LOOP);
    glVertex2f(1187.916438386335, 158.1865475971356);  // Point M
    glVertex2f(1085.7567917816673, 158.1865475971356); // Point N
    glVertex2f(1115.5159117022802, 85.9961170301473); // Point O
    glVertex2f(1241.859170361778, 85.9961170301473);  // Point P
glEnd();
//drawCircle();
drawEllipseOutline(916.2888f, 126.8207f, 58.0f, 22.0f, 1.0f, 1.0f, 1.0f);
//drawEllipse();

glPushMatrix();
     glTranslatef(450.0f,73.f,0.0f);
    // Seat of the bench
    drawRectangle(300.0f, 150.0f, 150.0f, 20.0f, 0.6f, 0.3f, 0.1f);  // Seat color: brown
    // Drawing the legs of the bench
    drawRectangle(320.0f, 130.0f, 10.0f, 20.0f, 0.3f, 0.1f, 0.0f);  // Left front leg
    drawRectangle(420.0f, 130.0f, 10.0f, 20.0f, 0.3f, 0.1f, 0.0f);  // Right front leg
glPopMatrix();

glPushMatrix();
     glTranslatef(680.0f,73.f,0.0f);
    // Seat of the bench
    drawRectangle(300.0f, 150.0f, 150.0f, 20.0f, 0.6f, 0.3f, 0.1f);  // Seat color: brown
    // Drawing the legs of the bench
    drawRectangle(320.0f, 130.0f, 10.0f, 20.0f, 0.3f, 0.1f, 0.0f);  // Left front leg
    drawRectangle(420.0f, 130.0f, 10.0f, 20.0f, 0.3f, 0.1f, 0.0f);  // Right front leg
glPopMatrix();
     if (isRaining) {
           drawRain();
}

    glFlush();

}


#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <GL/gl.h>
#include <utility>
#include <algorithm>

    GLfloat position20 = 0.0f;
    GLfloat speed20 = 2.0f;

void update20(int value){
        if (position20 >= 1300.0)
        position20 = 0.0f;
        position20 += speed20;
        glutPostRedisplay();
        glutTimerFunc(15, update20, 0);
    }
    GLfloat position21 = 0.0f;
    GLfloat speed21 = 2.0f;

void update21(int value){
    if (position21 >= 150.0)
        position21 = 0.0f;

    position21 += speed21;

    glutPostRedisplay();
    glutTimerFunc(100, update21, 0);
}

GLfloat position22 = 0.0f;
GLfloat speed22 = 2.0f;

void update22(int value){
    if (position22 >= 1300.0)
    position22 = 0.0f;

    position22 += speed22;

    glutPostRedisplay();
    glutTimerFunc(80, update22, 0);
}
GLfloat position23 = 0.0f;
GLfloat speed23 = 2.0f;
void update23(int value){
    if (position23 >= 220.0)
        position23 = 0.0f;

    position23 += speed23;

    glutPostRedisplay();
    glutTimerFunc(80, update23, 0);
}


// door function



void drawBezierCurve(float x0, float y0, float x1, float y1, float x2, float y2){
    glLineWidth(1.0f);
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.01){
        float xt = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
        float yt = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;
        glVertex2f(xt, yt);
    }
    glEnd();
}

void drawGlassPanes1(float x, float y, float w, float h){
    float thickness = 2.0f;
    float padding = 1.5f;
    int rows = 1;
    int cols = 7;
    float glassR = 0.113f, glassG = 0.564f, glassB = .713f;
    float dividerR = 1.0f, dividerG = 0.992f, dividerB = 0.816f;
    float paneW = (w - (cols - 1) * thickness - 2 * padding) / cols;
    float paneH = (h - (rows - 1) * thickness - 2 * padding) / rows;
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            float px = x + padding + c * (paneW + thickness);
            float py = y + padding + r * (paneH + thickness);
            drawRectangle(px, py, paneW, paneH, glassR, glassG, glassB);
        }
    }
    for (int c = 1; c < cols; c++){
        float vx = x + padding + c * paneW + (c - 0.5f) * thickness;
        drawRectangle(vx - thickness / 2, y + padding, thickness, h - 2 * padding, dividerR, dividerG, dividerB);
    }
    for (int r = 1; r < rows; r++){
        float hy = y + padding + r * paneH + (r - 0.5f) * thickness;
        drawRectangle(x + padding, hy - thickness / 2, w - 2 * padding, thickness, dividerR, dividerG, dividerB);
    }
}
void smallplane(){
    glPushMatrix();
    glTranslatef(-400, 0.0f, 0.0f);
    glScalef(0.5f, 0.45f, 0.0f);
    glColor3f(0.9373f, 0.9412f, 0.8784f);
    // Body
    glBegin(GL_QUADS);
    glVertex2f(760, 340);
    glVertex2f(1055, 340);
    glVertex2f(1055, 420);
    glVertex2f(760, 420);
    glEnd();
    // Head
    glBegin(GL_POLYGON);
    glVertex2f(1055, 420);
    glVertex2f(1110, 400);
    glVertex2f(1115, 395);
    glVertex2f(1120, 390);
    glVertex2f(1125, 385);
    glVertex2f(1126, 380);
    glVertex2f(1125, 365);
    glVertex2f(1123, 362);
    glVertex2f(1120, 360);
    glVertex2f(1115, 358);
    glVertex2f(1110, 355);
    glVertex2f(1100, 349);
    glVertex2f(1085, 345);
    glVertex2f(1075, 341);
    glVertex2f(1060, 341);
    glVertex2f(1055, 340);
    glEnd();
    // Back Sid
    glBegin(GL_POLYGON);
    glVertex2f(670, 420);
    glVertex2f(710, 380);
    glVertex2f(720, 360);
    glVertex2f(760, 340);
    glVertex2f(760, 420);
    glEnd();
    // Upper wings
    glColor3f(1.0f, .5f, .5f);
    glBegin(GL_POLYGON);
    glVertex2f(690, 420);
    glVertex2f(670, 480);
    glVertex2f(695, 480);
    glVertex2f(720, 440);
    glVertex2f(740, 420);
    glEnd();
    // Upper small wings
    glBegin(GL_QUADS);
    glVertex2f(720, 405);
    glVertex2f(700, 395);
    glVertex2f(630, 415);
    glVertex2f(620, 420);
    glEnd();
    // Wings
    glColor3f(0.1686f, 0.4588f, 0.6627f);
    glBegin(GL_QUADS);
    glVertex2f(960, 377);
    glVertex2f(860, 377);
    glVertex2f(730, 320);
    glVertex2f(760, 310);
    glEnd();
    // Windows & stripes
    glColor3f(.5f, .5f, 0.5f);
    for (int i = 0; i < 8; ++i){
        int offset = i * 25;
        glBegin(GL_QUADS);
        glVertex2f(750 + offset, 380);
        glVertex2f(750 + offset, 400);
        glVertex2f(760 + offset, 400);
        glVertex2f(760 + offset, 380);
        glEnd();
    }
    // Extra rectangle
    glBegin(GL_QUADS);
    glVertex2f(975, 375);
    glVertex2f(975, 405);
    glVertex2f(990, 405);
    glVertex2f(990, 375);
    glEnd();
    // Pilot windows
    glBegin(GL_QUADS);
    glVertex2f(1100, 385);
    glVertex2f(1100, 395);
    glVertex2f(1108, 395);
    glVertex2f(1108, 385);
    glVertex2f(1090, 385);
    glVertex2f(1090, 395);
    glVertex2f(1098, 395);
    glVertex2f(1098, 385);
    glEnd();
    // Small triangle on head
    glBegin(GL_TRIANGLES);
    glVertex2f(1110, 385);
    glVertex2f(1110, 395);
    glVertex2f(1120, 385);
    glEnd();
    glPopMatrix();
}



void drawGradientCircle(float cx, float cy, float r, float lightR, float lightG,float lightB,
                        float baseR,  float baseG,  float baseB, int segments = 100){
    glBegin(GL_TRIANGLE_FAN);
    glColor3f((lightR + baseR) / 2.0f,
              (lightG + baseG) / 2.0f,
              (lightB + baseB) / 2.0f);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        if (x < 0)
            glColor3f(lightR, lightG, lightB);
        else
            glColor3f(baseR, baseG, baseB);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
bool pointInQuad(float px, float py,
                 float x1, float y1,
                 float x2, float y2,
                 float x3, float y3,
                 float x4, float y4) {
    auto pointInTriangle = [](float px, float py,
                              float Ax, float Ay,
                              float Bx, float By,
                              float Cx, float Cy) -> bool {
        float w1 = (Ax*(Cy-Ay) + (py-Ay)*(Cx-Ax) - px*(Cy-Ay)) /((By-Ay)*(Cx-Ax) - (Bx-Ax)*(Cy-Ay));
        float w2 = (py-Ay - w1*(By-Ay)) / (Cy-Ay);
        return (w1 >= 0) && (w2 >= 0) && (w1 + w2 <= 1);
    };
    return pointInTriangle(px, py, x1, y1, x2, y2, x3, y3) ||pointInTriangle(px, py, x1, y1, x3, y3, x4, y4);
}
void drawBush(float x1, float y1,
                  float x2, float y2,
                  float x3, float y3,
                  float x4, float y4) {
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
    float minX = fmin(fmin(x1, x2), fmin(x3, x4));
    float maxX = fmax(fmax(x1, x2), fmax(x3, x4));
    float minY = fmin(fmin(y1, y2), fmin(y3, y4));
    float maxY = fmax(fmax(y1, y2), fmax(y3, y4));

    for (float y = minY; y <= maxY; y += 15) {
        for (float x = minX; x <= maxX; x += 15) {
            if (pointInQuad(x, y, x1, y1, x2, y2, x3, y3, x4, y4)) {
                float r = 8 + 10 % 5;
                drawCircle(x, y, r, 0.0f, 0.6f, 0.0f);
            }
        }
    }

    for (float y = minY + 10; y <= maxY; y += 25) {
        for (float x = minX + 10; x <= maxX; x += 25) {
            if (pointInQuad(x, y, x1, y1, x2, y2, x3, y3, x4, y4)) {
                float r = 5 + 8 % 4;
                drawCircle(x, y, r, 0.2f, 0.8f, 0.2f);
            }
        }
    }
}
void drawFlooringPattern() {
    float x1 = 1299.4863f, y1 = 11.4743f;
    float x2 = 630.8281f,  y2 = 152.6327f;
    float x3 = 1300.4062f, y3 = 168.5131f;

    int rows = 12;
    int cols = 10;

    for (int i = 0; i < rows; i++) {
        float t1 = (float)i     / rows;
        float t2 = (float)(i+1) / rows;

        float lx1 = x2 + (x3 - x2) * t1;
        float ly1 = y2 + (y3 - y2) * t1;
        float rx1 = x1 + (x3 - x1) * t1;
        float ry1 = y1 + (y3 - y1) * t1;

        float lx2 = x2 + (x3 - x2) * t2;
        float ly2 = y2 + (y3 - y2) * t2;
        float rx2 = x1 + (x3 - x1) * t2;
        float ry2 = y1 + (y3 - y1) * t2;

        for (int j = 0; j < cols; j++) {
            float s1 = (float)j     / cols;
            float s2 = (float)(j+1) / cols;

            float bx1 = lx1 + (rx1 - lx1) * s1;
            float by1 = ly1 + (ry1 - ly1) * s1;
            float bx2 = lx1 + (rx1 - lx1) * s2;
            float by2 = ly1 + (ry1 - ly1) * s2;

            float tx1 = lx2 + (rx2 - lx2) * s1;
            float ty1 = ly2 + (ry2 - ly2) * s1;
            float tx2 = lx2 + (rx2 - lx2) * s2;
            float ty2 = ly2 + (ry2 - ly2) * s2;

    if ((i + j) % 2 == 0)
        glColor3f(0.6f, 0.6f, 0.6f);
    else
    glColor3f(0.85f, 0.85f, 0.85f);
            glBegin(GL_QUADS);
                glVertex2f(bx1, by1);
                glVertex2f(bx2, by2);
                glVertex2f(tx2, ty2);
                glVertex2f(tx1, ty1);
            glEnd();
        }
    }
}

void drawPlantPotWithBush(float x, float y, float width, float height) {
    float potHeight = height * 0.7f;
    float rimHeight = height * 0.3f;

    float centerX = x + width / 2.0f;
    float baseY = y + potHeight + rimHeight;

    drawCircle(centerX, baseY + 30, 40, 0.0f, 0.6f, 0.0f);
    drawCircle(centerX - 35, baseY + 20, 35, 0.0f, 0.5f, 0.0f);
    drawCircle(centerX + 35, baseY + 20, 35, 0.0f, 0.5f, 0.0f);
    drawCircle(centerX - 20, baseY + 50, 30, 0.0f, 0.7f, 0.0f);
    drawCircle(centerX + 20, baseY + 50, 30, 0.0f, 0.7f, 0.0f);
}





void drawPushDoor() {
    glBegin(GL_QUADS);
        glColor3f(0.369f, 0.494f, 0.675f); // fill color
        glVertex2f(16, 96);
        glVertex2f(68.8631f, 116);
        glVertex2f(68.6349f, 277.1418f);
        glVertex2f(16.5004f, 292.2207f);
    glEnd();

    glLineWidth(3.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_LINES);
        glVertex2f(16, 96);
        glVertex2f(16.5004f, 292.2207f);
        glVertex2f(16.5004f, 292.2207f);
        glVertex2f(68.6349f, 277.1418f);
        glVertex2f(68.8631f, 116);
        glVertex2f(68.6349f, 277.1418f);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF); // dashed pattern
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2f(42.56765f, 106.0f);
        glVertex2f(42.56765f, 284.68125f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1.0f);
}

void drawPushDoor2() {
    glBegin(GL_QUADS);
        glColor3f(0.369f, 0.494f, 0.675f);
        glVertex2f(93, 125);  // Vertex 1
        glVertex2f(128.3894f, 139); // Vertex 2
        glVertex2f(128.3894f, 256.8384f); // Vertex 3
        glVertex2f(93, 265.7180f); // Vertex 4
    glEnd();

    // Drawing lines with the same pattern as before
    glLineWidth(3.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_LINES);
        glVertex2f(93, 125); // Vertex 1
        glVertex2f(93, 265.7180f); // Vertex 4
        glVertex2f(93, 265.7180f); // Vertex 4
        glVertex2f(128.3894f, 256.8384f); // Vertex 3
        glVertex2f(128.3894f, 139); // Vertex 2
        glVertex2f(128.3894f, 256.8384f); // Vertex 3
    glEnd();

    // Drawing dashed line in the middle
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF); // dashed pattern
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2f(110.6947f, 132.0f);  // Horizontal center line start
        glVertex2f(110.6947f, 261.8092f);  // Horizontal center line end
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1.0f);
}

void drawPushDoor3() {
    glBegin(GL_QUADS);
        glColor3f(0.369f, 0.494f, 0.675f);
        glVertex2f(148, 180);
        glVertex2f(167.2974711819085, 183.3954606036475);
        glVertex2f(167.2974711819085, 246);
        glVertex2f(148, 249.6974227917067);
    glEnd();

    glLineWidth(3.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_LINES);
        glVertex2f(148, 180);
        glVertex2f(148, 249.6974227917067);
        glVertex2f(148, 249.6974227917067);
        glVertex2f(167.2974711819085, 246);
        glVertex2f(167.2974711819085, 183.3954606036475);
        glVertex2f(167.2974711819085, 246);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2f(157.64873559095425, 181.6977303018238);
        glVertex2f(157.64873559095425, 244.3987113963232);
       glVertex2f(148, 180);
        glVertex2f(167.2974711819085, 183.3954606036475);

    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1.0f);
}

void drawPushDoor4() {
    glBegin(GL_QUADS);
        glColor3f(0.369f, 0.494f, 0.675f);
        glVertex2f(215.0662556213664, 172);
        glVertex2f(224.0378426276773, 175);
        glVertex2f(224.0378426276773, 227.8431492863085);
        glVertex2f(215.0662556213664, 229.3932379898749);
    glEnd();

    glLineWidth(3.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_LINES);
        glVertex2f(215.0662556213664, 172);
        glVertex2f(215.0662556213664, 229.3932379898749);
        glVertex2f(215.0662556213664, 229.3932379898749);
        glVertex2f(224.0378426276773, 227.8431492863085);
        glVertex2f(224.0378426276773, 175);
        glVertex2f(224.0378426276773, 227.8431492863085);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2f(219.55254912452285, 174.5f);
        glVertex2f(219.55254912452285, 227.3436931385917f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1.0f);
}
void drawPushDoor5() {
    glBegin(GL_QUADS);
        glColor3f(0.369f, 0.494f, 0.675f);
        glVertex2f(233.1995340965637, 179);
        glVertex2f(239.2391067870856, 181);
        glVertex2f(239.1103890449463, 223.5503277105387);
        glVertex2f(232.6333241568273, 224.5449984866471);
    glEnd();

    glLineWidth(3.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_LINES);
        glVertex2f(233.1995340965637, 179);
        glVertex2f(233.1995340965637, 224.5449984866471);
        glVertex2f(233.1995340965637, 224.5449984866471);
        glVertex2f(239.1103890449463, 223.5503277105387);
        glVertex2f(239.2391067870856, 181);
        glVertex2f(239.1103890449463, 223.5503277105387);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
        glVertex2f(236.1693204418246, 179.5f);
        glVertex2f(236.1693204418246, 223.8256630981939f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1.0f);
}

void circleCar(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f( 0,0,0);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}
//
// car_3 wheel circle

void car() {
    glPushMatrix();
    glTranslatef(0.0, 0.0f, 0.0f);

    //car body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(600, 410);   // 110+300
    glVertex2f(600, 420);   // 120+300
    glVertex2f(605, 430);   // 130+300
    glVertex2f(620, 430);   // 130+300
    glVertex2f(630, 440);   // 140+300
    glVertex2f(680, 440);   // 140+300
    glVertex2f(690, 430);   // 130+300
    glVertex2f(700, 430);   // 130+300
    glVertex2f(700, 410);   // 110+300
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(600, 410);
    glVertex2f(600, 420);
    glVertex2f(605, 430);
    glVertex2f(620, 430);
    glVertex2f(630, 440);
    glVertex2f(680, 440);
    glVertex2f(690, 430);
    glVertex2f(700, 430);
    glVertex2f(700, 410);
    glEnd();

    //car door
    glBegin(GL_POLYGON);
    glColor3ub(25, 104, 88);
    glVertex2f(625, 430);
    glVertex2f(633, 439);
    glVertex2f(655, 439);
    glVertex2f(655, 430);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(625, 430);
    glVertex2f(633, 439);
    glVertex2f(655, 439);
    glVertex2f(655, 430);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(25, 104, 88);
    glVertex2f(655, 439);
    glVertex2f(678, 439);
    glVertex2f(687, 430);
    glVertex2f(655, 430);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(655, 439);
    glVertex2f(678, 439);
    glVertex2f(687, 430);
    glVertex2f(655, 430);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(625, 430);
    glVertex2f(687, 430);
    glVertex2f(687, 415);   // 115+300
    glVertex2f(625, 415);   // 115+300
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(655, 430);
    glVertex2f(655, 415);
    glEnd();

    // wheels
    circleCar(8.0, 617.495, 415.235, 1.0, 1.0, 1.0); // 115.235+300
    circleCar(8.0, 683.133, 415.015, 1.0, 1.0, 1.0); // 115.015+300

    glPopMatrix();
}







void display3_view() {
        glClearColor(0.396, 0.820, 0.973, 1.0);
              if (isRaining) {

glClearColor(0.5843f, 0.6471f, 0.7098f, 0.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);

    // rasta dan e c er piche
    glBegin(GL_QUADS);
    glColor3f(0.8706f, 0.7647f, 0.6667f);
    glVertex2f(596.1367780438247, 147.6327602632784);
    glVertex2f(1300, 170);
    glVertex2f(1300.0, 224.1164303542989);
    glVertex2f(485.0947886877912, 201.0227971692856);
    glEnd();

    // rasta
    glBegin(GL_QUADS);
    glColor3f(0.8863f, 0.7686f, 0.6353f);
    glVertex2f(83.4764, 0.3951);
    glVertex2f(1152.2943, 0.5953);
    glVertex2f(483.7939, 200.7577);
    glVertex2f(296.9276, 201.3507);
    glEnd();

    // oporer borabor rasta
    // bam pasher rastar border
    glBegin(GL_QUADS);
    glColor3f(0.6118f, 0.5373f, 0.4353f);
    glVertex2f(52.8771, 0.5293);
    glVertex2f(83.4764, 0.3951);
    glVertex2f(296.9276, 201.3507);
    glVertex2f(295.0903, 202.6335);
    glEnd();

    // border er upor er iline
    glBegin(GL_QUADS);
    glColor3f(0.7961f, 0.5490f, 0.4235f);
    glVertex2f(26.0880, 0.5353);
    glVertex2f(52.8771, 0.5293);
    glVertex2f(295.0903, 202.6335);
    glVertex2f(293.6735, 203.0973);
    glEnd();

    // border er opur er rasta
    glBegin(GL_POLYGON);
    glColor3f(0.8196f, 0.4588f, 0.2980f);
    glVertex2f(0.0, 0.0);
    glVertex2f(26.0880, 0.5353);
    glVertex2f(147.6578, 91.6167);
    glVertex2f(87.5409, 129.5996);
    glVertex2f(1.3044, 90.4966);
    glVertex2f(0.0, 0.0);
    glEnd();

    ////border er opur er rasta2
    glBegin(GL_QUADS);
    glColor3f(0.8196f, 0.4588f, 0.2980f);
    glVertex2f(147.6578, 91.6167);
    glVertex2f(295.0903, 202.6336);
    glVertex2f(87.5409, 202.6336);
    glVertex2f(87.5409, 90.4966);
    glEnd();

    // annex 01 er bulding
    glBegin(GL_QUADS);
    glColor3f(0.349, 0.267, 0.302);
    glVertex2f(0.0, 90.49661755272481);
    glVertex2f(295.0903494685817, 204.6335654430225);
    glVertex2f(295.0011062164624, 225.2518256660875);
    glVertex2f(0.0, 312.1474992616353);
    glEnd();

    //annex 07
    glBegin(GL_QUADS);
    glColor3f(0.275f,0.0188f, 0.137f);
    glVertex2f(483, 200);
    glVertex2f(1300, 200);
    glVertex2f(1300, 287);
    glVertex2f(483, 287);
    glEnd();

    // piller
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(71.9129505427863, 76.7814353842085);
    glVertex2f(81.4459774611849, 77.0793424754085);
    glVertex2f(80.6910068622449, 308.6420378912223);
    glVertex2f(71.5148141438746, 312.0066418879578);
    glEnd();

    glPushMatrix();
    glTranslatef(100.5697, 64.0648, 0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(71.9129505427863, 76.7814353842085);
    glVertex2f(81.4459774611849, 76.7814353842085);
    glVertex2f(81.4459774611849, 203.9352);
    glVertex2f(71.9129505427863, 203.9352);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(205, 151.9086130516011);
    glVertex2f(210.5877264055559, 151.058207108191);
    glVertex2f(210.5877264055559, 254);
    glVertex2f(205, 254);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(205, 151.9086130516011);
    glVertex2f(210.5877264055559, 151.058207108191);
    glVertex2f(210.5877264055559, 254);
    glVertex2f(205, 254);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(244.3129771011757, 174.233118733604);
    glVertex2f(246.8357717235292, 174.233118733604);
    glVertex2f(246.8357717235292, 237.7422475159813);
    glVertex2f(244.3129771011757, 237.7422475159813);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(227.9720093895162, 165.1347906660839);
    glVertex2f(230.7889627931987, 165.1347906660839);
    glVertex2f(230.7889627931987, 244.7719610129507);
    glVertex2f(227.9720093895162, 244.7719610129507);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(261.9265016864052, 184.5399913184432);
    glVertex2f(264.0149028149285, 184.5399913184432);
    glVertex2f(264.0149028149285, 230.3339121539055);
    glVertex2f(261.9265016864052, 230.3339121539055);
    glEnd();

    glPushMatrix();
    glTranslatef(16.0, 10.0, 0.0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(261.9265016864052, 184.5399913184432);
    glVertex2f(264.0149028149285, 184.5399913184432);
    glVertex2f(264.0149028149285, 216.3339121539055);
    glVertex2f(261.9265016864052, 216.3339121539055);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.0, 12.0, 0.0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(261.9265016864052, 184.5399913184432);
    glVertex2f(264.0149028149285, 184.5399913184432);
    glVertex2f(264.0149028149285, 215.3339121539055);
    glVertex2f(261.9265016864052, 215.3339121539055);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.0, 15.0, 0.0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(261.9265016864052, 184.5399913184432);
    glVertex2f(264.0149028149285, 184.5399913184432);
    glVertex2f(264.0149028149285, 215.3339121539055);
    glVertex2f(261.9265016864052, 215.3339121539055);
    glEnd();
    glPopMatrix();

    // nicher chad
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.8, 0.4);
    glVertex2f(0.0, 312.1474992616353);
    glVertex2f(283.6291725613816, 228.5382547195481);
    glVertex2f(283.6291725613816, 223.5382547195481);
    glVertex2f(66.9384684772161, 319.0192360586722);
    glVertex2f(0.0, 332.936088887624);
    glEnd();

    // middle
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(0.8881262763529, 354.299368404069);
    glVertex2f(1.2977581748895, 329.936088887624);
    glVertex2f(70.9384684772161, 300.0192360586722);
    glVertex2f(280.6396904343573, 225.0733346246547);
    glVertex2f(247.3566214779486, 245.2425773239534);
    glVertex2f(0.8881262763529, 354.299368404069);
    glEnd();

    // 3 number chad
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.333, 0.0);
    glVertex2f(0.8881262763529, 354.299368404069);
    glVertex2f(287.2299791773771, 223.0976659850995);
    glVertex2f(300.2801731422936, 230.4091951006197);
    glVertex2f(0.8881262763529, 383.7931124159107);
    glEnd();

    // aro upore
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.659, 0.408);
    glVertex2f(147.7470156995607, 322.9233197484841);
    glVertex2f(289.9179924547182, 234.0073520613166);
    glVertex2f(280.4420992785732, 234.4617728578276);
    glVertex2f(115.1419081069187, 324.7384474383);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.749, 0.0);
    glVertex2f(0.8881262763529, 383.7931124159107);
    glVertex2f(77.9843886245927, 342.3048422782225);
    glVertex2f(77.1694150323584, 379.4094306136194);
    glVertex2f(0.3011008285456, 429.8108769135501);
    glEnd();

    // annex l1
    glBegin(GL_QUADS);
    glColor3f(0.46f, 0.74f, 0.83f);
    glVertex2f(294.9276242442949, 201.3507116159309);
    glVertex2f(382.8062222090683, 201.3507116159309);
    glVertex2f(382.8062222090683, 223.4091951006197);
    glVertex2f(294.9276242442949, 223.4091951006197);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(296.9276242442949, 223.4091951006197);
    glVertex2f(382.8062222090683, 223.4091951006197);
    glVertex2f(382.8062222090683, 253.9694020368612);
    glVertex2f(257.849148739168, 253.9694020368612);
    glEnd();

    // annex l2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(296.9276242442949, 223.4091951006197);
    glVertex2f(382.8062222090683, 223.4091951006197);
    glVertex2f(382.8062222090683, 262.7091421442963);
    glVertex2f(244.0078724287756, 262.7091421442963);
    glEnd();

    // left up l2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(244.0078724287756, 262.7091421442963);
    glVertex2f(270.795437241631, 262.7091421442963);
    glVertex2f(270.795437241631, 283.682377901205);
    glVertex2f(207.537920259119, 283.682377901205);
    glEnd();

    // leftup
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(270.795437241631, 262.7706044861324);
    glVertex2f(383.0330540996398, 262.7706044861324);
    glVertex2f(383.0330540996398, 296.8946311124793);
    glVertex2f(404.6579541934993, 308);
    glVertex2f(270.2655056077541, 308);
    glEnd();

    // big glass
    drawGlassPanes1(279.6374785377819f, 262, 100, 48);

    // big glass  upper
    glBegin(GL_QUADS);
    glColor3f(0.760f, 0.76f, 0.760f);
    glVertex2f(270.3287001122025, 305);
    glVertex2f(390, 305);
    glVertex2f(407, 313);
    glVertex2f(266, 313);
    glEnd();

    // majhkhan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.549, 0.0);
    glVertex2f(399.6486412082369, 306.2785753165301);
    glVertex2f(436.9334783650598, 321.1269231741898);
    glVertex2f(475.086678935429, 300.0457125755724);
    glVertex2f(475.086678935429, 331.3160519629283);
    glVertex2f(399.6486412082369, 331.3160519629283);
    glVertex2f(399.6486412082369, 316.2785753165301);
    glEnd();

    // annex 2 front glass 2
    glBegin(GL_POLYGON);
    glColor3f(0.87f, 0.83f, 0.64f);
    glVertex2f(382.8062222090683, 280);
    glVertex2f(483.7938870128262, 280);
    glVertex2f(483.7938870128262, 298.0045303513236);
    glVertex2f(436.9334783650598, 321.1269231741898);
    glVertex2f(382.8062222090683, 298.0045303513236);
    glVertex2f(382.8062222090683, 200.4779178362875);
    glEnd();

    // buiding er border
    glPushMatrix();
    glTranslatef(-105, -80, 0);
    drawRectangle(400.0f, 300.0f, 100.0f, 8.0f, 0.412f, 0.412f, 0.412f);
    glPopMatrix();

    // mid line between glass and ground
    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.83f, 0.64f);
    glVertex2f(257, 253);
    glVertex2f(484.5, 253);
    glVertex2f(484.5, 265);
    glVertex2f(240, 265);
    glEnd();

    drawGlassPanes1(381, 262, 104.5, 37);

    glBegin(GL_QUADS);
    glColor3f(0.760f, 0.760f, 0.760f);
    glVertex2f(239, 265);
    glVertex2f(271, 265);
    glVertex2f(271, 273.9540066628481);
    glVertex2f(224, 274.1865507954708);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.83f, 0.64f);
    glVertex2f(224, 274.);
    glVertex2f(271, 273.9540066628481);
    glVertex2f(271, 286);
    glVertex2f(206, 286);
    glEnd();

    //Cloud

    glPushMatrix();
    glTranslatef(position21,0,0);
    drawCloud1(500,500);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position22,0,0);
    glScalef(0.5,0.5,1.0);
    drawCloud2(350,1400);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position23,0,0);
    glScalef(0.5,0.5,1.0);
    drawCloud2(2250,1300);
    glPopMatrix();

    // planes
    glPushMatrix();
    glTranslatef(position20, 580.0f, 0.0f);
    smallplane();
    glPopMatrix();

    //tree beside c Building

    glPushMatrix();
    glScalef(0.3,0.5,1.0);
    glTranslatef(1550,380,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.6,1.0);
    glTranslatef(2650,330,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6,0.6,1.0);
    glTranslatef(200,310,0);
    drawChristmasTree(1840.0f, 47.0f, 160.0f, 280.0f);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.4,1.0);
    glTranslatef(100,240,0);
    drawChristmasTree(4150.0f, 300.0f, 160.0f, 280.0f);
    glPopMatrix();

    // c building circle
    glPushMatrix();
    glScalef(1.17f, 1.10f, 1.0f);
    glTranslatef(69, 94.5, 0);
    drawGradientCircle(700.0f, 340.0f, 240.0f, 0.9f, 0.9f, 0.9f, 0.760f, 0.76f, 0.760f);
    glPopMatrix();

    // circle down part
    glBegin(GL_QUADS);
    glColor3f(0.760f, 0.760f, 0.760f);
    glVertex2f(741, 182);
    glVertex2f(1062, 182);
    glVertex2f(1062, 262);
    glVertex2f(741, 262);
    glEnd();

    // circle down part glass
    glBegin(GL_QUADS);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(741, 182);
    glVertex2f(1062, 182);
    glVertex2f(1062, 242);
    glVertex2f(741, 242);
    glEnd();

    // glass
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.85f, 0.95f);
    glVertex2f(646, 364.7403517059937);
    glVertex2f(629.5, 405.7459924874826);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(1170.1409, 405.7459924874826);
    glVertex2f(1153, 364.6329941794602);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.85f, 0.95f);
    glVertex2f(694, 301.0281768918899);
    glVertex2f(673, 324);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(1128, 324);
    glVertex2f(1106, 301.281768918899);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.85f, 0.95f);
    glVertex2f(623, 440);
    glVertex2f(619, 481);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(1181, 481);
    glVertex2f(1176.5, 440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.85f, 0.95f);
    glVertex2f(624.5, 528);
    glVertex2f(635, 568);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(1164.5, 568);
    glVertex2f(1174.5, 528);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.85f, 0.95f);
    glVertex2f(658, 613);
    glVertex2f(685, 648);
    glColor3f(0.113f, 0.564f, 0.713f);
    glVertex2f(1115, 648);
    glVertex2f(1140, 613);
    glEnd();

    // annex 2 front glass
    glBegin(GL_QUADS);
    glColor3f(0.113f, 0.564f, 0.7130f);
    glVertex2f(382.8062222090683, 200.4779178362875);
    glVertex2f(483.7938870128262, 200.4779178362875);
    glVertex2f(483.7938870128262, 254);
    glVertex2f(382.8062222090683, 254);
    glEnd();

    // circle line using beziercurve
    glColor3f(0.0f, 0.0f, 0.0f);
    drawBezierCurve(740, 262, 980, 262, 1062, 262);
    drawBezierCurve(708, 670, 900, 670, 1092, 670);
    drawBezierCurve(735, 690, 910, 690, 1065, 690);
    drawBezierCurve(767, 710, 910, 710, 1032, 710);
    drawBezierCurve(917, 740, 934, 580, 921, 262);
    drawBezierCurve(938, 739, 975, 582, 941, 262);
    drawBezierCurve(961, 733.5, 1009, 579, 957, 262);
    drawBezierCurve(985, 730, 1043, 575, 977, 262);
    drawBezierCurve(1010, 719, 1075, 566, 994, 262);
    drawBezierCurve(1032, 710, 1104, 556, 1011, 262);
    drawBezierCurve(1064, 691, 1129, 546, 1027, 262);
    drawBezierCurve(1092, 670, 1151, 536, 1039, 262);
    drawBezierCurve(1115, 648, 1170, 523, 1052, 262);
    drawBezierCurve(1150, 596, 1190, 450, 1060, 262);
    // left
    drawBezierCurve(892, 740, 890, 580, 905, 262);
    drawBezierCurve(874, 740, 851, 577, 887, 262);
    drawBezierCurve(845, 734, 811, 571, 867, 262);
    drawBezierCurve(821, 730, 775, 565, 850, 262);
    drawBezierCurve(797, 722, 740, 556, 832, 262);
    drawBezierCurve(767, 710, 710, 544, 814, 262);
    drawBezierCurve(736, 691, 682, 533, 801, 262);
    drawBezierCurve(708, 670, 657, 523, 784, 262);
    drawBezierCurve(685, 647, 636, 523, 764, 262);
    drawBezierCurve(653, 603, 615, 450, 741, 262);

    // PARKING

    glBegin(GL_TRIANGLES);
    glColor3f(0.8706f, 0.7647f, 0.6667f);
    glVertex2f(1299.4863431989108, 11.4743637369186);
    glVertex2f(630.8281179233156, 152.6327197850181);
    glVertex2f(1300.4062905814822, 168.5131538704647);
    glEnd();
    // road side RIGHT

    glBegin(GL_POLYGON);
    glColor3f(0.30f, 0.15f, .047f);
    glVertex2f(1152.294277378869, 0.5953010458131);
    glVertex2f(1300, 0);
    glVertex2f(1299.4176452563743, 2.812426775411);
    glVertex2f(598.8281179233156, 159.6858509434785);
    glVertex2f(596.1367780438247, 147.6327602632784);
    glVertex2f(1152.294277378869, 0.5953010458131);
    glEnd();

    // border
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1299.4176452563743, 2.812426775411);
    glVertex2f(1299.4863431989108, 11.4743637369186);
    glVertex2f(606.396246128399, 160.7418177105664);
    glVertex2f(598.8281179233156, 159.6858509434785);
    glEnd();

    // C ER PASHER RASTA
    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.15f, .047f);
    glVertex2f(598.8281179233156, 149.6327197850181);
    glVertex2f(1298.4062905814822, 166.8131768234987);
    glVertex2f(1298.4062905814822, 171.5131538704647);
    glVertex2f(598.8281179233156, 157.156688191266);
    glEnd();

    // BORD.
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(598.8281179233156, 156.3406738156157);
    glVertex2f(1298.4062905814822, 172.0743808496222);
    glVertex2f(1298.4062905814822, 174.5033191525594);
    glVertex2f(598.8281179233156, 159.2735970191149);
    glEnd();

    // BACK ENTRY OF C BUILDING
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1078.5405999297334, 262.8261963719961);
    glVertex2f(1300, 270);
    glVertex2f(1299.726553180645, 276.9135757269882);
    glVertex2f(1078.489310945866, 267.9635612965232);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1115.6313065040633, 260.1122971756657);
    glVertex2f(1115.3777150131343, 263.3348822795231);
    glVertex2f(1239.363383998938, 266.1627116433855);
    glVertex2f(1238.7109683945062, 258.4968282913179);
    glVertex2f(1219.4548396221599, 256.7977581055232);
    glVertex2f(1115.6313065040633, 260.1122971756657);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1287.731938191844, 264.2705616514101);
    glVertex2f(1287.379092387262, 260.4867932754078);
    glVertex2f(1288.0296352154278, 269.5943928697254);
    glVertex2f(1249.1326238312097, 267.3855056800612);
    glEnd();

    // 1ST PILLER
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1108.5764659443578, 186.239140517457); // Center of the fan
    glVertex2f(1111.988176034126, 186.239140517457);
    glVertex2f(1111.988176034126, 262.8098251279502);
    glVertex2f(1108.5764659443578, 262.8098251279502);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(1111.988176034126, 185.9761323587915); // Center of the fan
    glVertex2f(1115.1710711089652, 186.239140517457);
    glVertex2f(1115.1710711089652, 262.8098251279502);
    glVertex2f(1111.988176034126, 262.8098251279502);
    glEnd();

    // 2ND PILLER
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1160.1348947610768, 186.6711878491064);
    glVertex2f(1164.7519164526361, 186.6684153837378);
    glVertex2f(1164.773112603714, 265.1774190649665);
    glVertex2f(1160.0093798028654, 264.2554062648026);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(1164.7519164526361, 186.6684153837378);
    glVertex2f(1169.9332104108712, 186.8476224456502);
    glVertex2f(1169.9332104108712, 265.1027200895467);
    glVertex2f(1164.773112603714, 265.1774190649665);
    glEnd();

    // 3RD PILLER
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1220.3782235419924, 186.6684153837378);
    glVertex2f(1224.6819480097122, 186.8476224456502);
    glVertex2f(1224.8868872700798, 264.3868458643198);
    glVertex2f(1220.1732842816248, 264.0794369737685);
    glEnd();

    // 4TH PILLER
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1239.1866856624365, 186.6684153837378);
    glVertex2f(1244.817953736962, 186.8476224456502);
    glVertex2f(1244.6584630678465, 267.4216913227469);
    glVertex2f(1239.4766284578734, 267.6035102188326);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.8f, 0.0f, 0.0f);
    glVertex2f(1244.817953736962, 186.6684153837378);
    glVertex2f(1250.9081807321684, 186.8476224456502);
    glVertex2f(1250.9081807321684, 267.6035102188326);
    glVertex2f(1244.6584630678465, 266.8914450933589);
    glEnd();

    // 5TH PILLER
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1288.4658553771446, 207.4423934283032);
    glVertex2f(1293.784076005029, 207.925868030838);
    glVertex2f(1294.2044586319648, 269.9418763780121);
    glVertex2f(1288.0296352154278, 269.5943928697254);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.8f, 0.0f, 0.0f);
    glVertex2f(1293.784076005029, 207.925868030838);
    glVertex2f(1298.507354585035, 207.3535585816047);
    glVertex2f(1297.7693406429096, 269.5319507606001);
    glVertex2f(1294.2044586319648, 269.9418763780121);
    glEnd();

    // front C building Entry
    // glass
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(700, 280);
    glVertex2f(699.9662035274524, 290.2111777887104);
    glVertex2f(785.3276708212455, 289.9098695929029);
    glVertex2f(720, 275);
    glEnd();

    // 1st piller
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(500.719393761909, 193.3330106622638);
    glVertex2f(506.4324142284048, 193.4917056752219);
    glVertex2f(506.4324142284048, 295.7887652602219);
    glVertex2f(500.719393761909, 295.7887652602219);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(506.4324142284048, 193.4917056752219);
    glVertex2f(511.8235944095425, 193.4917056752219);
    glVertex2f(511.8235944095425, 295.7236677191886);
    glVertex2f(506.4324142284048, 295.7236677191886);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(507.1195491489399, 272.9993159021253);
    glVertex2f(628.601309783021, 267.2258081370178);
    glVertex2f(628.601309783021, 295.9060835748871);
    glVertex2f(507.2537349698606, 295.1423367974218);
    glEnd();

    // 2nd piller
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(544.2494795033981, 192.4865880350536);
    glVertex2f(551.1442538754131, 192.4865880350536);
    glVertex2f(551.1442538754131, 273.1479737849707);
    glVertex2f(544.2494795033981, 273.1479737849707);
    glEnd();

    // 3rd piller
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(564.2066196576111, 193.668252229321);
    glVertex2f(567.4529318184902, 193.7850667795886);
    glVertex2f(567.1119346570385, 270.5163614657751);
    glVertex2f(564.2066196576111, 270.6481533930701);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(567.4529318184902, 193.668252229321);
    glVertex2f(573.3743178782028, 193.7850667795886);
    glVertex2f(573.3743178782028, 272.736880909065);
    glVertex2f(567.1119346570385, 270.5163614657751);
    glEnd();

    // chad
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(644.8732500871048, 266.5801663120493);
    glVertex2f(676.8358552787722, 268.8016424224859);
    glVertex2f(679.5988227906361, 268.9845701473736);
    glVertex2f(679.8835736065565, 272.686330754338);
    glVertex2f(644.3344156308588, 274.9321003838589);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(637.4855665861012, 180);
    glVertex2f(644.0398512062516, 180);
    glVertex2f(644.0398512062516, 268.8016424224859);
    glVertex2f(637.4855665861012, 268.8016424224859);
    glEnd();

    // piller 4
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(680.1281903952372, 178.047084428404);
    glVertex2f(682.9593238077588, 178.047084428404);
    glVertex2f(682.8462120644958, 272.4554894246355);
    glVertex2f(679.8835736065565, 272.686330754338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(677.0283919371622, 178.047084428404);
    glVertex2f(680.1281903952372, 178.047084428404);
    glVertex2f(679.8835736065565, 272.686330754338);
    glVertex2f(677.3751308193962, 272.6496867436077);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(682.9593238077588, 178.047084428404);
    glVertex2f(689.5464107224161, 178.047084428404);
    glVertex2f(689.4993145548096, 272.6501463082412);
    glVertex2f(682.8462120644958, 272.4554894246355);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f); // Red color
    glVertex2f(689.2974439136328, 178.047084428404);
    glVertex2f(694.5759929996071, 177.5010276264069);
    glVertex2f(694.5759929996071, 304.3527667058199);
    glVertex2f(690, 304);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(694.5759929996071, 177.5010276264069);
    glVertex2f(701.3095025251616, 177.2018730696693);
    glVertex2f(701.3095025251616, 304.858980577953);
    glVertex2f(694.5759929996071, 304.3527667058199);
    glEnd();

    // 5 piller
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(763.714377057203, 183.6917839206568);
    glVertex2f(769.6072458609956, 183.6917839206568);
    glVertex2f(769.6072458609956, 288.2464177494189);
    glVertex2f(763.714377057203, 288.8439991246361);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(769.6072458609956, 183.6917839206568);
    glVertex2f(775.9146549969757, 183.6917839206568);
    glVertex2f(775.9146549969757, 290.7857160884943);
    glVertex2f(769.6072458609956, 290.2464177494189);
    glEnd();

    // glass er chad
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(545.398534082733, 292.7637991247255);
    glVertex2f(605.5902034095014, 300.4740915002266);
    glVertex2f(758.3276708212455, 290.9098695929029);
    glVertex2f(727.9375991018672, 288.4841395428686);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.760f, 0.760f, 0.760f);
    glVertex2f(504.3734639049129, 288.9209417802476);
    glVertex2f(602.5902034095014, 300.4740915002266);
    glVertex2f(602.9784387391031, 310.4052470438083);
    glVertex2f(500.9168800291897, 295.8243255124515);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(650.1653082275585, 270.4272277428001);
    glVertex2f(725.9212200962293, 268.6806060841046);
    glVertex2f(726.1923349580047, 278.7118559697937);
    glVertex2f(650, 280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(602.5902034095014, 300.4740915002266);
    glVertex2f(796.9420777719604, 283.5497960285989);
    glVertex2f(797.0863681158785, 293.9387007906959);
    glVertex2f(602.9784387391031, 311.4052470438083);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(512.3293853483249, 281.5480177318852);
    glVertex2f(611.0990772738903, 275.4633518969316);
    glVertex2f(630.2053835634305, 286.6665014232669);
    glVertex2f(543.8847453761201, 291.5947915523902);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(644.3344156308588, 274.9321003838589);
    glVertex2f(689.4993145548096, 272.6501463082412);
    glVertex2f(690.3015023660904, 279.8390836907677);
    glVertex2f(644.7631607122304, 282.3312317414755);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); // Red color
    glVertex2f(644.7631607122304, 282.3312317414755);
    glVertex2f(690.3015023660904, 279.8390836907677);
    glVertex2f(690, 290);
    glVertex2f(644.0398512062516, 294.0001474239893);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); // Red color
    glVertex2f(504.3734639049129, 288.9209417802476);
    glVertex2f(602.5902034095014, 300.4740915002266);
    glVertex2f(644.8104533805736, 298.2447851466007);
    glVertex2f(644.550538530238, 268.3511005075811);
    glEnd();

    // piller
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f); // Red color
    glVertex2f(718.4320231458969, 183.6181684606628);
    glVertex2f(721.4547638953333, 183.766785889859);
    glVertex2f(721.4547638953333, 268.8354460231544);
    glVertex2f(718.3811853163588, 268.7450466531846);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(721.4547638953333, 183.766785889859);
    glVertex2f(727.321159035158, 183.087562223831);
    glVertex2f(727.4763191591026, 278.6956636010764);
    glVertex2f(721.4547638953333, 278.0646479198989);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(633.8447567531335, 180.5470679076668);
    glVertex2f(644.9249012321061, 180.3270575877403);
    glVertex2f(644.9249012321061, 297.0001474239893);
    glVertex2f(633.8447567531335, 297.808440457895);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f); // Red color
    glVertex2f(512.3293853483249, 281.5480177318852);
    glVertex2f(611.0990772738903, 275.4633518969316);
    glVertex2f(611.8024181833916, 281.1242535593613);
    glVertex2f(511.3042577296061, 284.8187276868007);
    glEnd();

    // annex 1 door
    glBegin(GL_QUADS);
    glColor3f(0.369, 0.494, 0.675);
    glVertex2f(16, 96);
    glVertex2f(68.8630969748587, 116);
    glVertex2f(68.6349282219748, 277.1417996479576);
    glVertex2f(16.500426299522, 292.2207017424457);
    glEnd();

    //door er brd...

  drawPushDoor();

    glBegin(GL_QUADS);
    glColor3f(0.369, 0.494, 0.675);
    glVertex2f(93, 125);
    glVertex2f(128.3894444933949, 139);
    glVertex2f(128.3894444933949, 256.8384310213052);
    glVertex2f(93, 265.7180347327184);
    glEnd();
//3
    glBegin(GL_QUADS);
    glColor3f(0.369, 0.494, 0.675);
    glVertex2f(148, 180);
    glVertex2f(167.2974711819085, 183.3954606036475);
    glVertex2f(167.2974711819085, 246);
    glVertex2f(148, 249.6974227917067);
    glEnd();
    drawPushDoor3();
//4
    glBegin(GL_QUADS);
    glColor3f(0.369, 0.494, 0.675);
    glVertex2f(215.0662556213664, 172);
    glVertex2f(224.0378426276773, 175);
    glVertex2f(224.0378426276773, 227.8431492863085);
    glVertex2f(215.0662556213664, 229.3932379898749);
    glEnd();

    drawPushDoor4();
    glBegin(GL_QUADS);
    glColor3f(0.369, 0.494, 0.675);
    glVertex2f(233.1995340965637, 179);
    glVertex2f(239.2391067870856, 181);
    glVertex2f(239.1103890449463, 223.5503277105387);
    glVertex2f(232.6333241568273, 224.5449984866471);
    glEnd();

    drawPushDoor2();
    drawPushDoor5();
    // soller panel 1
    glBegin(GL_POLYGON);
    glColor3f(0.1176f, 0.3608f, 0.6078f);
    glVertex2f(0.4907, 430.677);
    glVertex2f(77.3793, 379.8451);
    glVertex2f(78.6608, 363.6130);
    glVertex2f(176.0531, 411.882);
    glVertex2f(104.2903, 534.0495);
    glVertex2f(1.3450, 493.4694);
    glEnd();

    // sollar border's
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(3.5349, 438.4030);
    glVertex2f(127.1320, 494.2636);
    glVertex2f(123.8332, 498.0024);
    glVertex2f(0.2361, 442.8015);
    glEnd();

    glPushMatrix();
    glTranslatef(5.0f, -18.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(6.5349, 438.4030);
    glVertex2f(129.1320, 494.2636);
    glVertex2f(129.8332, 498.0024);
    glVertex2f(2.0, 442.8015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.0f, -29.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(6.5349, 438.4030);
    glVertex2f(126.1320, 494.2636);
    glVertex2f(125.8332, 498.0024);
    glVertex2f(3, 442.8015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(31.0f, -41.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(5.5349, 438.4030);
    glVertex2f(118.8332, 494.2636);
    glVertex2f(118.8332, 498.0024);
    glVertex2f(5.5349, 442.8015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(44.0f, -51.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(5.5349, 438.4030);
    glVertex2f(111.8332, 494.2636);
    glVertex2f(111.8332, 498.0024);
    glVertex2f(5.5349, 442.8015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(57.0f, -61.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(5.5349, 438.4030);
    glVertex2f(104.8332, 490.2636);
    glVertex2f(106.8332, 494.0024);
    glVertex2f(5.5349, 442.8015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70.0f, -71.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(3.5349, 438.4030);
    glVertex2f(100.8332, 490.2636);
    glVertex2f(100.8332, 494.0024);
    glVertex2f(2.5349, 442.8015);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(3.5349, 463.4030);
    glVertex2f(116.1320, 513.2636);
    glVertex2f(112.8332, 517.0024);
    glVertex2f(0.2361, 465.8015);
    glEnd();

    // lines
    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(0.5467, 467.5578);
    glVertex2f(100.0f, 380.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(3.8084017824062, 489.101312598084);
    glVertex2f(117.4627651167045, 387.6262195317615);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(32.0120566114846, 499.583198381009);
    glVertex2f(133.0964040470956, 394.3553410639148);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(54.3904654570943, 508.0999028825877);
    glVertex2f(147.8738249349421, 397.1514427169581);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(69.4249915778173, 517.4344189332083);
    glVertex2f(158.5241323092583, 402.264245855756);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0627f, 0.1961f, 0.3490f);
    glVertex2f(90.5746255620024, 523.6957368332621);
    glVertex2f(162.6865874990882, 418.1716172269055);
    glEnd();

    //////////////////////////////

    // soller  pillar 1
    glBegin(GL_POLYGON);
    glColor3f(0.6627f, 0.6706f, 0.6627f);
    glVertex2f(102.7436, 355.9);
    glVertex2f(107.1920, 355.9);
    glVertex2f(107.1920, 509.4007);
    glVertex2f(102.7436, 509.4007);
    glEnd();

    // pillar 2
    glBegin(GL_POLYGON);
    glColor3f(0.6627f, 0.6706f, 0.6627f);
    glVertex2f(137.1293, 356.7539);
    glVertex2f(140.5111, 354.4458);
    glVertex2f(140.5111, 457.8914);
    glVertex2f(137.1293, 459.5811);
    glEnd();

    // pillar 3
    glBegin(GL_QUADS);
    glColor3f(0.6627f, 0.6706f, 0.6627f);
    glVertex2f(162.6866, 334.3515);
    glVertex2f(165.0436, 334.3515);
    glVertex2f(165.0436, 418.1716);
    glVertex2f(162.6866, 418.1716);
    glEnd();

    // soller box
    glBegin(GL_POLYGON);
    glColor3f(0.8941f, 0.8078f, 0.6157f);
    glVertex2f(77.4026, 342);
    glVertex2f(111.8943, 327);
    glVertex2f(131.1703, 318);
    glVertex2f(169.6219, 310);
    glVertex2f(169.6219, 324.4740);
    glVertex2f(174.1948, 326.8950);
    glVertex2f(136.4005, 356.7539);
    glVertex2f(78.1211, 359.0889);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6627f, 0.6706f, 0.6627f);
    glVertex2f(141.9923, 353.4774);
    glVertex2f(144.1015, 352.0983);
    glVertex2f(163.6243, 385.3429);
    glVertex2f(160.5241, 385.3429);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6627f, 0.6706f, 0.6627f);
    glVertex2f(53.4558, 512.5342);
    glVertex2f(103.0364, 467.8624);
    glVertex2f(103.1067, 470.8166);
    glVertex2f(55.1232, 513.7177);
    glEnd();

    // annex er bam
    glBegin(GL_QUADS);
    glColor3f(0.0509f, 0.2902f, 0.4824f);
    glVertex2f(294.7815, 200.1715);
    glVertex2f(383.3027, 200.1499);
    glVertex2f(383.3027, 226.8803);
    glVertex2f(294.6255, 226.8803);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.384f, 0.486f, 0.604f);
    glVertex2f(660.5835493090948, 200.4008882560463);
    glVertex2f(1299.2464804193346, 206.4058226574163);
    glVertex2f(1299.3620667687696, 207.5616861517673);
    glVertex2f(660.4658565018713, 202.6370515932938);
    glEnd();

    // c er nicher line///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(866.5310947807823, 261.4531388633845);
    glVertex2f(866.5310947807823, 180.1829880503726);
    glEnd();

    glPushMatrix();
    glTranslatef(20.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(866.5310947807823, 261.4531388633845);
    glVertex2f(866.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(866.5310947807823, 261.4531388633845);
    glVertex2f(866.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(89.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(109.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(127.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(143.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(160.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(160.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(172.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(185.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(193.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-34.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-52.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-68.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-83.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-104.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-125.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(867.5310947807823, 261.4531388633845);
    glVertex2f(867.5310947807823, 180.1829880503726);
    glEnd();
    glPopMatrix();
    //////////?/////c er pasher railin ////////////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(0.0, 3.0f, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.384f, 0.486f, 0.604f);
    for (float x = 660.5835493090948; x <= 1299; x += 3.0f){
        glVertex2f(x, 200.9112144263578);
        glVertex2f(x, 160.8373117348637);
    }
    glEnd();
    glPopMatrix();

    drawFlooringPattern();
    drawBush(1299.6930558361557f, 12.0655658650163f,1299.4347634474054f, 50.0127429101021f,660.0f,
              170.8515027251352f,660.0f, 148.2536155754597f);

    glPushMatrix();
    glScalef(0.5f,.5f,1.0f);
    drawPlantPotWithBush(150, 100, 12, 16);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.35f,.35f,1.0f);
    drawPlantPotWithBush(500, 360, 12, 16);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.20f,.20f,1.0f);
    drawPlantPotWithBush(1150, 800, 12, 16);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15f,0.15f,1.0f);
    drawPlantPotWithBush(1750, 1200, 12, 16);
    glPopMatrix();

//road divider
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(580.0f , 10.0f);
        glVertex2f(600.0f , 10.0f);
        glVertex2f(400.0f , 195.0f);
        glVertex2f(390.0f , 195.f);
        glEnd();

        glBegin(GL_QUADS);//split1
        glColor3f(0.8706f, 0.7647f, 0.6667f);
        glVertex2f(535.0f , 40.0f);
        glVertex2f(570.0f , 45.0f);
        glVertex2f(570.0f , 55.0f);
        glVertex2f(530.0f , 50.f);
        glEnd();

        glBegin(GL_QUADS);//split2
        glColor3f(0.8706f, 0.7647f, 0.6667f);
        glVertex2f(490.0f , 90.0f);
        glVertex2f(520.0f , 95.0f);
        glVertex2f(520.0f , 85.0f);
        glVertex2f(490.0f , 80.f);
        glEnd();

        glBegin(GL_QUADS);//split3
        glColor3f(0.8706f, 0.7647f, 0.6667f);
        glVertex2f(450.0f , 130.0f);
        glVertex2f(500.0f , 135.0f);
        glVertex2f(500.0f , 125.0f);
        glVertex2f(450.0f , 120.f);
        glEnd();

        glBegin(GL_QUADS);//split4
        glColor3f(0.8706f, 0.7647f, 0.6667f);
        glVertex2f(410.0f , 170.0f);
        glVertex2f(440.0f , 175.0f);
        glVertex2f(440.0f , 165.0f);
        glVertex2f(410.0f , 160.f);
        glEnd();

    glPushMatrix();
    glScalef(1.6,2,1);
    glTranslatef(-50,-340,0);
       car();
    glPopMatrix();
 glColor3f(0,0,1);

    glPushMatrix();
    glScalef(1.6,2,1);
    glTranslatef(70,-340,0);
    car();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.6,2,1);
    glTranslatef(105,-365,0);
    glColor3f(0.0f,0.0f,1.0f);
    car();
    glPopMatrix();




    glBegin(GL_QUADS);
    glColor3f(0.1137, 0.5647, 0.7137);
    glVertex2f(294.827, 200.0);
    glVertex2f(455.0, 200.0);
    glVertex2f(455.0, 227);
    glVertex2f(294.827, 227);
    glEnd();



    glBegin(GL_QUADS);
     glColor3f(0.1137, 0.5647, 0.7137);
    glVertex2f(284.0f, 238.1815454770666f);  // First vertex
    glVertex2f(390.0f, 238.1815454770666f);  // Second vertex
    glVertex2f(390.0f,254.3514557178951f);  // Third vertex
    glVertex2f(258.0f, 254.3514557178951f);  // Fourth vertex
glEnd();


    if (isRaining) {
        drawRain();
    }


    glFlush();



}


void keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentScene = 1;
        glutPostRedisplay();
    }
    if (key == '2') {
        currentScene = 2;
        glutPostRedisplay();
    }
    if (key == '3') {
        currentScene = 3;  // Switch to scene 3
        glutPostRedisplay();  // Trigger re-render to show scene 3
    }
}

// Function to display the correct scene based on the current scene
void displayBasedOnScene() {
    if (currentScene == 1) {
        display1_view();  // Display scene 1
    } else if (currentScene == 2) {
        display2_view();  // Display scene 2
    } else if (currentScene == 3) {
        display3_view();  // Display scene 3
    }
}

void timer2(int value) {
    if (isRaining) {
        updateRain(); // Update raindrop positions
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(1000 / 60, timer2, 0); // Redraw at 60 FPS
}





  int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1300,800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("S C H O O L");

    gluOrtho2D(0,1300,0,800);
    glutTimerFunc(10000, update, 0);
    glutTimerFunc(2000, update1, 0);
    glutTimerFunc(2000, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(1000, timer, 0);
    glutTimerFunc(1000, update10, 0);
    glutTimerFunc(2000, update20, 0);
    glutTimerFunc(1000, update21, 0);
    glutTimerFunc(1000, update22, 0);
    glutTimerFunc(1000, update23, 0);

    glutDisplayFunc(displayBasedOnScene);
   glutMouseFunc(mouse);
       glutTimerFunc(1000, timer2, 0);
    glutKeyboardFunc(keyboard);
    sound();
    glutMainLoop();
    return 0;

}
