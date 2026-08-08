#include "controller.h"

Controller::Controller()
{
    gameOver = false;
    gameRunning = false;
}

void Controller::renderStart(){
    glClearColor(0.04f, 0.01f, 0.12f, 1.0f);

    if(currentScore+100 < ai.score){
        bg.overAllSpeed += 0.01;
        currentScore = ai.score;
    }

    bg.animate(sunScaleChanger);
    bg.render();

    if(gameRunning){
        ai.render();
        if(ai.hero.newBullet)    ai.hero.newBullet = false;
        if(ai.newEnemyBullet)    ai.newEnemyBullet = false;
        if(ai.enemyDead)         ai.enemyDead = false;
    }
    else{
        renderBg();
        button();
    }

    if(ai.hero.dead){
        gameOver = true;
        gameRunning = false;
        if(wait > 5)        wait = -1;
        else if(wait >= 0)  wait += 0.05;
        if(bg.overAllSpeed > 0)
            bg.overAllSpeed -= (bg.overAllSpeed / 2);
    }
}

void Controller::renderBg(){
    Color color;

    // ── Dark glass panel (main menu card) ────────────────────────────────────
    color.setColor("0D1117");
    glPushMatrix();
        glTranslatef(-3.12f, -2.62f, 0);
        glScalef(7.0f, 6.5f, 1);
        Shapes::rect(color);
    glPopMatrix();

    // ── Top accent stripe (red) ───────────────────────────────────────────────
    color.setColor("E94560");
    glPushMatrix();
        glTranslatef(-3.12f, 3.7f, 0);
        glScalef(7.0f, 0.18f, 1);
        Shapes::rect(color);
    glPopMatrix();

    // ── Bottom accent stripe ──────────────────────────────────────────────────
    glPushMatrix();
        glTranslatef(-3.12f, -2.62f, 0);
        glScalef(7.0f, 0.18f, 1);
        Shapes::rect(color);
    glPopMatrix();

    // ── Divider line below title ──────────────────────────────────────────────
    color.setColor("E94560");
    glPushMatrix();
        glTranslatef(-3.0f, 2.4f, 0);
        glScalef(6.8f, 0.07f, 1);
        Shapes::rect(color);
    glPopMatrix();

    Text logo;

    // ── Game title ────────────────────────────────────────────────────────────
    color.setColor("E94560");
    glPushMatrix();
        glTranslatef(-0.95f, 3.0f, 0);
        logo.text(color, "Death By Race");
    glPopMatrix();

    // ── Subtitle ──────────────────────────────────────────────────────────────
    color.setColor("AAAACC");
    glPushMatrix();
        glTranslatef(-2.1f, 2.0f, 0);
        logo.text(color, "Click to Start the Race");
    glPopMatrix();

    // ── Controls label ───────────────────────────────────────────────────────
    color.setColor("E94560");
    glPushMatrix();
        glTranslatef(-2.5f, 1.2f, 0);
        logo.text(color, "CONTROLS");
    glPopMatrix();

    // ── Control entries ───────────────────────────────────────────────────────
    color.setColor("CCCCEE");
    glPushMatrix();
        glTranslatef(-2.5f, 0.6f, 0);
        logo.text(color, "Shoot      : S");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5f, 0.0f, 0);
        logo.text(color, "Move       : Arrow Keys");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5f, -0.6f, 0);
        logo.text(color, "Pause/Resume : P / R");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5f, -1.2f, 0);
        logo.text(color, "Quit       : Q");
    glPopMatrix();

    // ── Game over score display ───────────────────────────────────────────────
    if(gameOver){
        color.setColor("FFD700");
        glPushMatrix();
            glTranslatef(-1.0f, 3.2f, 0);
            logo.text(color, "SCORE:");
        glPopMatrix();
        glPushMatrix();
            glTranslatef(2.0f, 3.2f, 0);
            logo.score(color, ai.score);
        glPopMatrix();
    }
}

void Controller::button(){
    Color btnColor;

    // Button shadow/glow
    btnColor.setColor("7B1535");
    glPushMatrix();
        glTranslatef(-.8f, -2.4f, 0);
        glScalef(1.7f, 0.9f, 1);
        Shapes::rect(btnColor);
    glPopMatrix();

    // Main button
    btnColor.setColor("E94560");
    glPushMatrix();
        glTranslatef(-.77f, -2.33f, 0);
        glScalef(1.65f, 0.8f, 1);
        Shapes::rect(btnColor);
    glPopMatrix();

    // Button text
    btnColor.setColor("FFFFFF");
    Text logo;
    glPushMatrix();
        glTranslatef(-0.3f, -2.1f, 0);
        logo.text(btnColor, "FIGHT!");
    glPopMatrix();
}

void Controller::clicked(float x, float y){
    if(!gameRunning){
        // Click anywhere to start!
        AI newAI;
        ai = newAI;
        gameRunning = true;
        gameOver = false;
        wait = 0;
        bg.overAllSpeed = 0;
    }
}
