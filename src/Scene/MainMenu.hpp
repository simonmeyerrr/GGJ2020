#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP
#include "AScene.hpp"

class MainMenu : virtual public AScene {
public:
    MainMenu(IScene::TypeScene unnamed);
    MainMenu(MainMenu &) = delete;
    ~MainMenu();
    MainMenu &operator=(const MainMenu &) = delete;

    void update() override;
    void event(std::shared_ptr<MainWindow> &) override;
    void display() override;
private:
};
#endif /*MAIN_MENU_HPP*/