//
// Created by fgdou on 5/19/22.
//

#include <iostream>
#include "Maths/Timer.h"
#include "Renderer.h"
#include "Input.h"
#include "World.h"
#include "Menu/Menu.h"
#include "Menu/StartMenu.h"
#include "Menu/EndMenu.h"

int ntps, nfps;
std::shared_ptr<Menu> menu;
std::shared_ptr<World> world;
bool shouldQuit = false;

void tps()
{
     static int cnt = 0;
     cnt++;
     static double lastTime = Timer::getInstance().getSeconds();
     double time = Timer::getInstance().getSeconds();
     if (time - lastTime > 1.0)
     {
         lastTime = time;
         ntps = cnt;
         cnt = 0;

         std::string title = "ProjProg " + std::to_string(ntps) + " tps / " + std::to_string(nfps) + " fps";
         Renderer::getInstance().setWindowTitle(title);
     }

    Input::getInstance().update();

     if(menu == nullptr) {
         world->update();
         if(world->isDead()){
             menu = std::make_shared<EndMenu>(false);
         }
         if(world->hasWin()){
             menu = std::make_shared<EndMenu>(true);
         }
     }else {
         menu->update();
         auto selected = menu->getSelected();

         if(!selected.empty()){
             if(selected == "Play"){
                 menu = nullptr;
             }else if(selected == "Quit"){
                 shouldQuit = true;
             }else if(selected == "Restart"){
                 world = std::make_shared<World>();
                 menu = nullptr;
             }
         }
     }
}
void fps()
{
     static int cnt = 0;
     cnt++;
     static double lastTime = Timer::getInstance().getSeconds();
     double time = Timer::getInstance().getSeconds();
     if (time - lastTime > 1.0)
     {
         lastTime = time;
         nfps = cnt;
         cnt = 0;
     }

    Renderer &renderer = Renderer::getInstance();
    renderer.clear();

    // DRAW CALLS BELLOW
    world->draw();
    if(menu != nullptr)
        menu->draw();
    
    // drawDebug(world);


    renderer.render();
}

void drawDebug(){

    //Collision debug with lineDraw
    Renderer &renderer = Renderer::getInstance();
    Vec2 mouse = Input::getInstance().getMousePos();
    Vec2 pt(-500, 100);
    renderer.drawLine(pt, mouse, {255, 0, 0});
    Room &playerRoom = world->getPlayerRoom();
    Collision col = playerRoom.getCollisionAfterMove(pt, mouse - pt);
    if (col.isColliding)
    {
        // double insideRatio = 1- (col.impact - pt).norm()/(mouse-pt).norm() ;
        renderer.drawRect(col.impact, Vec2(5), {0, 255, 0});
        renderer.drawRect(col.newPos, Vec2(5), {0, 0, 250});
        renderer.drawLine(col.newPos, col.newPos + Vec2(20) *col.newDir.normalize(), {255, 0, 0});
        renderer.drawLine(col.impact, col.impact + col.newDir, {50, 50, 50,255});
    }
}

int main(int argc, char **argv)
{
    bool exit = false;
    Timer timer = Timer::getInstance();
    Renderer renderer = Renderer::getInstance();

    double last_time = timer.getSeconds();

    world = std::make_shared<World>();
    menu = std::make_shared<StartMenu>();

    // main loop
    while (!(Input::getInstance().hasBeenPressedOnce(Input::escape) || Input::getInstance().hasBeenPressedOnce(Input::exit) || shouldQuit))
    {
        auto now = timer.getSeconds();
        auto dt = now - last_time;

        if (dt > Timer::getDeltaTime())
        {
            last_time += dt;
            tps();
        }
        else
        {
            fps();
        }

        // std::string err = std::string(SDL_GetError());
        // if (!err.empty())
        //     std::cerr << err << '\n';
    }
    SDL_Quit();
}
