#ifndef SETTINGS_HPP
    #define SETTINGS_HPP
#include "AScene.hpp"

class Settings : virtual public AScene {
public:
    Settings(IScene::TypeScene unnamed);
    Settings(Settings &) = delete;
    ~Settings();
    Settings &operator=(const Settings &) = delete;

    void update() override;
    void event(std::shared_ptr<MainWindow> &) override;
    void display() override ;
private:
};
#endif /*SETTINGS_HPP*/